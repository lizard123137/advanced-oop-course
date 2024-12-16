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

typedef student_multi::nth_index<0>::type nazwisko_idx;
typedef student_multi::nth_index<1>::type index_idx;
typedef student_multi::nth_index<2>::type plec_idx;

int main() {
	student_multi students;

	students.insert({"99532", "Adam", "Nowak", "M"});
	students.insert({"99533", "Adam", "Kowalski", "M"});
	students.insert({"99534", "Karolina", "Nowak", "K"});
	students.insert({"99535", "Karolina", "Piotrkowska", "K"});
	students.insert({"99536", "Anna", "Grudzien", "K"});

	return EXIT_SUCCESS;
}
