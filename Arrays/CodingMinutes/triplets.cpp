#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > triplets(vector<int> arr, int sum){
    vector<vector<int> > ans;

    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        int find=sum-arr[i];
        int j=i+1,k=arr.size()-1;
        while(j<=k){
            if(arr[j]+arr[k]==find){
                ans.push_back( {0,0,0} );
                j++;
                k--;
            }
            else if(arr[j]+arr[k]<find){
                j++;
            }
            else{
                k--;
            }
        }
    }

    return ans;
}

int main(){

    vector<int> arr{5,6,8,1,3,6,7,8,6,12,5,1,2,6,9,8,1};
    int sum=15;
    vector<vector<int > > ans=triplets(arr,sum);
    for(auto it:ans){
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }

}