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

void printStk(stack* Stack);
stack* createStack();
int push(stack* Stack, int item);
int pop(stack* Stack);
int getPriority(char element);
int isOperator(char element);
int isAlpha(char element);
char* postfixConversion(char * equation);
int checkingStack();

int main(){
    // checkingStack();
    // char* equation = "A+B+C"; // AB+C+
    // postfixConversion(equation);
}

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

int getPriority(char element){
    switch(element){
        case '+':
        case '-':
            return 1;
        case '/':
        case '*':
            return 2;
        case '^':
            return 3;
        default: 
            return 0;
    }
}


int isOperator(char element){
    switch(element){
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
            return 1;
        }
    return 0;
}

int isAlpha(char element){
    if ((element > 65 && element < 90) || (element > 98 && element < 123)){
            return 1;
        }
    return 0;
}

char* postfixConversion(char * equation){
    printf("%s", equation);

    stack* operatorStack = createStack();
    stack* outputStack = createStack();
    char* cursor = equation;
    while(cursor != '\0'){
        if (isAlpha(*cursor)){
            push(outputStack, *cursor);
        }
        if (operatorStack->head->data){}
        cursor++;
    }

    return equation;
}