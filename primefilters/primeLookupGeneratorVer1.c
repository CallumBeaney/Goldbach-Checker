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
        printf("\nInput integer threshold to load into prime bool table: ");
        
        if (!fgets(buf, 1024, stdin))
        {
            printf("\nInvalid input. Must input a number.\n");
            exit(1);
        }

        //  strtoull(converted buffer, string to catch non-numbers if needed, base 10)
        a = (uint32_t)strtoul(buf, &ptr, 10);
    
        printf("Running...\n");
        return a;

    } while (a == 0);
}

    //     //DEBUG:
    //     printf("\n\n\n0 is %i  and should be 0\n",  primeLookup[0]);
    //     printf("1 is %i  and should be 0\n",  primeLookup[1]);
    //     printf("2 is %i  and should be 1\n",  primeLookup[2]);
    //     printf("3 is %i  and should be 1\n",  primeLookup[3]);
    //     printf("4 is %i  and should be 0\n\n",  primeLookup[4]);
    //     printf("29 is %i and should be 1\n\n", primeLookup[29]);
    //     printf("96 is %i and should be 0\n", primeLookup[96]);
    //     printf("97 is %i and should be 1\n", primeLookup[97]);
    //     printf("98 is %i and should be 0\n", primeLookup[98]);
    //     // printf("7919 is %i and should be 1 \n", primeLookup[7919]);
    //     // printf("7920 is %i and should be 0\n", primeLookup[7920]);
    //     // printf("999983 is %i and should be 1\n", primeLookup[999983]);
    //     // printf("999985 is %i and should be 0\n", primeLookup[999985]);
    //     // printf("111111100 is %i and should be 0\n\n", primeLookup[111111100]);
    //     // printf("15485863 is %i and should be 1\n", primeLookup[15485863]);