#ifndef CHECKPOINT_YEHUDANEVO_MAIN_UTIL_C
#define CHECKPOINT_YEHUDANEVO_MAIN_UTIL_C

#include "School.h"


#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 11
#define SCORE_COUNT 10
#define MAX_LINE_LENGTH 256


void load_student(School* school, char* line) {
    char first_name[MAX_NAME_LENGTH], last_name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
    int group, class, scores[SCORE_COUNT];

    sscanf(line, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d",
           first_name, last_name, phone, &group, &class,
           &scores[0], &scores[1], &scores[2], &scores[3], &scores[4],
           &scores[5], &scores[6], &scores[7], &scores[8], &scores[9]);

    add_student(school->groups[group-1]->classes[class-1], first_name, last_name, phone, scores);
}



void loadStudentsFromFile(School* school, const char* filepath) {
    FILE* file = fopen(filepath, "r");
    char line[MAX_LINE_LENGTH];

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            load_student(school, line);
        }
        fclose(file);
    }
}




void insertNewStudent(School* school) {
    // implementation
}

void deleteStudent(School* school) {
    // implementation
}

void editStudentGrade(School* school) {
    // implementation
}

void searchStudent(School* school) {
    // implementation
}

void printAllStudents(School* school) {
    // implementation
}

void printTopNStudentsPerCourse(School* school) {
    // implementation
}

void printUnderperformedStudents(School* school) {
    // implementation
}

void printAverage(School* school) {
    // implementation
}

void exportDatabase(School* school) {
    // implementation
}

void handleClosing(School* school) {
    // implementation
}


#endif //CHECKPOINT_YEHUDANEVO_MAIN_UTIL_C
