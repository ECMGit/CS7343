run:
	gcc project_phase3.c -o pthread_sort.out
	cat /dev/null > sample1.txt
	./generator.sh 20
	./pthread_sort.out 20 sample1.txt 4
clean:
	cat /dev/null > sample1.txt
	rm a.out
	rm pthread_sort.out
