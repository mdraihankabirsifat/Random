#include <stdio.h>
typedef struct
{
    char n[50];
    int id;
    float m;
} Student;

float average(Student s[], int N)
{
    float sum = 0, avg;
    int i;
    for (i = 0; i < N; i++)
    {
        sum = sum + s[i].m;
    }
    avg = sum / N;
    return avg;
}

int main()
{
    int i, N;
    float avg;
    printf("Enter number of students: ");
    scanf("%d", &N);
    Student s[N];
    for (i = 0; i < N; i++)
    {
        printf("Name: ");
        scanf("%s", s[i].n);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Mark: ");
        scanf("%f", &s[i].m);
    }
    avg = average(s, N);
    printf("Average: %.2f\n", avg);
    return 0;
}