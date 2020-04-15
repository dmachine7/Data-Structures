#include<stdio.h>
#include<stdlib.h>

//node structure declaration
typedef struct Node{
  int data;
  struct Node* next;
}node;

//function to print list
void printlist(node*start){
  node*head=start;
  printf("current list is\n");
  while(head!=NULL){
    printf("%d ",head->data);
    head=head->next;
  }
}

//insertion function
void insert(node**start,int num,int pos){
  node*newnode=malloc(sizeof(node));
  if(!newnode){
    printf("memory error");
    return;
  }
  newnode->data=num;
  int k=1;
  node*ptr1=NULL,*ptr2=NULL;
  ptr1=*start;
  if(pos==1){
    newnode->next=ptr1;
    *start=newnode;
    return;
  }
  else{
    while((ptr1!=NULL)&&(k<pos)){
      ptr2=ptr1;
      ptr1=ptr1->next;
      k++;
    }
    ptr2->next=newnode;
    newnode->next=ptr1;
    return;
  }
}

//to delete complete linked printlist
void deletelist(node**start){
  node*iterator,*temp;
  iterator=*start;
  while(iterator){
    temp=iterator->next;
    free(iterator);
    iterator=temp;
  }
  *start=NULL;
  printf("\nlist deleted");
}

int main(){
  int length;
  printf("enter length of linked list\n");
  scanf("%d",&length);
  node*head=(node*)malloc(sizeof(node));
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
  //to take all number and position to insert
  do {
    int choice;
    int num,pos;
    printf("\nenter your choice\n1.insert\n2.print final list\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1: printf("\nenter number and positon\n");
              scanf("%d %d",&num,&pos);
              //as we used a double pointer hence only address of head is required
              insert(&head,num,pos);
              break;
      case 2: printlist(head);
              break;
    }
    if(choice==2){
      break;
    }
  } while(1);

  deletelist(&head);
  printf("\nprogram terminated");
  return 0;
}
