#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(string s1,string s2){
    if(s1.length()==s2.length()){
        return s1<s1;
    }
    else{
        return s1.length()<s2.length();
    }
}

void subsequences(string S,vector<string> &ans,string curr){
    //base case
    if(S.length()==0){ 
        ans.push_back(curr);
        return;
    }
    //small computation
    subsequences(S.substr(1),ans,curr+S[0]);
    subsequences(S.substr(1),ans,curr);


}

int main(){
    string S;
    getline(cin,S);
    vector<string> ans;
    subsequences(S,ans,"");
    sort(ans.begin(),ans.end(),comp);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;

}