#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double GRAMS_IN_LBS = 453.5924;

    char coffeeType1;
    char grindSize1;
    int grams1;
    char cream1;
    double temp1;

    char coffeeType2;
    char grindSize2;
    int grams2;
    char cream2;
    double temp2;

    char coffeeType3;
    char grindSize3;
    int grams3;
    char cream3;
    double temp3;

    char coffeeStrength;
    char cream4;
    int servings;
    char coffeeMaker;

    
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    
    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindSize1);
    printf("Bag weight (g): ");
    scanf(" %d", &grams1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &temp1);
    
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindSize2);
    printf("Bag weight (g): ");
    scanf(" %d", &grams2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &temp2);

    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindSize3);
    printf("Bag weight (g): ");
    scanf(" %d", &grams3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &temp3);

    printf("\n");

    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", 
    (coffeeType1 == 'L' || coffeeType1 == 'l'), (coffeeType1 == 'B' || coffeeType1 == 'b'), (grindSize1 == 'C' || grindSize1 == 'c'), (grindSize1 == 'F' || grindSize1 == 'f'), grams1, (grams1 / GRAMS_IN_LBS), (cream1 == 'Y' || cream1 == 'y'), temp1, (temp1 * 1.8) + 32.0);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", 
    (coffeeType2 == 'L' || coffeeType2 == 'l'), (coffeeType2 == 'B' || coffeeType2 == 'b'), (grindSize2 == 'C' || grindSize2 == 'c'), (grindSize2 == 'F' || grindSize2 == 'f'), grams2, (grams2 / GRAMS_IN_LBS), (cream2 == 'Y' || cream2 == 'y'), temp2, (temp2 * 1.8) + 32.0);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", 
    (coffeeType3 == 'L' || coffeeType3 == 'l'), (coffeeType3 == 'B' || coffeeType3 == 'b'), (grindSize3 == 'C' || grindSize3 == 'c'), (grindSize3 == 'F' || grindSize3 == 'f'), grams3, (grams3 / GRAMS_IN_LBS), (cream3 == 'Y' || cream3 == 'y'), temp3, (temp3 * 1.8) + 32.0); 

    printf("\n");

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream4);
    printf("Typical number of daily servings: ");
    scanf(" %d", &servings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &coffeeMaker);

    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", (coffeeStrength == 'M' || coffeeStrength == 'm'), (grindSize1 == 'F' || grindSize1 == 'f'), (grams1 == 500), (cream4 == 'Y' || cream4 == 'y'), (temp1 >= 70.0));    
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", (coffeeStrength == 'R' || coffeeStrength == 'r'), (grindSize2 == 'F' || grindSize1 == 'f'), (grams2 == 500), (cream4 == 'N' || cream4 == 'n'), (temp2 >= 70.0));    
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", (coffeeStrength == 'M' || coffeeStrength == 'm'), (grindSize3 == 'F' || grindSize3 == 'f'), (grams3 == 500), (cream4 == 'N' || cream4 == 'n'), (temp3 >= 70.0));    

    printf("\n");

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream4);
    printf("Typical number of daily servings: ");
    scanf(" %d", &servings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &coffeeMaker);

    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", (coffeeStrength == 'M' || coffeeStrength == 'm'), (grindSize1 != 'C' || grindSize1 != 'c') , (grams1 == 1000), (cream4 == cream1), (temp1 <= 69.9)); 
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", (coffeeStrength == 'R' || coffeeStrength == 'r'), (grindSize2 == 'C' || grindSize2 == 'c'), (grams2 == 1000), (cream4 == 'N' || cream4 == 'n'), (temp2 <= 69.9));     
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", (coffeeStrength == 'M' || coffeeStrength == 'm'), (grindSize3 == 'C' || grindSize3 == 'c'), (grams3 == 1000), (cream4 == 'N' || cream4 == 'n'), (temp3 <= 69.9));     

    printf("\n");

    printf("Hope you found a product that suits your likes!\n");

    return 0;
}
