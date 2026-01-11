#include "header.hpp"

 void EquationParser::loadEquation(char *av){
    string eq;

    if(!av)
        getline(cin, eq);
    else
        eq = string(av);
    this->equation =  eq;
}

int main(int ac, char **av){
    EquationParser equation("");
    Term terms;

    if (ac <= 2){
        equation.loadEquation(av[1]);
        equation.normalizeEquation();
        equation.extractTerms(terms);
    }
    else{
        cerr << "Error: expected exactly one argument" << endl;
        return 1;
    }
}