/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Write a function that takes a natural number as input and returns the number of digits the input has.

Constraint: don't use any loops.
*/

#include <iostream>
#include <cmath>


//loop based approach is simplest, but fails to meet the constraint.
int loop_count_digits(int n){
    int count = 0;
    while(n){
        //use integer divison by 10 to remove one digit at a time
        n = n/10;
        count++;
    }
    return count;
}

//using logarithm we can determine the number of digits in a number
int count_digits(int n){
    //log10(n) gives the number of digits in n
    return floor(log10(n)+1);
}


int main(){
    int n = 999;
    std::cout << "Number of digits using loops in " << n << " is " << loop_count_digits(n) << std::endl;
    std::cout << "Number of digits using log(n+1) in " << n << " is " << count_digits(n) << std::endl;
    return 0;
}