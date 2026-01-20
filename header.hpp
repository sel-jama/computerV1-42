#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <iomanip>

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
        vector<Term> terms;

    public:
        EquationParser(const string &eq) : equation(eq) {}
        // string getLeftSide() const { return leftSide; }
        // string getRightSide() const { return rightSide; }
        // string getEquation() const { return equation; }
        vector<Term> &getTerms() {return terms;}

        void loadEquation(char *av);
        void normalizeEquation();
        void splitEquation();
        void addSign();
        void extractTerms();
        void extractCoeffAndExpo();
        Term parseTerm(string &);
        
};

class EquationCalculator {
    private:
        vector<Term> terms;
        int equationDegree;

    public:
        void setTerms(vector<Term> &parsedTerms) { terms = parsedTerms;}
        void calculateSolution();
        void printReducedForm();
        void getPolynomialDegree();
        void solveDegreeZero();
        void solveDegreeOne();
        void solveDegreeTwo();

};
    
bool isSign(char c);
// char changeSign(char c);
void fillTerms(string &, vector<string> &);
void changeRightSigns(string &);
int getGCD(int p, int q);
double mySqrt(double n);
double myAbs(double n);