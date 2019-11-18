/**
 * Simulate helping a student
 */

#include <stdio.h>
#include <unistd.h>
#include "ta.h"

void help_student(int sleep_time)
{
    char grade = (char)(65+MAX_SLEEP_TIME-sleep_time);
    int id = student_array[serving_stu].student_id;
    student_array[serving_stu].student_grade = grade;
    printf("Helping a student id = %d for %d seconds waiting students = %d\n", id, sleep_time, waiting_students);
    
    printf("The student %d get a grade %c\n", id, grade);
    sleep(sleep_time);
    
}
