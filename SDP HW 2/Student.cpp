#include "Student.h"

Student::Student() {
	name = new char[0];
	subject = new char[0];
	date = new char[0];
	age = 0;
	grade = 0;
	timestamp = 0;
}

Student::~Student() {
	delete[] name;
	delete[] subject;
	delete[] date;
}

Student::Student(const Student& obj) {
	age = obj.age;
	grade = obj.grade;
	timestamp = obj.timestamp;

	int nameSize = strlen(obj.name) + 1;
	name = new char[nameSize];
	for (int i = 0; i < nameSize; ++i) {
		name[i] = obj.name[i];
	}

	int subjectSize = strlen(obj.subject) + 1;
	subject = new char[subjectSize];
	for (int i = 0; i < subjectSize; ++i) {
		subject[i] = obj.subject[i];
	}

	int dateSize = strlen(obj.date) + 1;
	date = new char[dateSize];
	for (int i = 0; i < dateSize; ++i) {
		date[i] = obj.date[i];
	}

}

Student& Student::operator=(const Student& obj) {
	if (this != &obj) {
		delete[] name;
		delete[] subject;
		delete[] date;

		age = obj.age;
		grade = obj.grade;
		timestamp = obj.timestamp;

		int nameSize = strlen(obj.name) + 1;
		name = new char[nameSize];
		for (int i = 0; i < nameSize; ++i) {
			name[i] = obj.name[i];
		}

		int subjectSize = strlen(obj.subject) + 1;
		subject = new char[subjectSize];
		for (int i = 0; i < subjectSize; ++i) {
			subject[i] = obj.subject[i];
		}

		int dateSize = strlen(obj.date) + 1;
		date = new char[dateSize];
		for (int i = 0; i < dateSize; ++i) {
			date[i] = obj.date[i];
		}

	}

	return *this;
}

void Student::getTimestamp() {
	int size = strlen(date)+1;
	char* t = new char[size];
	for (int i = 0; i < size; ++i) {
		t[i] = date[i];
	}
	
	t[4] = t[7] = '\0';
	struct tm tmdate = { 0 };
	tmdate.tm_year = atoi(&t[0]) - 1900;
	tmdate.tm_mon = atoi(&t[5]) - 1;
	tmdate.tm_mday = atoi(&t[8]);
	timestamp = std::mktime(&tmdate);

	delete[] t;
}
