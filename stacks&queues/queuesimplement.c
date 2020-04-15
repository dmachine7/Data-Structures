#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct Queues{
  int front,rear;
  int capacity;
  int *array;
}queue;

queue*createqueue(){
  queue*q=(queue*)malloc(sizeof(queue));
  q->front=q->rear=-1;
  q->capacity=SIZE;
  q->array=malloc(SIZE*sizeof(int));
  return q;
}

int underflow(queue*q){
  return q->front==q->rear;
}

int overflow(queue*q){
  return q->rear==q->front;
}

void enqueue(queue*q,int data){
  q->rear=(q->rear+1)%q->capacity;
  if(overflow(q)){
    printf("\nqueue overflow");
    if(q->rear==0)
      q->rear=q->capacity-1;
    else
      q->rear-=1;
    return;
  }
  else{
    q->array[q->rear]=data;
    return;
  }
}

int deq(queue*q){
  int data=NULL;
  if(underflow(q)){
    printf("\nqueue underflow");
  }
  else{
    q->front=(q->front+1)%q->capacity;
    data=q->array[q->front];
  }
  return data;
}

void printqueue(queue*q){
  queue*s=q;
  printf("\nyour queue : ");
  do{
    q->front=(q->front+1)%q->capacity;
    printf("%d ",q->array[q->front]);
  }while(q->front!=q->rear);
}

int main(){
  queue*Q;
  Q=createqueue();
  int choice;
  do{
    printf("\nenter choice: 1.enqueue 2.dequeue 3.print current queue 0.exit : \n");
    scanf("%d",&choice);
    int data;
    if(choice==1){
      printf("\nenter data: ");
      scanf("%d",&data);
      enqueue(Q,data);
    }
    else if(choice==2){
      data=deq(Q);
      printf("\n%d is dequeued",data);
    }
    else if (choice==3){
      printqueue(Q);
    }
  }while(choice);
  printf("\nprogram terminated");
  return 0;
}
