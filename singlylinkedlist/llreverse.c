#include<stdio.h>
#include<stdlib.h>
//node structure declaration
typedef struct Node{
  int data;
  struct Node*next;
}node;
node*head;
//to print list
void printlist (node*ptr){
  node*heads=ptr;
  printf("\nyour list is\n");
  while(heads!=NULL){
    printf("%d ",heads->data);
    heads=heads->next;
  }
}
//iterative reverse list function
node *reverse(node*current){
  /*maintained three pointers : current for current node ;
  nextnode the next of current is assigned to it
  ;prev becomes the previous node of current;
  likewise the assignment goes on till tail*/
  node*prev=NULL,*nextnode=NULL;
  while(current){
    nextnode=current->next;
    current->next=prev;
    prev=current;
    current=nextnode;
  }
  return prev;
}
//recursive reverse list function
void reverserecursive(node*prev,node*current){
  if(current){
    //beautiful implementation;
    //can be understood using function stack
    reverserecursive(current,current->next);
    current->next=prev;
  }
  else{
    //assigned head so now it points to original tail
    head=prev;
  }
}
//driver program
int main(){
  int length;
  printf("enter length of linked list\n");
  scanf("%d",&length);
  head=(node*)malloc(sizeof(node));
  node*list=head;
  printf("enter linked list\n");//input initial list
  while(length!=0){
    if(length==1){
      int temp;
      scanf("%d",&temp);
      list->data=temp;
      list->next=NULL;
    }
    else{
      int temp;
      scanf("%d",&temp);
      list->data=temp;
      list->next=(node*)malloc(sizeof(node));
      list=list->next;
    }
    length--;
  }
  printlist(head);
  head=reverse(head);
  printf("\nafter iterative reversal");
  printlist(head);
  reverserecursive(NULL,head);
  printf("\nafter recursive reversal");
  printlist(head);
  printf("\n program terminated");
  return 0;
}
