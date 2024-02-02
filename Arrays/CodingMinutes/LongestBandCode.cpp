#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

//Time complexity is O(2n)
//Space complexity is O(n)

int longestConsecutive(vector<int>& nums) {
         //Insertion O(n)
         unordered_set<int> elements;
         for (auto element:nums ){
             elements.insert(element);
         }

        int ans=0;
         //Iteration 0(n) Lookup O(1)
         for(auto element:nums){
             int currCount=1;
             if(elements.find(element-1)==elements.end()){
                 int toFind=element+1;
                 while(elements.find(toFind)!=elements.end()){
                     toFind++;
                     currCount++;
                 }
                 ans=max(ans,currCount);
             }
         }
        return ans;
}


int main(){
    vector<int> arr{1,9,3,0,18,5,2,4,10,7,12,6};
    //100,4,200,1,3,2
    //0,3,7,2,5,8,4,6,0,1
    //1,9,3,0,18,5,2,4,10,7,12,6
    cout<<longestConsecutive(arr)<<endl;
    return 0;
}