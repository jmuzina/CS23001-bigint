/**
* Joseph Muzina
* Project 1 - bigint
* CS 23001
*/

#include "bigint.hpp"

int main() {
	int x = 100;

	bigint bi(x);
	std::cout << "\nCalculating " << x << "!, Please wait... \n";
	bigint fact(bi.factorial());
	int trailingZeroes = fact.trailingZeroes();

	std::cout << "\n------------" << x << "!------------\n";
	std::cout << fact << "\n\n";

	std::cout << x << "! has " << trailingZeroes << " trailing zeroes.\n";

	std::cout << "See explanation of these calculations in factorial.txt\n\n";

	return 0;
}

