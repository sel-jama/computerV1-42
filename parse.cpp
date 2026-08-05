#include "header.hpp"

void EquationParser::normalizeEquation(){
    equation.erase(remove(equation.begin(), equation.end(), ' '), equation.end());
    if(equation.empty() || isWhiteSpacesOnly(equation))
        throw invalid_argument("Empty equation");
    for(char &c: equation)
        c = toupper(c);
    splitEquation();
    addSign();
}

void EquationParser::splitEquation(){

    size_t signPos = equation.find('=');

    if(signPos != string::npos){
        leftSide = equation.substr(0, signPos);
        rightSide = equation.substr(signPos+1);
    }
    else
        throw invalid_argument("Equation must contain '=' sign");

    if (leftSide.empty() || rightSide.empty())
        throw invalid_argument("Equation must have both left and right sides");
}

void fillTerms(string& side, vector<string>& allTerms)
{
    string currentTerm;

    for (string::iterator it = side.begin(); it != side.end(); ++it)
    {
        if (isSign(*it) && !currentTerm.empty())
        {
            allTerms.push_back(currentTerm);
            currentTerm.clear();
        }
        currentTerm += *it;
    }

    if (!currentTerm.empty())
        allTerms.push_back(currentTerm);
}

void EquationParser::extractTerms(){

    fillTerms(leftSide, allTerms);
    changeRightSigns(rightSide);
    fillTerms(rightSide, allTerms);

    //extract coeff and expos
    extractCoeffAndExpo();

    EquationCalculator calculate;

    calculate.setTerms(this->getTerms());
    calculate.setDisplayTerms(this->getDisplayTerms());

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

        Term dt;
        dt.coeff = term.second;
        dt.expo = term.first;
        this->displayTerms.push_back(dt);

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

    if (s.empty())
        throw invalid_argument("Empty term");

    if (isSign(s[0])){
        sign = s[0];
        pos = 1;
    }

    size_t starPos = s.find('*', pos);
    size_t xPos = s.find('X', pos);

    if(starPos == string::npos){


        if(xPos == string::npos){
            // pure number, e.g. "+4", "-9.3"
            coeffStr = s.substr(pos);
            try {
                t.coeff = stod(coeffStr);
            } catch (const invalid_argument&) {
                throw invalid_argument("Invalid coefficient in term: '" + s + "'");
            } catch (const out_of_range&) {
                throw out_of_range("Coefficient out of range in term: '" + s + "'");
            }
            if(sign == '-') t.coeff = -t.coeff;
            t.expo = 0;
            return t;
        }

        // has an X but no '*', e.g. "X", "-X", "2X", "X^2"
        coeffStr = s.substr(pos, xPos - pos);
        if(coeffStr.empty())
            t.coeff = 1;
        else {
            try {
                t.coeff = stod(coeffStr);
            } catch (const invalid_argument&) {
                throw invalid_argument("Invalid coefficient in term: '" + s + "'");
            } catch (const out_of_range&) {
                throw out_of_range("Coefficient out of range in term: '" + s + "'");
            }
        }
        if(sign == '-') t.coeff = -t.coeff;

        size_t caretPos = s.find('^', xPos);
        if (caretPos == string::npos){
            t.expo = 1;
            return t;
        }
        expoStr = s.substr(caretPos+1);
        try {
            t.expo = stoi(expoStr);
        } catch (const invalid_argument&) {
            throw invalid_argument("Invalid exponent in term: '" + s + "'");
        } catch (const out_of_range&) {
            throw out_of_range("Exponent out of range in term: '" + s + "'");
        }
        return t;
    }

    coeffStr = s.substr(pos, starPos-pos);
    try {
        t.coeff = stod(coeffStr);
    } catch (const invalid_argument&) {
        throw invalid_argument("Invalid coefficient in term: '" + s + "'");
    } catch (const out_of_range&) {
        throw out_of_range("Coefficient out of range in term: '" + s + "'");
    }
    if(sign == '-') t.coeff = -t.coeff;

    // size_t xPos = s.find("X", starPos);
    if(xPos == string::npos){
        throw invalid_argument("Invalid term, expected 'coeff * X^expo': '" + s + "'");
    } 

    size_t caretPos = s.find('^', xPos);
    if (caretPos == string::npos){
        t.expo = 1;
        return t;
    }
    expoStr = s.substr(caretPos+1);
    try {
        t.expo = stoi(expoStr);
    } catch (const invalid_argument&) {
        throw invalid_argument("Invalid exponent in term: '" + s + "'");
    } catch (const out_of_range&) {
        throw out_of_range("Exponent out of range in term: '" + s + "'");
    }
    return t;
}