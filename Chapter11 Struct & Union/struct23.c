/*Ques23: Write Recursive function for the following operation on a linked list
a). Find the length of the list
b).Find the sum of all the element is the list
c). Display the Linked list
d). Diplay the list in reverse order
e). Insert a node at the end
f).Delete the last node from the list
g).Search for an element in the list
*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

// a). Find the length of the list

int Length(struct node *head){
    if(head == NULL)
        return 0;
    
    return 1+ Length(head->next);
}

//b).Find the sum of all the element is the list

int sum(struct node *head){
    if(head == NULL)
        return 0;

    return head->data + sum(head->next);
}

//c). Display the Linked list

void Display(struct node *head){
    if(head == NULL)
        return;
    
    printf("%d ->",head->data);
    Display(head->next);        
    
}

//d). Diplay the list in reverse order

void DisplayReverse(struct node *head){
    if(head == NULL)
        return;
    
    DisplayReverse(head->next);
    printf("%d ->",head->data);        
    
}

//e). Insert a node at the end

struct node* insertEnd(struct node *head,int value){
    if(head == NULL)
    {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        return newNode;
    }
    head->next = insertEnd(head->next,value);
    return head;
}

//f).Delete the last node from the list

struct node* DeleteLastnode(struct node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    head->next = DeleteLastnode(head->next);
    return head;
}

//g).Search for an element in the list

int search(struct node *head,int key){
    if(head == NULL)
        return 0;
    if(head->data == key)
        return 1;
    return search(head->next,key);
}

int main(){
    struct node *head = NULL;

    struct node *n1 = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));

    n1->data= 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    head = n1;
    printf("Length of list = %d\n",Length(head));

    printf("Sum of elements is %d:\n",sum(head));

    printf("Linked List:\n");
    Display(head);
    printf("NULL\n");

    printf("List in reverse:\n");
    DisplayReverse(head);
    printf("NULL\n");

    head = insertEnd(head,110);
    head = insertEnd(head,120);
    head = insertEnd(head,130);

    printf("Linked List (before deletion):\n");
    Display(head);
    printf("NULL\n");

    head=DeleteLastnode(head);
    printf("After deletion:\n");
    Display(head);
    printf("NULL\n");

    int key;
    printf("Enter a key to search:");
    scanf("%d",&key);

    if(search(head,key))
        printf("Element %d found\n",key);
    else
        printf("Element %d not found\n",key);

    return 0;
}