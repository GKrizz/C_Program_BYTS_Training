Day 17   [30/01/2024] 

1.Given aa integer number invert the bits untill most active bit .

    #include <stdio.h>
    #include <math.h>
    void checker1(int num){
        int checker =1 <<((int)log2(num)+1);
        checker-=1;
        num^=checker;
        printf("%d",num);
    }
    void checker2(int num){
        
        
        int checker =1;
        while(checker<=num){
            num^=checker;
            // checker*=2;
            checker<<=1;
        }
        printf("%d",num);
    }
    int main()
    {
        int num;
        scanf("%d",&num);
        checker1(num);
        printf("\n");
        checker2(num);
        
        return 0;
    }
    /*
    10  --> 00001010
    1   --> 00000001
    ^   --> 00001011
    2   --> 00000010
    ^   --> 00001001
    4   --> 00000100
    ^   --> 00001101
    8   --> 00001000
    ^   --> 00000101
    16  --> 00010000   <--stop exicution
    */
	
2.Compression 

#include <stdio.h>
#include <math.h>
int Is_Vowel(char);
int main(){
    char str[100];
    scanf("%s",str);
    for(int ind=0;str[ind];ind+=1){
        int count =0;
        while(Is_Vowel(str[ind])){
            ind+=1;
            count+=1;
        }
        if(count){
            printf("%d",count);
        }
        printf("%c",str[ind]);
    }
    return 0;
}

int Is_Vowel(char ch){
    ch|=32;
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

Approach 2: compression

#include <stdio.h>
#include <math.h>
int Is_Vowel(char);
void replacer(char*,int,int,int);
int main(){
    char str[100];
    scanf("%[^\n]",str);
    for(int ind=0;str[ind];ind+=1){
        if(!Is_Vowel(str[ind])){
            continue;
        }
        int count =1;
        int end = ind+1;
        while(Is_Vowel(str[end])){
            end+=1;
            count+=1;
        }
        replacer(str,ind,end-1,count);
            ind = end-1;
    }
    printf("%s",str);
}

int Is_Vowel(char ch){
    ch|=32;
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

void replacer(char *str,int start,int end,int value){
    while(start<=end){
        str[start]=value+'0';
        start+=1;
    }
}

3.Check Even Frequency

#include <stdio.h>
void CheckEvenFrequency() {
    int n;
    scanf("%d", &n);

    int arr[100]; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }

    if (result == 0) {
        printf("All elements occur an even number of times.\n");
    } else {
        printf("Not all elements occur an even number of times.\n");
    }
}
int main() {
    CheckEvenFrequency();
    return 0;
}


4.Given a string representation of a number convert the number to integer form.

char str[100];
        scanf("%s",str);
        int length,num,ans;
        length=strlen(str);
        for (int i = 0; str[i]; i+=1) {//123
            num=str[i]-48;//1 2 3
            // printf("%d",num);
            ans=ans*10+num;//0*10+1=10+2=120+3=123
        }
        printf("%d",ans);
		
5.Given an array of element check whether all the elements occurs even number of times.
	7
	1 2 3 4 3 2 1

	6
	1 2 3 2 1 3

6.If input is 1 ,print 2.if input is 2 ,print1(without using conditiona statement)

7.given two sorted array and merge them into a single array.

8.given a N digited number find the sum of non prime digits.
