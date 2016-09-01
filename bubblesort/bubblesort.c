#include <stdio.h>

// prototypes
int print_array(int * list, int length);
int sort_array(int * list, int length);

int main()
{
    printf("Bubble Sort!\n");

    int array[] = {9,8,7,6,5,4,3,2,1,0};
    int length = sizeof(array) / sizeof(int);

    print_array(array, length);
    sort_array(array, length);
    print_array(array, length);

    return 0;
}

int sort_array(int * list, int length)
{
    int swapped = 1;

    printf("sorting...\n");

    while(swapped)
    {
        int c;
        swapped = 0;

        for(c = 0; c < (length-1); c++)
        {
            if(list[c] > list[c+1])
            {
                swapped = c > 0 ? 1 : 0;
                // swap using xor
                list[c]   = list[c] ^ list[c+1];
                list[c+1] = list[c] ^ list[c+1];
                list[c]   = list[c] ^ list[c+1];
            }
        }
        printf("\t");
        print_array(list, length);
    }

    printf("sorted\n");

    return 0;
}

int print_array(int * list, int length)
{
    int c;

    printf("[ ");
    for(c = 0; c < length; c++)
    {
        printf("%d ", list[c]);
    }
    printf("]\n");

    return 0;
}
