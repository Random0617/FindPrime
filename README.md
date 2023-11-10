# FindPrime
In int(main) function in main.cpp, you will see the following:
```
int(main) {
    ...
    single_method(generated, 1);
    //single_method(generated, 2);
    //single_method(generated, 3);
    //permanent_memory(generated, 1);
    //permanent_memory(generated, 2);
    //permanent_memory(generated, 3);
    ...
}
```
When running the code, only one of the six lines should be run at a time, because a lot of memory is used (about 4 GB) to store all numbers.
* single_method(generated, 1): Generate sieve of Eratosthenes for the first method.
* single_method(generated, 2): Generate sieve of Sundaram for the first method.
* single_method(generated, 3): Generate sieve of Atkin for the first method.
* permanent_memory(generated, 1): Generate sieve of Eratosthenes for the second method.
* permanent_memory(generated, 2): Generate sieve of Sundaram for the second method.
* permanent_memory(generated, 3): Generate sieve of Atkin for the second method.

Output:
* The first line is the number 1020, the number of integers generated, used for both methods.
* The second line is the full list of 1020 integers used in all tests.
* From the third line, each line displays the time it takes to complete one step (one group of numbers), which is one row of the table in either "Actual result, first method" or "Actual result, second method" subsections. Exact time taken may not be exactly the same on all runs, even if the same test is used.
* Prime numbers found are not actually displayed, because it would take very long to display tens of millions or hundreds of millions of them.
