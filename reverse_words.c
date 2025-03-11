#include <stdio.h>

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to reverse words 
void reverse_words(char *str) {
    if (!str) return;

    // Step 1: Find the length of the string
    char *end = str;
    while (*end) end++;  
    end--;              

    // Step 2: Reverse the entire string
    reverse(str, end);

    // Step 3: Reverse each word 
    char *word_start = NULL;
    char *ptr = str;

    while (*ptr) {
        if (*ptr != ' ' && word_start == NULL) {
            word_start = ptr;  // Mark the start of a word
        }

        if ((*ptr == ' ' || *(ptr + 1) == '\0') && word_start) {
            reverse(word_start, (*ptr == ' ') ? ptr - 1 : ptr);  
            word_start = NULL;  // Reset for next word
        }

        ptr++;
    }
}

int main() {
    char s1[] = "The dragons are coming";
    char s2[] = "code love I";
    char s3[] = "G";

    reverse_words(s1);
    printf("%s\n", s1);  

    reverse_words(s2);
    printf("%s\n", s2); 

    reverse_words(s3);
    printf("%s\n", s3);

    return 0;
}

