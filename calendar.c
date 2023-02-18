#include<stdio.h>
#include<stdbool.h>
//first day of the year
int getfirstDayofTheyear(int year)
{
    int firstDay=(year*365+ ((year-1)/4 )-((year-1)/100)+((year-1)/400))%7;
    return firstDay;
};
int main()
{

    char *month[]= {"January","February","March","April", "May", "June", "July", "August","September","October","November","December" };
    int daysInMonth[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int weekDay = 0;


    int year;
    printf("Enter any year= ");
    scanf("%d",&year);

// Welcome
    printf("-----Welcome To the Year %d-----\n",year);
//checking if the year is leap year or not
    int isLeapYear;
    if(year % 400 == 0)
    {
        printf("------%d is a leap year-----\n",year);
        isLeapYear = true;
    }
    else if(year%4==0&&year%100!=0)
    {
        printf("------ %d is a leap year------\n",year);
        isLeapYear=true;
    }

    else
    {
        printf("------ %d is not a leap year--------\n",year);
        isLeapYear=false;
    }

    if(isLeapYear)
    {
        daysInMonth[1]=29;
    }

    int onOrof;
    printf("press 1 To start the calendar\n");
    printf("press 0 To Exit the calendar");
    scanf("%d",&onOrof);

    if(onOrof==1)
    {
        //first day of the given year
        weekDay=getfirstDayofTheyear(year);
        for(int i=0; i<12; i++)
        {
            //Month
            printf("\n---------%s----------",month[i]);
            printf("\n");
            //Weekdays

            printf("\n Sun Mon Tue Wed Thu Fri Sat \n");

            //spaceCounter

            int spaceCounter=0;
            for(spaceCounter=1; spaceCounter<=weekDay; spaceCounter++)
            {
                printf(" ");
            }

            //Days
            int totalDays=daysInMonth[i];
            for(int j=1; j<=totalDays; j++)
            {
                printf("%5d",j);
                weekDay++;
                if(weekDay==7)
                {
                    printf("\n");
                    weekDay=0;
                }
            }
            printf("\n\n");

        }

    }
    else if(onOrof==0)
    {
        printf("Calendar stopped\n");

    }
    else
    {
        printf("you press the wrong key.please press again.\n");
        printf("press 1 To start the calendar\n");
        printf("Or press 0 To Exit the calendar: \n");

        scanf("%d",&onOrof);
    }



  return 0;

}
