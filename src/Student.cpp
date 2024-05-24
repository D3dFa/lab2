#include "Student.hpp"


Student::Student(const std::string& Name) : Name(Name) {}

void Student::SetResult(double result) {this->result = result;}

std::string Student::GetResult() {
    return "Ученик по имени:" + Name + " написал на - " + std::to_string(result);
}

std::vector<std::vector<double>*> Student::GetSolution(){
    return solutionVector;
}


GoodStudent::GoodStudent(const std::string& studentName) : Student(studentName) {}

void GoodStudent::studies(const std::string& filename) {
    read_file(filename);
    for (const auto& coeffs : coeffsVector) {
        TrueSolution(coeffs);
    }
}

NormalStudent::NormalStudent(const std::string& studentName) : Student(studentName) {}

void NormalStudent::studies(const std::string& filename) {
    read_file(filename);
    for (const auto& coeffs : coeffsVector) {
        if(rand()%100 < 55)
            TrueSolution(coeffs);
        else
            FalseSolution(coeffs);
    }
}

BadStudent::BadStudent(const std::string& studentName) : Student(studentName) {}

void BadStudent::studies(const std::string& filename) {
    read_file(filename);
    for (const auto& coeffs : coeffsVector) {
        FalseSolution(coeffs);
    }
}