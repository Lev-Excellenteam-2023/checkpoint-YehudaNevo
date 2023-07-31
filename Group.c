#include "Group.h"
#include <stdlib.h>

Group* create_group() {
    Group* group = (Group*)malloc(sizeof(Group));
    for(int i = 0; i < 10; i++) {
        group->classes[i] = create_class();
    }
    return group;
}

void cleanup_group(Group* group) {
    for (int i = 0; i < 10; i++) {
        cleanup_class(group->classes[i]);
        //free(group->classes[i]); // todo - maybe its more correct to  free it in group
    }
    free(group);
}