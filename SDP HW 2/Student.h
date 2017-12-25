#include<iostream>
#include <ctime>

#pragma once
class Student {
public:
	Student();
	~Student();
	Student(const Student&);
	Student& operator=(const Student&);

public:
	void getTimestamp();

public:
	char* name;
	int age;
	char* subject;
	int grade;
	char* date;
	time_t timestamp;
};

