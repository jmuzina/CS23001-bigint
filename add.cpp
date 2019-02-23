/**
* Joseph Muzina
* Project 1 - bigint
* CS 23001
*/

#include <fstream>
#include "bigint.hpp"

int main() {
	std::ifstream in("data1-1.txt");
	if (!in) {
		std::cerr << "Could not open data1-1.txt, exiting.\n";
		exit(1);
	}

	// Reads in two bigints, displays them, and displays their sum until end of file
	for (int i = 1; !in.eof(); i += 2) {
		bigint bi1;
		bigint bi2;

		if (!in.eof())
			in >> bi1;
		else 
			break;

		if (!in.eof())
			in  >> bi2;
		else
			break;

		std::cout << "------------------bigint " << i << "------------------\n" << bi1 << "\n\n";
		std::cout << "------------------bigint " << i + 1 << "------------------\n" << bi2 << "\n\n";

		bigint sum(bi1 + bi2);

		std::cout << "-------------bigint " << i << " + bigint " << i + 1 << "-------------\n" << sum << "\n\n";
		std::cout << "*****Finished addition of bigints " << i << " and " << i + 1 << "*****\n\n\n\n";
	}
	in.close();
	return 0;
}