#pragma once
#include "Human.hpp"

class Student : public Human{
protected:
    std::string Name;
    double result;

public:
    Student(const std::string& Name);
    void SetResult(double result);
    std::string GetResult();
    std::vector<std::vector<double>*> GetSolution();
    virtual void studies(const std::string& filename) = 0;
};

class GoodStudent : public Student {
public:
    GoodStudent(const std::string& studentName);
    virtual void studies(const std::string& filename);
};

class NormalStudent : public Student {
public:
    NormalStudent(const std::string& studentName);
    virtual void studies(const std::string& filename);
};

class BadStudent : public Student {
public:
    BadStudent(const std::string& studentName);
    virtual void studies(const std::string& filename);
};