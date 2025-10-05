#include <stdio.h>
struct student
{
    int roll;
    float cgpa;
};
// Without typedef, you need to write struct every time: struct student a;
// Need to remember the types
// Giving Names to Types using typedef:
typedef float cgpaType;
typedef int rollType;
typedef struct
{
    rollType roll;
    cgpaType cgpa;
} studentType;
int main()
{
    // Using typedef aliases
    studentType a;
    cgpaType tomalCgpa;
    rollType tomalRoll;
    // Example usage
    a.roll = 123;
    a.cgpa = 3.85;
    tomalCgpa = 3.92;
    tomalRoll = 456;
    printf("Student a - Roll: %d, CGPA: %.2f\n", a.roll, a.cgpa);
    printf("Tomal - Roll: %d, CGPA: %.2f\n", tomalRoll, tomalCgpa);
    return 0;
}