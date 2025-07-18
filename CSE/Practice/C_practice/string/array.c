#include <stdio.h>
#include <string.h>

int main()
{
    char countries[4][30];  // 4 country names, each up to 29 characters + '\0'
    for (int i = 0; i < 4; ++i)
    {
        printf("Enter country %d: ", i + 1);
        fgets(countries[i], sizeof(countries[i]), stdin);
        // Remove newline character if present
        int len = strlen(countries[i]);
        if (len > 0 && countries[i][len - 1] == '\n')
        {
            countries[i][len - 1] = '\0';
        }
    }
    printf("\nList of countries:\n");
    for (int i = 0; i < 4; ++i)
    {
        printf("%s\n", countries[i]);
    }
    return 0;
}