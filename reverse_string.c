#include <stdio.h>

int my_strlen( const char *str){
	int i = 0;
	for ( ;str[i]!='\0'; i++){ 
		
	}
	return i;
	
}
void reverse_string(char *str)
{
	int length = my_strlen(str);
	for (int i = 0 ; i < length/2 ; i++){
		char tmp = str[i];
		str[i] = str[length-i-1];
		str[length-i-1] = tmp;	
	}
}

int main(void)
{
    char test1[] = "edoc fo esuoh OT emocleW";
    char test2[] = "uoy pleh lliw ti ;3 melborp ni noitcnuf siht esU";
    char test3[] = "Hello World";
    char test4[] = "G";
    char test5[] = "abcde";

    printf("Before: %s\n", test1);
    reverse_string(test1);
    printf("After: %s\n\n",test1);

    printf("Before: %s\n", test2);
    reverse_string(test2);
    printf("After: %s\n\n", test2);

    printf("Before: %s\n", test3);
    reverse_string(test3);
    printf("After: %s\n\n", test3);

    printf("Before: %s\n", test4);
    reverse_string(test4);
    printf("After: %s\n\n", test4);

    printf("Before: %s\n", test5);
    reverse_string(test5);
    printf("After: %s\n\n", test5);

    return 0;
}

