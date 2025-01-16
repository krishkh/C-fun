#include <stdio.h>
#include <stdlib.h>

#define YELLOW "\033[33m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

typedef struct node{
    struct node* next;
    int data;
} node;

typedef struct dNode{
    struct dNode* prev;
    struct dNode* next;
    int data;
} dNode;

typedef struct list{
    node* head;
    int size;
    // other meta data
}list;

node* createNode(){
    node* temp = (node*)malloc(sizeof(node));
    temp -> next = NULL;
    return temp;
}

int printArr(node* list){
    node* temp = list;
    printf("[");
    while (temp != NULL){
        printf("%d, ", temp->data);
        temp = temp -> next;
    }
    printf("]\n");
    return 0;
}

int insert(node* head, int item, int index){
    node* top = head;
    node * temp = createNode();
    temp -> data = item;
    int count = 0;
    while (top != NULL){
        if (count == (index - 1)){
            temp -> next = top -> next;
            top->next = temp; 
            return 0;
        }
        count++;
        top = top -> next;
    }
    printf(RED "\n ERROR: INDEX OUT OF RANGE \n" RESET);
    return -1;
}

int delete(node** head, int index){
    node* temp = *head;
    // if index is 0
    if(index == 0){
        *head = temp -> next;
        return 0;
    }
    // otherwise
    int count = 0;
    while (temp != NULL){
        if (count == (index-1) && temp->next != NULL){
            temp -> next = (temp -> next) -> next;
            return 0;
        }
        temp = temp -> next;
        count++;
    }
    printf(RED "\n ERROR: INDEX OUT OF RANGE \n" RESET);
    return -1;
}

int reversal(node** head){
    node *top = *head;
    node *prev = NULL;
    while (top != NULL){
        node* temp = top -> next;
        top -> next = prev;
        prev = top;
        top = temp;
    }
    *head = prev;
    return 0;
}

int singlyLinkedList(){
    printf("---Welcome to Linked List Program---\n");
    node* head;
    head = createNode();
    head -> data = 1;
    printf("array is\n");
    printArr(head);
    insert(head,2,1);
    printArr(head);
    insert(head,3,2);
    printArr(head);
    insert(head,4,3);
    printArr(head);
    delete(&head,3);
    printArr(head);
    reversal(&head);
    printArr(head);
    return 0;
}



int main(){
    singlyLinkedList();
}