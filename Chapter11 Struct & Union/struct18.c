/*Ques:Write a function to create a copy of single linked list */

#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;

};
struct node* CreateCopyOfLinkedList(struct node *head ){
    if(head == NULL){
        //printf("List is empty!\n");
        return NULL;
    }

    struct node *newHead = NULL, *newTail = NULL;
    struct node *temp = head;

    while(temp != NULL){
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = temp->data;
        newNode->next = NULL;

        if(newHead == NULL){
            newHead = newNode;
            newTail = newNode;
        }
        else{
            newTail->next = newNode;
            newTail = newNode;
        }
        temp = temp->next;

    }
    return newHead;

}


//function to insert a node at the end
void insertEnd(struct node **head,int value){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
        return;
    }

    struct node *temp = *head;
    while(temp->next != NULL)
    temp = temp->next;

    temp->next = newnode;
}
void Display(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}


int main(){
    struct node *original = NULL;

    insertEnd(&original, 10);
    insertEnd(&original, 20);
    insertEnd(&original, 30);
    insertEnd(&original, 40);

    printf("Original List: ");
    Display(original);

    struct node *copy = CreateCopyOfLinkedList(original);
    printf("Copied list:");
    Display(copy);



    return 0;
}