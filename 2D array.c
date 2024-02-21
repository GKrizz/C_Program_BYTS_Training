// 1.Implement Row sum and Column sum in a Matrix

#include <stdio.h>
void sum_of_rows_ans_column(int m,int n,int arr[m][n]);
void upper_triangular_mattrix(int m,int n,int arr[m][n]);
void upper_triangular_mattrix(int m,int n,int arr[m][n]){
    int flag=0;
    for(int r=m-1;r>=1;r--){
        for(int c=0;c<r;c++){
            if(arr[r][c]!=0){
                flag=1;
                break;
            }
        }
        if(flag==1)break;
    }
    if(flag==1)
        printf("not upper upper_triangular_mattrix");
    else
        printf("upper_triangular_mattrix");
}
void sum_of_rows_ans_column(int m,int n,int arr[m][n]){
    printf("sum of Rows: ");
    int rsum=0;
    for(int row=0;row<m;row++,rsum=0){
        for(int col=0;col<n;col++){
            rsum=rsum+arr[row][col];
        }
        printf("%d ",rsum);
    }
    printf("\n");
    printf("sum of columns: ");
    int csum=0;
    for(int row=0;row<m;row++,csum=0){
        for(int col=0;col<n;col++){
            csum=csum+arr[col][row];
        }
        printf("%d ",csum);
    }
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            scanf("%d",&arr[row][col]);
        }
    }
    // sum_of_rows_ans_column(m,n,arr);
    upper_triangular_mattrix(m,n,arr);
}


