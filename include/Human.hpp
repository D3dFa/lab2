#pragma once
#include <coeffs.hpp>
#include <iostream>
#include <vector>

class Human {
public:
    ~Human();
protected:
    std::vector<coeffs*> CoefficientsVector;// вектор коэффициентов уравнений
    std::vector<std::vector<double>*> solutionVector;

    void solution();
    void read_file();
};