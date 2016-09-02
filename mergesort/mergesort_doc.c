/* Merge Sort
 * I wrote this in a google doc for practice
 * I had several errors
 * I used MS except in the prototypes
 * I didn't do the math right for leftMiddle and rightMiddle
 * Google quotes didn't copy over correctly
 * I mixed the variable names once 'rightArray' with 'rightSize'
 */

#include <stdio.h>

#define MS static void

// prototypes
MS print_array(int * array, int length);
MS merge_sort(int * array, int left, int right);

int main(int argc, char ** argv)
{
	int array[] = {9,8,7,6,5,4,3,2,1,0};
	int length = sizeof(array) / sizeof(int);

	print_array(array, length);
	merge_sort(array, 0, (length - 1));
	print_array(array, length);

	return 0;
}

MS merge(int * array, int left, int middle, int right)
{
	int c;
	int length = right - left + 1;
	int leftSize = middle - left;
	int rightSize = right - middle + 1;
	int leftArray[leftSize];
	int rightArray[rightSize];

	// fill leftArray
	for(c = 0; c < leftSize; c++)
	{
		leftArray[c] = array[c + left];
	}

	// fill rightArray
	for(c = 0; c < rightSize; c++)
	{
		rightArray[c] = array[c + middle];
	}

	// merge
	int l, r;
	for(c = left, l = 0, r = 0; c < (length + left); c++)
	{
		// check if leftArray exhausted
		if(l == leftSize)
		{
			array[c] = rightArray[r];
			r++;
			continue;
		}

		// check if rightArray exhausted
		if(r == rightSize)
		{
			array[c] = leftArray[l];
			l++;
			continue;
		}

		// compare two arrays
		// if leftArray is less
		if(leftArray[l] < rightArray[r])
		{
			array[c] = leftArray[l];
			l++;
			continue;
		}
		// if rightArray is less
		else
		{
			array[c] = rightArray[r];
			r++;
			continue;
		}
	}
}

MS sort(int * array, int left, int middle, int right)
{
	int leftRight = middle - 1;
	int leftMiddle = ((leftRight - left + 1) / 2) + left;
	int rightMiddle = ((right - middle + 1) / 2) + middle;

	if(left == right)
		return;

	// sort left half
	sort(array, left, leftMiddle, leftRight);
	// sort right half
	sort(array, middle, rightMiddle, right);
	// merge
	merge(array, left, middle, right);
}

/* merge_sort
 * 0 1 2 3 4 5 6 7 8 9
 * 9 8 7 6 5 4 3 2 1 0
 * L         M       R
 * {       } {       }
 */
MS merge_sort(int * array, int left, int right)
{
	int middle = ((right - left + 1) / 2) + left;

	sort(array, left, middle, right);
}

MS print_array(int * array, int length)
{
	int c;

	printf("[ ");

	for(c = 0; c < length; c++)
	{
		printf("%d ", array[c]);
	}

	printf("]\n");
}

