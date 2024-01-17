#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
struct stack{
    int *items;
    int top;
};
void push(struct stack *s,int x){
    if(s->top==MAX_SIZE-1){
        printf("Stack is full.\n");
        return;
    }else{
        s->top++;
        s->items[s->top]=x;
        printf("The data %d inserted successfully.\n",x);
    }
}
void peek(struct stack *s){
    if(s->top==-1){
        printf("The stack is empty.\n");
    }else{
        printf("The peek data is:%d\n",s->items[s->top]);
    }
}
void display(struct stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= s->top; ++i) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
void pop(struct stack *s){
    if(s->top==-1){
        printf("Stack is Empty.\n");
        return;
    }else{
        int a=s->items[s->top--];
        printf("The data %d is poped successfully.\n",a);
    }
}
int main(){
    struct stack s;
    s.top=-1;
    s.items=(int*)malloc(sizeof(int)*MAX_SIZE);
  int choice,value;
  do{
  printf("\n1. Push\n");
  printf("\n2. Peek\n");
  printf("\n3. Pop\n");
  printf("\n4. Display\n");
  printf("\n0. exit\n");
  printf("Enter your choice:");
  scanf("%d",&choice);
  switch(choice){
    case 1:
    printf("Enter the items.\n");
    scanf("%d",&value);
    push(&s,value);
    break;
    case 2:
    peek(&s);
    break;
    case 3:
    pop(&s);
    break;
    case 4:
    display(&s);
    break;
    case 0:
    printf("Exiting program.\n");
    break;
    default:
    printf("Invalid choice.");
  }
  }while(choice!=0);
    free(s.items);
}