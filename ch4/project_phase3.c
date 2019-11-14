//
//  project_phase3.c
//  cs7343_ch4
//
//  Created by 沈俊豪 on 11/11/19.
//  Copyright © 2019 沈俊豪. All rights reserved.
//

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int list[500];    //list of up to 500 non-negative integers with values 0 <= x <= 1000
int result[500];    //final sorted list
char * messages;    //output from each of the threads for proof of execution

int num_samples;
int num_threads;
static void *sort_routine(void *params);    /* thread that performs basic sorting algorithm */
static void *merger(void *params);    /* thread that performs merging of results */

typedef struct
{
int from_index;
int to_index;
} parameters;



int main(int argc, char *argv[]){
/*Read the value for the number of samples to be sorted;
Read the name of the file that contains the samples to be sorted;
Read the value of the number of threads to create;
*/
    //pthread_sort.out <array_size> <array_source.txt> <num_pthreads>
    num_samples = atoi(argv[1]);
    FILE *f = fopen(argv[2], "r"); // "r" for read
    int i;
    for (i = 0; i < num_samples; i++){
        fscanf(f, "%d,", &list[i]);
        printf("%d ", list[i]);
    }
    
    num_threads = atoi(argv[3]);
    pthread_t workers[num_threads+1];

    parameters *data;

    for(i = 0; i <num_threads; i++) {
        data = (parameters *) malloc (sizeof(parameters));
        data->from_index = i * (num_samples/(num_threads));
        data->to_index = data->from_index + (num_samples/(num_threads));
        pthread_create(&workers[i], 0, sort_routine, data);
    }
    
    for(i = 0; i < num_threads; i++){
        pthread_join(workers[i], NULL);
    }
    
    
    data = (parameters *) malloc (sizeof(parameters));
    data->from_index = 0;
    data->to_index = num_samples;
    pthread_create(&workers[num_threads], 0, merger, data);
    pthread_join(workers[num_threads], NULL);
    
    printf("output result array");
    for(i = 0; i < num_samples; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
/* end of main */
/* Sorting thread */
//Use any sorting routine that you want to use that accepts a starting and an ending index into an array of values. But within the sorting routine you must print to the char * messages value a string that contains the “thread_id” value;
int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);
}

static void *sort_routine(void *params)
{
    parameters *p = (parameters *)params;

    //SORT

    int begin = p->from_index;
    int end = p->to_index;

    printf("\nThe thread %d is sorting from %d to %d \n",(unsigned int)pthread_self(), begin, end);
    // output the array recieved

    //sort the array from begin to end
    qsort(list+begin, end - begin, sizeof(list[0]), cmp);

    // output the array sorted
    int k;
    printf("The sorted array: ");
    for(k = begin; k<end; k++){
        printf("%d ", list[k]);
    }
    printf("\n");
    
    printf("This thread %d is executed\n",(unsigned int)pthread_self());
    pthread_exit(NULL);
}
//for example

/* Merging thread */
//Use any companion merge routine that works with the multiple blocks of data sorted by the sorting thread.
static void *merger(void *params)
{

   //MERGE
    //merge all sorted subarray
    qsort(list, num_samples, sizeof(list[0]), cmp);
    int m;
    for(m=0; m<num_samples; m++)
    {
        result[m] = list[m];
    }
    pthread_exit(NULL);
}
