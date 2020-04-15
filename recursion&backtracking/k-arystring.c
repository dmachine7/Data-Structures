#include<stdio.h>
int num,k;

void print(int arr[]){
  int i=0;
  for(i=0;i<num;i++){
    printf("%d",arr[i]);
  }
  printf("\n");
}

void karystring(int arr[],int n,int k){
int j;
  if(n<1)
    print(arr);
  else{
    for(j=0;j<k;j++){
      arr[n-1]=j;
      karystring(arr,n-1,k);
    }
  }
}

int main(){
  printf("enter length and k : \n");
  scanf("%d",&num);
  scanf("%d",&k);
  int arr[num];
  karystring(arr,num,k);
  return 0;
}
