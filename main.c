#include <stdio.h>
#include "School.h"

void load_student(School* school, char* line) {
    char first_name[50], last_name[50], phone[11];
    int group, class, scores[10];

    sscanf(line, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d",
           first_name, last_name, phone, &group, &class,
           &scores[0], &scores[1], &scores[2], &scores[3], &scores[4],
           &scores[5], &scores[6], &scores[7], &scores[8], &scores[9]);

    add_student(school->groups[group-1]->classes[class-1], first_name, last_name, phone, scores);
}


int main() {

    School school = create_school();

    FILE* file = fopen("/Users/yehudanevo/CLionProjects/checkpoint-YehudaNevo/students_with_class.txt", "r");
    char line[256];

    if (file) {
        printf("DEBUG: open the file ");
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
