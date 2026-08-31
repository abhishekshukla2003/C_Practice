/*Ques15: Write a program to accept 10 record with the structure- Display the record before and after sorting where sorting is based on name*/


#include<stdio.h>
#include<string.h>

struct record{
    char name[20];
    int age;
    float salary;
};

int main()
{
    struct record r[10];
    for(int i=0;i<10;i++)
    {
        printf("Enter name, age and salary for record %d: \n",i+1);
        scanf("%s %d %f",r[i].name,&r[i].age,&r[i].salary);
    }
    printf("\nRecords before sorting:\n");
    for(int i=0;i<10;i++)
    {
        printf("Record %d: Name: %s, Age: %d, Salary: %.2f\n",i+1,r[i].name,r[i].age,r[i].salary);
    }
    printf("\nRecords after sorting:\n");
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(strcmp(r[i].name,r[j].name)>0)
            {
                struct record temp=r[i];
                r[i]=r[j];
                r[j]=temp;
            }
           
        }
        printf("Record %d: Name: %s, Age: %d, Salary: %.2f\n",i+1,r[i].name,r[i].age,r[i].salary);
    }



    return 0;
}