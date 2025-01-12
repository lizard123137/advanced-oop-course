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

std::ostream &operator<<(std::ostream &os, Student const &s) {
	return os << "[" << "\n"
		<< "\t" << "Index: " << s.index << "\n" 
		<< "\t" << "Imie: " << s.imie << "\n" 
		<< "\t" << "Nazwisko: " << s.nazwisko << "\n" 
		<< "\t" << "Plec: " << s.plec << "\n"
		<< "]," << std::endl; 
}

typedef multi_index_container<
	Student,
	indexed_by<
		ordered_non_unique<member<Student, std::string, &Student::nazwisko>>,
		ordered_unique<member<Student, std::string, &Student::index>>,
		ordered_non_unique<member<Student, std::string, &Student::plec>>
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

	nazwisko_type &nazwisko_idx = students.get<0>();
    index_type &index_idx = students.get<1>();
    plec_type &plec_idx = students.get<2>();

    std::cout << "Studenci wg nazwisk (ordered_non_unique):" << std::endl;
	for(auto &it : nazwisko_idx) {
		std::cout << it;
	}

	std::cout << "Studenci wg indeksow (ordered_unique):" << std::endl;
	for(auto &it : index_idx) {
		std::cout << it;
	}

	std::cout << "Studenci wg plci (ordered_unique):" << std::endl;
	for(auto &it : plec_idx) {
		std::cout << it;
	}

	return EXIT_SUCCESS;
}