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
    // code your abs later
    int a = abs(p);
    int b = abs(q);
    while (a != b){
        if(a>b)
            a = a-b;
        else 
            b = b-a;
    }
    return a;
}
