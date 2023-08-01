#include <stdio.h>
#include "School.h"
#include "main_util.h"

#define STUDENTS_FILE "/Users/yehudanevo/CLionProjects/checkpoint-YehudaNevo/DB/students_with_class.txt"


enum menu_inputs {
    Insert = '0',
    Delete = '1',
    Edit = '2',
    Search = '3',
    Showall = '4',
    Top10 = '5',
    UnderperformedStudents = '6',
    Average = '7',
    Export = '8',
    Exit = '9'
};

void menu(School *school) {
    char input[3];
    char option;
    int ch;
   // while ((ch = getchar()) != '\n' && ch != EOF);
    do {
        printf("\n|School Manager<::>Home|\n");
        printf("----------------------------\n");
        printf("\t[0] |--> Insert\n");
        printf("\t[1] |--> Delete\n");
        printf("\t[2] |--> Edit\n");
        printf("\t[3] |--> Search\n");
        printf("\t[4] |--> Show All\n");
        printf("\t[5] |--> Top 10 students per course\n");
        printf("\t[6] |--> Underperformed students\n");
        printf("\t[7] |--> Average per course\n");
        printf("\t[8] |--> Export\n");
        printf("\t[9] |--> Exit\n");
        printf("\n\tPlease Enter Your Choice (0-9): ");

        fgets(input, sizeof(input), stdin);
        option = input[0];

        // Skipping new line character if input is longer than 2 characters
        if (input[1] != '\n' && input[1] != '\0') {
            while (fgetc(stdin) != '\n');
        }

        switch (option) {
            case Insert:
                insertNewStudent(school);
                break;
            case Delete:
                deleteStudent(school);
                break;
            case Edit:
                editStudentGrade(school);
                break;
            case Search:
                searchStudent(school);
                break;
            case Showall:
                printAllStudents(school);
                break;
            case Top10:
                printTopNStudentsPerCourse(school);
                break;
            case UnderperformedStudents:
                printUnderperformedStudents(school);
                break;
            case Average:
                printAverage(school);
                break;
            case Export:
                exportDatabase(school);
                break;
            case Exit:
                handleClosing(school);
                break;
            default:
                if (input[0] == '\n') {
                    printf("\t\nPlease enter a number between 0-9!\t\nPress any key to continue...");
                } else {
                    printf("\nThere is no item with symbol \"%c\". Please enter a number between 0-9!\nPress any key to continue...",
                           input[0]);
                }
                getc(stdin);
                break;
        }
        while ((ch = getchar()) != '\n' && ch != EOF);
    } while (option != Exit);
}


int main() {

    School school = create_school();
    loadStudentsFromFile(&school, STUDENTS_FILE);
    menu(&school);


    return 0;
}
