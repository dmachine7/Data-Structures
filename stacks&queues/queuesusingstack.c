#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node*next;
}node;

//queue is implemented using two stacks
typedef struct Queue{
  node*s1;//stack 1
  node*s2;//stack 2
}queue;

node *createstack(){
  return NULL;
}

//in this function stacks are initialized for queue 
queue *createqueue(){
  queue*q=(queue*)malloc(sizeof(queue));
  q->s1=createstack();
  q->s2=createstack();
  return q;
}

int isStackEmpty(node*top){
  return top ==NULL;
}

void push (node**top,int data){
  node*new=(node*)malloc(sizeof(node));
  new->data=data;
  new->next=(*top);
  *top=new;
}

int pop(node**top){
  int data;
  if(isStackEmpty(*top)){
    printf("\nunderflow");
    return -1;
  }
  else{
    data=(*top)->data;
    (*top)=(*top)->next;
    return data;
  }
}

/*data is pushed in one of the stacks*/
void Enqueue(queue*q,int data){
  push(&q->s1,data);
}

/*if second stack is not empty then data is popped from it
otherwise we will push the popped data of first stack into second stack and then retured*/
int Dequeue(queue*q){
  if(!(isStackEmpty(q->s2))){
    return pop(&q->s2);
  }
  else{
    while(!(isStackEmpty(q->s1))){
      push(&q->s2,pop(&q->s1));
    }
    return pop(&q->s2);
  }
}

int main(){
  int choice=1;
  queue*q;
  q=createqueue();
  int data;
  while(choice){
    printf("\nenter choice: 1.Enqueue 2.Dequeue 0.Exit : ");
    scanf("%d",&choice );
    if(choice==1){
      printf("\nenter data: ");
      scanf("%d",&data);
      Enqueue(q,data);
    }
    else if(choice==2){
      data=Dequeue(q);
      printf("\n%d is dequeued",data);
    }
  }
  printf("\nprogram terminated");
  return 0;
}
