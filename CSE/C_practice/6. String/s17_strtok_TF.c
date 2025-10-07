#include <stdio.h>
#include <string.h>
static char *next_token = NULL;
char *my_strtok(char *str, const char *delimiters)
{
    if (str != NULL)
        next_token = str;
    if (next_token == NULL)
        return NULL;
    // Skip leading delimiters
    while (*next_token && strchr(delimiters, *next_token))
        next_token++;
    if (*next_token == '\0')
    {
        next_token = NULL;
        return NULL;
    }
    char *token_start = next_token;
    // Find end of token
    while (*next_token && !strchr(delimiters, *next_token))
        next_token++;

    if (*next_token)
    {
        *next_token = '\0';
        next_token++;
    }
    else
    {
        next_token = NULL;
    }
    return token_start;
}

int main()
{
    char str[] = "Hello,world;test:string";
    char *token = my_strtok(str, ",;:");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, ",;:");
    }
    return 0;
}