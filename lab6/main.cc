#include <iostream>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>

using namespace boost::multi_index;

struct Student {
	std::string index;
	std::string imie;
	std::string nazwisko;
	std::string plec;
};

typedef multi_index_container<
	Student,
	indexed_by<
		ordered_non_unique<member<Student, std::string, &Student::nazwisko>>,
		ordered_unique<member<Student, std::string, &Student::index>>,
		ordered_unique<member<Student, std::string, &Student::plec>>
	>
> student_multi;

typedef student_multi::nth_index<0>::type nazwisko_type;
typedef student_multi::nth_index<1>::type index_type;
typedef student_multi::nth_index<2>::type plec_type;

int main() {
	student_multi students;

	students.insert({"99535", "Adam", "Nowak", "M"});
	students.insert({"99212", "Adam", "Kowalski", "M"});
	students.insert({"99523", "Karolina", "Nowak", "K"});
	students.insert({"99755", "Karolina", "Piotrkowska", "K"});
	students.insert({"99333", "Anna", "Grudzien", "K"});

    // Odwolanie domyslnym indexem (pierwszym zdefiniowanym)
    std::cout << "Liczba studentow o nazwisku Nowak: "
        << students.count("Nowak")
        << std::endl;

    // Odwolania za pomoca pozostalych indeksow
    index_type &index_idx = students.get<1>();
    plec_type &plec_idx = students.get<2>();

    auto student = index_idx.find("99535");

    std::cout << "Student o numerze albumu 99535 to: "
        << student->imie << " "
        << student->nazwisko << " "
        << student->plec
        << std::endl;

    // Index typu ordered_unique grupuje rekordy o tej samej wartosci
    std::cout << "Liczba plci wsrod studentow: "
        << plec_idx.size()
        << std::endl;

	return EXIT_SUCCESS;
}
