// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <regex>
#include <math.h>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average = 0;

    // Sequence of user input -> store in fields of `student`
    std::string id;
    std::string n_assignments;
    std::string grade;
    int idValid = 0;
    int f_nameValid = 0;
    int l_nameValid = 0;
    int assignmentValid = 0;
    int gradesValid = 0;
    std::string f_name;
    std::string l_name;
    bool validCharCheck;

    while(idValid == 0)
    {

      std::cout << "Please enter the student's id number: ";
      std::getline(std::cin, id);

      //Researched Regular Expressions to teach myself how to use this algorithm.
      validCharCheck = !std::regex_match(id, std::regex("[123456789]+$"));

      if(!validCharCheck)
      {
        if( id.length() > 9)
        {
          printf("Sorry, I cannot understand your answer\n");
        }
        else
        {
          idValid = 1;
        }
      }
      else
      {
        printf("Sorry, I cannot understand your answer\n");
      }
    }

    student.id = std::stoi(id);

    while(f_nameValid == 0)
    {
      std::cout << "Please enter the student's first name: ";
      std::getline(std::cin, f_name);

      //Researched Regular Expressions to teach myself how to use this algorithm.
      validCharCheck = !std::regex_match(f_name, std::regex("^[A-Za-z]+$"));

      if(!validCharCheck)
      {
        f_nameValid = 1;
      }
      else
      {
        printf("Sorry, I cannot understand your answer\n");
      }

    }

    char *holder = new char[f_name.length() + 1];
    std::strcpy(holder, f_name.c_str());
    student.f_name = holder;

    while(l_nameValid == 0)
    {
      std::cout << "Please enter the student's last name: ";
      std::getline(std::cin, l_name);

      //Researched Regular Expressions to teach myself how to use this algorithm.
      validCharCheck = !std::regex_match(l_name, std::regex("^[A-Za-z]+$"));

      if(!validCharCheck)
      {
        l_nameValid = 1;
      }
      else
      {
        printf("Sorry, I cannot understand your answer\n");
      }

    }

    char *holder2 = new char[l_name.length() + 1];
    std::strcpy(holder2, l_name.c_str());
    student.l_name = holder2;

    while(assignmentValid == 0)
    {

      std::cout << "Please enter how many assignments were graded: ";
      std::getline(std::cin, n_assignments);

      validCharCheck = !std::regex_match(n_assignments, std::regex("[123456789]+$"));

      if(!validCharCheck)
      {
        if ( std::stoi(n_assignments) > 2147483647 && std::stoi(n_assignments) < 1)
        {
          printf("Sorry, I cannot understand your answer\n");
        }
        else
        {
          assignmentValid = 1;
        }
      }
      else
      {
        printf("Sorry, I cannot understand your answer\n");
      }

    }

    student.n_assignments = std::stoi(n_assignments);

    int ncount = 0;
    student.grades = new double[std::stoi(n_assignments)+1];
    int index = 0;

    std::cout << "\n";

    while(gradesValid == 0)
    {

      std::cout << "Please enter grade for assignment " << ncount << ": ";
      std::getline(std::cin, grade);

      validCharCheck = !std::regex_match(grade, std::regex("^\\d+\\.?\\d+$"));

      if(!validCharCheck)
      {
        student.grades[index] = std::stod(grade);
        index++;

        if ( ncount == std::stoi(n_assignments)-1)
        {
          gradesValid = 1;
        }

        ncount++;

      }
      else
      {
        printf("Sorry, I cannot understand your answer\n");
      }

    }

    calculateStudentAverage(&student, &average);

    std::cout << "\nStudent: " << student.f_name << " " << student.l_name << " [" << student.id << "]\n";
    printf("  Average grade: %.1f\n", average);

    return 0;
}

void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    Student student = *(Student*)object;

    for(int i = 0; i < student.n_assignments; i++)
    {
      *avg += student.grades[i];
    }

    *avg = (*avg/student.n_assignments);
}
