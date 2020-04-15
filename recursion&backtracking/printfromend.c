#include<stdio.h>
void print(int n){
  if(n<1){
    return 0;
  }
  else{
    printf("%d ",n);
    return print(n-1);
  }
}
int main(){
  int n;
  printf("enter number from which till 1 to be printed : ");
  scanf("%d",&n);
  print(n);
}
