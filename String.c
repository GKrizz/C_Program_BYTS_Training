#include <stdio.h>
#include <string.h>
#include <ctype.h>

void length_of_string(char str[]);
void is_vowel(char str[]);
void is_consonant(char str[]);
void reverse_string(char str[]);

void length_of_string(char str[]) {
    // printf("%ld", strlen(str));
    int len = 0;
    while (str[len]) {
        len++;
    }
    printf("%d",len) ;
    
    /*
    while (str[len++]);
    printf("%d",len-1);
    
    for(;str[len++])
    printf("%d",len-1);
    
    */
}
// void is_vowel(char str[]) {
//     int vowel = 0;

//     for (int i = 0; str[i]; i++) {
//         char ch = tolower(str[i]); // Convert to lowercase for case-insensitive comparison
//         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//             vowel++;
//     }
//     printf("Number of vowels: %d\n", vowel);
// }

// void is_consonant(char str[]) {
//     int cons = 0;
//     int vowel_count = is_vowel(str);

//     for (int i = 0; str[i]; i++) {
//         char ch = tolower(str[i]); // Convert to lowercase for case-insensitive comparison
//         if (!is_vowel(&ch)) {
//             cons++;
//         }
//     }
//     printf("Number of consonants: %d\n", cons);
// }

void reverse_string(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
    printf("Reversed string: %s\n", str);
}


int main()
{
    char str[100];
    scanf("%[^\n]",str);
    // length_of_string(str);
    // is_vowel(str);
    // is_consonant(str);
    reverse_string(str);
    
    /*
    char name[];
    
    scanf("%[^\n]s",name);//terminate when 0 takes
    scanf("%[^\a]s",name);//stop before l
    scanf("%[^A-Z & ^a-z]",name);//123ab-->123 bcz it terminate when the char came
    scanf("%[&A-Z | &a-z | &0-9]",name);//&it print only the given condition 
    
    printf("%s",name);



    char str[100]={'h','e','l','\0','l','o','\0'};
    printf("%c",str[4]);//l
    printf("\n%s",str);//hel
    */
    return 0;
}
