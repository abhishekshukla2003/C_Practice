/*Ques 13: Write a C program to accept name,age and city of five people and display the name and city of the eldest one.*/

#include<stdio.h>
#include<string.h>

struct people{
        char name[20];
        int age ;
        char city[20];
    };

int main(){
    
    struct people p1[5];
    int maxIndex =0;

    for(int i=0; i<5; i++){
    
    printf("Enter details for person %d:\n", i + 1);
    printf("Enter name: ");
    scanf("%s", p1[i].name);
    printf("Enter age: ");
    scanf("%d", &p1[i].age);
    printf("Enter city: ");
    scanf("%s", p1[i].city);

    
    }
    for(int i=1; i<5; i++){

        if(p1[i].age > p1[maxIndex].age){

            maxIndex = i;
        }
    }
    
    printf("Details of the oldest person:\n");
        printf("Name: %s\n", p1[maxIndex].name);
        printf("City: %s\n", p1[maxIndex].city);

    
    return 0;
}