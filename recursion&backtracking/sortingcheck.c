#include<stdio.h>
int checksort(int arr[],int n){
  if(n==1)
    return 1;
  return (arr[n-1]<arr[n-2])?0:checksort(arr,n-1);
}
int main(){
  int arr[5];
  int i;
  printf("enter array of length 5 : \n");
  for(i=0;i<5;i++){
    scanf("%d",&arr[i-1]);
  }
  i=checksort(arr,5);
  if(i==1)
    printf("sorted");
  else
    printf("not sorted");
  return 0;
}
