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