/**
* Joseph Muzina
* Project 1 - bigint
* CS 23001
*/

#include "bigint.hpp"
#include <fstream>

int main() {
	std::ifstream in("data1-2.txt");

	if (!in) {
		std::cerr << "Could not open data1-2.txt, exiting. \n";
		exit(1);
	}

	// Read all bigints from file and multiply them together
	for (int i = 1; !in.eof(); i += 2) {
		bigint bi1;
		bigint bi2;

		if (!in.eof())
			in >> bi1;
		else
			break;

		if (!in.eof())
			in >> bi2;
		else
			break;

		std::cout << "------------------bigint " << i << "------------------\n" << bi1 << "\n\n";
		std::cout << "------------------bigint " << i + 1 << "------------------\n" << bi2 << "\n\n";

		bigint product(bi1 * bi2);

		std::cout << "-------------bigint " << i << " * bigint " << i + 1 << "-------------\n" << product << "\n\n";
		std::cout << "*****Finished multiplication of bigints " << i << " and " << i + 1 << "*****\n\n\n\n";
	}
	in.close();
	return 0;
}