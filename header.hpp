#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <stdexcept>

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
        vector<Term> displayTerms;

    public:
        EquationParser(const string &eq) : equation(eq) {}
        const string &getEquation() {return equation;}
        const vector<Term> &getTerms() {return terms;}
        const vector<Term> &getDisplayTerms() {return displayTerms;}

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
        vector<Term> displayTerms;
        int equationDegree;

    public:
        void setTerms(const vector<Term> &parsedTerms) { terms = parsedTerms;}
        void setDisplayTerms(const vector<Term> &parsedTerms) { displayTerms = parsedTerms;}
        void calculateSolution();
        void printReducedForm();
        void getPolynomialDegree();
        void solveDegreeZero();
        void solveDegreeOne();
        void solveDegreeTwo();

};
    
bool isSign(char c);
void fillTerms(string &, vector<string> &);
void changeRightSigns(string &);
int getGCD(int p, int q);
double mySqrt(double n);
double myAbs(double n);
double myRound(double n);
bool toFraction(double num, double den, long &n, long &d);
bool isWhiteSpacesOnly(const string& str);