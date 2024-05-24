#include "Teacher.hpp"

Teacher::Teacher(const std::string& filename){
    read_file(filename);
    for (const auto& coeffs : coeffsVector) {
        TrueSolution(coeffs);
    }
}

void Teacher::teach(Student* student){
    std::vector<std::vector<double>*> StudentsolutionVector = student->GetSolution();
    if (StudentsolutionVector.size() != solutionVector.size()) {
        return;
    }

    int numSimilar = 0;
    const double eps = 0.1;

    for (int i = 0; i < solutionVector.size(); i++) {
        const std::vector<double>* vec1 = StudentsolutionVector[i];
        const std::vector<double>* vec2 = solutionVector[i];

        bool similar = true;

        if (vec1->size() != vec2->size()) {
            similar = false; 
        }else{
            for (int j = 0; j < vec1->size(); j++) {
                if (std::abs(vec1->at(j) - vec2->at(j)) > eps) {
                    similar = false;
                    break;
                }
            }
        }

        if (similar) {
            numSimilar++;
        }
    }

    float result = (static_cast<float>(numSimilar) / solutionVector.size()) * 100.0f;
    student->SetResult(result);
}