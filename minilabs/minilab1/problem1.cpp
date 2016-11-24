/* Part 1*/

#include <iostream>

using namespace std;

void printFrenchHelloWorld();
void printWeirdString();
double knotsToMPH(double knots);
double celciusToFarenheit(double celcius);

int main() {
    cout << "Q" << endl;

    printFrenchHelloWorld();

    printWeirdString();

    cout << "10 knots is " << knotsToMPH(10.0) << " MPH" << endl;
    cout << "42 degrees celcius is "
         << celciusToFarenheit(42.0)
         << " degrees farenheit" << endl;
}

/* Part 2 */
void printFrenchHelloWorld() {
    cout << "Bonjour, la monde!" << endl;
}

/* Part 3 */
void printWeirdString() {
    cout << "\" \' \\ $ \t\t() \\" << endl;
}

/* Part 4 */
double knotsToMPH(double knots) {
    return knots / 1.151;
}

double celciusToFarenheit(double celcius) {
    return (celcius * (9.0/5.0) + 32);
}
