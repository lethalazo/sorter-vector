/**
 * A Not so elegant C++ sorting and searching program that I developed, during a 'eureka' moment to make better use of vectors, in 30 mins, in the middle of the night.
 * @author Arsalan Azmi
 * @version 1.1, 7th March 2019
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

//Size of the integer array
unsigned int size = 15;
double integers[] = { 3, 7, 4, 5, -1, 11, 101, 78, 23, -19, -233, 23, -234, -233.5, 2 };
vector<double> sorted;

/**
 * Checks each of the element, provided the index to the elements.
 * Manipulates the sorted vector, and makes it 'sorted'.
 * @params int i (index for the given integer list), int j (index for the vector)
*/
void checkElem(unsigned int i, unsigned int j) {
	//Decrements the index for the 'sorted' vectr comparison
	j--;
	//Compares elements
	if (j == 0 && integers[i] < sorted[j]) {
		//Inserts before the current element
		sorted.insert(sorted.begin(), integers[i]);
	}
	else if (integers[i] > sorted[j]) {
		//Inserts after the current element
		sorted.insert(sorted.begin() + j + 1, integers[i]);
	}
	else {
		//Recurs and checks all the previous elements in the sorted array
		checkElem(i, j);
	}
}

/**
 * Implemented binary search, just because.
 * @params double toSearch - number to search
 * @return int middle - position of the element
*/
int binarySearch(double toSearch) {
	unsigned int left, right;
	unsigned int middle;
	left = 0;
	right = size - 1;
	while (left <= right) {
		middle = left + (right - left) / 2;
		if (sorted[middle] > toSearch) {
			right = middle - 1;
		}
		else if (sorted[middle] < toSearch) {
			left = middle + 1;
		}
		else {
			return middle;
		}
	}
	return -1;
}
/**
 * Implements the algorithm to sort the numbers using the power of vectors in C++
 * the plain-old main function.
*/
int main()
{
	//Inititalizes the vector by pushing in the first element to act as a pivot    
	sorted.push_back(integers[0]);
	//Compare each element with the elements in the sorted vector
	for (unsigned int i = 1; i < size; i++) {
		if (integers[i] >= sorted[i - 1]) {
			sorted.push_back(integers[i]);
		}
		else {
			//Check the element, made a different function for the use of recursion
			checkElem(i, i);
		}
	}
	//Pretty print the vector
	cout << "[";
	//Prints each element of the sorted vector
	for (unsigned int i = 0; i < size; i++) {
		if (i == size - 1)
		{
			cout << sorted[i];
		}
		else cout << sorted[i] << ",";
	}
	cout << "]";
	cout << "\n" << binarySearch(277); //277 does not exist
	cout << "\n" << binarySearch(-19); //-19 exists
}
