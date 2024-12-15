#include <iostream>
#include <boost/multi_index_member.hpp>

struct Student {
	std::string index;
	std::string imie;
	std::string nazwisko;
	std::strign plec;
};

typedef multi_index_container<Student, indexed_by<
// Multiset dla naw i set dla index
ordered_non_unique<member<Student, std::string, &Student::imie>,
ordered_unique<member<Student, std::string, &Student::index>,
// multiset nazw i unordered mutiset dla pl
ordered_non_unique<> // TODO finish implementation
ordered_unique<>
> student_multi;

int main() {
	student_multi students;

	students.inser({"	

	return EXIT_SUCCESS;
}
