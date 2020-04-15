#include<stdio.h>
#include<stdlib.h>

//stack implementation using linked list
typedef struct Stacklist{
  int data;
  struct Stacklist*next;
}stack;

//creation of stack or initialization of top
stack *createstack(){
  return NULL;
}

//to check stack underflow
int isStackEmpty(stack*top){
  return top==NULL;
}

//pushing data onto stack
void push(stack**top,int data){
  stack*temp=malloc(sizeof(stack));
  if(!temp)
    printf("\nmemory not allocated\n");
  else{
    temp->data=data;
    temp->next=*top;
    *top=temp;
  }
}

//popping out top most of stack
int pop (stack**top){
  stack*temp=*top;
  int item;
  if(isStackEmpty(temp))
    return -1;
  else{
    *top=(*top)->next;
    item=temp->data;
    return item;
  }
}

//to return current top of stack
int stacktop(stack*ptr){
  return ptr->data;
}

//to print current stack
void printlist(stack*ptr){
  stack*s=ptr;
  printf("\nyour stack is : ");
  while(s){
    printf("%d ",s->data);
    s=s->next;
  }
  printf("\n");
}

//freeing memory
void deletestack(stack**top){
  stack*temp,*ptr;
  ptr=*top;
  while(ptr->next){
    temp=ptr;
    ptr=ptr->next;
    free(temp);
  }
  free(ptr);
}

//driver program
int main(){
  stack*top;
  top=createstack();
  int choice=0;
  while(choice!=5){
    printf("enter choice: 1.push 2.pop 3.top 4.print 5.exit : ");
    scanf("%d",&choice);
    int data;
    switch (choice) {
      case 1: printf("\nenter data: ");
              scanf("%d",&data);
              push(&top,data);
              break;
      case 2: data=pop(&top);
              if(data==-1)
                printf("\nstack underflow\n");
              else
                printf("\n%d is popped out\n",data);
              break;
      case 3: printf("\ncurrent top is %d\n",stacktop(top));
              break;
      case 4: printlist(top);
              break;
      case 5: deletestack(&top);
              printf("\nstack deleted" );
              break;
    }
  }
  printf("\nprogram terminated");
  return 0;
}
