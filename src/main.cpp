#include <iostream>
#include "Student.hpp"
#include "Teacher.hpp"

int main() {
    
    const std::string& filename = "input.txt";
    std::vector< Student*> StudentList;
    Teacher* teacher = new Teacher(filename);

    for(int i = 0; i<10; i++){
        int type = rand() % 3;
        std::string Name = "Name-" + std::to_string(i);
        Student* student = nullptr;
        switch (type) {
            case 0:
                student = new GoodStudent(Name);
                break;
            case 1:
                student = new NormalStudent(Name);
                break;
            case 2:
                student = new BadStudent(Name);
                break;
        }
        StudentList.push_back(student);
    }

    for (const auto& student : StudentList) {
        student->studies(filename);
    }


    for (const auto& student : StudentList) {
        teacher->teach(student);
    }

    for (const auto& student : StudentList) {
        std::cout << student->GetResult() << std::endl;
    }
    
    for (auto& student : StudentList) {
        delete student;
    }
    // delete teacher;

    return 0;
}
