#include<stdio.h>
#include<string.h>

// Define structure record
struct record {
    char empname[20];
    int age;
    float salary;
};
typedef struct record person;

int main() {
    person employee;
    int i, n;
    FILE *fp;

    // Get number of records
    printf("How many records: ");
    scanf("%d", &n);

    // Open the file for writing
    fp = fopen("PEOPLE.txt", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Input employee details and write to file
    for (i = 0; i < n; i++) {
        printf("Enter the employee information %d (EmpName, Age, Salary): ", i + 1);
        scanf("%s %d %f", employee.empname, &employee.age, &employee.salary);
        fwrite(&employee, sizeof(person), 1, fp);
    }

    fclose(fp);

    int rec, result;
    FILE *people = fopen("PEOPLE.txt", "rb");
    if (people == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Prompt to read records
    printf("Which record do you want to read from file? ");
    scanf("%d", &rec);

    // Read and display records
    while (rec >= 0) {
        fseek(people, rec * sizeof(person), SEEK_SET);
        result = fread(&employee, sizeof(person), 1, people);

        if (result == 1) {
            printf("\n RECORD %d\n", rec);
            printf("Given name: %s\n", employee.empname);
            printf("Age: %d years\n", employee.age);
            printf("Current salary: $%.2f\n\n", employee.salary);
        } else {
            printf("\n RECORD %d not found!\n\n", rec);
        }

        printf("Which record do you want (0 to %d)? ", n - 1);
        scanf("%d", &rec);
    }

    fclose(people);
    return 0;
}

