#include <iostream>
using namespace std;

// takes an array of integers as input
void quickSort(int[], int, int);

// takes an array of integers as input
void insertionSort(int[]);

//  find median of three
int findPivotMedian(int[], int, int);

void swap(int[], int, int);

int counter = 0;

int main()
{

	int myArray10[10] = { 6, 1, 4, 9, 0, 3, 5, 2, 7, 8 };

	for (int i = 0; i < 10; i++) {
		cout << myArray10[i] << " ";
	}
	cout << endl;

	// send quicksort the array and the first and last indexes
	quickSort(myArray10, 0, 9);

	for (int i = 0; i < 10; i++) {
		cout << myArray10[i] << " ";
	}
	cout << endl;

	return 0;
}




// arrays are always passed by reference, actual memory address
// we are essentially passing the bass address of the array
void quickSort(int someArray[], int firstIndex, int lastIndex)
{
	int pivotIndex, pivotValue, length;

	length = (lastIndex + 1) - firstIndex;

	// 1
	if (length <= 1)
		return;

	// HANDLE CASE WHERE LENGTH = 2;
	if (length == 2) {
		// if we have an inversion, then swap and return
		if (someArray[firstIndex] > someArray[lastIndex]) {
			swap(someArray, firstIndex, lastIndex);
			counter++;
		}
		return;
	}

	// 2
	pivotIndex = findPivotMedian(someArray, firstIndex, lastIndex);
	pivotValue = someArray[pivotIndex];

	// order the whole list first
	// then send the left side and right side

	//3.1 hide pivot, swap pivot value with last value
	swap(someArray, pivotIndex, lastIndex);    	// must send swap function the proper index positions. it will swap the values

	//3.2
	int i = firstIndex;
	int j = lastIndex - 1;

	//3.3
	while (i <= j) {

		while ((i <= lastIndex) && (someArray[i] < pivotValue)) {
			i++;
			counter++;
		}
		while ((j >= firstIndex) && (someArray[j] >= pivotValue)) {
			j--;
			counter++;
		}
		if (i < j)
			swap(someArray, i, j);
		else
			break;
	}

	//3.4
	swap(someArray, i, lastIndex); // put pivot back


	//4 make a left array and a right array
	
	quickSort(someArray, firstIndex, i - 1);
	someArray[i] = pivotValue;
	quickSort(someArray, i + 1, lastIndex);
}



void insertionSort(int array[])
{


}

// returns index in the pivot
int findPivotMedian(int someArray[], int first, int last)
{
	int center = (first + last) / 2;

	if (someArray[first] > someArray[center] && someArray[first] < someArray[last])
		return first;
	if (someArray[first] < someArray[center] && someArray[first] > someArray[last])
		return first;
	if (someArray[center] > someArray[first] && someArray[center] < someArray[last])
		return center;
	if (someArray[center] < someArray[first] && someArray[center] > someArray[last])
		return center;
	else
		return last;
}

void swap(int someArray[], int a, int b) {
	// swap the actual values at those index positions
	int temp = someArray[a];
	someArray[a] = someArray[b];
	someArray[b] = temp;
}