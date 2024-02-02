int Solution::candy(vector<int> &A) {
    int n = A.size();
    if(n == 0)
     return 0;
    int i = 1;
    int sum = 1;
    int candy = 1;
     while(i < n){
         if(A[i] > A[i - 1]){
             candy++;
             sum += candy;
             i++;
         }else if(A[i -1] > A[i]){
             int count =0;
             while(A[i] < A[i-1] && i < n){
                 count++;
                 i++;
             }
             if(count >= candy){
              sum += count - candy + 1;}
              
              sum += count*(count+1)/2 ;
              candy = 1;
         }else{ // important last block when both have same ranking.
             candy = 1;
             sum += candy;   
             i++;
         }
     }
     
     return sum;
}

