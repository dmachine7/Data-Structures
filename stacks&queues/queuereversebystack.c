#include<stdio.h>
#include<stdlib.h>

//node and queue structure declaration
typedef struct Node{
  int data;
  struct Node*next;
}node;
typedef struct Queues{
  node*front;
  node*rear;
}queue;

//function to create stack
node*createstack(){
  return NULL;
}

//function to create queue
queue*createqueue(){
  node*temp=(node*)malloc(sizeof(node));
  queue*q=(queue*)malloc(sizeof(queue));
  q->front=q->rear=NULL;
  return q;
}

//to check queue underflow
int isQueueEmpty(queue*q){
  return q->front==NULL;
}

//to check stack underflow
int isStackEmpty(node*top){
  return top==NULL;
}

//to insert data into queue
void enqueue(queue*q,int item){
  node*new=(node*)malloc(sizeof(node));
  new->data=item;
  new->next=NULL;
  if(q->rear){
    q->rear->next=new;
  }
  q->rear=new;
  if(q->front==NULL)
    q->front=q->rear;
}

//to delete data from queue
int deq(queue*q){
  int data;
  node*temp=(node*)malloc(sizeof(node));
  if(isQueueEmpty(q)){
    data=-1;
    printf("\nqueue underflow");
  }
  else{
    temp=q->front;
    data=q->front->data;
    q->front=q->front->next;
    free(temp);
  }
  return data;
}

//to insert data onto queue
void push(node**top,int data){
  node*temp=(node*)malloc(sizeof(node));
  temp->data=data;
  temp->next=*top;
  *top=temp;
}

//to delete data from stack
int pop(node**top){
  int data;
  node*temp=*top;
  if(isStackEmpty(temp)){
    data=-1;
  }
  else{
    *top=(*top)->next;
    data=temp->data;
  }
  return data;
}

//function to print queue
void printqueue(queue*q){
  queue*temp=q;
  printf("\nyour queue is: ");
  while(temp->front){
    printf("%d ",temp->front->data);
    temp->front=temp->front->next;
  }
}

//driver program
int main(){
  queue*q;
  q=createqueue();
  int len;
  int data;
  printf("enter length of queue: ");
  scanf("%d",&len);
  printf("enter your queue to be reversed: ");
  while(len--){
    scanf("%d",&data);
    enqueue(q,data);
  }
  node*stack;
  stack=createstack();
  //dequeuing and appending data onto stack
  while(!(isQueueEmpty(q))){
    push(&stack,deq(q));
  }
  //popping data from stack and appending into queue to make new reversed queue
  while(!(isStackEmpty(stack))){
    enqueue(q,pop(&stack));
  }
  printf("\nafter reversal");
  printqueue(q);
  printf("\nprogram terminated");
  return 0;
}
