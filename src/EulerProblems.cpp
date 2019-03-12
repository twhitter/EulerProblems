//============================================================================
// Name        : EulerProblems.cpp
// Author      : Tyler Whitson
// Version     : v0.3
// Copyright   : No Copyright, do what you want
// Description : Euler Problems in C++
//============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <string>

void printSumOfMultiples3and5to1000()
{
	uint32_t sum = 0;	// this sum is big!

	for(uint16_t i = 999; i > 0; --i) // start from 100 and work our way down
	{
		if(!(i % 3) | !(i % 5))
		{
			sum += i;
		}
	}

	std::cout << sum << std::endl;
}

void evenSumsFibo()
{
	std::vector<int> fib_vector;

	fib_vector.push_back(1);	// Initialize first two terms of Fibonacci sequence in array
	fib_vector.push_back(2);

	uint32_t even_fib_sums = fib_vector[1];	// variable to hold the sums of
											// even integers of array
	uint32_t i = 2;		// Start at at 3rd term of Fibo sequence

	while(fib_vector.back() < 4e6)
	{
		fib_vector.push_back( (fib_vector[i-1] + fib_vector[i-2]) ); // Calculate nth term of fibo sequence

		if( !(fib_vector[i] % 2) )	// Brute force test for even-ness (can be optimized, every 3rd term is even)
		{
			even_fib_sums += fib_vector[i];
		}

		i++; // increment to calculate next term of fibo sequence
	}
	std::cout << even_fib_sums << std::endl;
}

void largestPrime()
{
	// Implementation of Trial Division to find largest prime in a given number
	// this is the slowest one, but it's easy for me to grasp, so here we are

	uint64_t big_number = 600851475143;
	uint64_t candidate = 2;
	std::vector<int> primes;

	while( big_number > 1 ) // keep dividing down until we hit the last possible prime number
	{
		if( big_number % candidate == 0)
		{
			primes.push_back( candidate );	// add our prime to the list
			big_number /= candidate;		// factor out found prime
		}
		else { candidate += 1; } // No prime numbers here, keep looking
	}

	std::cout << primes.back() << std::endl;
}

void largestPalindrome()
{
	// Largest possible product of 2 three digit numbers: 999^2 = 998001
	// So only six digit number needed to parse

	uint16_t num1 = 999;	// initialize variables for numbers to be multiplied
	uint16_t num2 = 999;
	uint32_t product;
	uint8_t finished = 0;

	std::string product_string;
	std::string fst_half;
	std::string sec_half;
	uint8_t len;

	while( finished == 0 )
	{
		product = num1*num2;
		product_string = std::to_string(product);

		len = product_string.length();

		for( int i = 0; i < (len/2); ++i)
		{
			fst_half[i] = product_string[i];
		}

		for( int i = len; i > (len/2); --i)
		{
			sec_half[i] = product_string[i];
		}

		if( fst_half.compare(sec_half) == 0 )
		{
			finished = 1;
		}
	}

	std::cout << product << std::endl;
	std::cout << num1 << std::endl;
	std::cout << num2 << std::endl;

}

int main()
{
	largestPalindrome();
	return 0;
}
