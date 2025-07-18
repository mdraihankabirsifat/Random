#include <stdio.h>
#include <ctype.h> // for isalpha, toupper, tolower
int main()
{
    char s[] = " ThiS iS # comment # a sTrIng ";
    char *t = s, *p = s;       // read with *p, write with *t
    int comment = 0, word = 0; // inside comment? inside word?

    while (*p)
    {
        if (*p == '#')
        {
            comment = 1 - comment; // toggle comment flag
            word = 0;
        }
        else if (!comment)
        {
            if (*p == ' ')
            {
                word = 0;
            }
            else if (isalpha(*p))
            {
                if (t != s && !word)
                    *t++ = ' ';

                if (!word)
                    *t = toupper(*p);
                else
                    *t = tolower(*p);

                word = 1;
                ++t;
            }
        }
        ++p;
    }
    *t = '\0';
    printf("\"%s\"\n", s);
    return 0;
}