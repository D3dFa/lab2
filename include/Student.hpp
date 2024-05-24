#pragma once
#include "Human.hpp"

class Student : public Human{
protected:
    std::string Name;
    float result;

public:
    virtual void studies() = 0;
};

class GoodStudent : public Student {
public:
    GoodStudent(const std::string& studentName);
    virtual void studies();
};

class NormalStudent : public Student {
public:
    NormalStudent(const std::string& studentName);
    virtual void studies();
};

class BadStudent : public Student {
public:
    BadStudent(const std::string& studentName);
    virtual void studies();
};