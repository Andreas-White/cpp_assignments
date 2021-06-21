//-----------------------------------------------------------------------
// File: Grades.cpp
// Summary: Presents the grades of three students after taking as input
// their results on two quizzes, a midterm and a final exam
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-15 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

// Prototypes
double score(int q1, int q2, int mE, int fE);
char grade(double score);

// The student structure
struct Student
{
    int id;
    int quizz1;
    int quizz2;
    int medExam;
    int finalExam;
    double finalScore;
    char finalGrade;
};

int main()
{
    // An array of Student 
    Student sd[3];

    system("CLS");

    // Takes the inputs for each student 
    for (int i = 0; i < 3; i++)
    {
        cout << "enter the student number: ";
        cin >> sd[i].id;

        cout << "enter two 10 point quizzes: " << endl;
        cin >> sd[i].quizz1;
        cin >> sd[i].quizz2;

        cout << "enter the midterm and final exam grades. These are 100 point tests: " << endl;
        cin >> sd[i].medExam;
        cin >> sd[i].finalExam; 
        sd[i].finalScore = score(sd[i].quizz1 ,sd[i].quizz2 ,sd[i].medExam ,sd[i].finalExam);
        sd[i].finalGrade = grade(sd[i].finalScore);
        cout << endl;
    }

    // Prints the elements of each student
    for (int i = 0; i < 3; i++)
    {
        cout << "The record for student number: " << sd[i].id << endl;
        cout << "The quiz grades are: " << sd[i].quizz1 << " " << sd[i].quizz2 << endl;
        cout << "The midterm and exam grades are: " << sd[i].medExam << " " << sd[i].finalExam << endl;
        cout << "The total numeric score is: " << sd[i].finalScore << endl;
        cout << "and the letter grade assigned is: " << sd[i].finalGrade << endl;
        cout << endl;
    }
      
    return 0;
}

// Calculates the final score of each student
double score(int q1, int q2, int mE, int fE)
{
    return ((q1 * 0.25 + q2 * 0.25) * 5)  + mE * 0.25 + fE * 0.5;
}

// Returns the final grade of each student in alphabetical form 
char grade(double score)
{
    if (score >= 90)
    {
        return 'A';
    }else if (score >= 80)
    {
        return 'B';
    }else if (score >= 70)
    {
        return 'C';
    }else if (score >= 60)
    {
        return 'D';
    }else if (score < 60)
    {
        return 'F';
    }
}
