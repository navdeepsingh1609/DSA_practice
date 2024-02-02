int Solution::divide(int x, int y) {
  long long a=x,b=y;
  int sign=0;
  if((a<0 && b<0) || (a>0 && b>0)){
      sign=0;
  }
  else{
      sign=1;
  } 
  
  a = abs(a);
  b = abs(b);
   
  long long int quotient = 0, temp = 0;
 
  for (int i = 31; i >= 0; --i) {
 
    if (temp + (b << i) <= a) {
      temp += b << i;
      quotient += 1ll<<i;
    }
  }
  if(sign==1){
    quotient=-quotient;
  }
  if(quotient>INT_MAX || quotient<INT_MIN){
      return INT_MAX;
  }
  
  return quotient;
}
