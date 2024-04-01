#include <stdio.h>

#define NUMBER_OF_TESTCASES 6
#define ARRAY_SIZE 10

static void findSecondMax(int array[], int *secondMaxValue)
{
    int maxValue;
    int i;

    if(array[0] >= array[1])
    {
        maxValue = array[0];
        *secondMaxValue = array[1];
    }
    else
    {
        maxValue = array[1];
        *secondMaxValue  = array[0];
    }

    for(i = 2; i < ARRAY_SIZE; i++)
    {
        if(array[i] > maxValue)
        {
            *secondMaxValue = maxValue;
            maxValue = array[i];
        }
        else if (array[i] > *secondMaxValue)
        {
            *secondMaxValue = array[i];
        }
    }

    *secondMaxValue = *secondMaxValue;
    return;
}

static void runTests()
{
    int i;
    int max2;
    int result[NUMBER_OF_TESTCASES] = {99, 42, 100, 90, 105, 115};
    int testArray[NUMBER_OF_TESTCASES][ARRAY_SIZE] =
    {
        {15, 15, 8, 9, 7, 4, 99, 99, 7, 85},
        {35, 13, 28, 2, 12, 42, 87, 42, 21, 23},
        {12, 13, 100, 100, 100, 80, 80, 3, 54, 42},
        {22, 33, 90, 98, 70, 80, 80, 3, 54, 42},
        {115, 105, 8, 9, 7, 4, 99, 99, 7, 85},
        {115, 115, 115, 115, 115, 115, 115, 115, 115, 115},
    };

    for (i = 0; i < NUMBER_OF_TESTCASES; i++)
    { 
        findSecondMax(testArray[i], &max2);

        if (max2 == result[i])
        {
            printf("Test %d PASSED\n", i + 1);
        }
        else
        {
            printf("Test %d FAILED\n", i + 1);
        }
    }
    
    return;
}

int main()
{
    runTests();
    return 0;
}
