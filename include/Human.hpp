#pragma once
#include <Сoeffs.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class Human {
public:
    ~Human();

protected:
    std::vector<Сoeffs*> coeffsVector;
    std::vector<std::vector<double>*> solutionVector;

    void read_file(const std::string& filename);

    void TrueSolution(Сoeffs* coeffs);
    void FalseSolution(Сoeffs* coeffs);
};