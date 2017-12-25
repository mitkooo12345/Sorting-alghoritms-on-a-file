#include <iostream>
#include <fstream>
#include "Array.h"

void readFile(std::ifstream& file, Array& arr);

int main() {
	std::ifstream file;
	Array arr;

	char fileNameBuffer[500];
	std::cin >> fileNameBuffer;

	file.open(fileNameBuffer);
	if (file.is_open()) {
		readFile(file, arr);
	}
	file.close();

	char columBuffer[10];
	std::cin >> columBuffer;

	char orderBuffer[6];
	std::cin >> orderBuffer;

	if (!strcmp(columBuffer, "name")) {
		if (!strcmp(orderBuffer, "asc")) {
			arr.sortName(true);
		} else {
			arr.sortName(false);
		}

	} else if (!strcmp(columBuffer, "age")) {
		if (!strcmp(orderBuffer, "asc")) {
			arr.sortAge(true);
		} else {
			arr.sortAge(false);
		}

	} else if (!strcmp(columBuffer, "subject")) {
		if (!strcmp(orderBuffer, "asc")) {
			arr.sortSubject(true);
		} else {
			arr.sortSubject(false);
		}

	} else if (!strcmp(columBuffer, "grade")) {
		if(!strcmp(orderBuffer, "asc")) {
			arr.sortGrade(true);
		} else {
			arr.sortGrade(false);
		}

	} else if (!strcmp(columBuffer, "date")) {
		if (!strcmp(orderBuffer, "asc")) {
			arr.sortDate(true);
		}else {
			arr.sortDate(false);
		}
	}

	arr.print();

	return 0;
}

void readFile(std::ifstream& file, Array& arr) {

	char dummyLine[35];
	file.getline(dummyLine, 35);

	for (int i = 0; !file.eof(); ++i) {

		Student student;

		//name
		char nameBuffer[50];
		file.getline(nameBuffer, 50, ',');
		int size = strlen(nameBuffer) + 1;
		student.name = new char[size];
		for (int i = 0; i < size; ++i) {
			student.name[i] = nameBuffer[i];
		}

		//age
		file >> student.age;
		file.seekg(1, std::ios::cur);

		//subject
		char subjectBuffer[10];
		file.getline(subjectBuffer, 10, ',');
		size = strlen(subjectBuffer) + 1;
		student.subject = new char[size];
		for (int i = 0; i < size; ++i) {
			student.subject[i] = subjectBuffer[i];
		}

		//grade
		file >> student.grade;
		file.seekg(1, std::ios::cur);

		//date
		char dateBuffer[15];
		file.getline(dateBuffer, 15);
		size = strlen(dateBuffer) + 1;
		student.date = new char[size];
		for (int i = 0; i < size; ++i) {
			student.date[i] = dateBuffer[i];
		}

		arr.add(student);
	}
}