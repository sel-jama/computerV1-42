#include "header.hpp"

void EquationCalculator::calculateSolution(){
    printReducedForm();
    getPolynomialDegree();
    if(equationDegree > 2)
        cout << "The polynomial degree is strictly greater than 2, I can't solve." << endl;
    else if (equationDegree == 0)
        solveDegreeZero();
    else if(equationDegree == 1)
        solveDegreeOne();
    else if (equationDegree == 2)
        solveDegreeTwo();
    else 
        cout << "The polynomial degree is negative, I can't solve." << endl;

}

void EquationCalculator::printReducedForm(){
    double tmpCoeff;

    cout << "Reduced form: ";
    for (auto it = terms.begin(); it != terms.end(); it++){
        tmpCoeff = it->coeff;
        if(it != terms.begin()){
            if(it->coeff < 0) {cout << " - "; tmpCoeff = -tmpCoeff;}
            else cout << " + ";
        }
        cout << tmpCoeff << " * " << "X^" << it->expo ;
    }
    cout << " = 0" << endl;
}

void EquationCalculator::getPolynomialDegree(){
    int maxExpo = 0;
    for (auto it = terms.begin(); it!= terms.end(); it++){
        if(it->expo > maxExpo) maxExpo = it->expo;
    }
    equationDegree = maxExpo;
    cout << "Polynomial degree: " << equationDegree << endl;
}

void EquationCalculator::solveDegreeZero(){
    double c = 0;
    for (auto it = terms.begin(); it != terms.end(); it++)
        if(it->expo == 0) c = it->coeff;
    if(c==0)
        cout << "Any real number is a solution.";
    else
        cout << "No solution.";
    cout << endl;

}

void EquationCalculator::solveDegreeOne(){
    double a, b;
    for (auto it = terms.begin(); it != terms.end(); it++){
        if(it->expo == 1) a = it->coeff;
        else b = it->coeff;
    }

}

void EquationCalculator::solveDegreeTwo(){}