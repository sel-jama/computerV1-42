#include "header.hpp"

void EquationParser::normalizeEquation(){
    equation.erase(remove(equation.begin(), equation.end(), ' '), equation.end());
    for(char &c: equation)
        c = toupper(c);
    cout<< this->equation << endl;
    splitEquation();
    addSign();
    cout << "left side : " << leftSide<< endl << "Righ side : " << rightSide << endl;
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

void EquationParser::extractTerms(Term &terms){

    fillTerms(leftSide, allTerms);
    changeRightSigns(rightSide);
    fillTerms(rightSide, allTerms);

    for(auto it = allTerms.begin(); it != allTerms.end(); it++){
        cout << "Term " << *it << endl;
    }
    //extract coeff and expos
}