#include <stdio.h>
typedef struct
{
    char name[50]; // dissimilar datatype
    int id;
    float mark;
    char grade;
} Student;

char findGrade(Student s)
{
    char g;
    if(s.mark >= 90) g = 'A';
    else if(s.mark >= 80) g = 'B';
    else if(s.mark >= 70) g = 'C';
    else if(s.mark >= 60) g = 'D';
    else g = 'F';
    return g;
}

int main()
{
    Student s;
    printf("Name: ");
    gets(s.name);
    printf("ID: ");
    scanf("%d", &s.id);
    printf("Mark: ");
    scanf("%f", &s.mark);
    s.grade = findGrade(s);
    printf("Student Information:\n");
    printf("Name: %s\n", s.name);
    printf("ID: %d\n", s.id);
    printf("Mark: %.2f\n", s.mark);
    printf("Grade: %c\n", s.grade);
    return 0;
}