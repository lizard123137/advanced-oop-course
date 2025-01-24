#include <iostream>
#include <regex>

int main() {
    // 10.1
    std::regex re_float(R"([+-]\d+\.\d+)");
    
    std::cout << "Podaj wyrazenie w ktorym wyszukane zostana liczby zmiennoprzecinkowe: ";
    std::string haystack;
    std::getline(std::cin, haystack);
    
    auto begin = std::sregex_iterator(haystack.begin(), haystack.end(), re_float);
    auto end = std::sregex_iterator();

    for(std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        std::cout << "Liczba zmiennoprzecinkowa: " << match.str() << std::endl;
    }

    // 10.2
    std::regex re_hour(R"(([01][0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?)");

    std::cout << "Podaj wyrazenie w ktorym wyszukana zostanie godzina: ";
    std::getline(std::cin, haystack);

    begin = std::sregex_iterator(haystack.begin(), haystack.end(), re_hour);

    for(std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        std::cout << "Godzina: " << match.str() << std::endl;
    }

    return EXIT_SUCCESS;
}