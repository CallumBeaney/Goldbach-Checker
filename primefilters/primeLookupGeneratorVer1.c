/* This program loads the result of a prime checking function as (1 = is prime | 0 = isn't prime) into a lookup table based on user input.
Presently runs to around Five Hundred Million 500000000 but not to One Billion 1000000000.
This model is not the most efficient; alternative sieves/wheel factorisation etc will be employed in future versions. */

#include <stdio.h>
#include <stdlib.h>

typedef uint32_t u32;

u32 getInput(void);
int isPrime(u32 n);
char * populatePrimeLookup(u32 userInput);
// void debugger(char *primeLookup);

int main(void)
{
    u32 userInput = getInput();

    char * primeLookup = populatePrimeLookup(userInput);

    // debugger(primeLookup);

    /* primeLookup now points to space in memory malloc'd for passArray in below Fn */
    free(primeLookup); 
    
    printf("Done.\n");
}

char * populatePrimeLookup(u32 userInput)
{
    char *passArray = malloc(sizeof(userInput));  

    if(passArray == NULL)
    {
        printf("Unable to allocate memory.\n");
        exit(1);
    }

    for (u32 i = 0; i < userInput; i++)
    {
        char primeStatus = isPrime(i);
        passArray[i] = primeStatus;
    }

    return passArray;
}

int isPrime(u32 n)
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

u32 getInput(void)
{
    u32 a;
    char buf[1024];
    char *ptr;

    do 
    {
        printf("\nInput integer threshold to load into prime bool table: ");
        
        if (!fgets(buf, 1024, stdin))
        {
            printf("\nInvalid input. Must input a number.\n");
            exit(1);
        }

        /* strtoull(converted buffer, string to catch non-numbers if needed, base 10) */
        a = (uint32_t)strtoul(buf, &ptr, 10);
    
        return a;

    } while (a == 0);
}

// void debugger(char* primeLookup)
// {
//         printf("1 = is prime; 0 = is not prime\n");
//         printf("\n0 \tis %i and should be 0\n", primeLookup[0]);
//         printf("1 \tis %i and should be 0\n",   primeLookup[1]);
//         printf("2 \tis %i and should be 1\n",   primeLookup[2]);
//         printf("3 \tis %i and should be 1\n",   primeLookup[3]);
//         printf("4 \tis %i and should be 0\n\n", primeLookup[4]);
//         printf("5 \tis %i and should be 1\n\n", primeLookup[5]);
// }