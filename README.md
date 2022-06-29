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
~~~
Let's say that (the variable userInput == 33) and so we check Goldbach's Conjecture up to 32.  
Program counts up starting at 4 in twos (countUp defaults at 4), until (countUp == 32).  

In the OUTER LOOP - (a = 0), and (b == countUp) for a given value of countUp in the OUTER LOOP.  
In the INNER LOOP - Variables (a) and (b) work in locked pairs. (a) increments; (b) decrements.  
                  - As such, (a + b) will always be equal to countUp.   
                  - If on a given loop (both a and b are primes), break to the OUTER LOOP.  
Rtn to OUTER LOOP - The program checks whether the INNER LOOP found (a & b are primes).
                  - When it does, countup increments by 2. Otherwise, the program ends.

On the 13th loop of both INNER and OUTER loops where (userInput == 32), (countUp == 28).  
The program proceeds as such:
~~~
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
                                          5 (P)  |    23 (P) 
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
~~~ 
