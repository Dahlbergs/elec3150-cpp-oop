/* * ELEC3071: Lab 1
 * Author: Samuel Dahlberg
 * Desc: Demonstrate a looping algorithm which swaps the outermost entries in an
 * array or variable size.
 */

#include <iostream>

int main() {

    // Define number of elements in the array.
    const int n = 20;

    int arr1[n];

    // Initialize the array with values from 0 to n
    for(int i = 0; i < n; i++) {
        arr1[i] = i;
    }

    // Print out array contents before swap.
    std::cout << "=== Before Swap ===" << std::endl;

    for(int i = 0; i < n; i++) {
        std::cout << "Array element " << i << ": " << arr1[i] << std::endl;
    }

    // Loop through half of the array, swapping the outermost values.
    for(int i = 0; i < (n / 2); i++) {
        // Temporarily store array value;
        int temp = arr1[i];3
        // Replace current index with outermost
        arr1[i] = arr1[(n - 1) - i];
        // Replace outermost index with current
        arr1[(n - 1) - i] = temp;
    }

    // Print out array contents after swap.
    std::cout << "=== After swap ===" << std::endl;

    for(int i = 0; i < n; i++) {
        std::cout << "Array element " << i << ": " << arr1[i] << std::endl;
    }
}
