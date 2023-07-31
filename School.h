#include "Group.h"
#ifndef CHECKPOINT_YEHUDANEVO_SCOOL_H
#define CHECKPOINT_YEHUDANEVO_SCOOL_H


typedef struct {
    Group* groups[12];
} School;

School create_school();
void cleanup_school(School* school);
void print_school(School* school);



#endif //CHECKPOINT_YEHUDANEVO_SCOOL_H
