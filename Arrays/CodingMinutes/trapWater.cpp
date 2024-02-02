#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

//Two Pointer approach is best filling from 1st to 2nd last moving pointer left or right
//We can keep max so far arrays from both sides

int trap(vector<int>& height) {
        //A[i] -> L,R max so far
        //sum of overall min(max L,max R) - currHeight would be my ans 
        int size=height.size();
        if(size<=2) return 0;

        //TC: O(n), SC: O(1)
        //Instead of arrays keep variables and update them on the go
        int LeftMax=height[0],RightMax=height[size-1],i=1,j=size-2;
        //may updating left or right max would depend upon whis is min at that index
        //Now while checking, 
        //if height of current >= max chosen => no water trapped & update height
        //if height of current < max chosen => water trapped & update height not required 
        int ans=0;
        while(i<=j){
            if(LeftMax<RightMax){
                if(height[i]>LeftMax){
                    LeftMax=height[i];
                }
                else{
                    ans+=LeftMax-height[i];
                }
                i++;
            }
            else{
                if(height[j]>RightMax){
                    RightMax=height[j];
                }
                else{
                    ans+=RightMax-height[j];
                }
                j--;
            }
        }
        return ans;
        //TC: O(n), SC: O(n)
        // vector<int> LeftMax(size),RightMax(size);
        // LeftMax[0]=height[0];
        // RightMax[size-1]=height[size-1];
        // for(int i=1;i<size;i++){
        //     LeftMax[i]=max(LeftMax[i-1],height[i]);
        // }
        // for(int i=size-2;i>=0;i--){
        //     RightMax[i]=max(RightMax[i+1],height[i]);
        // }
        // int waterTrapped=0;
        // for(int i=0;i<size;i++){
        //     waterTrapped+=min(LeftMax[i],RightMax[i])-height[i];
        // }
        // return waterTrapped;
    }

int main(){
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    //4,2,0,3,2,5
    cout<<trap(height)<<endl;
    return 0;
}