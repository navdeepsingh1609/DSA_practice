#include<iostream>
using namespace std;

string evenOdd(int n){
    return (n&1)==0?"Even":"Odd";
    //4-> 100 rightmost bit is 0
    //5-> 101 rightmost bit is 1
}

bool powerOf2(int n){
    return (n&n-1)==0;
    //256 100000000  any power of two is of form 0xb10... i.e only 1 bit is set
    //255 011111111 & ==0
    //178 10110010
    //177 10110001  & !=0
}

int getIthBit(int n,int i){
    int mask=1<<i;
    return (n&(mask))>0?1:0;
    //1010 n=2
    //0100 |
    //1110
}

void setIthBit(int &n,int i){
    int mask=1<<i;
    n=(n | mask);
    //1010 n=2
    //0100 |
    //1110
}

void clearIthBit(int &n,int i){
    int mask=(~(1<<i));
    n=(n&mask);
    //1010 n=3
    //0111 &
    //
}

void clearBitsInRange(int &n,int i,int j){
    int a=((~0)<<(j+1));
    int b=(1<<i)-1;
    int mask=a|b;
    n=(n&mask);
    // 1110101111
    // 9876543210
    //   j    i    lets say i=2 and j=7 
    //we would need a mask which is ...11100..00111... 0 b/w i and j and rest is 1
    //so we can simply do mask & number to clear the bits
    //Mask is two step process,   ...11110000000  (j+1 bits at right should be 0 rest 1)
    //                            a=>(~0)<<j+1 why j+1 coz j is also included to be cleared
    //                            ........000011 (i bits at right should be 1)
    //                            b=>(1<<i)-1
    //                            mask=> a|b
}

void replaceBits(int &n,int i,int j,int m){
    clearBitsInRange(n,i,j);
    int mask=(m<<i);
    n=n|mask;
    //See the question in notes
    //We are given with two integers n and m  and we need to replace i to j bits of n with m (size of m is j-i+1)
}

int countSetBits(int &n){
    //TC: O(setBitsCount)
    //9: 1001
    //8: 1000 & => 1000 (last set bit is removed) 
    //so a number would become 0 only in setBits number of times
    //instead of log n times like in below example
    int setBits=0;
    while(n>0){
        n=(n&(n-1)); //This removes the rightmost set bit of a number 
        setBits++;
    }
    return setBits;

    //TC: O(log(n))
    // int setBits=0;
    // while(n>0){
    //     if(n&1)
    //         setBits++;
    //     n=n>>1;
    // }
    // return setBits;
}

double NormalExpo(int a,int n){
    double ans=1;
    bool negative=(n<0)?true:false;
    if(negative) n=-1*n;
    while(n--){
        ans=ans*(double)a;
    }
    if(negative) return (double)1/ans;
    return ans;
}

double FastExponent(int a,int n){
    //2, 10 
    // a^8 a^4 a^2 a^1 => a^8 * a^2 =a^10
    // 1   0   1   0   => log(n)   
    //We can represeng n in terms of its bits in log n and now for each bit if its 1 
    //we can multiply the ans by the number and in each iteration we can multiply the number by two times
    double ans=1;
    bool negative=(n<0)?true:false;
    if(negative) n=(-1*n);
    while(n){
        int last_bit=(n&1);
        if(last_bit)
            ans=ans*double(a);
        a=a*a;
        n=n>>1;
    }
    if(negative) ans= (double)(1)/ans;

    return ans;
}

int decimalToBinary(int n){
    //Normally in long division method we keep on dividing no by 2 and keeping the reminder
    //and then the reverse of the remaiders is our anwer 
    //Instead 
    //1101
    //1*1+10*1+100+1*1000
    int ans=0,pow=1;
    while(n){
        int last_digit=((n&1)==0)?0:1; //same as reminder=n%2
        ans+=pow*last_digit;
        pow=pow*10;
        n=n>>1; //same as n=n/2
    }
    return ans;
}

int main(){
    int n=15,i=1,j=3,m=2;
    // cout<<NormalExpo(2,-10)<<endl;
    cout<<decimalToBinary(177);
    // replaceBits(n,i,j,m);
    // cout<<countSetBits(n)<<endl;
    // cout<<n<<endl;
}