#include "School.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
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

void delete_student(School* school, const char* firstName, const char* lastName) {
    for (int g = 0; g < 12; g++) {
        Group* group = school->groups[g];
        for (int c = 0; c < 10; c++) {
            Class* class = group->classes[c];
            Student* current_student = class->head;
            Student* previous_student = NULL;

            while (current_student != NULL) {
                if (strcmp(current_student->first_name, firstName) == 0 &&
                    strcmp(current_student->last_name, lastName) == 0) {

                    // If it's the first student in the class, update the class's head pointer.
                    if (previous_student == NULL) {
                        class->head = current_student->next;
                    } else {
                        previous_student->next = current_student->next;
                    }

                    free(current_student);

                    return ;
                }

                previous_student = current_student;
                current_student = current_student->next;
            }
        }
    }

    return ;
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

