#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char country[11];
    printf("Enter the name of your country: ");
    scanf("%10s", country);
    printf("You are from %s.\n", country);
    printf("The first letter of your country's name is: %c\n", country[0]);
    getchar(); // This consumes the '\n' left in the buffer

    char str[10];
    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);
    // Optionally remove newline again
    str[strcspn(str, "\n")] = '\0';
    fputs(str, stdout);

    return 0;
}
