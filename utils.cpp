#include "header.hpp"

void EquationParser::addSign(){
    if(!leftSide.empty() && !isSign(leftSide[0]))
            leftSide = '+' + leftSide;

    if(!rightSide.empty() && !isSign(rightSide[0]))
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
    // code your myAbs later
    int a = myAbs(p);
    int b = myAbs(q);
    while (a != b){
        if(a>b)
            a = a-b;
        else 
            b = b-a;
    }
    return a;
}

double mySqrt(double n){ 
    if (n < 2) return n;
    double guess = n/2;
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

double myAbs(double n){
    if(n < 0) n = -n;
    return n;

}


// 0.905239
// -0.475131