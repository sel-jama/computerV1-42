#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Term{
    double coeff;
    int expo;
};

class EquationParser {
    private: 
        string equation;
        string leftSide;
        string rightSide;
        vector<string> allTerms;

    public:
        EquationParser(const string &eq) : equation(eq) {}
        string getLeftSide() const { return leftSide; }
        string getRightSide() const { return rightSide; }
        string getEquation() const { return equation; }

        void loadEquation(char *av);
        void normalizeEquation();
        void splitEquation();
        void addSign();
        void extractTerms(Term &);
        
    };
    
bool isSign(char c);
char changeSign(char c);
void fillTerms(string &, vector<string> &);
void changeRightSigns(string &);