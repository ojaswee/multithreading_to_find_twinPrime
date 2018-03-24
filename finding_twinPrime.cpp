/* 
A prime pair or twin prime is a prime number that has a prime gap of two, in other words,
differs from another prime number by two, for example the twin prime pair (41, 43).
We are tring to find all twin prime numbers between 1 to 50.
This is a sequental code
*/

#include <iostream>
#include <ctime>
#include <deque>

using namespace std;

void printDeque(deque<int>primeNumbers) {
	for (int i = 0; i < primeNumbers.size() -1 ; i++) {
		if (primeNumbers.at(i+1)- primeNumbers.at(i) == 2)
			cout << primeNumbers.at(i) << ","
				<< primeNumbers.at(i+1) << endl;
	}
	cout<< "Pairs of Twin Primes: " << primeNumbers.size() / 2 << endl;
}

void twinPrime(deque<int>primeNumbers) {
	deque<int>twinPrime; 
	while(primeNumbers.size()-1) {
		if ((primeNumbers[1] - primeNumbers.front()) ==2) {
			twinPrime.push_back(primeNumbers.front());
			twinPrime.push_back(primeNumbers[1]);
		}
		primeNumbers.pop_front();
	}
	cout << "Twin Prime (s): \n"; printDeque(twinPrime);
}

void prime(deque<int>primeNumbers, int maxNum) {
	for (int num = 3; num < maxNum; num++) { //max integer we want to check 
		bool isPrime = false;
		for (int j = 0; j <primeNumbers.size() && (primeNumbers[j] < maxNum / 2) + 1; j++) {
			if (num % primeNumbers[j] == 0) { //for composite numbers break the loop
				isPrime = false;
				break;
			}
			else
				isPrime = true;
		}

		if (isPrime) {
			primeNumbers.push_back(num);
		}
	}
	//printDeque(primeNumbers);
	twinPrime(primeNumbers);
}

void main() {
	double duration = 0.00;
	clock_t start;
	deque<int> primeNumbers; //store all the found prime numbers here
	primeNumbers.push_back(2);
	int maxNum = 50;//000000;
	start = clock();
	prime(primeNumbers, maxNum);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;

	cout << "\nTime to compute: " << duration << " seconds" << endl; //total seconds passed
	cout << endl;
	system("pause");
}