#include<stdio.h>

void TOH(int n,char from,char to ,char aux){
  //base task
  if(n==1){
    printf("\nmove disk %d from rod %c to rod %c",n,from,to);
    return;
  }
  //subtask hence called recursively 
  TOH(n-1,from,aux,to);
  printf("\nmove disk %d from rod %c to rod %c",n,from,to);
  TOH(n-1,aux,to,from);
}

int main(){
  int num;
  printf("enter number of disks : ");
  scanf("%d",&num);
  char from,to,aux;
  from='A';
  to='B';
  aux='C';
  TOH(num,from,to,aux);
  return 0 ;
}
