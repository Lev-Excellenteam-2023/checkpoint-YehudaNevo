#ifndef CHECKPOINT_YEHUDANEVO_CLASS_H
#define CHECKPOINT_YEHUDANEVO_CLASS_H

#include "Student.h"

typedef struct {
    Student* head;
    int count;
} Class;

Class* create_class();
void add_student(Class* class, char* first_name, char* last_name, char* phone, int scores[10]);
void cleanup_class(Class* class);




#endif //CHECKPOINT_YEHUDANEVO_CLASS_H
