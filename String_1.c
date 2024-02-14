#include <stdio.h>
#include <string.h>

void Is_Pangram();
void Is_Anagram();
void find_num_of_occurance();
void word_count();
void Decompression(char str[]);
void reverseWord(char str[], int start, int end);
void reverse_WordbyWord(char str[]);
void reverse_occurance_of_Word(char str[]);
int isAlphabetic(char ch);
void special_symbol_stay(char str[]);

int main() {
    int choice;

    printf("Choose an operation:\n");
    printf("1. Find pangram\n");
    printf("2. Find anagram\n");
    printf("3. Find Number of occurance\n");
    printf("4. Count words\n");
    printf("5. Decompression  input:a2b4g --> output:aabbbbg\n");
    printf("6. Reverse word by word\n");
    printf("7. Reverse Occurance of word\n");
    printf("8. Reverse string but special symbol stay as it's\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            Is_Pangram();
            break;
        case 2:
            Is_Anagram();
            break;
        case 3:
            char str[100];
            printf("Enter the string: ");
            scanf(" %[^\n]", str);
            find_num_of_occurance(str);
            break;
        case 4:
            printf("Enter the string: ");
            scanf(" %[^\n]", str);
            word_count(str);
            break;
        case 5:
            printf("Enter the string: ");
            scanf(" %[^\n]", str);
            Decompression(str);
            break;
        case 6:
            printf("Enter the string: ");
            scanf(" %[^\n]", str);
            reverse_WordbyWord(str);
            printf("%s", str);
            break;
        case 7:
            printf("Enter the string: ");
            scanf(" %[^\n]", str);
            reverse_occurance_of_Word(str);
            printf("%s", str);
            break;
        case 8:
            printf("Enter the string: ");
            scanf(" %[^\n]", str);
            special_symbol_stay(str);
            printf("%s", str);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

void Is_Pangram() {
    char str[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    int arr[26] = {0}; // 0->a, 1->b, 2->char

    for (int ind = 0; str[ind]; ind += 1) {
        arr[(str[ind] | 32) - 'a'] += 1;//str-->it take each element at once |32--> it is bits|97->its like if the num is a means 97-97 =0 so arr[0] will be updated as 1.
    }

    for (int ind = 0; ind < 26; ind += 1) {
        if (arr[ind] == 0) {
            printf("Not a pangram\n");
            return;
        }
    }

    printf("Pangram\n");
}

void Is_Anagram() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf(" %[^\n]", str1);
    printf("Enter the second string: ");
    scanf(" %[^\n]", str2);
    int arr1[26] = {0};
    int arr2[26] = {0};

    for (int ind = 0; str1[ind]; ind += 1) {
        arr1[(str1[ind] | 32) - 'a'] += 1;
    }

    for (int ind = 0; str2[ind]; ind += 1) {
        arr2[(str2[ind] | 32) - 'a'] += 1;
    }

    for (int ind = 0; ind < 26; ind += 1) {
        if (arr1[ind] != arr2[ind]) {
            printf("Not anagrams\n");
			return ;
        }
    }
    printf("Anagrams\n");
}

void find_num_of_occurance(char str[]) {
    int arr[26] = {0};

    for (int ind = 0; str[ind]; ind += 1) {
        char ch = str[ind] | 32;
        int itr = ch - 'a';
        arr[itr] += 1;
    }

    for (int ind = 0; ind < 26; ind++) {
        if (arr[ind]) {
            printf("%c -> %d\n", ind + 'a', arr[ind]);
        }
    }
}

void word_count(char str[]){
    
    int words = 0;
    int is_word = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            is_word = 0;  // If space or tab --> not a word
        else {
            if (!is_word) {
                is_word = 1;  // here it count a word after space  ex: gud mrng--> _m= word(1)
                words+=1;
            }
        }
    }
    printf("%d",words);
}

void Decompression(char str[]){
    for (int i = 0; str[i]; i+=1) {
        if (str[i] >= '1' && str[i] <= '9') {
            int count = str[i] - '0'; // Convert char to integer |'3'-'0'=3 ASCII value of '3' is 51 &  '0' is 48 51-48=3
            for (int j = 1; j < count; j+=1) 
                printf("%c", str[i-1]); //i-1 print the previous character
        } 
        else 
            printf("%c", str[i]);
    }
}

void reverseWord(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverse_WordbyWord(char str[]) {
    int length = strlen(str);

    int start = 0;
    int end = 0;
    for (; end <= length; end++) {
        if (str[end] == ' ') {
            reverseWord(str, start, end - 1);
            start = end + 1;
        }
    }
    // reverseWord(str, 0, length - 1);---->this is for reverse occurance of word
}

void reverse_occurance_of_Word(char str[]) {
    int length = strlen(str);

    int start = 0;
    int end = 0;
    for (; end <= length; end++) {
        if (str[end] == ' ') {
            reverseWord(str, start, end - 1);
            start = end + 1;
        }
    }
    reverseWord(str, 0, length - 1);//---->this is for reverse occurance of word
}

int isAlphabetic(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

void special_symbol_stay(char str[]) {
    int length = strlen(str);

    int start = 0;
    int end = 0;
    for (; end <= length; end++) {
        if (!isAlphabetic(str[end])) {
            reverseWord(str, start, end - 1);
            start = end + 1;
        }
    }
    // reverseWord(str, 0, length - 1);//---->this is for reverse occurance of word
}
