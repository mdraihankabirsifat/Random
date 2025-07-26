#include <stdio.h>
int main()
{
    char name[50];
    int age;
    char str[100];
    // Using scanf and printf (standard input/output)
    printf("Enter your name and age: ");
    scanf("%s %d", name, &age);
    printf("You entered: %s %d\n", name, age);
    // Using sprintf to write to a string
    sprintf(str, "%s %d", name, age);
    printf("Formatted string using sprintf: %s\n", str);
    // Using sscanf to read from a string
    char newName[50];
    int newAge;
    sscanf(str, "%s %d", newName, &newAge);
    printf("Extracted from string using sscanf: %s %d\n", newName, newAge);
    return 0;
}
