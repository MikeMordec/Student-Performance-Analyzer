//============================================================================
// Name        : PE_8-13.cpp
// Author      : Mike Mordec
// CSC 155-001 : Lab 7 - CSC 155 - CS Dept. Oakton Comunity College
// Date        : 11/10/22
// Description : Write a program to calculate students' average test scores and their grades
//============================================================================

//Header files
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<math.h>
//namespace statement.
using namespace std;
const int numTests = 5;
const int numStudents = 10;
// Theses are function prototypes
void getData(ifstream &inFile, string names[numStudents], double tests[numStudents][numTests + 1]); //#1
double calculateAverage(double tests[]); //#2
char getLetterGrade(double grade);
void printTests(ofstream &outFile, string names[numStudents], double tests[numStudents][numTests + 1], char grade[numStudents], double classAverage); //#3
int main()
{
// Declaring stream files
ifstream inFile;
inFile.open ("ch8_Ex13Data.txt");
// opens the input file
ofstream outFile;
outFile.open ("Ch8_Ex13Out.txt");
// Opens the output file
string names[numStudents];
double tests[numStudents][numTests + 1];
char grade[numStudents];
//declaring arrays
if(!inFile.is_open())
{
//Terminates the program
cout << "Error in opening file.";
cout << "Program terminates." << endl;
return 1;
} // Display an error if the input file does not open.
getData(inFile, names, tests); //gets data into arrays
// Declaring Variables
double runningAverage = 0.0, classAverage = 0.0;
for(int i = 0; i < numStudents; i++)
{
tests[i][numTests] = calculateAverage(tests[i]); //storing the average in the last element of the tests array
grade[i] = getLetterGrade(tests[i][numTests]); //gets letter grade
runningAverage += tests[i][numTests]; //adds up all the averages from students
}
classAverage = runningAverage / numStudents; //calcs class average
printTests(outFile, names, tests, grade, classAverage); //prints results
return 0;
}
//reads in student test tests and name
void getData(ifstream &inFile, string names[numStudents], double tests[numStudents][numTests + 1])
{
for(int i = 0; i < numStudents; i++)
{
inFile >> names[i]; //gets name
for(int j = 0; j < numTests ; j++)
{
inFile >> tests[i][j]; //gets test tests
}
}
inFile.close (); //closing data file
}
// average the test tests for the student
double calculateAverage(double tests[numTests])
{
double total = 0;
double average = 0.0;
for(int i = 0; i < numTests; i++)
{
total += tests[i]; //gets test tests and adds to running total
}
average = total / numTests; //calcs the average
return average; //returns the average
}
// determines and returns the students letter grade
char getLetterGrade(double grade)
{
if (grade < 60)
return 'F';
else if (grade < 70)
return 'D';
else if (grade < 80)
return 'C';
else if (grade < 90)
return 'B';
else
return 'A';
}
void printTests(ofstream &outFile, string names[numStudents], double tests[numStudents][numTests + 1], char grade[numStudents], double classAverage)
{
//align the names to the left
cout.setf(ios::left);
cout << fixed << showpoint << setprecision (2);
cout << setw(10) << "Name" << setw(9);
cout.unsetf(ios::left);
//align the test headings to the right
cout.setf(ios::right);
cout << "Test 1" << setw(8) << "Test 2" << setw(8) << "Test 3" << setw(8) <<"Test 4" << setw(8) << "Test 5" << setw(11) << "Average" << setw(8) << "Grade" << endl;
//align the names to the left
outFile.setf(ios::left);
outFile << fixed << showpoint << setprecision (2);
outFile << setw(10) << "Name" << setw(9);
//align the test headings to the right
outFile.setf(ios::right);
outFile << "Test 1" << setw(8) << "Test 2" << setw(8) << "Test 3" << setw(8) <<"Test 4" << setw(8) << "Test 5" << setw(11) << "Average" << setw(8) << "Grade" << endl;
// Read and write a students name from the input file
for(int i = 0; i < numStudents; i++)
{
cout.unsetf(ios::right);
cout.setf(ios::left); //align the names to the left
cout << setw(10) << names[i] << setw(9);
cout.unsetf(ios::left);
cout.setf(ios::right); //align the tests to the right
cout << fixed << showpoint << setprecision (2);
outFile.unsetf(ios::right);
outFile.setf(ios::left); //align the names to the left
outFile << setw(10) << names[i] << setw(9);
outFile.unsetf(ios::left);
outFile.setf(ios::right); //align the tests to the right
outFile << fixed << showpoint << setprecision (2);

for(int j = 0; j < numTests + 1; j++)
{
if(j == numTests) //if it's time to print the average of the tests, needs special formatting
{
cout << setw(11) << tests[i][j];
cout << setw(6) << grade[i] << endl;
outFile << setw(11) << tests[i][j];
outFile << setw(6) << grade[i] << endl;
}
else //otherwise just print the test score
{
cout << tests[i][j] << setw(8);
outFile << tests[i][j] << setw(8);
}
}
}
cout << "\n\nClass average: " << classAverage << endl << endl;;
outFile << "\n\nClass average: " << classAverage << endl << endl; //class average
outFile.close (); //closing output file
}
