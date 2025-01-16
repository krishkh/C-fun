#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* next;
    int coefficient;
} node;

node * createVar(int coefficient){
    node* newVar = (node* )malloc(sizeof(node));
    newVar -> coefficient = coefficient;
    newVar -> next = NULL;
    return newVar;
}

void addVar(node* eqn, int coefficient){
    node* cursor = eqn;
    while(cursor->next != NULL){
        cursor = cursor -> next;
    }
    cursor -> next = createVar(coefficient);
}

node* addEqn(node* eqn1, node* eqn2){
    node* temp1 = eqn1;
    node* temp2 = eqn2;
    node* head = createVar(0);
    while(temp1 || temp2){
        // This will add both coeff if both exist, if only one then only one is added to the coefficientSum
        int coefficientSum = temp1->coefficient? (temp2->coefficient? temp1->coefficient + temp2->coefficient : temp1->coefficient ): temp2->coefficient;
        addVar(head, coefficientSum);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return head -> next;
}

void printEqn(node* eqn){
    node* cursor = eqn;
    int count = 0;
    while(cursor != NULL){
        printf("%dx^%d + ", cursor->coefficient, count);
        cursor = cursor -> next;
        count++;
    }
    printf("\n");
}

int main(){
    printf("---Start of Polynomial Program---\n");
    // equestion 1
    node* eqn1 = createVar(1);
    addVar(eqn1, 2);
    addVar(eqn1, 3);
    addVar(eqn1, 4);
    printEqn(eqn1);
    // equestion 1
    node* eqn2 = createVar(1);
    addVar(eqn2, 2);
    addVar(eqn2, 3);
    addVar(eqn2, 4);
    printEqn(eqn2);
    node* sumEqn = addEqn(eqn1, eqn2);
    printEqn(sumEqn);

}