/**
 * General structure of a student.
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "ta.h"

void *student_loop(void *param){
//	int *lnumber = (int *)param;
//	int number = *lnumber;
    student *s = (student *)param;
    int index = s->index;
    s->student_id = (unsigned int)pthread_self();
    int number = s->student_id;
//    int id = (unsigned int)pthread_self()
//    int number = atoi(&id);
//    char *grade = s->student_grade;
	int sleep_time;
	int times_through_loop = 0;

	srandom((unsigned)time(NULL));

	while (times_through_loop < 5) {
		sleep_time = (int)((random() % MAX_SLEEP_TIME) + 1);
		hang_out(number,sleep_time);

		/* acquire the mutex lock */
		if ( pthread_mutex_lock(&mutex_lock) != 0)
			printf("StudentA %s\n",strerror(errno));

		if (waiting_students < NUM_OF_SEATS) {
			++waiting_students;
			printf("\t\tStudent %d takes a seat waiting = %d\n",number, waiting_students);
			
            //student semaphore increment, one student is requesting for help
			if (sem_post(students_sem) != 0)
				printf("StudentB %s\n",strerror(errno));
            
            
			if (pthread_mutex_unlock(&mutex_lock) != 0)
				printf("StudentC %s\n",strerror(errno));
            
            //student receiving help
			if (sem_wait(ta_sem) != 0)
				printf("StudentD %s\n",strerror(errno));
            
			serving_stu = index;
			printf("Student %d receiving help\n",number);
			

			++times_through_loop;
		} else {
			printf("\t\t\tStudent %d will try later\n",number);
			pthread_mutex_unlock(&mutex_lock);
		}
	}
}

