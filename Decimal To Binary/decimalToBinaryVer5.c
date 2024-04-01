#include <stdio.h>
#define NUMBER_OF_BITS 32

typedef struct
{
    int num;
    int bit1;
    int bit2;
    int expectedResults;
} TestCase;

static void swapBits(int *num, int bit1, int bit2)
{

    /*
        This block of code below retrieves the values of certain bits in the given number.
        Shifts num to the right by bit1 and bit2
        and then we get the bits in this position by masking them with the &1 operation.,
        This operation assigns the value of a particular bit to the variables bit1Val and bit2Val.
    */

    int bit1Val;
    int bit2Val;

    if(bit1 >= 0 && bit1 < NUMBER_OF_BITS && bit2 >= 0 && bit2 < NUMBER_OF_BITS)
    {
        bit1Val = (*num >> bit1) & 1;
        bit2Val = (*num >> bit2) & 1;

        if(bit1Val != bit2Val)
        {
            *num ^= (1 << bit1);
            *num ^= (1 << bit2);
        }
    }

    /*
        This block of code below to change the value of two specific bits
        It uses XOR operation. First, by shifting the number 1 to the left by bit1 and bit2,
        That is, we move it to the position where the relevant bits are.
        Then, by XORing this value with num
        we change the specified bits.
        This operation is performed if the value of two bits are not equal.
        (i.e. if different) allows us to change the relevant bits.
    */

    return;
}

static void runTests()
{

    TestCase tests[] = 
    {
        {131, 0, 4, 146},
        {256, 3, 8, 8},
        {131, 39, 3, 131},
        {1, -31, 0, 1}
    };

    int numTests = sizeof(tests) / sizeof(TestCase);
    int i;

    for(i = 0; i < numTests; i++)
    {

        swapBits(&tests[i].num, tests[i].bit1, tests[i].bit2);

        if(tests[i].num != tests[i].expectedResults)
        {
            printf("Test %d FAILED - Expected %d, Got: %d\n", i+1, tests[i].expectedResults, tests[i].num);
        }
        else
        {
            printf("Test %d PASSED\n", i+1);
        }
    }

    return;
}

int main()
{
    runTests();
    return 0;
}