#include <stdio.h>
#include <string.h>
#include <math.h>

//global varable setup done outside of functions for ease of use across all functions
int amount_of_students = 5;
int amount_of_exams = 13;
char names[5][10];
int results[5][13]; 
int sums[5];
float averages[5];
float group_average = 0;


/* The below code calculates averages on both individual student
level and at a group level using the index numbers 
(or in case of the 2D arrays, the first index indicated will be the common identifier) 
to identify students, ex all index 0's  will relate to the first student across all arrays.
To keep the input to one line only everything
is kept in a single scanf. A calculation is run to convert a potential
lowercase letter starting the name */
float calculate_average() {
    for (int student = 0; student < amount_of_students; student++)
    {
        scanf("%s %d %d %d %d %d %d %d %d %d %d %d %d %d", 
            names[student], &results[student][0], &results[student][1], &results[student][2], &results[student][3], 
            &results[student][4], &results[student][5], &results[student][6], &results[student][7], &results[student][8], 
            &results[student][9], &results[student][10], &results[student][11], &results[student][12]);

        if(names[student][0] > 96 && names[student][0] < 123) {
            names[student][0] -= 32; 
        }

        for (int exam = 0; exam < amount_of_exams; exam++)
        {
            sums[student] += results[student][exam];
        }

        averages[student] = (float)sums[student] / amount_of_exams;
    }

    int group_sum = 0;
    int group_tests_taken = amount_of_students * amount_of_exams;

    for (int sum = 0; sum < amount_of_students; sum++)
    {
        group_sum += sums[sum];
    }

    group_average = (float)group_sum / group_tests_taken;
}

/* The following block of code will take the averages prepared by the last function
and compare them. The first step finds the highest average, the next prints the name associated with it
and the third finds those performing below average and lists them.

These two are kept separate as in a real life scenario there
might be times when a teacher needs to run only the first function, and not the second, comparitive, function*/

int compare_average() {
    float current_highest_average = 0;
    for (int student_average = 0; student_average < amount_of_students; student_average++)
    {
        if (averages[student_average] >= current_highest_average)
        {
            current_highest_average = averages[student_average];
        } 
    }

    for (int student_high_average = 0; student_high_average < amount_of_students; student_high_average++) {
        if (averages[student_high_average] == current_highest_average) {
            printf("%s\n", names[student_high_average]); 
        }
    }
    
    for (int student_low_average = 0; student_low_average < amount_of_students; student_low_average++) {
        if (averages[student_low_average] < group_average) {
            printf("%s\n", names[student_low_average]);
        }
    }
}

int main() {
    calculate_average();
    compare_average();

    return 0;
}

