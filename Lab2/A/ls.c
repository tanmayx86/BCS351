#include <stdio.h> 

// Function to perform linear search 
int linearSearch(int crr[], int n, int key)
 { 

    //  //Printing the addresses od Array crr
    // for (int i = 0; i < n; i++) 
    // { 
    //      printf("The address of Array arr at index %d is : %p \n", i, &crr[i]);
    // } 

    for (int i = 0; i < n; i++) 
    { 
        if (crr[i] == key) 
        return i; // Return index if found 
    } 
    return -1; // Return -1 if not found 
    } 


int main() 
{
    int arr[] = {5, 12, 7, 25, 18}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
     //Printing the addresses od Array arr
    // for (int i = 0; i < n; i++) 
    // { 
    //      printf("The address of Array arr at index %d is : %p \n", i, &arr[i]);
    // } 


    int key = 25; 
    printf("Enter the value of key to be searched:-  : \t");
    scanf("%i", &key );
    // printf("The address of key is : %p \n", &key);

    //Calling linearSearch()
    int result = linearSearch(arr, n, key);   //? Pass by value ? or by Reference?

    if (result != -1) 
        printf("Element %d found at index %d.\n", key, result); 
    else 
        printf("Element %d not found in the array.\n", key); 
    return 0; 
}