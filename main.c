#include <stdio.h>
#include "School.h"
#include "main_util.h"


#define STUDENTS_FILE "/Users/yehudanevo/CLionProjects/checkpoint-YehudaNevo/students_with_class.txt"



int main() {

    School school = create_school();
    loadStudentsFromFile(&school,STUDENTS_FILE);
    print_school(&school);
    cleanup_school(&school);

    return 0;
}
