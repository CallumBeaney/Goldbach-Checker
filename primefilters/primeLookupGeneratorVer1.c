#include <stdio.h>
#include <stdlib.h>

typedef uint32_t u32;

u32 getInput(void);
int isPrime(u32 n);
char * populatePrimeLookup(u32 userInput);

// TODO: Presently runs to around Five Hundred Million 500000000 but not to One Billion 1000000000.

int main(void)
{
    u32 userInput = getInput();

    char * primeLookup;
    primeLookup = populatePrimeLookup(userInput);

}

char * populatePrimeLookup(u32 userInput)
{
    char *passArray = malloc(sizeof(userInput));  
    if(passArray == NULL)
    {
        printf("Unable to check.\n");
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
        printf("\nInput threshold integer to check for an exception: ");
        
        if (!fgets(buf, 1024, stdin))
        {
            printf("\nInvalid input. Must input a number.\n");
            exit(1);
        }

        //  strtoull(converted buffer, string to catch non-numbers if needed, base 10)
        a = strtoull(buf, &ptr, 10);
        
        if (a < 4)
        {
            printf("\nInvalid input. Must input a number over 3.\n");
            exit(1);
        }
       
        if ( !(a % 2 == 0) )
        {
            a = a - 1;
            printf("Checking up to %u...\n", a);
            return a;    
        }

        printf("Checking...\n");
        return a;

    } while (a == 0);
}

