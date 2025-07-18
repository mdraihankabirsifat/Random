#include <stdio.h>
int main()
{
    char ccountry[] = "China";
    char *bcountry = "Bangladesh";
    char *acountry = "Australia";
    bcountry = acountry;
    printf("%s\n", bcountry);
    bcountry = ccountry;
    printf("%s", bcountry);
    return 0;
}