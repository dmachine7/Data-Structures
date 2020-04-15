#include<stdio.h>
#include<stdlib.h>

//double linked list node structure
typedef struct dllNode{
  int data;
  struct dllNode*next;
  struct dllNode*prev;
}node;
node*head=NULL;

//function to append list
void append(){
  node*temp=NULL;
  temp=(node*)malloc(sizeof(node));
  printf("\nenter number to be appended: ");
  scanf("%d",&temp->data);
  temp->next=NULL;
  temp->prev=NULL;
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

//function to insert node at a given position
void dllinsert(node**start,int num ,int pos){
  node*temp=NULL;
  temp=(node*)malloc(sizeof(node));
  node*nextnode=NULL,*prevnode=NULL;
  nextnode=*start;
  temp->data=num;
  temp->prev=NULL;
  temp->next=NULL;
  int k=1;
  if(pos==1){
    temp->next=nextnode;
    if(nextnode){
      nextnode->prev=temp;
    }
    *start=temp;
    return;
  }
  else{
    while((nextnode!=NULL)&&(k<pos)){
      prevnode=nextnode;
      nextnode=nextnode->next;
      k++;
    }
    temp->next=nextnode;
    temp->prev=prevnode;
    prevnode->next=temp;
    nextnode->prev=temp;
    return;
  }
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
  //loop to take input of the list and also insert at a user given position
  while(1){
    int choice;
    printf("enter choice: \n1.append list \n2.insert at given position \n3.print final list\n");
    scanf("%d",&choice);
    if(choice==1){
      append();
    }
    else if(choice==2){
      int num,pos;
      printf("enter number and position\n");
      scanf("%d %d",&num,&pos);
      dllinsert(&head,num,pos);
    }
    else{
      printlist(head);
      break;
    }
  }
  printf("\nprogram terminated");
  return 0;
}
