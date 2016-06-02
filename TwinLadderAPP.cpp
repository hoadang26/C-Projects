//Program: Twin Ladder Problem Solver
//Date: 04/07/2016
//Name: Hoa (Violet) Dang

#include <iostream>
#include <cmath>

using namespace std;
//function prototype
void welcome();
void validatex(double x);


int main() {
    double x,a,b;
    double dx;
    dx = .125;
    double closeness;
    double h;

    welcome();
    cout << "Enter a guess for the valley width (between 0 and 12): ";
    cin >> x;
    validatex(x);

    do
    {
        double x2 = x*x;
        a = sqrt(400-x2);
        b = sqrt(900-x2);

        h = (a*b*x)/((a*x)+(b*x));
        cout << "The new height is: " << h << endl;

        closeness = h-10;

        if (abs(closeness) <= dx) {
            cout << "The closest possible alley width is : " << x << endl;
            break;
        }
        else
            x = x+dx;
            cout << "the new x is: " << x << endl;}

    while (true);

    return 0;
}

void welcome() {
    cout << "Welcome to the Twin Ladder Problem Solver" << endl << endl;
    cout << "How it works: " << endl;
    cout << "You will enter a guess for the alley width" << endl;
    cout << "The program will increment the number by 0.125 until it reaches the closest possible valley width" << endl;
    cout << endl << endl;
}

void validatex(double x) {
    if (x<=12 && x>=0) {
        cout << "You entered: " << x <<endl; }
    else {
        cout << "You have entered an invalid input" << endl;
        cout << "Please enter a number between 0 and 12: ";
        cin >> x;
    }

}
