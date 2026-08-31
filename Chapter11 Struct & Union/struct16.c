/*Ques 16: Write a function to count the number of occureances of an element in a single linked list. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
    int data;
    struct node *next;
};

int countOccurrences(struct node *head,int value){
    int count = 0;
    struct node *temp = head;
    while(temp != NULL){
        if(temp->data == value)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;

}

int main(){
    struct node *head = NULL;

    //creating nodes
    struct node *n1 = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));
    struct node *n4 = malloc(sizeof(struct node));
 
    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;
    
    n3->data = 20;
    n3->next = n4;
    
    n4->data = 10;
    n4->next = NULL;
    
    head = n1;

    printf("Number of Occurences of 10 = %d\n",countOccurrences(head,10));

 
    return 0;
}