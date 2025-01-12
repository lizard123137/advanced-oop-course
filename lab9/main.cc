#include <iostream>
#include <fstream>
#include <regex>

int main() {
    // 9.1
    try {
        std::ifstream file("code.txt");
        file.exceptions(std::ifstream::failbit);

        std::regex re(R"(^\s*//)"); // regex to check if line is a comment

        std::string line;
        while(getline(file, line)) {
            if(!std::regex_search(line, re))
                std::cout << line << std::endl;
        }
    } catch(const std::ios_base::failure& e) {
        std::cout << "Failed to open file: " << e.what() << std::endl;
    }

    // 9.2
    int acc = 0;

    while(acc < 21) {
        break; // TODO
    }

    if(acc == 21) {

    } else {

    }

    return EXIT_SUCCESS;
}