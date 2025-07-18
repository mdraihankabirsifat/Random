#include <stdio.h>
int main()
{
    char str[] = "Hello World";
    char *ptr = str; // Pointer to the first character of the string
    printf("String: %s\n", ptr);
    printf("First character: %c\n", *ptr);
    printf("Second character: %c\n", *(ptr + 1));
    char a[] = "Bangladesh";
    char *b = "China", *c = "India";
    b = a;
    fputs(b, stdout);
    return 0;
}