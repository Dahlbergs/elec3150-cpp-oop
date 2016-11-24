#include <iostream>

int* bubbleSort(int *array, int length) {
    int sorted = false;

    while(!sorted) {
        sorted = true;

        for(int i = 0; i < length; i++) {
            if (i != (length - 1)) {
                if (array[i] > array[i+1]) {
                    sorted = false;
                    int temp = array[i];
                    array[i] = array[i+1];
                    array[i+1] = temp;
                }
            }
        }
    }

    return array;
}

int main() {
    int int_array[] = {100,75,25,50,0};

    int* sorted_array = bubbleSort(int_array, 5);

    std::cout << "{";
    for(int i = 0; i < 5; i++) {
        std::cout << sorted_array[i] << " ,";
    }
    std::cout << "}" << std::endl;
}
