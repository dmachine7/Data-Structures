#include<stdio.h>
#include<stdlib.h>

//node structure declared
typedef struct Nodes{
  int data;
  struct Nodes*next;
}node;

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
      /*two pointers maintained: ptr1 always sotes the next node of new node and ptr2 stores previous node
      of the new node and both are assigned after the loop accordingly*/
      ptr2=ptr1;
      k++;
      ptr1=ptr1->next;
    }
    ptr2->next=newnode;
    newnode->next=ptr1;
    return;
  }
}

//to print list
void printlist (node*ptr){
  node*head=ptr;
  printf("\nyour list is\n");
  while(head!=NULL){
    printf("%d ",head->data);
    head=head->next;
  }
}

//driver program
int main(){
  int length;
  printf("enter length of linked list\n");
  scanf("%d",&length);
  node*head=(node*)malloc(sizeof(node));
  /*head is used to point to the first node throughout the program and must be checked if it is doing so or
  not and the list is used for storing data in the list and for furthur creation of node by taking up memory
  from the heap  */
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
  return 0;
}
