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
    if(maxExpo > 0)
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
    double sol;
    for (auto it = terms.begin(); it != terms.end(); it++){
        if (it->expo == 1) a = it->coeff;
        else b=it->coeff;
    }
    if(a == 0){
        solveDegreeZero();
        return ;
    }
    sol = -b/a;
    cout << "The solution is: " << sol << endl;

}

void EquationCalculator::solveDegreeTwo(){
    double a, b, c, sol1, sol2;
    double discriminant;

    for (auto it = terms.begin(); it != terms.end(); it++){
        if(it->expo == 2) a = it->coeff;
        else if (it->expo == 1) b = it->coeff;
        else c=it->coeff;
    }
    if(a == 0){
        solveDegreeOne();
        return;
    }
    discriminant = b*b - 4*a*c;

    if(discriminant > 0){
        //implement your own sqrt later 
        cout << a<< " " << b << " " << c << endl;
        sol1 = (-b - sqrt(discriminant)) / (2*a);
        sol2 = (-b + sqrt(discriminant)) / (2*a);
        cout << "Discriminant is strictly positive, the two solutions are:" << endl;
        cout  << sol1 << endl;
        cout  <<sol2 << endl;
    }
    else if (discriminant == 0){
        sol1 = -b / (2*a);
        cout << "Discriminant is null, the solution is:" << endl;
        cout << sol1 << endl;
    }
    else {
        cout << "Discriminant is strictly negative, the two complex solutions are:" << endl;
        int gcd1 = getGCD(-b, 2*a);
        int gcd2 = getGCD(sqrt(-discriminant) , 2*a);
        cout << -b/gcd1 << "/" << (2*a)/gcd1 << " + " << sqrt(-discriminant)/gcd2 << "i/" << (2*a)/gcd2 << endl;
        cout << -b/gcd1 << "/" << (2*a)/gcd1 << " - " << sqrt(-discriminant)/gcd2 << "i/" << (2*a)/gcd2 << endl;
    }
}



// 0.905239
// -0.475131

// -1/5 + 2i/5
// -1/5 - 2i/5