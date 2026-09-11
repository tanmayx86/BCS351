#include <stdio.h>

// Performs binary search on a sorted array
int binarySearch(int data[], int size, int value)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (data[middle] == value)
        {
            return middle;
        }
        else if (data[middle] < value)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    return -1;
}

// Displays all elements of the array
void display(int data[], int size)
{
    printf("Elements in the array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }

    printf("\n");
}

int main()
{
    int numbers[] = {2, 4, 10, 15, 18, 23, 32};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int value, position;

    display(numbers, size);

    printf("Enter the element you want to search: ");
    scanf("%d", &value);

    position = binarySearch(numbers, size, value);

    if (position >= 0)
    {
        printf("%d is present at position %d.\n", value, position + 1);
    }
    else
    {
        printf("%d is not present in the array.\n", value);
    }

    return 0;
}
