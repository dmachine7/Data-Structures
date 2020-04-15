#include<stdio.h>
#include<stdlib.h>

//circular linked list node structure
typedef struct CLLnode{
  int data;
  struct CLLnode*next;
}node;
node*head=NULL;

//function to append list
void append(){
  node*temp=NULL;
  temp=(node*)malloc(sizeof(node));
  printf("\nenter number to be appended : " );
  scanf("%d",&temp->data );
  temp->next=NULL;
  if(head==NULL){
    head=temp;
    temp->next=head;
    return;
  }
  else{
    node*ptr=head;
    while(ptr->next!=head){
      ptr=ptr->next;
    }
    ptr->next=temp;
    temp->next=head;
    return;
  }
}

//function to count elements of the list
void countlist(node*start){
  node*ptr=start;
  int count=0;
  if(ptr==NULL){
    return;
  }
  do{
    ptr=ptr->next;
    count++;
  }while(ptr!=start);
  printf("\nlength of the list is %d",count);
  return;
}

//function to print the elements of the list
void printlist(node*start){
  node*ptr=start;
  if(ptr==NULL){
    return;
  }
  printf("\nthe list is : ");
  do{
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }while(ptr!=start);
  return;
}

int main(){
  int choice;
  while(1){
    printf("enter choice : 1.append list 2.print list : ");
    scanf("%d",&choice);
    if(choice==1){
      append();
    }
    else{
      countlist(head);
      printlist(head);
      break;
    }
  }
  return 0;
}
