#include <iostream>

using namespace std;

int main() {
    cout << "5 numbers";
    int a, b, c, d, e; /* Declare 5 different variables of type int */
    cin >> a >> b >> c >> d >> e; /* Read values from std input to variables */
    int x; // Declare new variable.
    x = a + b + c + d + e; /* Add other variables together and assign the sum to x*/
    int f; // Declare new variable.
    f = x/5; // Assign the integer quotient of x and 5 to f.
}
