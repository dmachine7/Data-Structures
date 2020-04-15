#include<stdio.h>

int fibonacci(int n){
  if(n<=1){
    return n;
  }
  return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
  int num;
  printf("enter number of terms : ");
  scanf("%d",&num);
  int i;
  for(i=0;i<num;i++){
    printf("%d\n",fibonacci(i));
  }
  return 0;
}
