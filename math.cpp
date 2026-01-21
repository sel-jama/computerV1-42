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
    auto it = terms.begin();
    for (; it != terms.end(); it++){
        tmpCoeff = it->coeff;
        if(it != terms.begin()){
            if(it->coeff < 0) {cout << " - "; tmpCoeff = -tmpCoeff;}
            else cout << " + ";
        }
        cout << tmpCoeff << " * " << "X^" << it->expo ;
    }
    if(it == terms.begin())
        cout << "0";
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
    a=b= 0;
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
    cout << "The solution is: " << endl << sol << endl;

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

    if (b==0) b=0; //for -0
    if(discriminant > 0){
        //implement your own sqrt later 
        sol1 = (-b - mySqrt(discriminant)) / (2*a);
        sol2 = (-b + mySqrt(discriminant)) / (2*a);
        if (sol1 == 0) sol1 = 0;
        if (sol2 == 0) sol2 = 0;
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
        if (sol1 == 0) sol1 = 0;
        if (sol2 == 0) sol2 = 0;

        cout << sol1  << " + " << sol2 << "i" << endl;
        cout << sol1 << " - " <<  sol2 << "i" << endl;

        // int gcd1 = getGCD(-b, 2*a);
        // int gcd2 = getGCD(mySqrt(-discriminant) , 2*a);
        // if(gcd1)
        //     cout << -b/gcd1 << "/" << (2*a)/gcd1 << " + " ;
        // else
        //     cout << -b << "/" << 2*a << " + ";

        // if(gcd2)
        //     cout << mySqrt(-discriminant)/gcd2 << "i/" << (2*a)/gcd2 << endl;
        // else
        //     cout << mySqrt(-discriminant) << "i/" << (2*a) << endl;
        
        // if(gcd1)
        //     cout << -b/gcd1 << "/" << (2*a)/gcd1 << " - " ;
        // else
        //     cout << -b << "/" << 2*a << " - " ;
        // if (gcd2)
        //     cout << mySqrt(-discriminant)/gcd2 << "i/" << (2*a)/gcd2 << endl;
        // else
        //     cout << mySqrt(-discriminant) << "i/" << 2*a << endl;

    }
}
