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
~~~ 
