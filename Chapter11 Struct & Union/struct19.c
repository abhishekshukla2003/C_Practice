/*Ques19: Write a function to move the largest element to the end of single linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;

};
void MoveLargestToEnd(struct node **head){
    struct node *temp = *head;
    struct node *largest = *head;
    struct node *largestPrev = NULL;

    if(*head == NULL || (*head)->next == NULL){
        
        return ;
    }
    //Find Largest node
    while(temp->next != NULL)
    {
        if(temp->next->data > largest->data)
        {
            largest = temp->next;
            largestPrev = temp;
        }
        temp = temp->next;
    }
    //Largest is already at the end
    if(largest->next == NULL)
        return;

    //Remove largest from its current position
    if(largestPrev == NULL){
        *head = (*head)->next;
    }
    else
    {
        largestPrev->next = largest->next;
    }
    //Find last node
    temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    //Attach largest at end
    temp->next = largest;
    largest->next = NULL;

}
void Display(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}

int main()
{
    struct node *head = NULL;

    //Create nodes
    struct node *n1 = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));
    struct node *n4 = malloc(sizeof(struct node));

    //Assign data
    n1->data = 10;
    n2->data = 20;
    n3->data = 50;
    n4->data = 40;

    //Link nodes

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    head = n1;

    printf("Before moving largest:\n");
    Display(head);

    MoveLargestToEnd(&head);

    printf("After moving largest:\n");
    Display(head);

    return 0;
}