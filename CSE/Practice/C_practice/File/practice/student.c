#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char name[50];
    float marks;
} Student;

// Function to clear input buffer
void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Add a new student
void add_student(const char *filename)
{
    FILE *fp = fopen(filename, "ab"); // append in binary mode
    if (fp == NULL)
    {
        fprintf(stderr, "ERROR: Cannot open file '%s' for writing\n", filename);
        return;
    }

    Student s;
    printf("\n--- Add New Student ---\n");
    printf("Enter Student ID: ");
    if (scanf("%d", &s.id) != 1)
    {
        printf("Invalid ID format!\n");
        fclose(fp);
        return;
    }

    clear_buffer(); // Clear input buffer

    printf("Enter Student Name: ");
    if (fgets(s.name, sizeof(s.name), stdin) != NULL)
    {
        // Remove newline if present
        s.name[strcspn(s.name, "\n")] = '\0';
    }

    printf("Enter Marks: ");
    if (scanf("%f", &s.marks) != 1)
    {
        printf("Invalid marks format!\n");
        fclose(fp);
        return;
    }

    if (fwrite(&s, sizeof(Student), 1, fp) == 1)
    {
        printf("Student added successfully!\n");
    }
    else
    {
        printf("Error writing to file!\n");
    }

    fclose(fp);
}

// Display all students
void display_students(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("No student records found or cannot open file.\n");
        return;
    }

    Student s;
    int count = 0;

    printf("\n--- Student Records ---\n");
    printf("%-5s %-20s %-8s\n", "ID", "Name", "Marks");
    printf("%-5s %-20s %-8s\n", "----", "--------------------", "--------");

    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        printf("%-5d %-20s %-8.2f\n", s.id, s.name, s.marks);
        count++;
    }

    if (count == 0)
    {
        printf("No records found.\n");
    }
    else
    {
        printf("\nTotal students: %d\n", count);
    }

    fclose(fp);
}

// Search student by ID
void search_student(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("No student records found or cannot open file.\n");
        return;
    }

    int search_id;
    printf("Enter Student ID to search: ");
    if (scanf("%d", &search_id) != 1)
    {
        printf("Invalid ID format!\n");
        fclose(fp);
        return;
    }

    Student s;
    int found = 0;

    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        if (s.id == search_id)
        {
            printf("\n--- Student Found ---\n");
            printf("ID: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with ID %d not found.\n", search_id);
    }

    fclose(fp);
}

// Display menu
void display_menu()
{
    printf("\n=== Student Management System ===\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

int main()
{
    const char *filename = "students.dat";
    int choice;

    printf("Welcome to Student Management System\n");
    printf("Data will be stored in: %s\n", filename);

    while (1)
    {
        display_menu();

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            clear_buffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            add_student(filename);
            break;
        case 2:
            display_students(filename);
            break;
        case 3:
            search_student(filename);
            break;
        case 4:
            printf("Thank you for using Student Management System!\n");
            return 0;
        default:
            printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}