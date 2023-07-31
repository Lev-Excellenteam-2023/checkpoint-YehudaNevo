#include "School.h"
#include <stdio.h>
#include "School.h"

School create_school() {
    School school;
    for(int i = 0; i < 12; i++) {
        school.groups[i] = create_group();
    }
    return school;
}

void cleanup_school(School* school) {
    for(int i = 0; i < 12; i++) {
        cleanup_group(school->groups[i]);
    };
}
void print_school(School* school) {
    for(int g = 0; g < 12; g++) {
        Group* group = school->groups[g];
        for(int c = 0; c < 10; c++) {
            Class* class = group->classes[c];
            Student* current_student = class->head;
            while(current_student != NULL) {
                printf("Group: %d, Class: %d, Student First Name: %s, Student Last Name: %s, Scores: ",
                       g+1, c+1, current_student->first_name, current_student->last_name);
                for(int i = 0; i < 10; i++) {
                    printf("%d ", current_student->scores[i]);
                }
                printf("\n");
                current_student = current_student->next;
            }
        }
    }
}

