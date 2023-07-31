
#ifndef CHECKPOINT_YEHUDANEVO_STUDENT_H
#define CHECKPOINT_YEHUDANEVO_STUDENT_H


typedef struct Student {
    char first_name[50];
    char last_name[50];
    char phone[11];
    int scores[10];
    struct Student *next;  // add a pointer to the next student in the list
} Student;




#endif //CHECKPOINT_YEHUDANEVO_STUDENT_H
