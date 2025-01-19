#include <iostream>
#include <exception>
#include <limits>
#include <fstream>
#include <regex>

class SumOverflowException : public std::exception {
private:
    std::string message;

public:
    SumOverflowException(const char* msg): message(msg) {}

    const char* what() const throw() {
        return this->message.c_str();
    }
};

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
    int tries_success = 0;
    int tries_failed = 0;

    while(acc < 21) {
        int tmp = 0;

        std::cout << "Aktualna suma: " << acc << std::endl;

        while(true) {
            std::cout << "Podaj liczbe do dodania: ";
            std::cin >> tmp;
            
            if (std::cin) { // If previous cin attempt was a success break out
                tries_success++;
                break;
            } else {
                std::cout << "Nieprawidlowy format wejscia!" << std::endl;
                
                // Clear bad input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                tries_failed++;
            }
        }

        acc += tmp;
    }

    if(acc == 21) {
        std::cout << "Osiagnieto sume 21 przy "
            << tries_success << " udanych probach i "
            << tries_failed << " nieudanych probach"
            << std::endl;
    } else {
        throw SumOverflowException("Suma przekroczyla 21");
    }

    return EXIT_SUCCESS;
}