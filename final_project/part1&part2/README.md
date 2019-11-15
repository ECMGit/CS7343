#**CSE 5343/7343, Operating Systems Fall 2019 Project Phase 4** 

##**Part 1 (**basically typing in and running the code provided) Due date: November 21, 2019 

Grading: 50 points 

**Requirements:** 

1. Implement the thread based Programming Project 1 “The Sleeping Teaching Assistant” of Chapter 5 in your text (page 260). The source code is provided in CANVAS in the Parts 1 and 2 directory. 

**To be turned in:** The following is what is to be submitted to CANVAS in the ‘Project 4 – Parts 1 and 2’.

1. The output of the program execution (there are multiple printf statements in the code). 

##**Part 2 (**enhancing part 1) Due date: November 21, 2019 

Grading: 50 points 

**Requirements:** 

1. Modify the program of Part 1 in the following way(s):
    a. Incorporate the transfer of information between the students and the teaching 

assistant using one or more methods of InterProcess Communications (IPC) that we discussed. What should be transferred is the following: 

1. From student to Teaching Assistant – when the student is allowed to see the TA they will pass their Student ID# to the TA. 
2. From the TA to the student – when the TA visits with a student they will pass a “grade” to the student. 

HINT: The easiest way to implement this could be with the use of data structures defined such that there is an array of “Num_Students” structures defined for the students; each student would have a student.studentIDnum and a student.grade field (just an example). The student number can be made up or you could simply use the pthread count as the ID#. The grade value does not matter – just so you pass a value from the TA to the student and can display the results. 

b. Add printf statements to output student ID#s received by the TA as well as printf statements to output the grades assigned by the TA to each student. 

**To be turned in:** The following is what is to be submitted to CANVAS in the ‘Project 4 – Parts 1 and 2’. 

1. The modified source code files; 
2. The output of the program execution with the additional output requirements. 