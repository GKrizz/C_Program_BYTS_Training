#include <stdio.h>

void main(){
  int j;
  for(j=1;j<=5;j++){
      printf("%d\t",j);
  }
}

// 1	2	3	4	5	

void main(){
  int i,j;
  for(i=1;i<=5;i++){
    for(j=1;j<=5;j++){
    // for(j=5;j>=1;j--){
        printf("%d\t",j);
        // printf("%c\t",j+64);
      }
      printf("\n");
    }
}
/*
Output:

    1	2	3	4	5	
    1	2	3	4	5	
    1	2	3	4	5	
    1	2	3	4	5	
    1	2	3	4	5

    1	1	1	1	1	
    2	2	2	2	2	
    3	3	3	3	3	
    4	4	4	4	4	
    5	5	5	5	5	

    *	*	*	*	*	
    *	*	*	*	*	
    *	*	*	*	*	
    *	*	*	*	*	
    *	*	*	*	*	

    A	B	C	D	E	
    A	B	C	D	E	
    A	B	C	D	E	
    A	B	C	D	E	
    A	B	C	D	E

    5	4	3	2	1	
    5	4	3	2	1	
    5	4	3	2	1	
    5	4	3	2	1	
    5	4	3	2	1		
*/

void main(){
  int i,j;
  for(i=1;i<=5;i++){
    for(j=1;j<=i;j++){
        printf("%d\t",j);
      }
      printf("\n");
    }
}
/*
Output:

    1	
    1	2	
    1	2	3	
    1	2	3	4	
    1	2	3	4	5

    1	
    2	2	
    3	3	3	
    4	4	4	4	
    5	5	5	5	5

    *
    *	*
    *	*	*
    *	*	*	*
    *	*	*	*	*

    A	
    A	B	
    A	B	C	
    A	B	C	D	
    A	B	C	D	E	

    5	
    5	4	
    5	4	3	
    5	4	3	2	
    5	4	3	2	1	
*/

void main(){
  int i,j;
  for(i=1;i<=5;i++){
    for(j=i;j>=1;j--){
        printf("%d\t",j);
      }
      printf("\n");
    }

    printf("\n");
    
    int x,y;
    for(x=5;x>=1;x--){
        for(y=x;y>=1;y--){
            printf("%d\t",y);
      }
      printf("\n");
    }
}
/*
    1	
    2	1	
    3	2	1	
    4	3	2	1	
    5	4	3	2	1	

    5	4	3	2	1	
    4	3	2	1	
    3	2	1	
    2	1	
    1

    A	
    B	A	
    C	B	A	
    D	C	B	A	
    E	D	C	B	A	

    E	D	C	B	A	
    D	C	B	A	
    C	B	A	
    B	A	
    A	

*/

void main(){
  int i,j;
  for(i=1;i<=5;i++){
    for(j=5;j>=i;j--){
        printf("%d\t",j);
      }
      printf("\n");
    }

    printf("\n");
    int x,y;
    for(x=5;x>=1;x--){
        for(y=5;y>=x;y--){
            printf("%d\t",y);
      }
      printf("\n");
    }
}

/*
    5	4	3	2	1	
    5	4	3	2	
    5	4	3	
    5	4	
    5	

    5	
    5	4	
    5	4	3	
    5	4	3	2	
    5	4	3	2	1

    E	D	C	B	A	
    E	D	C	B	
    E	D	C	
    E	D	
    E	

    E	
    E	D	
    E	D	C	
    E	D	C	B	
    E	D	C	B	A	

*/
void main(){
  int i,j;
  for(i=5;i>=1;i--){
    for(j=1;j<=i;j++){
        printf("%d\t",j);
      }
      printf("\n");
    }

    printf("\n");
    int x,y;
    for(x=1;x<=5;x++){
        for(y=x;y<=5;y++){
            printf("%d\t",y);
      }
      printf("\n");
    }
}

/*
1	2	3	4	5	
1	2	3	4	
1	2	3	
1	2	
1	

1	2	3	4	5	
2	3	4	5	
3	4	5	
4	5	
5	

A	B	C	D	E	
A	B	C	D	
A	B	C	
A	B	
A	

A	B	C	D	E	
B	C	D	E	
C	D	E	
D	E	
E	

*/