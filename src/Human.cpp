#include "Human.hpp"
#include <cmath>

void Human::read_file(const std::string& filename){
    std::ifstream input(filename);
    std::string line;
    double a,b,c;
    char signB, signC;

    while (std::getline(input, line)) {
        sscanf(line.c_str(), "%lfx^2 %c %lfx %c %lf", &a, &signB, &b, &signC, &c);
        if (signB == '-') { b = -b; }
        if (signC == '-') { c = -c; }
        coeffsVector.push_back(new Сoeffs(a, b, c));
    }

    input.close();
}

void Human::TrueSolution(Сoeffs* coeffs){
    std::vector<double>* Solution = new std::vector<double>({1, 1});
    if (coeffs->a == 0){
        std::vector<double>* Solution = new std::vector<double>({-coeffs->b/coeffs->a});
        solutionVector.push_back(Solution);
        return;
    }
    double discriminant = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;
    double root1, root2;

    if (discriminant > 0) {
        root1 = (-coeffs->b + std::sqrt(discriminant)) / (2 * coeffs->a);
        root2 = (-coeffs->b - std::sqrt(discriminant)) / (2 * coeffs->a);
        std::vector<double>* Solution = new std::vector<double>({root1, root2});
    } else if (discriminant == 0) {
        root1 = -coeffs->b / (2 * coeffs->a);
        std::vector<double>* Solution = new std::vector<double>({root1});
    } else {
        std::vector<double>* Solution = new std::vector<double>({});
    }
    solutionVector.push_back(Solution);
}
void Human::FalseSolution(Сoeffs* coeffs){
    std::vector<double>* Solution = new std::vector<double>({0, 0});
    solutionVector.push_back(Solution);
}

Human::~Human() {
    for (const auto& coeffs : coeffsVector) {
        delete coeffs;
    }
    for (const auto& sol : solutionVector) {
        delete sol;
    }
}