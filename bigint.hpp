/**
 * Joseph Muzina
 * Project 1 - BigInt
 * CS 23001
 */

#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>

 // Maximum number of integers in a bigint object
const int CAPACITY = 1024;

class bigint {
public:
	bigint();
	bigint(int);
	bigint(const char[]);
	
	bigint timesDigit(const int) const;
	bigint times10(const int) const;
	bigint operator+(const bigint&) const;
	bigint operator*(const bigint&) const;
	bigint factorial() const;

	void debugPrint(std::ostream&) const;

	int placeholder() const;
	int operator[](const int) const;
	int trailingZeroes() const;

	friend std::ostream& operator<<	(std::ostream&, bigint);
	friend std::istream& operator>>	(std::istream&, bigint&);

	friend bool operator==(const bigint&, const bigint&);
	friend bool operator!=(const bigint&, const bigint&);
private:
	int digits[CAPACITY];
};

int strLen(const char[]);
int charToInt(const char);
char intToChar(const int);

#endif