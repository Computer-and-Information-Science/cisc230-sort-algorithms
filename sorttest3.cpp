// srttest3.cpp - Sort test program #3
//
// Performs a sort on an array of random integers using a custom comparison
//	function.

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

// Include the sort code. The file used here must define a function called
//	"sort" that takes two parameters: an array of integers (or template type)
//	and an integer size.
#include "bubble.h"

// Custom comparison function. This function will cause the sort altorithm
//	to sort integers according to the rightmost digit. When the rightmost
//	digit of two integers is the same, they are to be considered equal.
inline bool cmp_mod_10 (int a, int b) { return abs(a) % 10 < abs(b) % 10; }

int checksum1(int a[], int n);
int checksum2(int a[], int n);
void print(int a[], int n);
bool is_sorted(int a[], int n);

int main(int argc, char* argv[]) {

	int* x;		// Array of integers, allocated dynamically
	int size;	// Size of array x

	// Initialize random number generator
	srand(time(0));

	// Get size of array to be sorted
	if (!(size = argc > 1 ? atoi(argv[1]) : 0)) {
		cout << "Enter array size: ";
		cin >> size;
	}

	// Set verbose mode if <=120 elements. In verbose mode, displays array
	//	before and after sorting, shows the checksums, and generates values
	//	<1000 for readability.
	bool verbose = size <= 120;

	// Allocate array of int's.
	x = new int[size];

	// Fill array with random numbers.
	for (int i = 0; i < size; i++)
		x[i] = verbose ? (rand() % 1000) : rand();

	// Produce initial checksums.
	int cksum1a = checksum1(x, size);
	int cksum2a = checksum2(x, size);

	// Show array and checksums, if verbose set.
	if (verbose) {
		cout << endl << "Before sort:" << endl;
		print(x, size);
		cout << "  Checksums: " << cksum1a << " " << cksum2a << endl << endl;
	}

	// Sort the array.
	cout << "Sorting... ";
	cout.flush();
	clock_t t = clock();
	sort(x, size, cmp_mod_10);
	t = clock() - t;

	// Produce checksums.
	int cksum1b = checksum1(x, size);
	int cksum2b = checksum2(x, size);

	// Show result.
	cout << (is_sorted(x, size) && cksum1a == cksum1b && cksum2a == cksum2b ?
		"success." : "FAILED") << endl;

	// Show array, if verbose set.
	if (verbose) {
		cout << endl << "After sort:" << endl;
		print(x, size);
		cout << "  Checksums: " << cksum1b << " " << cksum2b << endl << endl;
	}

	// Show run time.
	cout << "Run time: " << fixed << setprecision(2) <<
		((double)t) / CLOCKS_PER_SEC << " seconds." << endl;

	// Deallocate array.
	delete[] x;
}

// checksum1 - A simple checksum to see if an array of integers contains the
//	same values, but not necessarily in the same order. Returns the sum of
//	of the values in the array, disregarding overflow.
int checksum1(int a[], int n) {
	int cksum = 0;
	for (int i = 0; i < n; i++)
		cksum += a[i];
	return cksum;
}

// checksum2 - Another simple checksum. Initializes a checksum to zero, then
//	XOR's all values into the checksum.
int checksum2(int a[], int n) {
	int cksum = 0;
	for (int i = 0; i < n; i++)
		cksum ^= a[i];
	return cksum;
}

// print - Prints all values in an array, formatted for readability. Assumes
//	each value is fewer than 5 digits.
void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i && !(i % 12))
			cout << endl;
		cout << setw(5) << a[i];
	}
	cout << endl;
}

// is_sorted - Checks an array to see if the values are sorted.
bool is_sorted(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		if (cmp_mod_10(a[i + 1], a[i]))
			return false;
	return true;
}
