int Solution::removeDuplicates(vector<int> &A) {
    
    int i=0,j=1,n=A.size();
    if(n==0){
        return 0;
    }
    for(;j<n;j++){
        if(A[i]!=A[j]){
            i++;
            A[i]=A[j];
        }
        
    }
    return i+1;
   
}
