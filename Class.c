#include "Class.h"
#include <stdlib.h>
#include <string.h>


Class* create_class() {
    Class* class = (Class*)malloc(sizeof(Class));
    class->head = NULL;
    class->count = 0;
    return class;
}




void add_student(Class* class, char* first_name, char* last_name, char* phone, int scores[10]) {
    Student* new_student = (Student*)malloc(sizeof(Student));

    strcpy(new_student->first_name, first_name);
    strcpy(new_student->last_name, last_name);
    strcpy(new_student->phone, phone);
    memcpy(new_student->scores, scores, sizeof(int) * 10);

    new_student->next = class->head;
    class->head = new_student;
    class->count++;
}


void cleanup_class(Class* class) {
    Student *current_student = class->head, *temp;
    while (current_student != NULL) {
        temp = current_student;
        current_student = current_student->next;
        free(temp);
    }
    class->head = NULL;
    class->count = 0;
    free(class); // todo - maybe its more correct to  free it in group
}



