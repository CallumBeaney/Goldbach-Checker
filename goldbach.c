#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULL;

ULL getInput(void);
int isPrime(ULL);
void initiateChecker(ULL);

// REF for debug:  https://www.mathematical.com/primelist1to100kk.html
// REF for primes: https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170

int main(void)
{
    ULL userInput = getInput();
    
    initiateChecker(userInput);
}


void initiateChecker(ULL userInput)
{
    ULL countUp = 4; //Countup begins at 4 because Goldbach speaks of (positive numbers >2). 
    ULL goldbachIsRight = 0;
    ULL a, b, tempCounter, halfCountup;

    while(countUp <= userInput)
    {
        a = 0;
        b = countUp;
        halfCountup = (countUp / 2);
        tempCounter = 0;

        /*  Variables (a) and (b) work in locked pairs.
            (a) increments; (b) decrements. 
            When a & b are primes, countup increments by 2  */

        while( (a++ <= halfCountup) && (b-- >= halfCountup) ) 
        {   
            if (isPrime(a) == 1 && isPrime(b) == 1)
            {
                goldbachIsRight++;
                tempCounter = 1;

                // Hereon all primes are odd numbers.
                if (a > 3)
                {
                    a++;
                    b--;
                }
                break;
            }
        }
        
        // By now, if Goldbach's conjecture is WRONG for a given even number, (tempCounter == 0)
        if ( tempCounter != 1 ) 
        {
                printf("Conjecture failed: %llu is even and cannot be formed by primes.\n", countUp);
                exit(1);
        }

        if (a > 3)
        {
            a++;
            b--;
        }

        countUp += 2;
    }
    printf("\nThere are \t[%llu] even numbers in the range (4 - %llu).\n\t\t[%llu] fulfilled Goldbach's Conjecture in this check.\n\n", (userInput / 2) - 1, userInput, goldbachIsRight);

}


int isPrime(ULL n)
{
    if (n == 2 || n == 3)
        return 1;

    if (n <= 1 || n % 3 == 0 || n % 2 == 0)
        return 0;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

ULL getInput(void)
{
    ULL a;
    char buf[1024];
    char *ptr;

    do 
    {
        printf("\nGoldbach's Conjecture asserts that every even integer greater than 2 is equal to the sum of two primes.\n"
                "Input threshold integer to check for an exception: ");
        
        if (!fgets(buf, 1024, stdin))
        {
            printf("\nInvalid input. Must input a number.\n");
            exit(1);
        }

        //  strtoull(converted buffer, string to catch non-numbers, base 10)
        a = strtoull(buf, &ptr, 10);
        
        if (a < 4)
        {
            printf("\nInvalid input. Must input a number over 3.\n");
            exit(1);
        }
       
        if ( !(a % 2 == 0) )
        {
            a = a - 1;
            printf("Checking up to %llu...\n", a);
            return a;    
        }

        printf("Checking...\n");
        return a;

    } while (a == 0);
}
