#include <stdio.h>
#include <windows.h> // For Sleep()
int main()
{
    int h = 0, m = 0, s = 0;
    while (1)
    {
        // Print the time
        printf("%02d:%02d:%02d", h, m, s);
        fflush(stdout); // Immediately show the output
        Sleep(1000); // Wait for 1 second
        // Move the cursor back 8 characters: hh:mm:ss has 8 characters including colons
        for (int i = 0; i < 8; i++)
        {
            printf("\b");
        }
        // Update the time
        s++;
        if (s == 60)
        {
            s = 0;
            m++;
        }
        if (m == 60)
        {
            m = 0;
            h++;
        }
        if (h == 24)
        {
            h = 0;
        }
    }
    return 0;
}