#include "pch.h"
#include "EratosthenesSieve.h"

#include <list>

using namespace std;

int * EratosthenesSieve::FindPrimesUpTo(int n)
{
	auto listOfPrimes(new list<int>());

	// TODO: actually populate list using algorithm

	auto numPrimes = listOfPrimes->size();
	auto currInd(0);
	int * results = new int[numPrimes];

	for (list<int>::iterator it = listOfPrimes->begin(); it != listOfPrimes->end(); it++)
	{
		results[currInd] = 0;
		currInd++;
	}

	return results;
}
