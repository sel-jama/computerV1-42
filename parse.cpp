#include "header.hpp"

void EquationParser::normalizeEquation(){
    equation.erase(remove(equation.begin(), equation.end(), ' '), equation.end());
    for(char &c: equation)
        c = toupper(c);
    // cout<< this->equation << endl;
    splitEquation();
    addSign();
}

void EquationParser::splitEquation(){

    size_t signPos = equation.find('=');

    if(signPos != string::npos){
        leftSide = equation.substr(0, signPos);
        rightSide = equation.substr(signPos+1);
    }
}

void fillTerms(string &side, vector<string> &allTerms){

    string currentTerm = "";
    
    for(char c: side){
        if(isSign(c) && !currentTerm.empty()){
            allTerms.push_back(currentTerm);
            currentTerm = "";
        }
        currentTerm += c;
    }
    if(!currentTerm.empty())
        allTerms.push_back(currentTerm);
}

void EquationParser::extractTerms(){

    fillTerms(leftSide, allTerms);
    changeRightSigns(rightSide);
    fillTerms(rightSide, allTerms);

    // for(auto it = allTerms.begin(); it != allTerms.end(); it++){
    //     cout << "Term " << *it << endl;
    // }

    //extract coeff and expos
    extractCoeffAndExpo();

    EquationCalculator calculate;
    calculate.setTerms(this->getTerms());

    // for(auto it = terms.begin(); it != terms.end(); it++){
    //     cout << "Coeff: " << it->coeff << " Expo: " << it->expo << endl;
    // }
    calculate.calculateSolution();

}

void EquationParser::extractCoeffAndExpo(){
    map<int, double> m;
    Term t;

    for(string str: allTerms){
        t = parseTerm(str);
        m[t.expo] += t.coeff;
    }

    for(auto term : m){

        if(term.second != 0){
            Term t;
            t.coeff = term.second;
            t.expo = term.first;
            this->terms.push_back(t);
        }
    }
}

Term EquationParser::parseTerm(string &s){
    size_t pos = 0;
    string coeffStr;
    string expoStr;
    char sign = '+';
    Term t ;

    if (isSign(s[0])){
        sign = s[0];
        pos = 1;
    }

    size_t starPos = s.find('*', pos);
    if(starPos == string::npos){
        //just coeff like +4
        coeffStr = s.substr(pos);
        t.coeff = stod(coeffStr);
        if(sign == '-') t.coeff = -t.coeff;
        t.expo = 0;
        return t;
    }

    coeffStr = s.substr(pos, starPos-pos);
    t.coeff = stod(coeffStr);
        if(sign == '-') t.coeff = -t.coeff;
    
    size_t xPos = s.find("X", starPos);
    if(xPos == string::npos){ //check this later, maybe not the best option, try to test 2X+4*4 for example
        t.expo = 0;
        return t;
    } 

    size_t caretPos = s.find('^', xPos);
    if (caretPos == string::npos){
        t.expo = 1;
        return t;
    }
    expoStr = s.substr(caretPos+1);
    t.expo = stoi(expoStr);
    return t;
}