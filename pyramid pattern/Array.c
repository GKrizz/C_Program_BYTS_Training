#include <stdio.h>
#include <math.h>

void Sum_and_Product(int arr[], int size);
void reverse(int arr[], int size);
void replace_and_update_sum(int arr[],int size);
void replace_and_update_product(int arr[],int size);
int Prime_Array(int);
void leftRotate(int arr[],int size);
void RightRotate(int arr[],int size);
void Palindrome(int arr[],int size);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    printf("Choose an operation:\n");
    printf("1. Print original array\n");
    printf("2. Reverse\n");
    printf("3. Sum and Product\n");
    printf("4. replace and update sum\n");
    printf("5. replace and update Product\n");
    printf("6. Prime\n");
    printf("7. leftRotate\n");
    printf("8. RightRotate\n");
    printf("9. Palindrome\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Original Array: ");
            for (int i = 0; i < size; i++) {
                printf("%d, ", arr[i]);
            }
            printf("\n");
            break;
        case 2:
            reverse(arr, size);
            break;
            
        case 3:
            Sum_and_Product(arr, size);
            break;
        case 4:
            replace_and_update_sum(arr, size);
            break;
        case 5:
            replace_and_update_product(arr, size);
            break;
        case 6:
            printf("Prime Array: ");
            for(int i=0;i<size;i++){
                printf("%d",Prime_Array(arr[i]));
            }
            break;
        case 7:
            printf("Left Rotate: ");
            leftRotate(arr,size);
            break;
        case 8:
            printf("Right Rotate: ");
            RightRotate(arr,size);
            break;
        case 9:
            printf("Palindrome : \n");
            Palindrome(arr,size);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

void Sum_and_Product(int arr[], int size) {
    int sum = 0, prod = 1;
    printf("Sum of array: %d\n", sum);
    printf("Product of array: %d\n", prod);
}

void reverse(int arr[], int size) {
    printf("Reverse: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void replace_and_update_sum(int arr[],int size){
    int sum = 0,i;
    for ( i = 0; i < size; sum += arr[i++]);
    printf("Sum: %d\n",sum);
    
    for ( i = 0; i < size; i++)
    {
        arr[i] = sum - arr[i];
        printf("%d ", arr[i]);
    }
}

void replace_and_update_product(int arr[],int size){
    int prod = 0,i;
    for ( i = 0; i < size; prod += arr[i++]);
    printf("product: %d\n",prod);
    
    for ( i = 0; i < size; i++){
        arr[i] = prod / arr[i];
        printf("%d ", arr[i]);
    }
}

int Prime_Array(int num){
    if(num<2) return 0;
    if(num%2==0) return num==2;
    for(int itr=3;itr<=sqrt(num);itr+=2){
        if((num%itr)==0) return 0;
    }
    return num;
}

void leftRotate(int arr[], int size){
    int temp = arr[size-1],i;
    for ( i = size - 1; i >0 ; i-=1)
    {
        arr[i] = arr[i - 1];
    }
    arr[i] = temp;
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
}

void RightRotate(int arr[], int size){
    int temp = arr[0],i;
    for (i = 0; i < size - 1; i++)    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
    
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
}

void Palindrome(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int copy = arr[i];
        int rev = 0;
        int original = copy; 

        while (copy != 0) {
            rev = rev * 10;
            rev = rev + (copy % 10);
            copy /= 10;
        }

        if (original == rev) {
            printf("%d is a Palindrome\n", arr[i]);
        } else {
            printf("%d is not a Palindrome\n", arr[i]);
        }
    }
}

