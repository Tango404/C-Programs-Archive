#define MAX_PRODUCTS 3
#define GRAMS 64
#define POUNDS_CONVERSION 2.20462
struct CatFoodInfo
{
    int skuNumber;
    double productPrice;
    int calories;
    double productWeight;
};

struct ReportData
{
    int skuNumber;
    double productPrice;
    int caloriesServing;
    double weightLBS;
    double weightKGS;
    int weightG;
    double totalServing;
    double costServing;
    double costCalorieServing;


};

// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive (int *wholeNumber);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive (double *doubleNumber);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber);

// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNumber, const double *productPrice, const double *productWeight, const int calories);


// 7. Logic entry point (MOVED TO BOTTOM)



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg (const double *poundsToBeConverted, double *conversionResultKG);


// 9. convert lbs: g
int convertLbsG(const double *poundsToBeConverted, int *conversionResultG);


// 10. convert lbs: kg / g
void convertLbs(const double *poundsToBeConverted, double *conversionResultKG, int *conversionResultG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *calculatedResult);


// 12. calculate: cost per serving
double calculateCostPerServing(const double *productPrice, const double *totalServings, double *calculatedResult);


// 13. calculate: cost per calorie
double calculateCostPerCal(const double *productPrice, const double *totalCalories, double *calculatedResult);


// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo productData);


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData dataDisplayed, const int cheapestProductOption);


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct);


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);
