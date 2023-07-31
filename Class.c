#include "Class.h"
#include <stdlib.h>
#include <string.h>


Class* create_class() {
    Class* class = (Class*)malloc(sizeof(Class));
    class->students = NULL;
    class->count = 0;
    class->size = 0;
    return class;
}



void add_student(Class* class, char* first_name, char* last_name, char* phone, int scores[10]) {
    if(class->count == class->size) {
        class->size = class->size * 2 + 1;
        class->students = (Student*)realloc(class->students, class->size * sizeof(Student));
    }
    strcpy(class->students[class->count].first_name, first_name);
    strcpy(class->students[class->count].last_name, last_name);
    strcpy(class->students[class->count].phone, phone);
    memcpy(class->students[class->count].scores, scores, sizeof(int) * 10);
    class->count++;
}

void cleanup_class(Class* class) {
    free(class->students);
    class->students = NULL;
    class->count = 0;
    class->size = 0;
}


