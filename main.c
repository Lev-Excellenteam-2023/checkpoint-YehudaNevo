#include <stdio.h>
#include "School.h"

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 11
#define SCORE_COUNT 10
#define MAX_LINE_LENGTH 256
#define STUDENTS_FILE "/Users/yehudanevo/CLionProjects/checkpoint-YehudaNevo/students_with_class.txt"

void load_student(School* school, char* line) {
    char first_name[MAX_NAME_LENGTH], last_name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];
    int group, class, scores[SCORE_COUNT];

    sscanf(line, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d",
           first_name, last_name, phone, &group, &class,
           &scores[0], &scores[1], &scores[2], &scores[3], &scores[4],
           &scores[5], &scores[6], &scores[7], &scores[8], &scores[9]);

    add_student(school->groups[group-1]->classes[class-1], first_name, last_name, phone, scores);
}

int main() {

    School school = create_school();
    FILE* file = fopen(STUDENTS_FILE, "r");
    char line[MAX_LINE_LENGTH];

    if (file) {
        printf("DEBUG: open the file \n");
        while (fgets(line, sizeof(line), file)) {
            load_student(&school, line);
        }
        fclose(file);
    } else{
        perror("Error opening file");
        return 1;
    }

    print_school(&school);
    cleanup_school(&school);

    return 0;
}
