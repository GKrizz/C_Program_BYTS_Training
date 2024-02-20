1.Check the peak element in array
2.write a program to chck whether is pangram number or not.
3.given a array which contains 0,1,2. (without using sorting algorithm)


1.Check the peak element in array
#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nPeak elements: ");

    // Check for peak elements
    int maxpeak=0;
    if (arr[0] > arr[1]) {
        maxpeak=arr[0];
    }

    for (int i = 1; i < size - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            if(arr[i]>maxpeak)
                maxpeak=arr[i];
        }
    }
    if (arr[size - 1] > arr[size - 2]) {
        if(arr[size-1]>maxpeak)
            maxpeak=arr[size-1];
    }
    printf("%d ", maxpeak);
    return 0;
}
2.write a program to chck whether is pangram number or not.

3.given a array which contains 0,1,2. (without using sorting algorithm)
#include <stdio.h>

// Function declarations
void without_swapping(int *arr, int size);
void with_swapping(int *arr, int size);
void print_array(int *arr, int size);

// Function to rearrange array without swapping
void without_swapping(int *arr, int size) {
    int i, zeros = 0, ones = 0, twos = 0;

    for (i = 0; i < size; i += 1) {
        if (arr[i] == 0)
            zeros++;
        else if (arr[i] == 1)
            ones++;
        else
            twos++;
    }

    for (i = 0; i < zeros; i += 1)
        arr[i] = 0;
    for (i = zeros; i < zeros + ones; i++)
        arr[i] = 1;
    for (i = zeros + ones; i < zeros + ones + twos; i++)
        arr[i] = 2;

    // Print the updated array
    print_array(arr, size);
}

// Function to rearrange array with swapping
void with_swapping(int *arr, int size) {
    int i = 0;
    int j = size - 1;
    int temp;

    while (i < j) {
        while (i < j && arr[i] == 0)
            i++;
        while (j > i && arr[j] == 1)
            j--;
        if (i < j) {
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // Print the updated array
    print_array(arr, size);
}

// Function to print array elements
void print_array(int *arr, int size) {
    printf("\nUpdated array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int size, i;
    scanf("%d", &size);

    int arr[size];

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements: ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
        
    int choice;
    printf("\nChoose operation\n1: Without Swapping\n2: With Swapping");
    printf("\nchoice");
    scanf("%d", &choice);

    if (choice == 1) {
        without_swapping(arr, size);
    } else if (choice == 2) {
        with_swapping(arr, size);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}

