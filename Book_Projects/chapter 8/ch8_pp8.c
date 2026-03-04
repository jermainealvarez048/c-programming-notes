/*
Modify Programming Project 7 so that it prompts for five quiz grades for each of five stu
dents, then computes the total score and average score for each student, and the average
score, high score, and low score for each quiz.
*/

#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_QUIZZES 5

int main(void) {
    int grade[NUM_STUDENTS][NUM_QUIZZES];
    int student, quiz, total, high, low;

    // prompt five quiz grades for each student
    for (student = 0; student < NUM_STUDENTS; student++) {
        printf("Student %d Quiz Scores: ", student + 1);
        for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
            scanf("%d", &grade[student][quiz]);
        }
    }

    // compute total and average score for each student
    printf("\nTotal and Average Score for Each Student\n");
    for (student = 0; student < NUM_STUDENTS; student++) {
        total = 0;
        for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
            total += grade[student][quiz];
        }
        printf("Student %d: Total = %d Average = %d\n", student + 1, total, total / NUM_QUIZZES);
    }

    //average score, high score, and low score for each quiz
    printf("\nAverage, High, and Low Score for Each Quiz\n");
    for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
        total = 0;
        high = grade[0][quiz];
        low = grade[0][quiz];
        for (student = 0; student < NUM_STUDENTS; student++) {
            int score = grade[student][quiz];

            total += score;
            if (score > high)
                high = score;
            if (score < low)
                low = score;
        }
        printf("Quiz %d: Average = %d High = %d Low = %d\n", quiz + 1, total / NUM_QUIZZES, high, low);
    }

    return 0;
}