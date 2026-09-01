/*Ques17: Write a function to find smallest and largest element of a single linked list.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
    int data;
    struct node *next;

};

void SmallestandLargestElement(struct node *head,int *smallest ,int *largest){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    *smallest = head->data;
    *largest = head ->data;

    struct node *temp = head->next;

    while(temp != NULL){
        if(temp->data < *smallest)
        *smallest = temp->data;

        if(temp->data > *largest)
        *largest = temp->data;

        temp = temp->next;
    }

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



int main()
{
    struct node *head = NULL;
    int smallest,largest;

    insertEnd(&head,13);
    insertEnd(&head,12);
    insertEnd(&head,1);
    insertEnd(&head,10);

    insertEnd(&head,17);

    SmallestandLargestElement(head,&smallest,&largest);

    printf("Smallest element:%d\n",smallest);
    printf("Largest element:%d\n",largest);

    
    



    return 0;
}