#include <stdio.h>
#include <stdlib.h>

// Lets first implement a Stack
typedef struct node{
    struct node* next;
    char data;
}node;

typedef struct stack{
    node* head;
    int size;
}stack;

void printStk(stack* Stack){
    node* temp = Stack->head;
    while (temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

stack* createStack(){
    stack* newStack = (stack*)malloc(sizeof(stack));
    newStack -> size = 0;
    newStack -> head = NULL;
    return newStack;
}



int push(stack* Stack, int item){
    node* temp = (node*)malloc(sizeof(node));    
    temp -> data = item;
    temp -> next = Stack -> head;
    Stack -> head = temp;
    Stack -> size ++;
    return 0;
}

int pop(stack* Stack){
    int temp = Stack -> head -> data;
    Stack -> head = Stack -> head -> next;
    return temp;
}

int checkingStack(){
    printf("\n---Beginning of the Stack Program---\n");
    stack* Stack = createStack();
    push(Stack, 1);
    push(Stack, 2);
    push(Stack, 3);
    push(Stack, 4);
    printStk(Stack);
    printf("size: %d\n", Stack->size);
    printf("popped: %d\n", pop(Stack));
    printStk(Stack);
    return 0;
}

int main(){
    checkingStack();
}