#include<stdio.h>
#include<stdlib.h>

//linked list node and queue structure declaration
typedef struct Node{
  int data;
  struct Node*next;
}node;
typedef struct Queues{
  node*front;
  node*rear;
}queue;

//function to create queue structure
queue *createqueue(){
  node*temp=(node*)malloc(sizeof(node));
  queue*q=(queue*)malloc(sizeof(queue));
  q->front=q->rear=NULL;
  return q;
}

int isQueueEmpty(queue*q){
  return q->front==NULL;
}

//function to append data at one end in queue
void enqueue(queue*q,int data){
  node*new=(node*)malloc(sizeof(node));
  new->data=data;
  new->next=NULL;
  if(q->rear){
    q->rear->next=new;
  }
  q->rear=new;
  if(q->front==NULL)
    q->front=q->rear;
}

//function to dequeue from one end
int dequeue (queue*q){
  int data=-1;
  node*temp;
  if(isQueueEmpty(q)){
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

//function to print current queue
void printqueue(queue*q){
  queue*temp=q;
  printf("\nyour current queue is: ");
  while(temp->front){
    printf("%d ",temp->front->data);
    temp->front=temp->front->next;
  }
}

//to delete queue and free up used memory
void deletequeue(queue*q){
  node*temp;
  while(q->front){
    temp=q->front;
    q->front=q->front->next;
    free(temp);
  }
  free(q);
}

//driver program
int main(){
  int choice=1;
  queue*q;
  q=createqueue();
  do{
    int data;
    printf("\nenter choice: 1.Enqueue 2.Dequeue 3.print current queue 0.exit : ");
    scanf("%d",&choice);
    //switch case to perform desired function
    switch(choice){
      case 1: printf("\nenter data : ");
              scanf("%d",&data);
              enqueue(q,data);
              break;
      case 2: data=dequeue(q);
              printf("\n%d is dequeued.",data);
              break;
      case 3: printqueue(q);
              break;
      case 0: deletequeue(q);
              break;
    }
  }while(choice);
  printf("\nprogram terminated");
  return 0;
}
