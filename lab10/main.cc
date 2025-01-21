#include <iostream>
#include <regex>

int main() {
    // 10.1
    std::regex re_float(R"([+-]\d+\.\d+)");
    
    std::cout << "Podaj wyrazenie w ktorym wyszukane zostana liczby zmiennoprzecinkowe: ";
    std::string haystack;
    std::cin >> haystack;
    
    auto begin = std::sregex_iterator(haystack.begin(), haystack.end(), re_float);
    auto end = std::sregex_iterator();

    for(std::sregex_iterator i = begin; i != end; ++i) {
        std::smatch match = *i;
        std::cout << "Liczba zmiennoprzecinkowa: " << match.str() << std::endl;
    }

    return EXIT_SUCCESS;
}