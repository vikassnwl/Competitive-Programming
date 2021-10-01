// CPP implementation to find Remainder
// when a large Number is divided by R

#include <bits/stdc++.h>
using namespace std;

// Function to Return Remainder
int Remainder(string str, int R)
{
	// len is variable to store the
	// length of Number string.
	int len = str.length();

	int Num, Rem = 0;

	// loop that find Remainder
	for (int i = 0; i < len; i++) {

		Num = Rem * 10 + (str[i] - '0');
		Rem = Num % R;
	}

	// Return the remainder
	return Rem;
}

// Driver code
int main()
{

	// Get the large number as string
	string str = "13589234356546756";

	// Get the divisor R
	int R = 13;

	// Find and print the remainder
	cout << Remainder(str, R);

	return 0;
}

