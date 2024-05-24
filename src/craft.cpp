#include <iostream>
#include <fstream>

using namespace std;

double randomDouble(double min, double max) {
    return min + (rand() % 100 / 100.0f) * (max-min);
}

void generateQuadraticEquation(ofstream &file) {
    double a, b, c;
    a = randomDouble(-10.0, 10.0);
    b = randomDouble(-10.0, 10.0);
    c = randomDouble(-10.0, 10.0);

    file << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

int main() {

    ofstream inputFile("input.txt"); 

    int numEquations = 100;

    for (int i = 0; i < numEquations; ++i) {
        generateQuadraticEquation(inputFile);
    }

    inputFile.close(); 

    return 0;
}
