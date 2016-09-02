#include <stdio.h>

// globals
int fullLength;

int print_array(int * list, int length);
int merge_sort(int * array, int left, int right);

int main(int argc, char ** argv)
{
    printf("Merge Sort!\n");

    //int array[] = {9,8,7,6,5,4,3,2,1,0};
    int array[] = {3,5,2};
    int length = sizeof(array) / sizeof(int);
    fullLength = length;

    print_array(array, length);
    merge_sort(array, 0, length - 1);
    print_array(array, length);

    return 0;
}

int merge(int * array, int left, int middle, int right)
{
    printf("\tleft=%d middle=%d right=%d\n", left, middle, right);
    int leftSize = middle - left;
    int rightSize = right - middle + 1;
    int leftArray[leftSize];
    int rightArray[rightSize];
    int length = right - left + 1;
    int c;

    // fill left temp array
    for(c = 0; c < leftSize; c++)
    {
        leftArray[c] = array[left + c];
    }
    // fill right temp array
    for(c = 0; c < rightSize; c++)
    {
        rightArray[c] = array[middle + c];
    }

    // merge the two arrays
    // left index = i
    // right index = j
    int i = 0;
    int j = 0;
    for(c = left; c < (left + length); c++)
    {
        // if left side is exhausted add right side
        if(i == leftSize)
        {
            array[c] = rightArray[j];
            j++;
            continue;
        }
        // if right side is exhausted add left side
        if(j == rightSize)
        {
            array[c] = leftArray[i];
            i++;
            continue;
        }
        // compare and add lowest
        if(leftArray[i] <= rightArray[j])
        {
            array[c] = leftArray[i];
            i++;
            continue;
        }
        else
        {
            array[c] = rightArray[j];
            j++;
            continue;
        }
    }

    printf("\t");
    print_array(array, fullLength);

    return 0;
}

int sort(int * array, int left, int middle, int right)
{
    // return if array contains 1 element
    if(left == right)
        return 0;

    // sort left side
    int leftMiddle = ((middle - left) / 2) + left;
    int leftRight = middle - 1;
    sort(array, left, leftMiddle, leftRight);
    // sort right side
    int rightMiddle = ((right - middle + 1) / 2) + middle;
    sort(array, middle, rightMiddle, right);

    merge(array, left, middle, right);

    return 0;
}

/* merge_sort
 * 9 8 7 6 5 4 3 2 1 0
 * L         M       R
 * {       } {       }
 */

int merge_sort(int * array, int left, int right)
{
    if(left == right)
        return 0;

    int middle = (right - left + 1) / 2;
    sort(array, left, middle, right);

    return 0;
}

int print_array(int * list, int length)
{
    int c;

    printf("[ ");

    for(c = 0; c < length; c++)
    {
        printf("%d ",list[c]);
    }

    printf("]\n");

    return 0;
}
