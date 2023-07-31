
#ifndef CHECKPOINT_YEHUDANEVO_GROUP_H
#define CHECKPOINT_YEHUDANEVO_GROUP_H




#include "Class.h"

typedef struct {
    Class* classes[10];
} Group;

Group* create_group();
void cleanup_group(Group* group);




#endif //CHECKPOINT_YEHUDANEVO_GROUP_H
