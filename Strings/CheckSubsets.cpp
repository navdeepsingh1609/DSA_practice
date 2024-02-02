#include<iostream>
using namespace std;

bool checkSubset(string S, string subset){
    int i=S.size()-1,j=S.size()-1;
    while( i>=0 and j>=0){
        if(subset[j]==S[i]){
            j--;
            i--;
        }
        else{
            j--;
        }
    }
    return j==-1;
}

int main(){
    string S,subset;
    getline(cin,S);
    getline(cin,subset);

    cout<<checkSubset(S,subset);
    return 0;
}