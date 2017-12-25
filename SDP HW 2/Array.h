#include "Student.h"

#pragma once
class Array {
public:
	Array();
	~Array();

private:
	Array(const Array&);
	Array& operator=(const Array&);

public:
	void add(Student&);
	void print();

public:
	void sortGrade(bool);
	void sortAge(bool);
	void sortDate(bool);
	void sortName(bool);
	void sortSubject(bool);

private:
	void buckedSort(bool);
	void heapSort(bool);
	void heapify(int,int, bool);
	void quickSort(int,int, bool);
	long partition(int, int, bool);
	void selectionSortForName(bool);
	void selectionSortForSubject(bool);

private:
	void swap(Student&, Student&);
	void insureSpace();
	Student& get(int);

private:
	int size;
	int capacity;
	Student* arr;
};

