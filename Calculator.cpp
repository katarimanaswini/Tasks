#include <bits/stdc++.h>
using namespace std;

// Addition Operation
double add(double a, double b)
{
    return a + b;
}
// Subtraction Operation
double subtract(double a, double b)
{
    return a - b;
}
// Multiplication Operation
double multiply(double a, double b)
{
    return a * b;
}
// Division Operation
double divide(double a, double b)
{
    return a / b;
}

int main()
{
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> num2;

    double result;
    bool validOperation = true;

    switch (operation)
    {
    case '+':
        result = add(num1, num2);
        break;
    case '-':
        result = subtract(num1, num2);
        break;
    case '*':
        result = multiply(num1, num2);
        break;
    case '/':
        if (num2 != 0)
        {
            result = divide(num1, num2);
        }
        else
        {
            cout << "Error: Division by zero is not possible." << endl;
            validOperation = false;
        }
        break;
    default:
        cout << "Error: Invalid operator." << endl;
        validOperation = false;
        break;
    }
    if (validOperation)
    {
        cout << "The result is: " << result << endl;
    }
    return 0;
}
