#pragma once
#include "Human.hpp"
#include "Student.hpp"

class Teacher : public Human {
private:

public:
    Teacher(const std::string& filename);
    void teach(Student* student);
};