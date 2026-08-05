#include "header.hpp"

bool isWhiteSpacesOnly(const string& str){
    return str.find_first_not_of("\t\n\r\f\v") == string::npos;
}

void EquationParser::addSign(){
    if(!isSign(leftSide[0]))
            leftSide = '+' + leftSide;

    if(!isSign(rightSide[0]))
            rightSide = '+' + rightSide;
}

bool isSign(char c){
    return (c == '-' || c == '+');
}

void changeRightSigns(string &str){
    for(char &c: str){
        if(isSign(c)){
            if(c == '-') c = '+';
            else c = '-';
        }
    }
}

int getGCD(int p, int q){
    int a = myAbs(p);
    int b = myAbs(q);
    if(!a) return b;
    if(!b) return a;
    
    while (a != b){
        if(a>b)
            a = a-b;
        else 
            b = b-a;
    }
    return a;
}

double myAbs(double n){
    if(n < 0) n = -n;
    return n;

}


double mySqrt(double n){ 
    if (n == 0) return 0;
    double guess = n/2;
    if (guess == 0) guess = n; // avoid division by zero for tiny n
    double x = 0;
    double precision = 0.0001;
    while (true){
        x = (guess + n/guess)/2;
        if (myAbs(x -  guess) < precision)
            break;
        guess = x;
    }
    return x;
}

double myRound(double n){
    if (n >= 0)
        return (double)(long)(n + 0.5);
    return (double)(long)(n - 0.5);
}

// Tries to express num/den as an irreducible fraction n/d.
// Returns false if num or den isn't (close enough to) an integer,
// meaning the value should be displayed as a decimal instead.
bool toFraction(double num, double den, long &n, long &d){
    double roundedNum = myRound(num);
    double roundedDen = myRound(den);
    double epsilon = 0.0001;

    if (myAbs(num - roundedNum) > epsilon || myAbs(den - roundedDen) > epsilon)
        return false;

    long ln = (long)roundedNum;
    long ld = (long)roundedDen;

    if (ld < 0){ ln = -ln; ld = -ld; }
    if (ln == 0){ n = 0; d = 1; return true; }

    int g = getGCD((int)ln, (int)ld);
    if (g != 0){ ln /= g; ld /= g; }

    n = ln;
    d = ld;
    return true;
}