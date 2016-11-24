#include <iostream>

/* Problem 1 */

void validateGradeIfs(char grade) {
    if (grade == 'A') {
        std::cout << "100-90" << std::endl;
    } else if (grade == 'B') {
        std::cout << "89-80" << std::endl;
    } else if (grade == 'C') {
        std::cout << "79-70" << std::endl;
    } else if (grade == 'D') {
        std::cout << "69-60" << std::endl;
    } else if (grade == 'F') {
        std::cout << "60-0" << std::endl;
    } else {
        std::cout << "Invalid grade" << std::endl;
    }
}

void validateGradeSwitch(char grade) {
    switch(grade) {
    case 'A':
        std::cout << "100-90" << std::endl;
        break;
    case'B':
        std::cout << "89-80" << std::endl;
        break;
    case'C':
        std::cout << "79-70" << std::endl;
        break;
    case'D':
        std::cout << "69-60" << std::endl;
        break;
    case'F':
        std::cout << "60-0" << std::endl;
        break;
    default:
        std::cout << "Invalid grade" << std::endl;
    }
}

/* Problem 2 */

int main() {
    int number;
    std::cout << "Enter a number ";
    std::cin >> number;
    if(number == 10) // <-- Bug: Using assignment operator instead of comparison equals
        std::cout << "?!?!?!" << std::endl;
    if(number < 10)
        std::cout << "!!!!!!" << std::endl;
    if(number > 10)
        std::cout << "??????" << std::endl;
}

/* Problem 3 & 4*/
/* This will produce the output of:
   "Not!" since the postfix operator gets evaluated after the comparison.
   If you change to the prefix notation, the increment happens first, and
   then the comparison, making an output of "Greater!" */
void postVsPrefixPlusPlus() {
    int x = 5;

    if (x++ > 5) {
        std::cout << "Greater!";
    } else {
        std::cout << "Not!";
    }
}

/* Problem 5 */
/* Rank 1: While loop.
   While loops are the most versatile and can be used to make any other the
   other loops with additional code.

   Rank 2: For loop.
   For loops are used very commonly and are useful for iterating over arrays and
   other containers. They can be mimiced using a while loop but their design
   makes iteration faster and easier.

   Rank 3: Do while loops.
   Do while loops are useful in very particular situations. They are less
   versatile than the other loops and are used less because they can be
   confusing.

*/
