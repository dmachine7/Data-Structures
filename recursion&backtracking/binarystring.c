#include<stdio.h>
int num;

void print(int arr[]){
  int i=0;
  for(i=0;i<num;i++){
    printf("%d",arr[i]);
  }
  printf("\n");
}

void binary (int arr[],int n){
  if(n<1) {
    print(arr);
  }
  else{
    arr[n-1]=0;
    binary(arr,n-1);
    arr[n-1]=1;
    binary(arr,n-1);
  }
}

int main(){
  printf("enter length of string : ");
  scanf("%d",&num);
  int arr[num];
  binary(arr,num);
  return 0;
}
