#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    double grades[3];
public:
    Student(std::string n, double g1, double g2, double g3) : name(n) {
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }

    void displayGrades() const {
        std::cout << grades[0] << " " << grades[1] << " " << grades[2] << std::endl;
    }

    friend class Teacher;
    friend double calculateAverageGrade(const Student& s);
};

class Teacher {
public:
    void updateGrade(Student& s, int index, double newGrade) {
        if (index >= 0 && index < 3) {
            s.grades[index] = newGrade;
        }
    }
};

double calculateAverageGrade(const Student& s) {
    return (s.grades[0] + s.grades[1] + s.grades[2]) / 3.0;
}

int main() {
    Student s("John", 65.0, 70.0, 60.0);
    
    s.displayGrades();
    std::cout << calculateAverageGrade(s) << std::endl;

    Teacher t;
    t.updateGrade(s, 2, 85.0);
    
    s.displayGrades();
    std::cout << calculateAverageGrade(s) << std::endl;

    return 0;
}
