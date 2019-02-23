/**
* Joseph Muzina
* Project 1 - bigint
* CS 23001
*/

#include "bigint.hpp"

// Initialize the bigint to 0
bigint::bigint() {
	for (int i = 0; i < CAPACITY; ++i)
		digits[i] = 0;
}

// Initialize bigint to an int argument
bigint::bigint(int num) : bigint() {
	for (int i = 0; ((i < CAPACITY) && (num > 0)); ++i) {
		digits[i] = (num % 10);
		num /= 10;
	}
}

// Initialize bigint to a const char array argument
bigint::bigint(const char str[]) : bigint() {
	const int STR_LENGTH = strLen(str);

	for (int i = 0; i < STR_LENGTH; ++i)
		digits[i] = charToInt(str[STR_LENGTH - 1 - i]);
}

// Multiply bigint by a digit [0, 9]
bigint bigint::timesDigit(const int rhs) const {
	bigint result;
	int carry = 0;
	for (int i = 0; i < CAPACITY; ++i) {
		int answer = 0;

		if (carry > 0) {
			answer = carry;
			carry = 0;
		}

		int product = (digits[i] * rhs);
		answer += product % 10;

		if (answer >= 10) {
			carry = answer / 10;
			answer %= 10;
		}

		if ((product + carry) >= 10)
			carry += product / 10;

		result.digits[i] = answer;
	}
	return result;
}

// Multiply by 10 (place shift)
bigint bigint::times10(const int rhs) const {
	bigint tmp;

	if (rhs > 0) {
		for (int i = 0; i < CAPACITY; ++i)
			if (i >= rhs)
				tmp.digits[i] = digits[i - rhs];
	}
	else
		return *this; // If RHS <= 0, return as-is instead of multiplying

	return tmp;
}

// Addition
bigint bigint::operator+(const bigint &rhs) const {
	bigint result;

	bool carry = false;
	for (int i = 0; i < CAPACITY; ++i) {
		int placeSum = digits[i] + rhs.digits[i];
		int answer = (placeSum % 10);

		if (carry)
			++answer;

		if (answer == 10)
			answer = 0;

		if ((placeSum >= 10) || ((placeSum == 9) && (carry)))
			carry = true;
		else
			carry = false;

		result.digits[i] = answer;
	}
	return result;
}

// Multiplication
bigint bigint::operator*(const bigint &rhs) const {
	bigint product;
	for (int i = 0; i < CAPACITY; ++i) {
		bigint tmp = timesDigit(rhs.digits[i]);
		product = product + tmp.times10(i);
	}
	return product;
}

// Factorial
bigint bigint::factorial() const {
	if (*this == 0)
		return bigint(0);

	bigint fact(1);

	for (int i = 1; i != *this + 1; ++i)
		fact = bigint(fact) * i;

	return fact;
}

// prints out every element of bigint array 
// starting from the highend of the bigint to zero
void bigint::debugPrint(std::ostream &out) const {
	for (int i = 0; i < CAPACITY; ++i)
		out << digits[CAPACITY - 1 - i] << " | ";

	out << std::endl;
}

// Returns the index of the first placeholder zero in a bigint
int bigint::placeholder() const {
	int endPos = CAPACITY - 1;
	int found = digits[endPos];

	for (int i = 0; ((i < CAPACITY) && (digits[endPos - 1] == 0)); ++i) {
		found = digits[endPos];
		--endPos;
	}

	// Ensure bigints are always at least 1 int long and can have a length of CAPACITY
	if ((endPos == 0) || (endPos == (CAPACITY - 1)))
		++endPos;

	return endPos;
}

// Subscript
int bigint::operator[](const int INDEX) const {
	const int LENGTH = placeholder();
	int value = -1;

	if (INDEX < LENGTH)
		value = digits[LENGTH - 1 - INDEX];
	else if (INDEX == LENGTH)
		value = digits[0];
	else if (INDEX > LENGTH)
		value = 0;

	return value;
}

// Returns number of trailing zeroes
int bigint::trailingZeroes() const {
	int index;

	// Counts number of trailing zeroes
	for (index = 0; digits[index] == 0; ++index) {}

	return index;
}

// Output
std::ostream& operator<< (std::ostream &out, bigint rhs) {
	// Total number of digits to output
	const int LENGTH = (rhs.placeholder() >= 0) ? rhs.placeholder() : 1;

	// Maximum number of digits per line
	const int MAX_LINE_SIZE = 80;

	for (int i = 0; i < LENGTH; ++i) {
		if ((i % MAX_LINE_SIZE == 0) && (i != 0))
			out << '\n';
		out << rhs.digits[LENGTH - 1 - i];
	}
	return out;
}

// Input
std::istream& operator>>(std::istream &in, bigint &rhs) {
	char c;
	// Temporary array to hold chars from stream
	char tmpArr[CAPACITY];

	// Initialize temp array to zeroes
	for (int i = 0; i < CAPACITY; ++i)
		tmpArr[i] = 0;

	// Write all characters of stream up to semicolon to stream
	in >> c;
	for (int i = 0; ((c != ';') && (i < CAPACITY)); ++i) {
		tmpArr[i] = c;
		in >> c;
	}

	// Copy temporary array into bigint parameter
	rhs = bigint(tmpArr);
	return in;
}

// Compare if two bigints are equal
bool operator==(const bigint &lhs, const bigint &rhs) {
	for (int i = 0; i < CAPACITY; ++i)
		if (lhs.digits[i] != rhs.digits[i])
			return false;

	return true;
}

// Not equal
bool operator!=(const bigint &lhs, const bigint &rhs) {
	if (!(lhs == rhs))
		return true;
	return false;
}

// Returns the number of chars in a string
int strLen(const char str[]) {
	int strLength = 0;
	while (str[strLength] != 0)
		++strLength;

	return strLength;
}

// Converts from char value to integer
int charToInt(const char c) {
	return (c - '0');
}

// Converts from integer to char value
char intToChar(const int x) {
	return (x + '0');
}