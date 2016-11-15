#include <iostream>
#include <string>

std::string decrypt(std::string input, char key) {
    std::string output;

    for(char& token : input) {
        output += (char)((short)token ^ (short)key);
    }

    std::cout << output << std::endl;

    return output;
}

int main(int argc, char** argv) {

    if(argc < 3) {
        std::cout << "Invalid number of args, please provide a string to be"
            " encrypted, and a single\nchar key" << std::endl;

        return 1;
    } else if(sizeof(argv[2]) > 1) {
        //std::cout << "Key should be single char" << std::endl;

        //return 1;
    }

    decrypt(argv[1], *argv[2]);

    return 0;
}
