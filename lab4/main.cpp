// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3080-001
// Assignment: lab4: 2-3-4 Tree
// Due:        23:59:59, December 9, 2013
// Purpose:    Three different ways to calculate the nth term of a sequence.
// Input:      From standard input.
// Output:     To terminal.
//
// File:       TwoThreeFourTree.cpp

#include <iostream>         // for cout
#include <iomanip>          // for fixed, setprecision()

long int recursiveFunctionS(long int n);

int main(int argc, const char * argv[])
{
    clock_t begin=0, end=0;
    long int n=0;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "S(1) = 1; S(n) = S(n-1) + n\n";
    std::cout << "Enter a value for n: \n";
    std::cin >> n;
    
    std::cout << "\nRecursive: S(n) = ";
    begin = clock();
    std:: cout << recursiveFunctionS(n);
    end = clock();
    std::cout << std::endl << (end - begin) / double (CLOCKS_PER_SEC) << " seconds\n\n";
    
    std::cout << "For-loop: S(n) = ";
    begin = end = 0;
    long int sum = 0;
    begin = clock();
    for (int i = 1; i <= n; i++)
        sum += i;
    end = clock();
    std::cout << sum << std::endl;
    std::cout << (end - begin) / double (CLOCKS_PER_SEC) << " seconds\n\n";

    std::cout << "Arithmetic: S(n) = ";
    long int answer = 0;
    begin = end = 0;
    begin = clock();
    answer = ((n*(n+1))/2);
    end = clock();
    std::cout << n * (n+1) / 2 << std::endl;
    std::cout << (end - begin) / double (CLOCKS_PER_SEC) << " seconds\n\n";
    
    return 0;
}


long int recursiveFunctionS(long int n)
{
    if (n == 1)
        return n;
    else
        return recursiveFunctionS(n - 1) + n;
}


/*

 Question:
 With regards to timing, how could you determine which program was faster?
 
 Answer:
 Time them as is shown in the code above.

*/