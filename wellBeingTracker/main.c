#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{   
    int year;
    int month;
    int day;
    const int JAN = 1;
    const int DEC = 12; 
    double morning, morningTotal;
    double evening, eveningTotal;
    double avgTotal;

    printf("General Well-being Log\n");
    printf("======================\n");

do
{

        do
        {
                printf("Set the year and month for the well-being log (YYYY MM): ");
                scanf(" %d %d", &year, &month);

                if (year < MIN_YEAR || year > MAX_YEAR)
                {
                    printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
                }
                
                if (month < JAN || month > DEC)
                {
                    printf("   ERROR: Jan.(1) - Dec.(12)\n");
                }

                if ((month >= JAN && month <= DEC) && (year >= MIN_YEAR && year <= MAX_YEAR))
                {
                    printf("\n");
                    printf("*** Log date set! ***\n\n");
                }
                
        } while (year < MIN_YEAR || year > MAX_YEAR || month < JAN || month > DEC);
    
        do
        {    
                for (day = 1; day <= LOG_DAYS; day++)
                {
                    switch (month)
                        {
                            case 1:
                                printf("%d-JAN-0%d\n", year, day);
                                break;
                            case 2:
                                printf("%d-FEB-0%d\n", year, day);
                                break;
                            case 3:
                                printf("%d-MAR-0%d\n", year, day);
                                break;
                            case 4:
                                printf("%d-APR-0%d\n", year, day);
                                break;
                            case 5:
                                printf("%d-MAY-0%d\n", year, day);
                                break;
                            case 6:
                                printf("%d-JUN-0%d\n", year, day);
                                break;
                            case 7:
                                printf("%d-JUL-0%d\n", year, day);
                                break;
                            case 8:
                                printf("%d-AUG-0%d\n", year, day);
                                break;
                            case 9:
                                printf("%d-SEP-0%d\n", year, day);
                                break;
                            case 10:
                                printf("%d-OCT-0%d\n", year, day);
                                break;
                            case 11:
                                printf("%d-NOV-0%d\n", year, day);
                                break;
                            case 12:
                                printf("%d-DEC-0%d\n", year, day);
                                break;
                            default:
                                break;
                        }

                    do
                    {
                        printf("   Morning rating (0.0-5.0): ");
                        scanf(" %lf", &morning);
                        if (morning < 0.00 || morning > 5.0)
                            {
                                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                            }
                        else
                            {
                                morningTotal += morning;
                            }
                    } while (morning < 0.00 || morning > 5.0);
                    
                    do
                    {   
                        printf("   Evening rating (0.0-5.0): ");
                        scanf(" %lf", &evening);

                        if (evening < 0.00 || evening > 5.0)
                            {
                                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                            }
                        else
                            {
                                eveningTotal += evening;
                            }

                    } while (evening < 0.00 || evening > 5.0);

                    printf("\n");

            } 

                    printf("Summary\n");

                    printf("=======\n");

                    printf("Morning total rating: %.3lf\n", morningTotal);
                    printf("Evening total rating:  %.3lf\n", eveningTotal);

                    printf("----------------------------\n");

                    printf("Overall total rating: %.3lf\n\n", morningTotal + eveningTotal);

                    printf("Average morning rating:  %.1lf\n", morningTotal = (morningTotal /LOG_DAYS));

                    printf("Average evening rating:  %.1lf\n", eveningTotal = (eveningTotal /LOG_DAYS));

                    printf("----------------------------\n");

                    // AVERAGE CALCULATIONS
                    avgTotal = (morningTotal + eveningTotal) /2;
                    avgTotal = (avgTotal * 100 + 0.5 + 0.5);
                    avgTotal = (avgTotal /100);

                    printf("Average overall rating:  %.1lf\n", avgTotal);
                    

        } while ((morning < 0.00 || morning > 5.0) || (evening < 0.00 || evening > 5.0));

} while (((year < MIN_YEAR || year > MAX_YEAR) || (month < JAN || month > DEC)) && ((morning < 0.00 || morning > 5.0) || (evening < 0.00 || evening > 5.0)));

    

    return 0;
}