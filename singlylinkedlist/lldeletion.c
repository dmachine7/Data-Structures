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

//deletion function
void delete(node**start,int pos){
  if(*start==NULL){
    printf("\nlist empty\n");
    return;
  }
  int k=1;
  //declaring pointers to traverse
  node*ptr1=NULL,*ptr2=NULL;
  ptr1=*start;
  //deletion of first node
  if(pos==1){
    *start=(*start)->next;
    free(ptr1);
    return;
  }
  //deletion of any other node
  else{
    while((ptr1!=NULL)&&(k<pos)){
      ptr2=ptr1;
      ptr1=ptr1->next;
      k++;
    }
    if(ptr1==NULL){
      printf("\nincorrect position\n");
      return;
    }
    ptr2->next=ptr1->next;
    free(ptr1);
    return;
  }
}

//driver program
int main(){
  int length,i;
  printf("enter length\n");
  scanf("%d",&length);
  //declaring head pointer
  node* head=malloc(sizeof(node));
  node* list=head;
  //initial list
  printf("enter list\n");
  for(i=0;i<length;i++){
    if(i==length-1){
      int temp;
      scanf("%d",&temp);
      list->data=temp;
      list->next=NULL;
    }
    else{
      int temp;
      scanf("%d",&temp);
      list->data=temp;
      list->next=malloc(sizeof(node));
      list=list->next;
    }
  }
  printlist(head);

  //for user to insert or delete
  int flag=1;
  do{
    int choice;
    int num,pos,del;
    printf("\nenter your choice: 1.insert 2.delete 3.print list 4.exit\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1: printf("\nenter number and position to be inserted\n");
              scanf("%d %d",&num,&pos);
              insert(&head,num,pos);
              break;
      case 2: printf("\nenter position to be deleted\n");
              scanf("%d",&del);
              delete(&head,del);
              break;
      case 3: printlist(head);
              break;
      case 4: flag=0;
              break;
    }
  }while(flag==1);

  printf("program terminated");

  return 0;
}
