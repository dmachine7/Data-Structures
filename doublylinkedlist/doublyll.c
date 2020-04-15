#include<stdio.h>
#include<stdlib.h>

//double linked list node structure
typedef struct dllNode{
  int data;
  struct dllNode*next;
  struct dllNode*prev;
}node;
node*head=NULL;

//function to append data in doubly linked list
void append(){
  node*temp=NULL;
  temp=(node*)malloc(sizeof(node));
  printf("\nenter number to be appended\n");
  scanf("%d",&temp->data);
  temp->prev=NULL;
  temp->next=NULL;
  if(head==NULL){
    head=temp;
  }
  else{
    node*ptr=NULL;
    ptr=head;
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
  }
  return;
}

//function to print dll
void printlist(node*start){
  node*ptr=start;
  printf("\nyour list is : ");
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
  return;
}

//driver program
int main(){
  //loop until whole list is entered
  while(1){
    int choice;
    printf("enter: 1.append list 2.print final list\n");
    scanf("%d",&choice);
    if(choice==1){
      append();
    }
    else{
      printlist(head);
      break;
    }
  }
  printf("\nprogram terminated");
  return 0;
}
