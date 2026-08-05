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
    try {
        EquationParser equation("");

        if (ac <= 2){
            equation.loadEquation(av[1]);
            equation.normalizeEquation();
            equation.extractTerms();
        }
        else{
            cerr << "Error: expected exactly one argument" << endl;
            return 1;
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
}