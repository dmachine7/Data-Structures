#include<stdio.h>
#include<stdlib.h>

//cll node structure
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

//insertion function
void insert(node**start,int num,int pos){
  node*newnode=NULL;
  newnode=(node*)malloc(sizeof(node));
  newnode->data=num;
  node*ptr=NULL;
  ptr=*start;
  do{
    ptr=ptr->next;
  }while(ptr->next!=head);
  if(pos==1){
    newnode->next=head;
    ptr->next=newnode;
    head=newnode;
    return;
  }
  else{
    newnode->next=head;
    ptr->next=newnode;
    return;
  }
}

//function to delete node
void delete(node**start,int pos){
  node*temp1,*temp2;
  temp1=*start;

  if(pos==1){
    do{
      temp2=temp1;
      temp1=temp1->next;
    }while(temp1!=head);
    temp2->next=temp1->next;
    head=temp1->next;
    free(temp1);
    return;
  }
  else{
    do{
      temp2=temp1;
      temp1=temp1->next;
    }while(temp1->next!=head);
    temp2->next=head;
    free(temp1);
    return;
  }
}

//function to print list
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

//driver program
int main(){
  int choice;
  while(1){
    printf("enter your choice : 1.append 2.insert 3.delete 4.printlist\n");
    scanf("%d",&choice);
    if(choice==1){
      append();
    }
    else if(choice==2){
      int num,pos;
      printf("\nenter number and position(1=head,2=tail): ");
      scanf("%d %d",&num,&pos);
      insert(&head,num,pos);
    }
    else if(choice==3){
      int pos;
      printf("\nenter position(1=head,2=tail):  ");
      scanf("%d",&pos);
      delete(&head,pos);
    }
    else{
      printlist(head);
      break;
    }
  }
  return 0;
}
