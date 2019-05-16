# Authomatic-Course-Planner
Make a class, course SCHEDULE
----------------------------------------------
In this project, you will implement an automatic course planner for a curriculum semester of a department. 
In the curriculum, there are several courses for each year of the curriculum. Your program will assign a 
classroom and a time slot for each course in the curriculum. Courses in the same year should not be intersected 
with each other. There can be some intersection between courses of different years. 
There are 2 different types of the classroom; big and small. Mandatory courses in the curriculum should be assigned 
to a big classroom. Elective courses can be assigned to a big or small classroom according to the availability of them.
There is a limited number of dedicated classrooms for the department. The number of each type of classroom should be 
read from a file. In addition, for each weekday there are 2-time slots available; morning and afternoon. So there are 
in total 10 time slots available to place a course (5 weekdays*2). 
In the department curriculum, there are some service courses which are given by another department at the university. 
The time slot of these courses is fixed and predefined. Therefore, you cannot assign different time slots for those 
courses other than the requested time slot. Furthermore, some instructors may not available for some time slots. 
Thus, your program should respect these busy time slots for the respective courses.  All of these constraints should 
be taken from a file. You should not assume anything in prior and not use any hard-coded parameter in your code. 
In the end, your program will produce a file which contains a course schedule for the department. In this schedule, 
there should not be any intersection between courses for a year of the curriculum and respect to all constraints. 
If your program cannot find any possible schedule it will print a message “There is no way to make a perfect 
schedule for the department.” 
1.Format of the files; 
a. Courses.csv contains all courses in the curriculum. Each line has 7 items separated by ‘;’, from left to right; code of the course, name of the course, the year of the semester, credit, C: compulsory or E: Elective, D: department or S: service, name of the instructor. 
CENG104;COMPUTER PROGRAMMING II;1;6;C;D;OGR.GOR. YUSUF EVREN AYKAC 
CHEM101;GENERAL CHEMISTRY;1;5;C;S;DOC.DR. NURAY CELEBI 
CENG316;PARALLEL PROGRAMMING;3;5;E;D;DR. OGR. UYESI FAHREDDIN SUKRU TORUN … 
b. Service.csv contains time slot of service courses.  
Format of it as follows: 
CHEM101;Tuesday;Morning 
MATH102;Monday;Afternoon … 
c. Busy.csv contains the busy time slots for the respective course. You cannot assign a course to the specified time slot. That is, for example, 
CENG104 should not be placed on Tuesday according to the below file. 
CENG104;Tuesday;Morning 
CENG104;Tuesday;Afternoon 
CENG316;Friday;Afternoon 
CENG206;Monday;Morning 
d. Classroom.csv contains the number of classrooms for each type. For example, the following file means that there are 2 big classrooms and 1 small classroom.  
bigClass;2 
smallClass;1 
4. Your output should be ordered by weekdays and then classroom Id. 
The sample output file:  
Monday Morning bigClass1 CENG104  
Monday Morning bigClass2 CENG202  
Monday Morning smallClass1 CENG310  
Monday Afternoon bigClass1 MATH102  
Monday Afternoon bigClass2 ENGR202  
Monday Afternoon smallClass1 CENG415  
Tuesday Morning bigClass1 CHEM101  
Tuesday Morning bigClass2 --------  
Tuesday Morning smallClass1 CENG317  
Tuesday Afternoon bigClass1 ENG254  
Tuesday Afternoon bigClass2 CENG204 
Tuesday Afternoon smallClass1 --------  
Wednesday Morning bigClass1 TIT101  
Wednesday Morning bigClass2 --------  
… 
