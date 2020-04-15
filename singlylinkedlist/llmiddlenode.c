#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node*next;
}node;

void printlist(node*start){
  node*ptr=start;
  printf("\nthe list is:\n");
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
}

//insertion function
void insert(node**start,int num,int pos){
  node*newnode=(node*)malloc(sizeof(node));
  if(!newnode){
    printf("memory error");
    return;
  }
  newnode->data=num;
  int k=1;
  node *ptr1=NULL,*ptr2=NULL;//pointers to traverse and store locations
  ptr1=*start;
  //ins at beginning
  if(pos==1){
    newnode->next=ptr1;
    *start=newnode;
    return;
  }
  //ins elsewhere
  else{
    while((ptr1!=NULL) && (k<pos)){
      ptr2=ptr1;
      k++;
      ptr1=ptr1->next;
    }
    ptr2->next=newnode;
    newnode->next=ptr1;
    return;
  }
}

//function to find middle Node
//single scan ; used two pointers;
void middlenode(node*start){
  node*slowptr,*fastptr;
  slowptr=fastptr=start;
  int i=0;
  while(fastptr->next!=NULL){
    if(i==0){
      fastptr=fastptr->next;
      i=1;
    }
    else if(i==1){
      fastptr=fastptr->next;
      slowptr=slowptr->next;
      i=0;
    }
  }
  printf("\nmiddle node is : %d",slowptr->data);
  return;
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
  middlenode(head);
  printf("\nprogram terminated");
  return 0;
}
