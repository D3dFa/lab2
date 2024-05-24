#include "Human.hpp"


Human::~Human() {
    for (const auto& Coeff : CoefficientsVector) {
        delete Coeff;
    }
    for (const auto& sol : solutionVector) {
        delete sol;
    }
}