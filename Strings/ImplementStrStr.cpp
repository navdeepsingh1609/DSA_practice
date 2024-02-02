int Solution::strStr(const string A, const string B) {

//A is the haystack and the B is the needle 
//we have to find the first index of needle in the haystack and return it 

//first we need to find whether needle exists in haystack or not
// we can create a window that checks whether the string in the window is the correct or not

int size_of_window=B.size();
int n=A.size();

int i=0,j=0;
int index=0;

int flag=0;
while(i<n)
{
    if(A[i]!=B[j])
    {
        j=0;
        i=index+1;
        index=i;
        continue;
    }
    else
        j++; 
    if(j==B.size())
       { flag=1;break;}
    i++;
}

if(index>=n || flag==0)
    return -1;
return index;

}

