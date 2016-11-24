#include <iostream>

static int total = 0;

int accumulator(int additive) {
    total += additive;

    if (total > 1000) {
        return 1;
    }

    return 0;
}

int main() {

}
