#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int highest_mountain(vector<int> arr){
    int n=arr.size();
    int ans=0;//maximumCount
    for(int i=1;i<n-1;){
        int currLength=1;
        //Condition to check if a[i] is a peak
        if(arr[i-1]< arr[i] and arr[i+1]<arr[i]){
            int leftCount=0,rightCount=0,left=i;
            while(left>=1 and arr[left]>arr[left-1]){
                leftCount++;
                left--;
            }
            while(i<=n-2 and arr[i]>arr[i+1]){
                rightCount++;
                i++;
            }
            currLength+=leftCount+rightCount;
            ans=max(currLength,ans);
        }
        else{
            i++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<highest_mountain(arr);
    return 0;
}