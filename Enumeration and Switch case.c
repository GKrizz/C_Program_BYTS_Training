#include <stdio.h>
// -----------------------------------------|    enumeration    |-----------------------------------------------
/*
enum weekday{sun=1,mon,tue,wed,thu,fri,sat};
int scan(){
    int num;
    scanf("%d",&num);
    return num;
}

typedef enum weekday week;
        //   initial alternate  
        //   value   name
        
int main()
{
    enum weekday v1=scan();
    
    switch(v1){
        case sun:
            printf("sunday");
            break;
        case mon:
            printf("monday");
            break;
        case tue:
            printf("tue");
            break;
        case wed:
            printf("wed");
            break;
        case thu:
            printf("thu");
            break;
        case fri:
            printf("friday");
            break;
        case sat:
            printf("saturday");
            break;
    }
}

*/

// typedef ->[Alias method]
// ----------------------------------------------------------------------------------------

struct info{
    int num;
    float val;
};
typedef struct info;

int main(){
    info v1;
    info v2;
}


// ---------------------------------------|  Switch     |-------------------------------------------------

switch(expp){
    case v1:
        process 1
        break;
    case v2:
        process 2
        break;
    default:   // -->we can  write default at any where
        default process
        break; // (optional)
}


Note:

* Default is optional reprasents failling of all case values and will be exicuted when non of the matching case value found. 
* Default can written any where within the switch block.
* break is also optional & should be maintained if overflow of case values is not decide.
* All the case value should be unique.(should not be repetation) 


prob:1

1.Given a charachter check the given character is vowel or consonante with the switch case.(the case value can only be integer and charachter not float values.)
#include <stdio.h>

int main()
{
    char ch;
    scanf("%c",&ch);
    
    switch(ch|32){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("vowel");
            break;
        default: 
            printf("Consonant");
            break;
    }
}

Note :

error:case lable does not reduce to an integer constant
case 97.5:

2.Given a character .check the given character is an upper case or lower case or number or symbol
#include <stdio.h>
int main()
{
    char ch;
    scanf("%c",&ch);
    switch(ch){
        case 'a' ... 'z' :printf("Lower case");break;
        case 65 ... 96 :printf("Upper case");break;
        case 48 ... '9' :printf("Number");break;
        default :printf("SYMBOL");break;
    }
    /*
    if(ch>=65 && ch<=96)
        printf("Upper case");
    else if(ch>=97 && ch<=122)
        printf("Lower case");
    else if(ch>=48 && ch<=57)
        printf("Number");
    else if(ch==' '|| ch=='\t'|| ch=='\n')
        printf("separator");
    else
        printf("Symbol");*/
}

Note

* If the  range return is an integer range space on the lower limit side is maditatory byt soace on upper limit size is optional.
* If the range mentioned in the character range space on either side is optional.

3.Give a Three numbers find the largest?
#include <stdio.h>
int main()
{
    int num1,num2,num3;
    printf("Num1: ");
    scanf("%d",&num1);
    printf("Num2: ");
    scanf("%d",&num2);
    printf("Num3: ");
    scanf("%d",&num3);
    
    if(num1>=num2 && num1>=num3)
        printf("%d is largest",num1);
    else if(num2>=num3)
        printf("%d is largest",num2);
    else
        printf("%d is largest",num3);
}
            ---**-----
#include <stdio.h>
int maximum(int num1,int num2);

int main()
{
    int num1,num2,num3,num4;
    printf("Num1: ");
    scanf("%d",&num1);
    printf("Num2: ");
    scanf("%d",&num2);
    printf("Num3: ");
    scanf("%d",&num3);
    printf("Num4: ");
    scanf("%d",&num4);
    
    int max=maximum(maximum(num1,num2),maximum(num3,num4));
    printf("%d",max);
}

int maximum(int num1,int num2){
    return(num1>num2)?num1:num2;
}

-------------------------------|    Macros    |--------------------------------------------
they can be used to assign factionality to entity
macros(#define)


#include <stdio.h>
#define maximum(num1,num2) ((num1>num2)?num1:num2)
#define minimum(num1,num2) ((num1>num2)?num2:num1)
// int maximum(int num1,int num2);

int main()
{
    int num1,num2,num3,num4;
    printf("Num1: ");
    scanf("%d",&num1);
    printf("Num2: ");
    scanf("%d",&num2);
    printf("Num3: ");
    scanf("%d",&num3);
    printf("Num4: ");
    scanf("%d",&num4);
    
    
    int max=maximum(maximum(num1,num2),maximum(num3,num4));
    printf("maximum : %d\n",max);
    int min=minimum(minimum(num1,num2),minimum(num3,num4));
    printf("minimum: %d\n",min);
}

// int maximum(int num1,int num2){
//     return(num1<num2)?num1:num2;
// }


1. Given three numbers print them in ascending order

#include <stdio.h>
#define maximum(num1,num2) ((num1>num2)?num1:num2)
#define minimum(num1,num2) ((num1>num2)?num2:num1)
// int maximum(int num1,int num2);

int main()
{
    int num1,num2,num3,num4;
    printf("Num1: ");
    scanf("%d",&num1);
    printf("Num2: ");
    scanf("%d",&num2);
    printf("Num3: ");
    scanf("%d",&num3);
    printf("Num4: ");
    scanf("%d",&num4);
 
    int max=maximum(maximum(num1,num2),maximum(num3,num4));
    int min=minimum(minimum(num1,num2),minimum(num3,num4));
    int mid1=maximum(minimum(num1,num2),minimum(num3,num4));
    int mid2=minimum(maximum(num1,num2),maximum(num3,num4));
    // int mid=num1+num2+num3-max-min;
    printf("%d %d %d %d",min,mid1,mid2,max);
    
    
    // int max=maximum(maximum(num1,num2),maximum(num3,num4));
    // printf("maximum : %d\n",max);
    // int min=minimum(minimum(num1,num2),minimum(num3,num4));
    // printf("minimum: %d\n",min);
}

// int maximum(int num1,int num2){
//     return(num1<num2)?num1:num2;
// }
-------------------------------------------Problem----------------------------------------

1.Leap year or not

int main()
{
    // int year=100;
// // Approach 1
    // (year%4==0 && year%100!=100||year%400==0)?printf("leap"):printf("not leap");
// Approach 2
    // if(year %4==0){
    //     if(year%100==0){
    //         if(year%400==0){
    //             printf("leap year1");
    //         }else{
    //             printf("not a leap year1")
    //         }
    //     }else{
    //         printf("leap year2")
    //     }
    // }else{
    //     printf("Not a leap year2";)
    // }

2.Valid date/month/year 


#include <stdio.h>
int isValidDate(int date,int month,int year);
// int isLeapYear(int year) {
//     return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
// }

int main() {
    int date,month,year;
    scanf("%d/%d/%d",&date,&month,&year);

    if (isValidDate(date,month,year))
        printf("Valid date");
    else
        printf("Invalid date");
}

int isValidDate(int date,int month,int year) {
    if (year<1||month<1||month>12||date<1)||date>31{
        return 0;
    }
    int days_in_month;
    switch (month) {
        case 2:
            days_in_month = ((year%4==0 && year%100!=0) || (year%400==0))? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days_in_month = 30;
            break;
        default:
            days_in_month = 31;
    }
    return (date <= days_in_month);
}


3.LCM

		#include <stdio.h>
		int main()
		{
			int num1,num2;
			scanf("%d %d",&num1,&num2);
			int lcm=1;
			for(int i=1;1;i+=1){
				if(i%num1==0 && i%num2==0){
					lcm=i;
					break;
				}
			}
			printf("%d",lcm);
		}

4.GCD

		//Approch 2

		#include <stdio.h>
		int GCD(int num1,int num2);
		int main()
		{
			int num1,num2;
			scanf("%d %d",&num1,&num2);
			int result=(num1>num2)?GCD(num1,num2):GCD(num2,num1);
			printf("%d",result);
			return 0;
		}


		int GCD(int num1,int num2){//38 4
			while(num1%num2){// 38 % 4    4 % 2
				int temp=num2;// 4
				num2=(num1 % num2);//2
				num1=temp;//4
			}
			return num2;
		}

5.Given a even number .Find the sum of even numbers which are less than or equal to the given number.

	#include <stdio.h>
	int main()
	{
		int num;
		scanf("%d",&num);
		num/=2;
		int sum=(num * (num+1));
		printf("%d",sum);
		return 0;
	}

6.Given a number print the next most available pallindrome in such a way the next number will be form by sum of current number + reverse of current number.

153(not a prime) + 351 --> 504(not a prime)+405--> 909
195+591 --> 786+687 --> 1473+3741 --> 5214+4125 --> 9339(which is pallindrom)

	#include <stdio.h>
	int reverse(int num);
	int reverse(int num){
		int rev=0;
		while(num){
			rev=rev*10+num%10;
			num/=10;
		}
		return rev;
	}
	int main(){
		int num;
		scanf("%d",&num);
		while(1){
			int rev=reverse(num);
			if(rev==num){
				break;
			}
			num=num+rev;
		}
		printf("%d",num);
	}


H.W:

1.Given a number find the largest prime factor.
	#include <stdio.h>

	int main() {
		int num;
		scanf("%d", &num);

		int largestPrimeFactor = 0;
		int i = 2;
		while (num > 1) {
			while (num % i == 0) {
				largestPrimeFactor = i;
				num /= i;
			}
			i += 1;
		}
		if (largestPrimeFactor) {
			printf("Largest prime factor: %d", largestPrimeFactor);
		} else {
			printf("Not a prime");
		}

		return 0;
}

2.Given a number find the smallest prime factor.
				12--> 2
				
#include <stdio.h>
int main() {
    int num;
    scanf("%d", &num);

    int smallestPrimeFactor = 0;
    int i = 2;
    while (i <= num) {
        if (num % i == 0) {
            smallestPrimeFactor = i;
            break;
        }
        i += 1;
    }
    if (smallestPrimeFactor) {
        printf("Smallest prime factor: %d", smallestPrimeFactor);
    } else {
        printf("Not a prime");
    }

    return 0;
}

3.write a program to convert given a number to the mentioned base value .(base lies in range 2 to 10)
     10 20 1010