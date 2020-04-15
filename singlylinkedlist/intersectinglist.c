#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node*next;
}node;

int listlen(node*start){
  node*ptr=start;
  int count=0;
  while(ptr!=NULL){
    count++;
    ptr=ptr->next;
  }
  return count;
}

//function to find intersection point of two linked list
//most efficient approach
void intersection(node*head1,node*head2){
  int l1,l2;
  node*list1=NULL,*list2=NULL;
  //1.find length of both list
  l1=listlen(head1);
  l2=listlen(head2);
  int diff;
  int flag=0;
  //2.find difference
  if(l1>l2){
    diff=l1-l2;
    list1=head1;
    list2=head2;
  }
  else{
    diff=l2-l1;
    list1=head2;
    list2=head1;
  }
  //3.traverse longer list diff times
  while(diff--){
    list1=list1->next;
  }
  //4.now compare each node next pointer till intersection or termination
  while(list1){
    if(list1==list2){
      flag=1;
      break;
    }
    list1=list1->next;
    list2=list2->next;
  }

  if(flag){
    printf("\nintersection occurs at : %d",list1->data);
    return;
  }
  else{
    printf("\nno intersection");
    return;
  }
}

int main(){
  node*head1=(node*)malloc(sizeof(node));
  head1->data=1;
  node*head2=(node*)malloc(sizeof(node));
  head2->data=7;

  node*newnode=(node*)malloc(sizeof(node));
  newnode->data=2;
  head1->next=newnode;

  newnode=(node*)malloc(sizeof(node));
  newnode->data=3;
  head1->next->next=newnode;

  newnode=(node*)malloc(sizeof(node));
  newnode->data=4;
  head1->next->next->next=newnode;

  newnode=(node*)malloc(sizeof(node));
  newnode->data=5;
  head1->next->next->next->next=newnode;
  head2->next=newnode;

  newnode=(node*)malloc(sizeof(node));
  newnode->data=6;
  head1->next->next->next->next->next=newnode;
  head2->next->next=newnode;

  head1->next->next->next->next->next->next=NULL;
  head2->next->next->next=NULL;

  intersection(head1,head2);
  printf("\nprogram terminated");
  return 0;
}
