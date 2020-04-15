#include<stdio.h>
#include<stdlib.h>

//dll node structure
typedef struct DLLnode{
  int data;
  struct DLLnode*next;
  struct DLLnode*prev;
}node;
node*head=NULL;

//to print list
void printlist(node*start){
  node*ptr=start;
  printf("\nyour list is : ");
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
  return;
}

//function to append data in list
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
    node*p=NULL;
    p=head;
    while(p->next!=NULL){
      p=p->next;
    }
    p->next=temp;
    temp->prev=p;
  }
  return;
}

//function to delete node from a user given position
void dlldelete(node**start,int pos){
  if(!(*start)){
    printf("\nlist is empty");
    return;
  }
  node*ptr1=NULL,*ptr2=NULL;
  ptr1=*start;
  int k=1;
  if(pos==1){
    *start=(*start)->next;
    if(*start!=NULL){
      ptr1->prev=NULL;
    }
    free(ptr1);
    return;
  }
  else{
      while((k<pos)&&(ptr1->next!=NULL)){
      k++;
      ptr1=ptr1->next;
    }
    ptr2=ptr1->prev;
    ptr2->next=ptr1->next;
    if(ptr1->next){
      ptr1->next->prev=ptr2;
    }
    free(ptr1);
    return;
  }
  return;
}

//driver program
int main(){
  int choice;
  while(1){
    printf("1.append list 2.delete node 3.print list \nenter choice : ");
    scanf("%d",&choice);
    if(choice==1){
      append();
    }
    else if(choice ==2){
      int pos;
      printf("\nenter position of node: ");
      scanf("%d",&pos);
      dlldelete(&head,pos);
    }
    else{
      printlist(head);
      break;
    }
  }
  printf("\nprogram terminated");
  return 0;
}
