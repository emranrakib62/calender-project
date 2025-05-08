#include <stdio.h>
#include <stdbool.h>


int getFirstDayOfTheYear(int year) {
    int firstDay = (year * 365 + ((year - 1) / 4)
                    - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    return firstDay;
}

int main() {
   
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year, weekDay = 0;

   
    printf("Enter any year: ");
    scanf("%d", &year);

  
    printf("\n----- Welcome To the Year %d -----\n", year);


    bool isLeapYear = false;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        printf("------ %d is a leap year ------\n", year);
        isLeapYear = true;
        daysInMonth[1] = 29; 
    } else {
        printf("------ %d is not a leap year ------\n", year);
    }

    int onOrOff;
    printf("\nPress 1 to start the calendar\n");
    printf("Press 0 to exit the calendar: ");
    scanf("%d", &onOrOff);

    if (onOrOff == 1) {
        weekDay = getFirstDayOfTheYear(year);

        for (int i = 0; i < 12; i++) {
            printf("\n\n  --------- %s ---------\n", months[i]);
            printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

      
            for (int j = 0; j < weekDay; j++) {
                printf("     ");
            }

            int totalDays = daysInMonth[i];
            for (int day = 1; day <= totalDays; day++) {
                printf("%5d", day);
                weekDay++;

              
                if (weekDay == 7) {
                    printf("\n");
                    weekDay = 0;
                }
            }
            printf("\n");
        }

    } else if (onOrOff == 0) {
        printf("\nCalendar stopped.\n");
    } else {
        printf("\nYou pressed the wrong key. Please run the program again.\n");
    }

    return 0;
}

