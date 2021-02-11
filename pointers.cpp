// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;
    student.f_name = new char[128];
    student.l_name = new char[128];

    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 1, 9);
    std::cin.ignore();
    std::cout << "Please enter the student's first name: ";
    std::cin.getline(student.f_name, 128);
    std::cout << "Please enter the student's last name: ";
    std::cin.getline(student.l_name, 128);
    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);
    std::cin.ignore();
    std::cout << std::endl;
    student.grades = new double[student.n_assignments];

    int i;
    for (i = 0; i < student.n_assignments; i++)
    {
        std::string message = "Please enter grade for assignment " +  std::to_string(i) + ": ";
        student.grades[i] = promptDouble(message, 1, 1000);
    }

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`
    calculateStudentAverage(&student, &average);
    average = average * 10;
    average = average + 0.5;
    average = (int)average;
    average = average / 10;
    std::cout << std::endl;
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]" << std::endl;
    std::cout <<  "  Average grade: " << average << std::endl;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int num;
    std::cout << message;
    std::cin >> num;
    return num;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double num;
    std::cout << message;
    std::cin >> num;
    return num;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    Student *student = (Student*) object;

    double *doub_ptr = student->grades;
    int i;
    for (i = 0; i < student->n_assignments; i++)
    {
        *avg += doub_ptr[i];
    }
    *avg = *avg / student->n_assignments;
}
