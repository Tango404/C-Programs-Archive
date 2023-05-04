#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int shopping;

int apples;
int oranges;
int pears;
int tomatoes;
int cabbages;

int pickedApples;
int pickedPears;
int pickedCabbages;
int pickedOranges;
int pickedTomatoes;

int main(void)
{

do
{

    printf("Grocery Shopping\n");
    printf("================\n");

    // APPLES

    do
    {
        printf("How many APPLES do you need? : ");
        scanf(" %d", &apples);
        if (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (apples < 0);

    printf("\n");

    // ORANGES

    do
    {
        printf("How many ORANGES do you need? : ");
        scanf(" %d", &oranges);
        if (oranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (oranges < 0);

    printf("\n");

    // PEARS

    do
    {
        printf("How many PEARS do you need? : ");
        scanf(" %d", &pears);
        if (pears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (pears < 0);

    printf("\n");

    // TOMATOES

    do
    {
        printf("How many TOMATOES do you need? : ");
        scanf(" %d", &tomatoes);
        if (tomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (tomatoes < 0);

    printf("\n");

    // CABBAGES

    do
    {
        printf("How many CABBAGES do you need? : ");
        scanf(" %d", &cabbages);
        if (cabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
    } while (cabbages < 0);

    printf("\n");

    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");

    // PICKING APPLES

    if (apples >= 1)
    {
        do 
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf(" %d", &pickedApples);
            if (pickedApples > apples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
            }
            else if (pickedApples <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if(pickedApples < apples)
            {
                apples = apples - pickedApples;
                printf("Looks like we still need some APPLES...\n");
            }
            else if (pickedApples == apples)
            {
                printf("Great, that's the apples done!\n\n");
                break;
            }
        } while (apples != 0);
    }

    // PICKING ORANGES

    if(oranges >= 1)
    {
        do 
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf(" %d", &pickedOranges);
            if (pickedOranges > oranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            }
            else if (pickedOranges <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if(pickedOranges < oranges)
            {
                oranges = oranges - pickedOranges;
                printf("Looks like we still need some ORANGES...\n");
            }
            else if (pickedOranges == oranges)
            {
                printf("Great, that's the oranges done!\n\n");
                break;
            }
        } while (oranges != 0);
    }

    // PICKING PEARS

    if(pears >= 1)
    {
        do
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf(" %d", &pickedPears);
            if (pickedPears > pears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
            }
            else if (pickedPears <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if(pickedPears < pears)
            {
                pears = pears - pickedPears;
                printf("Looks like we still need some PEARS...\n");
            }
            else if (pickedPears == pears)
            {
                printf("Great, that's the pears done!\n\n");
                break;
            }
        } while (pears != 0);
    }

    // PICKING TOMATOES 

    if(tomatoes >= 1)
    {
        do 
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf(" %d", &pickedTomatoes);
            if (pickedTomatoes > tomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
            }
            else if (pickedTomatoes <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if(pickedTomatoes < tomatoes)
            {
                tomatoes = tomatoes - pickedTomatoes;
                printf("Looks like we still need some TOMATOES...\n");
            }
            else if (pickedTomatoes == tomatoes)
            {
                printf("Great, that's the tomatoes done!\n\n");
                break;
            }
        } while (tomatoes != 0);
    }

    // PICKING CABBAGES

    if(cabbages >= 1)
    {
        do
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf(" %d", &pickedCabbages);
            if (pickedCabbages > cabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
            }
            else if (pickedCabbages <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if(pickedCabbages < cabbages)
            {
                cabbages = cabbages - pickedCabbages;
                printf("Looks like we still need some CABBAGES...\n");
            }
            else if (pickedCabbages == cabbages)
            {
                printf("Great, that's the cabbages done!\n\n");
                break;
            }
        } while (cabbages != 0);
    }

    printf("All the items are picked!\n\n");

    printf("Do another shopping? (0=NO): ");
    scanf(" %d", &shopping); // 1 = RE LOOP, 0 = END LOOP
    printf("\n");

} while (shopping != 0);

printf("Your tasks are done for today - enjoy your free time!\n");
    
    return (0);
}