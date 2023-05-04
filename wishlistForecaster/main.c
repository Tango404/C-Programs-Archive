#define _CRT_SECURE_NO_WARNINGS
#define WISHLIST_ITEMS 10 // Macro to help with validation

#include <stdio.h>

int main(void)
{

    // Unmodifiable Values
    const float minValue = 500.00;
    const float maxValue = 400000.00;
    const float minCost = 100.00;

    float netIncome;  // Net Income Variable
    double totalCost; // Total Cost Variable (Selection 1)

    // Wishlist Related Variables
    int wishlistItem;
    double wCost[10];
    int wPriority[10];
    char wFinance[10];
    int wSelect;

    // Selection 2 Variables
    int prioritySelected;
    double priorityTotal = 0.00;

    // Loop Variables
    int i; // For Loop (Item Details)
    int j; // For Loop (Finance Note)
    int k; // For Loop (Selection 2)
    int counter;
    int flag = 1;

    // Misc Variables
    int months;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    // Net Monthly Income Start
    do
    {
        printf("Enter your monthly NET income: $");
        scanf(" %f", &netIncome);

        if (netIncome < minValue)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (netIncome > maxValue)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }

    } while (netIncome > maxValue || netIncome < minValue);
    // Net Monthly Income End

    printf("\n");

    // Wishlist Items Prompt Start
    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf(" %d", &wishlistItem);

        if (wishlistItem < 1 || wishlistItem > WISHLIST_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }

    } while (wishlistItem < 1 || wishlistItem > WISHLIST_ITEMS);
    // Wishlist Items Prompt End

    // Item Details Loop Start
    for (i = 0; i < wishlistItem; i++)
    {
        printf("\n");
        printf("Item-%d Details:", i + 1);
        printf("\n");

        do // Cost Start
        {
            printf("   Item cost: $");
            scanf(" %lf", &wCost[i]);

            if (wCost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (wCost[i] < minCost); // Cost End

        do // Priority Start
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf(" %d", &wPriority[i]);

            if (wPriority[i] < 1 || wPriority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }

        } while (wPriority[i] < 1 || wPriority[i] > 3); // Priority End

        do // Finance Start
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &wFinance[i]);

            if (wFinance[i] != 'y' && wFinance[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }

        } while (wFinance[i] != 'y' && wFinance[i] != 'n'); // Finance End
    }
    // Item Details Loop End

    printf("\n");

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    // Wishlist Forcasting Start
    for (i = 0; i < wishlistItem; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, wPriority[i], wFinance[i], wCost[i]);
        totalCost += wCost[i]; // This adds up the sum of cost of the items
    }
    // Wishlist Forcasting End

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf(" %d", &wSelect);

        printf("\n");

        if (wSelect < 0 || wSelect > 2)
        {
            printf("ERROR: Invalid menu selection.\n\n");
            flag = 1;
        }

        if (wSelect == 0)
        {
            flag = 0;
            printf("Best of luck in all your future endeavours!\n\n");
        }
        else if (wSelect == 1)
        {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalCost);
            months = totalCost / netIncome;
            printf("Forecast: %d years, %d months\n", (int)months / 12, months % 12 + 1);

            for (j = 0; j < 10; j++)
            {
                if (wFinance[j] == 'y')
                {
                    counter = counter + 1;
                }
            }
            if (counter >= 1)
            {
                printf("NOTE: Financing options are available on some items.\n"
                       "      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n\n");

            flag = 1;
        }

        else if (wSelect == 2)
        {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf(" %d", &prioritySelected);
            printf("\n");
            priorityTotal = 0;
            counter = 0;

            for (k = 0; k < 10; k++)
            {
                if (wPriority[k] == prioritySelected)
                {
                    priorityTotal = priorityTotal + wCost[k];
                }
                if (wPriority[k] == prioritySelected)
                {
                    if (wFinance[k] == 'y')
                    {
                        counter = counter + 1;
                    }
                }
            }
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", prioritySelected);
            printf("Amount:   $%1.2lf\n", priorityTotal);
            months = priorityTotal / netIncome;
            printf("Forecast: %d years, %d months\n", (int)months / 12, months % 12 + 1);

            if (counter >= 1)
            {
                printf("NOTE: Financing options are available on some items.\n"
                       "      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n\n");
        }

    } while (flag == 1);

    return 0;
}