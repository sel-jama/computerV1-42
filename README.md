# 🧮 ComputorV1

A powerful polynomial equation solver that can handle equations up to degree 2, written in C++.

---

## ✨ Features

- **Polynomial Equation Parsing**: Parse and normalize complex polynomial equations
- **Multi-degree Support**: Solve equations of degree 0, 1, and 2
- **Real & Complex Solutions**: Get both real and complex number solutions
- **Term Extraction**: Automatically extract and combine like terms
- **Reduced Form Display**: View equations in their reduced canonical form
- **Custom Math Functions**: Uses custom implementations of `sqrt` and `abs` without external dependencies

---

## 📋 Usage

### Basic Syntax

```bash
./computor "<polynomial equation>"
```

### Examples

#### Degree 0 (Constant)
```bash
./computor "0 * X^0 = 0"
# Output: Any real number is a solution.

./computor "5 = 0"
# Output: No solution.
```

#### Degree 1 (Linear)
```bash
./computor "4 * X^1 = 0"
# Output:
# Reduced form: 4 * X^1 = 0
# Polynomial degree: 1
# The solution is: 0

./computor "2 * X + 3 = 0"
# Output:
# Reduced form: 3 + 2 * X^1 = 0
# Polynomial degree: 1
# The solution is: -1.5
```

#### Degree 2 (Quadratic)
```bash
./computor "1 * X^0 + 1 * X^2 = 0"
# Output:
# Reduced form: 1 * X^0 + 1 * X^2 = 0
# Polynomial degree: 2
# Discriminant is strictly negative, the two complex solutions are:
# 0 + 1i
# 0 - 1i
```

---

## 🛠️ Building

### Prerequisites
- C++ compiler (g++, clang, etc.)
- Make

### Compile
```bash
make
```

### Clean Build
```bash
make clean
make
```

---

## 📁 Project Structure

```
ComputorV1/
├── main.cpp          # Entry point
├── header.hpp        # Header file with class definitions
├── parse.cpp         # Equation parsing and normalization
├── math.cpp          # Equation solving algorithms
├── utils.cpp         # Utility functions
├── Makefile          # Build configuration
└── README.md         # This file
```

---

## 🔧 Core Components

### `EquationParser`
Handles parsing and normalization of equation strings:
- Removes whitespace and converts to uppercase
- Splits equation at the `=` sign
- Extracts individual terms with coefficients and exponents

### `EquationCalculator`
Solves the normalized polynomial equation:
- Calculates the polynomial degree
- Applies appropriate solving algorithm based on degree
- Handles discriminant calculation for quadratic equations
- Computes both real and complex solutions

---

## ✅ Supported Formats

- Simple coefficients: `4 * X^1`
- Degree notation: `X^2`, `X^3`
- Negative terms: `-5 * X^0`
- Multiple terms: `4 * X^1 + 2 * X^0 = 0`
- Whitespace tolerance: `4 * X ^ 1 = 0` (normalized automatically)

---

## ⚠️ Limitations

- **Maximum Degree**: Only solves equations up to degree 2 (quadratic)
- Equations with degree > 2 will be rejected
- Negative discriminant solutions are displayed in complex form (a ± bi)

---

## 📊 Output Examples

### Reduced Form
The solver displays the equation in reduced form with combined like terms:
```
Reduced form: 1 * X^0 + 2 * X^1 + 3 * X^2 = 0
```

### Solution Types

**Positive Discriminant** (2 distinct real solutions):
```
Discriminant is strictly positive, the two solutions are:
-0.5
2.5
```

**Zero Discriminant** (1 repeated real solution):
```
Discriminant is null, the solution is:
1.0
```

**Negative Discriminant** (2 complex conjugate solutions):
```
Discriminant is strictly negative, the two complex solutions are:
-0.5 + 2.5i
-0.5 - 2.5i
```

---

## 🚀 Future Enhancements

- [ ] Support for higher degree polynomials (3+)
- [ ] Fraction-based output for exact solutions
- [ ] Enhanced syntax checking and error messages
- [ ] Graphical visualization of solutions

---

## 📝 License

This project is part of the 42 School curriculum.

---

**Happy solving! 🎓**
