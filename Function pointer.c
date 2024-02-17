31.01.2024


#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#define MAX(num1,num2) ((num1>num2)?num1:num2)

int* get_array(int size){
    int *arr = (int*) malloc(size * sizeof(int));
    
    for(int ind=0;ind<size ; ind+=1){
        scanf("%d",&arr[ind]);
    }
    return arr;
}

int get_max(int *arr, int len){
    int max = arr[0];// 1 2 3 5 5
    for(int ind=1;ind<len;ind+=1){// ind = 1, 2 3 4
        max = MAX (max, arr[ind]);//5  
    }
    return max;
}

int get_max_ind(int *arr, int len){
    int max_ind = 0;
    for(int ind=1;ind<len;ind+=1){
        if(arr[ind] > arr[max_ind]){
            max_ind = ind;
        }
    }
    return max_ind;
}

int main()
{
    int size;
    scanf("%d",&size);
    int *arr = get_array(size);
    int max_ind = get_max_ind(arr,size);
    arr[max_ind] = INT_MIN;
    printf("%d",get_max(arr,size));
    return 0;
}

---------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <malloc.h>

void get_max(int *arr,int size);

int* get_array(int size){
    int *arr=(int*) malloc(size * sizeof(int));
    for(int ind=0;ind<size;ind+=1){
        scanf("%d",&arr[ind]);
    }
    return arr;
}



int main()
{
    int size,len;
    scanf("%d%n",&size,&len);
    int *arr=get_array(size);
    
    // int leftSum = 0;
    // for (int ind = 0; ind < size; ind++) {
    //     int temp = arr[ind];
    //     arr[ind] = leftSum;
    //     leftSum += temp;
    // }
    
    
   // 2.Given an arry of number find the maximum number
    get_max(arr,size);
   // 3.Given an arry of number find the maximum index
    get_max_index(arr,size);
    for(int ind=0;ind<size;ind+=1){
        printf("%d",arr[ind]);
    }
    
}

void get_max(int *arr,int size){
                                              // 1 2 3 4 5   -->5 
    int max = arr[0];                        //max = [0] -->1  
    // int maxIndex = 0;
    for (int ind = 1; ind < size; ind++) {  // ind = 1
        if (arr[ind] > max) {               //  2 >1
            max = arr[ind];                 //  max= 2
            // maxIndex = ind;
            }
        }
    printf("Maximum Value: %d\n", max);
    // printf("Maximum index: %d\n", maxIndex);
}
void get_max_index(int *arr,int size){
                                        
    // int max = arr[0];                    
    int maxIndex = 0;
    for (int ind = 1; ind < size; ind++) {  
            maxIndex = ind;
            }
    printf("Maximum index: %d\n", maxIndex);
}
-----------------------------------------------------------------------------------

    //4.Given the set of paranthisis 
#include <stdio.h>

int isBalanced(char* expression) {
    int count = 0;

    for (int i = 0; expression[i]; i++) {
        if (count < 0) 
                return 0;
        if (expression[i] == '(')
            count++;
        else
            count--;
    }
    return (count == 0); 
}

int main() {
    char expression[100];

    // Input: Get the expression from the user
    printf("Enter the expression: ");
    scanf("%s", expression);

    // Check if the parentheses are balanced
    if (isBalanced(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
-------------------------------------------------------------------Function pointers---------------------------------------------------------



#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

int mul(int num1, int num2) {
    return num1 * num2;
}

int que(int num1, int num2) {
    return num1 / num2;
}

int rem(int num1, int num2) {
    return num1 % num2;
}

int absolute_diff(int ptr(int,int),int num1,int num2){
    // printf("%d\n",((*ptr)(num1,num2)));
    int result;
    result=(num1>num2)?ptr(num1,num2):ptr(num2,num1);
    printf("%d\n",result);
}

int main() {
    
    absolute_diff(&sub,10,20);
    absolute_diff(&sub,50,10);
    // int (*ptr)(int,int)=&sum;
    // printf("%p %p",&sum,*ptr);
    // printf("\n");
    // printf("%d",(*ptr)(1,5));
    // return 0;
}

#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

int mul(int num1, int num2) {
    return num1 * num2;
}

int que(int num1, int num2) {
    return num1 / num2;
}

int rem(int num1, int num2) {
    return num1 % num2;
}

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int choice;
    switch (choice) {
        case 1:
            printf("addition: %d", sum(num1,num2));break;
        case 2:
            printf("subtraction: %d", sub(num1,num2));break;
        case 3:
            printf("multiplication: %d", mul(num1,num2));break;
        case 4:
            printf("quotient %d", que(num1,num2));break;
        case 5:
            printf("Remainder: %d", rem(num1,num2));break;
        default:
            printf("Invalid choice");
    }
}

#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

int sub(int num1, int num2) {
    return num1 - num2;
}

int mul(int num1, int num2) {
    return num1 * num2;
}

int que(int num1, int num2) {
    return num1 / num2;
}

int rem(int num1, int num2) {
    return num1 % num2;
}

int main() {
    int num1, num2,choice;
    scanf("%d %d %d", &num1, &num2,&choice);
    
    int(*ptr[])(int,int)={[1]=sum,[2]=sub,[3] =mul,[4] = que,[5]rem};
    
    int result=(ptr[choice])(num1,num2);
    printf("%d",result);


}
----------------------------------------Two dimensional array-------------------------------------------

#include <stdio.h>

int main() {
    /*
    arr->200
    int arr1[10][10];
    arr[row][col]=nase_add+((row* noe_per_row)+col)sizeof(datatype)
    arr[3][5]->200+((3*10)+5)*4
             ->200+(35*4) -> 200 +140->340*/
            
    // Declare a 2D array named 'arr1' with dimensions 10x10
    int arr1[10][10];

    // Assuming you want to calculate the index for a 2D array element
    int row = 3;
    int col = 5;
    int nase_add = 200;  // Some base address

    // Calculate the index using the formula
    int index = nase_add + ((row * 10) + col) * sizeof(int);

    // Print the result
    printf("Index for arr[3][5]: %d\n", index);

    return 0;
}
----------------------------------------------------------------------------------------
write a c program to take 2  n*m  (n-num of rows)( m-num of colum )and print sum .

#include<stdio.h>
int main(){
    int row,cols;
    scanf("%d %d",&row,&cols);
    int mat1[row][cols],mat2[row][cols],sol[row][cols];
    for(int row1=0;row1<row;row1+=1){
        for(int col=0;col<cols;col+=1){
            scanf("%d",&mat1[row1][col]);
        }
    }
    for(int row1=0;row1<row;row1+=1){
        for(int col=0;col<cols;col+=1){
            scanf("%d",&mat2[row1][col]);
        }
    }
    for(int row1=0;row1<row;row1+=1){
        for(int col=0;col<cols;col+=1){
            sol[row1][col] = mat1[row1][col] + mat2[row1][col];
        }
    }
    
    for(int row1=0;row1<row;row1+=1,printf("\n")){
        for(int col=0;col<cols;col+=1){
            printf("%3d ",sol[row1][col]);
        }
    }
    
}

-------------------------------------------------------------------------------------
int main(){
    int row,cols;
    int *arr=(int*) malloc(10*sizeof(int));
    scanf("%d %d",&row,&cols);
    int **mat=(int **)malloc(row*sizeof(int*));
    for(int ind=0;ind<row;ind+=1){
        mat[ind]=(int*) malloc(sizeof(int)*cols);
    }
    for(int ind=0;ind<row;ind+=1){
        free(mat[ind]);
    }
    printf("%lu",sizeof(mat));
    free(mat);
    mat=NULL;
}
----------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
int* get_array(int size){
   return  (int*)malloc(sizeof(int) * size);
}
int main(){
    int size ;
    scanf("%d",&size);
    int *arr = get_array(size);
    for(int ind=0;ind<size;ind+=1){
        scanf("%d",&arr[ind]);
    }
    while(size > 1){
        int new_size = (size+1)/2;
        int *new_arr = get_array(new_size);
        for(int ind=0,new_ind=0;new_ind  < new_size ; new_ind +=1){
            new_arr[new_ind] = arr[ind++];
            if(ind < size){
                new_arr[new_ind]+= arr[ind++];
            }   
        }
        for(int ind=0;ind<new_size;ind+=1){
            printf("%d ",new_arr[ind]);
        }
        printf("\n");
        arr= new_arr;
        size = new_size;
    }
    return 0;
}

----------------------------------------------------------------------
/*
Time complexity
1.O(1)           -->input output
2.O(log2(num))--> binary search
3.O(num)       factoriyal
4.O(nlogn) -->sorting
5.O(n^2)   -->number pattern
6.O(2^n)   -->recurtion
*/


#include <stdio.h>

int main()
{
    int num;//1unit
    scanf("%d",&num);//1unit
    printf("%d",&num);//1unit
}//3 unit -->1 unit

int main(){
    int num;//1 unit
    scanf("%d",&num);
    int fact=1;
    for(int ind=1;ind<=num;ind+=1){//1unit+(num+1)+num
        
        fact*=ind
    }
}