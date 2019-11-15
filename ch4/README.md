# project 3 introduction

> using ’divide and conquer‘ by multi-threading application. Divide a given array which stored in a txt file.



```
//run random number generator
> ./generator.sh <number of random integers>

// we save random integer in a txt file sample1.txt

> gcc project_phase3.c -o pthread_sort.out
> pthread_sort.out <array_size> sample1.txt <num_pthreads>


//or you can generator default script by Makefile
> make run
// it generate 80 random number and 4 thread for sorting 1 thread for mergring

//clean all generated number in sample1.txt
> make clean
```

running result and anaysis:

we use default paramter in Makefile

generate 20 random numbers, and create 4 threads for sorting, each thread sort 5 numbers,

In each sorting thread we simply called a qsort function which used to sort sub array in divided range.

after sorting different chunk of integers,

 we create another thread which **merge** the sorted subarray and check whole array has been sorted

```
gcc project_phase3.c -o pthread_sort.out
cat /dev/null > sample1.txt
./generator.sh 20
./pthread_sort.out 20 sample1.txt 4



------------------------------output below this line---------------------------------------
339 797 781 536 204 531 727 315 262 520 408 615 610 206 868 922 378 860 299 664 
The thread 16822272 is sorting from 10 to 15 
The sorted array: 
The thread 17358848 is sorting from 15 to 20 

The thread 16285696 is sorting from 5 to 10 
206 The sorted array: 262 315 520 531 727 
This thread 16285696 is executed

The thread 15749120 is sorting from 0 to 5 
The sorted array: 204 339 536 781 797 
This thread 15749120 is executed
The sorted array: 408 610 615 868 
This thread 16822272 is executed
299 378 664 860 922 
This thread 17358848 is executed

output result array204 206 262 299 315 339 378 408 520 531 536 610 615 664 727 781 797 860 868 922 
```



in the program we have 2 functions except main

we read the input of number of thread and create the assigned number of thread within **sort_routine** function and we divide the input array by setting begin pointer and end pointer to each sorting thread.

after creating and executing sorting thread, we create another thread and assign it within **merger** function to merge sorting result into result.