#include<stdio.h>
#include<stdlib.h>

//node structure declared
typedef struct Nodes{
  int data;
  struct Nodes*next;
}node;

//to print list
void printlist (node*ptr){
  node*head=ptr;
  printf("\nyour list is\n");
  while(head!=NULL){
    printf("%d ",head->data);
    head=head->next;
  }
}

//function to find and print nth node from end
//when length of linked list is known
void nodefromend(node*start,int len,int pos){
  len=len-pos;
  node*ptr=start;
  int i;
  for(i=0;i<len;i++){
    ptr=ptr->next;
  }
  printf("%d node from end is %d",pos,ptr->data);
  return;
}

//takes O(n) time; ans in one scan
//used two pointers
//efficient function
void fromend(node*head,int pos){
  node*ptr1=NULL,*ptr2=head;
  int i;
  for(i=1;i<pos;i++){
    ptr2=ptr2->next;
  }
  while(ptr2!=NULL){
    if(ptr1==NULL){
      ptr1=head;
    }
    else{
      ptr1=ptr1->next;
    }
    ptr2=ptr2->next;
  }
  printf("%d node from end is %d",pos,ptr1->data);
}


//driver program
int main(){
  int length;
  int len;
  printf("enter length of linked list\n");
  scanf("%d",&length);
  len=length;
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
  int pos;
  printf("\nenter position from end\n");
  scanf("%d",&pos);
  nodefromend(head,len,pos);
  printf("\nenter position from end\n");
  scanf("%d",&pos);
  fromend(head,pos);
  printf("\nprogram terminated");

  return 0;
}
