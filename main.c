#include <stdio.h>
#include <string.h>
#include <math.h>

//global setup done outside of function for ease of use
int amount_of_students = 5;
int amount_of_exams = 13;
char names[5][10]; 
int sums[5];
float averages[5];
float group_average = 0;

float calculate_student_average() {
    

    //for (int student = 0; student < amount_of_students; student++)
    for (int student = 0; student < 1; student++)
    {
        printf("Please input name of student and press ENTER:\n");
        scanf("%s", names[student]);
        names[student][0] -= 32; 


        printf("Please input exam scores:");

        for (int exam = 0; exam < amount_of_exams; exam++)
        {
            int entered_exam_score = 0;
            scanf("%d", &entered_exam_score);
            sums[student] += entered_exam_score;
        }

        printf("The sum for %s is %d\n", names[student], sums[student]);
        averages[student] = (float)sums[student] / amount_of_exams;
        printf("The average for %s is %.1f\n", names[student], averages[student]);
    }
}

int calculate_group_average() {
    //this might have to change
    int group_sum = 0;
    int group_tests_taken = amount_of_students * amount_of_exams;

    for (int sum = 0; sum < amount_of_students; sum++)
    {
        group_sum += sums[sum];
    }

    printf("The combined exam score for everyone in all tests is %d\n", group_sum);
    group_average = (float)group_sum / group_tests_taken;
    printf("The group\'s average is %.1f\n", group_average);
    
}

int main() {
    calculate_student_average();
    calculate_group_average();

    return 0;
}

