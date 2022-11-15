## EXAMPLE OUTPUT:
~~~
./goldbach   

Goldbach's Conjecture asserts that every even integer greater than 2 is equal to the sum of two primes.
Input threshold integer to check for an exception: 100000001 
Checking up to 100000000...

There are [49999999] even numbers in the range (4 - 100000000).
          [49999999] fulfilled Goldbach's Conjecture in this check.
~~~               
## LOOP LOGIC

Let's say that the user inputs '33'. The program will check Goldbach's Conjecture up to 32, which is called userInput.  
Program increments a variable called countUp in twos (countUp begins at 4), until it equals the userInput, 32.  

| Place in file   |   What's happening |
| ----------- | ----------- |
| OUTER LOOP  | (a = 0), and (b = countUp) for a given value of countUp in OUTER LOOP. |
| INNER LOOP  | These variables change as a locked pair: (a++) and (b--). |
|             | As such, (a + b) will always be equal to the OUTER LOOP value of countUp. |  
|             | If on a given loop (both a and b are primes), program breaks to the OUTER LOOP. |                   
|             | Otherwise, it keeps going until (a == b) and then breaks. |
| OUTER LOOP  | The program checks whether the INNER LOOP found (a && b are primes). |
|             | When it does, countup increments by 2. Otherwise, the program ends.        |

### EXAMPLE
Let's say we're on the 13th loop of both INNER and OUTER loops where (userInput == 32), and (countUp == 28).  
The program proceeds as such:

~~~
__13th ITERATION_     OUTER WHILE LOOP    INNER WHILE LOOP
                      userInput =   32            
                      countUp   =   28
                      a         =    0    
                      b         =   28    
                                          a++    |    b--
                                          1 (NP) |    27 (NP)
                                          2 (P)  |    26 (NP)
                                          3 (P)  |    25 (NP)
                                          4 (NP) |    24 (NP)                                         
                                          5 (P)  |    23 (P)  <-- BOTH PRIMES
                                          -- BREAK; 
                      -- countup += 2;

__14th ITERATION_     userInput =   32            
                      countUp   =   30
                      a         =    0
                      b         =   30
                                          a++    |    b--
                                          1 (NP) |    29 (P)
                                          2 (P)  |    28 (NP)
                                          ...
                                          ... and so on
~~~ 


