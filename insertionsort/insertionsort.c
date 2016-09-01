#include <stdio.h>

// prototypes
int print_array(int * array, int length);
int sort_array(int * list, int length);

int main()
{
    printf("Insertion Sort!\n");

    int array[] = {9,8,7,6,5,4,3,2,1,0};
    int length = sizeof(array) / sizeof(int);

    print_array(array, length);
    sort_array(array, length);
    print_array(array, length);

    return 0;
}

int sort_array(int * list, int length)
{
    int i, j;

    printf("sorting...\n");

    for(i = 1; i < length; i++)
    {
        for(j = i; j > 0; j--)
        {
            if(list[j] < list[j-1])
            {
                // swap
                list[j]   = list[j] ^ list[j-1];
                list[j-1] = list[j] ^ list[j-1];
                list[j]   = list[j] ^ list[j-1];
            }
            else
            {
                break;
            }
        }
        printf("\t");
        print_array(list, length);
    }

    printf("sorted\n");

    return 0;
}

int print_array(int * array, int length)
{
    int c;

    printf("[ ");
    for(c = 0; c < length; c++)
    {
        printf("%d ", array[c]);
    }
    printf("]\n");

    return 0;
}
