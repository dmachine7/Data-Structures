#include<stdio.h>
#include<stdlib.h>

//node structure
typedef struct node{
  int num;
  struct node * next;
}Node;

//function to print list
void printlist(Node * n){
  Node * test=n;
    while(test!=NULL){
      printf("%d\n",test->num);
      test=test->next;
    }
}

//driver program
int main(){
  int t;
  int i;
  scanf("%d",&t);

  //node creation and initialisation
  Node * head=NULL;
  head=malloc(sizeof(Node));
  Node * list=head;

  //loop to take input
  for(i=0;i<t;i++){
    if(i==t-1){
      int temp;
      scanf("%d",&temp);
      list->num=temp;
      list->next=NULL;
    }
    else{
      int temp;
      scanf("%d",&temp);
      list->num=temp;
      list->next=(Node*)malloc(sizeof(Node));
      list=list->next;
    }
  }

  //head as arguement passed to print list
  printlist(head);
  return 0;
}
