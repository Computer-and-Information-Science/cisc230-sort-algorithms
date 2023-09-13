# Sort Algorithm Implementations

This project contains implementations of 5 different sort algorithms, each
implemented in its own header file. The algorithms are:

- Bubble Sort
- Insertion Sort
- Selection Sort
- Merge Sort (two versions)
- Quicksort

Also included are three test programs. Each test program prompts for (or
accepts on the command line) an array size. An array of the specified size
is created and populated with values. That array is then sorted is verified
to ensure the sort was successful. In addition the, sort process is timed
and the CPU time used by the sort process is reported.

The three test programs are:

- *sorttest1.cpp* - Populates an array with random integers.
- *sorttest2.cpp* - Populates an array with random strings.
- *sorttest3.cpp* - Populates an array with random integers and supplies
a custom sort function for sorting the array.

Selection of the sort algorithm is made by changing the include file in the
sort test program.

Additional sort algorithms may be implemented, each in its own header file.
A template for sort file implementations is as follows:

```C++
// Standard comparison function
template <typename T>
inline bool sort_compare (const T& a, const T& b) { return a < b; }

// Sort implementation using comparison function
template <typename T, typename U>
void sort (T a[], size_t n, U cmp) {
	// Sort algorithm implementation goes here.
}

// Sort using sort_compare as the comparison function
template <typename T>
void sort (T a[], size_t n) { sort(a, n, sort_compare<T>); }

```

This allows for the optional inclusion of a sorting comparison function. A
comparison function takes two parameters and is to return `true` when the
first argument should come before the second argument in the desired sorting
order.