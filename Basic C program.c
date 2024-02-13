
#include <stdio.h>
#include <math.h>

int Number_of_digits(int);
int Is_amstrong(int);
int Is_Strong(int);
int factorial(int);
int reverse(int);
int Is_Adam(int);
void Is_Magic(int);

int main()
{
    int num;
    scanf("%d",&num);
    Is_Magic(num);
    return 0;
}

int Number_of_digits(int num){
    int count=0;
    while(num){
        // num=num/10;
        // count+=1;
        return log10(num)+1;
    }
    return count;
}

int Is_amstrong(int num){
    int count =Number_of_digits(num);
    int originalNum=num;
    int sum=0;
    while(num){
        sum=sum+pow(num%10,count);
        num=num/10;
    }
     if (sum == originalNum) {
        printf("Armstrong number\n");
    } else {
        printf("Not an Armstrong number\n");
    }
}

int factorial(int unit_digit){
    if(unit_digit ==1)return 1;
    if(unit_digit >0)
        return unit_digit *factorial(unit_digit -1);
}

int Is_Strong(int num){
    int originalNum=num;
    int sum=0;
    while(num){
        int unit_digit=num%10;
        sum=sum + factorial(unit_digit);
        num=num/10;
    }
     if (sum == originalNum) {
        printf("Strong number");
    } else {
        printf("Not a strong number");
    }
}

int reverse(int num){   //234
    int rev=0;
    while(num){
        rev=rev*10+num%10;  //4
        num=num/10;  //23
    }
    return rev;
}
int Is_Adam(int num){
    int SqrAndRev=reverse(num*num);
    int rev = reverse(num);
    int RevAndSqr=rev*rev;
    
    if(SqrAndRev==RevAndSqr)
        printf("Adam");
    else
        printf("Not adam");
}
