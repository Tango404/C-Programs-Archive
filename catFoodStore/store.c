#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "store.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive (int *wholeNumber)
{
    int value = 0;
    do
    {
        scanf(" %d", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);

    if (wholeNumber != NULL)
    {
        *wholeNumber = value;
        return *wholeNumber;
    }
    else
    {
        return value;
    }

}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive (double *doubleNumber)
{
    double value;

    do
    {
        scanf(" %lf", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (value <= 0);

    if (doubleNumber != NULL)
    {
        *doubleNumber = value;
        return *doubleNumber;
    }
    else
    {
        return value;
    }
};


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");

    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
    printf("NOTE: A 'serving' is %dg\n\n", GRAMS);

};

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber)
{

    struct CatFoodInfo getInfoSafeState = {0, 0.00, 0, 0.00};

        
        printf("Cat Food Product #%d\n", sequenceNumber+1); // PLUS 1 because of formatting
        printf("--------------------\n");
        
        printf("SKU           : ");
        getIntPositive(&getInfoSafeState.skuNumber);

        printf("PRICE         : $");
        getDoublePositive(&getInfoSafeState.productPrice);

        printf("WEIGHT (LBS)  : ");
        getDoublePositive(&getInfoSafeState.productWeight);

        printf("CALORIES/SERV.: ");
        getIntPositive(&getInfoSafeState.calories);

        printf("\n");

        return getInfoSafeState;
};


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNumber, const double *productPrice, const double *productWeight, const int calories)
{

    printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *productPrice, *productWeight, calories);
    
};


// 7. Logic entry point



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg (const double *poundsToBeConverted, double *conversionResultKG)
{
    double result;

    result = *poundsToBeConverted /POUNDS_CONVERSION;
    
    if (conversionResultKG != NULL)
    {
        *conversionResultKG = result;
        return *conversionResultKG;
    }
    else
    {
        return result;
    }
};

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *poundsToBeConverted, int *conversionResultG)
{
    int result;
    double conversionResult;

    result = (int)(convertLbsKg(poundsToBeConverted, &conversionResult) * 1000); // Type casting

    if (conversionResultG != NULL)
    {
        *conversionResultG = result;
        return *conversionResultG;
    }
    else
    {
        return result;
    }
};


// 10. convert lbs: kg and g
void convertLbs(const double *poundsToBeConverted, double *conversionResultKG, int *conversionResultG)
{
    *conversionResultKG = convertLbsKg(poundsToBeConverted, conversionResultKG);
    *conversionResultG = convertLbsG(poundsToBeConverted, conversionResultG);
};



// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *calculatedResult)
{
    double result;
    
    result = (double)servingSizeGrams /(double)totalGrams; // Type casting
    
    if(calculatedResult != NULL)
    {
        *calculatedResult = result;
        return *calculatedResult;
    }
    else
    {
        return result;
    }
};


// 12. calculate: cost per serving
double calculateCostPerServing(const double *productPrice, const double *totalServings, double *calculatedResult)
{
    double result;
    
    result = (double)*productPrice / (double)*totalServings; // Type casting
    
    if(calculatedResult != NULL)
    {
        *calculatedResult = result;
        return *calculatedResult;
    }
    else
    {
        return result;
    }
    
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double *productPrice, const double *totalCalories, double *calculatedResult)
{
    double result;
    
    result = *productPrice / *totalCalories;
    
    
    if(calculatedResult != NULL)
    {
        *calculatedResult = result;
        return *calculatedResult;
    }
    else
    {
        return result;
    }
}


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo productData)
{
    struct ReportData dataReport = {0};
    double totalCalories;
        
    dataReport.skuNumber = productData.skuNumber;
    dataReport.productPrice = productData.productPrice;
    dataReport.caloriesServing = productData.calories;
    dataReport.weightLBS = productData.productWeight;
    
    // Weight Conversion
    convertLbs(&productData.productWeight, &dataReport.weightKGS, &dataReport.weightG);
    
    // Total Serving
    calculateServings(dataReport.weightG, GRAMS, &dataReport.totalServing);
        
    // Cost Per Serving
    calculateCostPerServing(&dataReport.productPrice, &dataReport.totalServing, &dataReport.costServing);
    
    // Total Calories Calculation
    totalCalories = dataReport.caloriesServing * dataReport.totalServing;
    
    // Cost Calorie Serving
    calculateCostPerCal(&dataReport.productPrice, &totalCalories, &dataReport.costCalorieServing);
    
    return dataReport;
    
};


// 15. Display the formatted table header for the analysis results

void displayReportHeader(void)
{
    printf("Analysis Report (Note: Serving = %dg)\n", GRAMS);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData dataDisplayed, const int cheapestProductOption)
{
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", dataDisplayed.skuNumber, dataDisplayed.productPrice, dataDisplayed.weightLBS, dataDisplayed.weightKGS, dataDisplayed.weightG, dataDisplayed.caloriesServing, dataDisplayed.totalServing, dataDisplayed.costServing, dataDisplayed.costCalorieServing);
};


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct)
{
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n", cheapestProduct.skuNumber, cheapestProduct.productPrice);
    printf("Happy shopping!\n");
    
};


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    int i;
    int cheapestProduct = 0;

    struct CatFoodInfo catFoodProducts[MAX_PRODUCTS] = {{0}}; // Create an array with size MAX_PRODUCTS (Set in safe zero state)
    struct ReportData reportData[MAX_PRODUCTS] = {{0}}; // Array for ReportData size is MAX_PRODUCTS (Set in safe zero state)
    
    
    openingMessage(MAX_PRODUCTS);


    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        catFoodProducts[i] = getCatFoodInfo(i); // getCatFoodInfo products are being stored in each index of catFoodProducts
    };

    displayCatFoodHeader();

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        displayCatFoodData(catFoodProducts[i].skuNumber, &catFoodProducts[i].productPrice, &catFoodProducts[i].productWeight, catFoodProducts[i].calories);
    };
    
    printf("\n");
    
    displayReportHeader();
    
    // For loop to calclulate the reported data, iterates through the array's serving cost and finds he cheapest one, and assigns the index of i to a variable cheapestProduct which is used later on.
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        reportData[i] = calculateReportData(catFoodProducts[i]);
        if(reportData[i].costServing < reportData[i - 1].costServing)
        {
            cheapestProduct = i;
        }
    }
    
    // For loop to display and iterate through reportData array, when cheapestProduct = i, it will print a *** at the end of the line.
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        displayReportData(reportData[i], cheapestProduct);
        if(cheapestProduct == i)
        {
            printf(" ***");
        }
    printf("\n");
    }
    
    printf("\n");
    
    // Uses the index of cheapestProduct to display the price and sku number
    displayFinalAnalysis(catFoodProducts[cheapestProduct]);

};
