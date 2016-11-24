/* Question 1 */

#include <iostream>

int main() {
    char char_array[] = {'D', 'A', 'H', 'L', 'B', 'E', 'R', 'G'};

    size_t size = sizeof(char);

    char *ptr = &char_array[0];

    std::cout << "{";
    for (int i = 0; i < 8; i++) {
        std::cout << *(ptr + (i * size));

        if (i < 7) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}
