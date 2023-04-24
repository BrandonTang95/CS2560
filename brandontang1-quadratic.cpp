// 
//  Name:   Tang, Brandon 
//  Project:  1
//  Due:        2/10/23
//  Course:  cs-2560-01-sp23 
// 
//  Description: 
//     A program that prompts the user for the coefficients a, b, and c of a quadratic equation and prints out the solution.
// 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
       int a, b, c;
       double disc;
       double x1, x2;
       cout << "Quadratic Equation Solver by Brandon Tang" << endl;
       cout << endl;
       cout << "Enter values for a b c? ";
       cin >> a >> b >> c;
       cout << endl;

       disc = b * b - (4 * a * c);

       x1 = (-b + sqrt(disc)) / (2 * a);
       x2 = (-b - sqrt(disc)) / (2 * a);

       if (a == 0)
       {
              cout << "Not a quadratic equation." << endl;
       }
       else if (disc < 0)
       { 
              cout << "Roots are imaginary." << endl;
       }
       else
       {
              cout << fixed << "The roots are " << setprecision(2) << x1 << " and " << setprecision(2) << x2 << ".";
       }
       
       return 0;
}
