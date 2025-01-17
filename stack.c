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
        printf("%c -> ", temp -> data);
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
    push(Stack, '1');
    push(Stack, '2');
    push(Stack, '3');
    push(Stack, '4');
    printStk(Stack);
    printf("size: %d\n", Stack->size);
    printf("popped: %c\n", pop(Stack));
    printStk(Stack);
    return 0;
}

char* postfixConversion(char * equation){
    printf("%s", equation);

    stack* operatorStack = createStack();
    stack* outputStack = createStack();
    char* cursor = equation;
    while(cursor != '\0'){
        if (cursor > 65 && cursor < 90 || cursor > 98 && cursor < 123){
            push(outputStack);
        }

        if (operatorStack->head->data)
        cursor++;
    }

    return equation;
}

int main(){
    checkingStack();
    char* equation = "A+B+C"; // AB+C+
    postfixConversion(equation);
}