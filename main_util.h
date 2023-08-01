#ifndef CHECKPOINT_YEHUDANEVO_MAIN_UTIL_C
#define CHECKPOINT_YEHUDANEVO_MAIN_UTIL_C

#include <stdlib.h>
#include "string.h"
#include "School.h"

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 11
#define SCORE_COUNT 10
#define MAX_LINE_LENGTH 256


void load_student(School *school, char *line) {
    char first_name[MAX_NAME_LENGTH], last_name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
    int group, class, scores[SCORE_COUNT];

    sscanf(line, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d",
           first_name, last_name, phone, &group, &class,
           &scores[0], &scores[1], &scores[2], &scores[3], &scores[4],
           &scores[5], &scores[6], &scores[7], &scores[8], &scores[9]);

    add_student(school->groups[group - 1]->classes[class - 1], first_name, last_name, phone, scores);
}


void loadStudentsFromFile(School *school, const char *filepath) {
    FILE *file = fopen(filepath, "r");
    char line[MAX_LINE_LENGTH];

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            load_student(school, line);
        }
        fclose(file);
    }
}


void insertNewStudent(School *school) {

    char first_name[50], last_name[50], phone[11];
    int group, class, scores[10];

    printf("\nEnter first name: ");
    while (scanf("%s", first_name) != 1) {
        printf("\nInvalid input. Please enter a valid first name: ");
        while (getchar() != '\n');
    }

    printf("\nEnter last name: ");
    while (scanf("%s", last_name) != 1) {
        printf("\nInvalid input. Please enter a valid last name: ");
        while (getchar() != '\n');
    }

    printf("\nEnter phone: ");
    while (scanf("%s", phone) != 1) {
        printf("\nInvalid input. Please enter a valid phone number: ");
        while (getchar() != '\n');
    }

    printf("\nEnter group: ");
    while (scanf("%d", &group) != 1 || group < 1 || group > 12) {
        printf("\nInvalid input. Please enter a valid group number between 1 and 12: ");
        while (getchar() != '\n');
    }

    printf("\nEnter class: ");
    while (scanf("%d", &class) != 1 || class < 1 || class > 10) {
        printf("\nInvalid input. Please enter a valid class number between 1 and 10: ");
        while (getchar() != '\n');
    }

    for (int i = 0; i < 10; i++) {
        printf("\nEnter score %d: ", i + 1);
        while (scanf("%d", &scores[i]) != 1 || scores[i] < 0 || scores[i] > 100) {
            printf("\nInvalid input. Please enter a valid score between 0 and 100: ");
            while (getchar() != '\n');
        }
    }

    add_student(school->groups[group - 1]->classes[class - 1], first_name, last_name, phone, scores);
}

Student *find_student(School *school) {
    char first_name[50], last_name[50];
    printf("\nEnter first name: ");
    while (scanf("%s", first_name) != 1) {
        printf("\nInvalid input. Please enter a valid first name: ");
        while (getchar() != '\n');
    }

    printf("\nEnter last name: ");
    while (scanf("%s", last_name) != 1) {
        printf("\nInvalid input. Please enter a valid last name: ");
        while (getchar() != '\n');
    }

    for (int g = 0; g < 12; g++) {
        Group *group = school->groups[g];
        for (int c = 0; c < 10; c++) {
            Class *class = group->classes[c];
            Student *current_student = class->head;

            while (current_student != NULL) {
                if (strcmp(current_student->first_name, first_name) == 0 &&
                    strcmp(current_student->last_name, last_name) == 0) {
                    return current_student;
                }
                current_student = current_student->next;
            }
        }
    }
    return NULL;
}

void deleteStudent(School *school) {
    Student *s = find_student(school);
    if (s == NULL)
        return;
    delete_student(school, s->first_name, s->last_name);
}


void editStudentGrade(School *school) {
    Student *s = find_student(school);
    if (s == NULL) {
        printf("Student not found.\n");
        return;
    }

    // Print the current information about the student
    printf("Editing grades for %s %s\nCurrent grades: ", s->first_name, s->last_name);
    for (int i = 0; i < 10; i++) {
        printf("%d ", s->scores[i]);
    }
    printf("\n");

    // Ask which grade to edit
    int subjectIndex;
    printf("Enter the index of the subject to edit (0-9): ");
    scanf("%d", &subjectIndex);
    if (subjectIndex < 0 || subjectIndex > 9) {
        printf("Invalid subject index. Aborting edit.\n");
        return;
    }

    // Ask for the new grade
    int newGrade;
    printf("Enter the new grade for subject %d: ", subjectIndex);
    scanf("%d", &newGrade);

    // Update the grade
    s->scores[subjectIndex] = newGrade;

    printf("Grade updated successfully.\n");
}


void searchStudent(School *school) {
    Student *s = find_student(school);
    if (s == NULL) {
        printf("this student not exist");
        return;
    }
    printf("Student First Name: %s, Student Last Name: %s, Scores: ",
           s->first_name, s->last_name);
    for (int i = 0; i < 10; i++) {
        printf("%d ", s->scores[i]);
    }
    printf("\n");
}

void printAllStudents(School *school) {
    print_school(school);
}

void printTopNStudentsPerCourse(School *school) {
    int group, course;

    printf("Enter the group (1-12): ");
    scanf("%d", &group);
    if (group < 1 || group > 12) {
        printf("Invalid group. Aborting.\n");
        return;
    }

    printf("Enter the course (0-9): ");
    scanf("%d", &course);
    if (course < 0 || course > 9) {
        printf("Invalid course. Aborting.\n");
        return;
    }

    Student *top_students[10] = {NULL};
    int min_score[10] = {0};

    Group *selected_group = school->groups[group - 1];
    for (int c = 0; c < 10; c++) {
        Class *class = selected_group->classes[c];
        Student *current_student = class->head;
        while (current_student != NULL) {
            for (int i = 0; i < 10; i++) {
                if (current_student->scores[course] > min_score[i]) {
                    for (int j = 9; j > i; j--) {
                        top_students[j] = top_students[j - 1];
                        min_score[j] = min_score[j - 1];
                    }
                    top_students[i] = current_student;
                    min_score[i] = current_student->scores[course];
                    break;
                }
            }
            current_student = current_student->next;
        }
    }


    printf("Group %d, Course %d, best 10 students:\n", group, course);
    for (int i = 0; i < 10 && top_students[i] != NULL; i++) {
        printf("%d. First Name: %s, Last Name: %s, Score: %d\n",
               i + 1,
               top_students[i]->first_name,
               top_students[i]->last_name,
               top_students[i]->scores[course]);
    }
}


void printUnderperformedStudents(School *school) {
    printf("Underperformed Students (Average less than 65):\n");

    for (int g = 0; g < 12; g++) {
        Group *group = school->groups[g];
        for (int c = 0; c < 10; c++) {
            Class *class = group->classes[c];
            Student *current_student = class->head;
            while (current_student != NULL) {
                int sum = 0;
                for (int i = 0; i < 10; i++) {
                    sum += current_student->scores[i];
                }
                double average = (double) sum / 10;

                if (average < 65) {
                    printf("Group: %d, Class: %d, Student First Name: %s, Student Last Name: %s, Average Score: %.2f\n",
                           g + 1, c + 1, current_student->first_name, current_student->last_name, average);
                }

                current_student = current_student->next;
            }
        }
    }
}


void printAverage(School *school) {
    int groupNumber, courseNumber;
    double sum = 0;
    int studentCount = 0;

    printf("Enter the group number (1-12): ");
    scanf("%d", &groupNumber);
    printf("Enter the course number (1-10): ");
    scanf("%d", &courseNumber);

    // Validating the group and course numbers
    if (groupNumber < 1 || groupNumber > 12 || courseNumber < 1 || courseNumber > 10) {
        printf("Invalid group or course number. Please enter valid values.\n");
        return;
    }

    Group *group = school->groups[groupNumber - 1];
    for (int c = 0; c < 10; c++) {
        Class *class = group->classes[c];
        Student *current_student = class->head;
        while (current_student != NULL) {
            sum += current_student->scores[courseNumber - 1];
            studentCount++;
            current_student = current_student->next;
        }
    }

    if (studentCount > 0) {
        double average = sum / studentCount;
        printf("Average score for Group %d, Course %d: %.2f\n", groupNumber, courseNumber, average);
    } else {
        printf("No students found for Group %d, Course %d.\n", groupNumber, courseNumber);
    }
}


void exportDatabase(School *school) {
    char filename[256];
    int fileNumber = 1;
    snprintf(filename, sizeof(filename), "/Users/yehudanevo/CLionProjects/checkpoint-YehudaNevo/DB/school_database_%d.txt", fileNumber++);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating file");
        return;
    }

    for (int g = 0; g < 12; g++) {
        Group *group = school->groups[g];
        for (int c = 0; c < 10; c++) {
            Class *class = group->classes[c];
            Student *current_student = class->head;
            while (current_student != NULL) {
                fprintf(file, "%s %s %s %d %d",
                        current_student->first_name, current_student->last_name, current_student->phone,
                        g + 1, c + 1);
                for (int i = 0; i < 10; i++) {
                    fprintf(file, " %d", current_student->scores[i]);
                }
                fprintf(file, "\n");
                current_student = current_student->next;
            }
        }
    }

    fclose(file);
    printf("Database exported successfully to %s\n", filename);
}


void handleClosing(School *school) {
    cleanup_school(school);
}


#endif //CHECKPOINT_YEHUDANEVO_MAIN_UTIL_C
