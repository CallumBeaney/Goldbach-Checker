#include <stdio.h>
#include <stdlib.h>

int isPrime(long);
long long getInput(void);

int main(void)
{
    long long input = getInput();
    long long countup = 4; //Countup begins at 4 because Goldbach speaks of ℕ⁺>2. 

    long long truecounter = 0;
    long long a, b, tempcounter;

    /* EXAMPLE:

        __13th ITERATION_   OUTER WHILE LOOP    INNER WHILE LOOP
                            input   =     32            
                            countup =     28
                            a       =      0    
                            b       =     28    
                                                a++    |      b--
                                                1 (NP) |      27 (NP)
                                                2 (P)  |      26 (NP)
                                                3 (P)  |      25 (NP)
                                                5 (P)  |      23 (P) 
                                                -- BREAK; 
                            -- countup += 2;

        __14th ITERATION_   input   =     32            
                            countup =     30
                            ...
    */

    while(countup <= input)
    {
        a = 0;
        b = countup;
        tempcounter = 0;

        /*  Variables (a) and (b) work in locked pairs.
            (a) increments; (b) decrements. 
            When a & b are primes, countup increments by 2  */

        while(a++ <= (countup / 2) && b-- >= (countup / 2)) 
        {   
            if (isPrime(a) == 1 && isPrime(b) == 1)
            {
                truecounter++;
                tempcounter = 1;

                // Hereon all primes are odd numbers.
                if (a > 3)
                {
                    a++;
                    b--;
                }
                break;
            }
        }
        
        if ( tempcounter != 1 )
        {
                printf("Conjecture failed: %lld is even and cannot be formed by primes.\n", countup);
                return 1;
        }

        if (a > 3)
        {
            a++;
            b--;
        }

        countup += 2;
    }
    printf("\nThere are \t[%lld] even numbers in the range (4 - %lld).\n\t\t[%lld] fulfilled Goldbach's Conjecture in this check.\n\n", (input / 2) - 1, input, truecounter);
}


int isPrime(long n)
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

long long getInput(void)
{
    long long a;
    char buf[1024];

    do 
    {
        printf("\nGoldbach's Conjecture asserts that every even integer greater than 2 is equal to the sum of two primes.\n"
                "Input threshold integer to check for an exception: ");
        
        if (!fgets(buf, 1024, stdin))
        {
            printf("\nInvalid input. Must input a number.\n");
            exit(1);
        }
        a = atoi(buf);
        
        if (a < 4)
        {
            printf("\nInvalid input. Must input a number over 3.\n");
            exit(1);
        }
       
        if ( !(a % 2 == 0) )
        {
            a = a - 1;
            printf("Checking up to %lld...\n", a);
            return a;    
        }

        printf("Checking...\n");
        return a;

    } while (a == 0);
}
