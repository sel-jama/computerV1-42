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
    auto it = displayTerms.begin();

    for (; it != displayTerms.end(); it++){
        tmpCoeff = it->coeff;
        if(it != displayTerms.begin()){
            if(it->coeff < 0) {cout << " - "; tmpCoeff = -tmpCoeff;}
            else cout << " + ";
        }
        cout << tmpCoeff << " * " << "X^" << it->expo ;
    }
    if(it == displayTerms.begin())
        cout << "0";
    cout << " = 0" << endl;
}

void EquationCalculator::getPolynomialDegree(){
    int maxExpo = 0;
    for (auto it = terms.begin(); it!= terms.end(); it++){
        maxExpo = max(maxExpo, it->expo);
    }
    equationDegree = maxExpo;
    if(maxExpo > 0)
        cout << "Polynomial degree: " << equationDegree << endl;
}

void EquationCalculator::solveDegreeZero()
{
    double c = 0;
    if(!terms.empty())
        c = terms.front().coeff;

    if (c == 0)
        cout << "Any real number is a solution.";
    else
        cout << "No solution.";

    cout << endl;
}

void EquationCalculator::solveDegreeOne(){
    double a, b, sol;
    a=b= 0;
    
    for (auto it = terms.begin(); it != terms.end(); it++){
        if (it->expo == 1) a = it->coeff;
        else b=it->coeff;
    }
    if(a == 0){
        solveDegreeZero();
        return ;
    }
    sol = -b/a;
    if(sol == 0) sol = 0;
    cout << "The solution is:" << endl << sol << endl;

}

void EquationCalculator::solveDegreeTwo(){
    double a, b, c, sol1, sol2;
    double discriminant;

    a = b = c = sol1 = sol2 =  discriminant = 0;
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

    if (b==0) b=0;
    if(discriminant > 0){
        sol1 = (-b - mySqrt(discriminant)) / (2*a);
        sol2 = (-b + mySqrt(discriminant)) / (2*a);
        if (myAbs(sol1) < 0.000001) sol1 = 0;
        if (myAbs(sol2) < 0.000001) sol2 = 0;
        cout << "Discriminant is strictly positive, the two solutions are:" << endl;
        cout  << sol1 << endl;
        cout  << sol2 << endl;
    }
    else if (discriminant == 0){
        sol1 = -b / (2*a);
        if (sol1 == 0) sol1 = 0;
        cout << "Discriminant is null, the solution is:" << endl;
        cout << sol1 << endl;
    }
    else {
        cout << "Discriminant is strictly negative, the two complex solutions are:" << endl;
        sol1 = -b/(2*a);
        sol2 = mySqrt(-discriminant)/(2*a);
        if (myAbs(sol1) < 0.000001) sol1 = 0;
        if (myAbs(sol2) < 0.000001) sol2 = 0;

        long n1, d1, n2, d2;
        bool frac1 = toFraction(-b, 2*a, n1, d1);
        bool frac2 = toFraction(mySqrt(-discriminant), 2*a, n2, d2);

        if (frac1 && frac2){
            string realPart = (n1 == 0) ? "0"
                : (d1 == 1 ? to_string(n1) : to_string(n1) + "/" + to_string(d1));
            string imagPart = (d2 == 1) ? to_string(n2) + "i"
                : to_string(n2) + "i/" + to_string(d2);

            cout << realPart << " + " << imagPart << endl;
            cout << realPart << " - " << imagPart << endl;
        }
        else {
            cout << sol1  << " + " << sol2 << "i" << endl;
            cout << sol1 << " - " <<  sol2 << "i" << endl;
        }
    }
}