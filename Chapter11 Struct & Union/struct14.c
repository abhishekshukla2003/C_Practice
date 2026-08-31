/*Ques 15: Write a program to accept name and arrival time of five trains and display the name with Railways time format.(2PM is written as 14.00).*/

#include <stdio.h>

struct train
{
    char name[30];
    int hour;
    int minute;
    char ampm[3];
};

int main()
{
    struct train t1[5];

    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter details for train %d:\n", i + 1);

        printf("Enter train name: ");
        scanf(" %29[^\n]", t1[i].name);

        printf("Enter arrival time (hour,minute,AM/PM): ");
        scanf("%d,%d,%2s",
              &t1[i].hour,
              &t1[i].minute,
              t1[i].ampm);
    }

        printf("\nTrain Arrival Details...\n");

    for (int i = 0; i < 5; i++)
    {
        int railway_hour = t1[i].hour;

        if (t1[i].ampm[0] == 'P' || t1[i].ampm[0] == 'p')
        {
            if (railway_hour != 12)
                railway_hour += 12;
        }
        else if (t1[i].ampm[0] == 'A' || t1[i].ampm[0] == 'a')
        {
            if (railway_hour == 12)
                railway_hour = 0;
        }

        printf("%s - %02d:%02d\n",
               t1[i].name,
               railway_hour,
               t1[i].minute);
    }

    return 0;
}
