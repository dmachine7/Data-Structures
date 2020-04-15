#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 //max size of array defined

//stack structrure[simple array implementation]
typedef struct ArrayStack{
  int top;
  int capacity;
  int *array;
}stack;

//function to create a stack and allocate memory from heap
stack*createStack(){
  stack*S=(stack*)malloc(sizeof(stack));
  if(!S)
    return NULL;
  S->top=-1;
  S->capacity=SIZE;
  S->array=malloc(SIZE*sizeof(int));
  if(!S->array)
    return NULL;
  return S;
}

//to check stack overflow
int isStackFull(stack*top){
  return top->top==top->capacity-1;
}

//to check stack underflow
int isStackEmpty(stack*top){
  return top->top==-1;
}

//function to push data onto stack
void push (stack*temp,int data){
  if(isStackFull(temp))
    printf("\nstack overflow\n");
  else{
    temp->array[++temp->top]=data;
  }
}

//function to pop out data from stack
int pop(stack*temp){
  if(isStackEmpty(temp))
    return -1;
  else{
    return temp->array[temp->top--];
  }
}

//function to delete stack and free memory
void DeleteStack(stack*temp){
  if(temp){
    if(temp->array)
      free(temp->array);
    free(temp);
  }
}

//driver program
int main(){
  int choice;
  stack*top;
  top=createStack();
  while(1){
    printf("enter choice : 1.push 2.pop 3.exit : ");
    scanf("%d",&choice);
    if(choice==1){
      int data;
      printf("\nenter data: ");
      scanf("%d",&data);
      push(top,data);
    }
    else if(choice==2){
      int data;
      data=pop(top);
      if(data==-1)
        printf("\nstack underflow\n");
      else
        printf("\ndata popped out : %d\n",data);
    }
    else{
      DeleteStack(top);
      printf("\nstack deleted ");
      printf("\nprogram terminated");
      break;
    }
  }
  return 0;
}
