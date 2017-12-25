#include "Array.h"

Array::Array() {
	size = 0;
	capacity = 0;
	arr = new Student[0];
}

Array::~Array() {
	delete[] arr;
}

void Array::insureSpace() {
	if (size > capacity) {
		capacity = capacity * 2;
		if (capacity == 0) {
			capacity = 1;
		}

		Student* tempArray = new Student[capacity];
		for (int i = 0; i < size - 1; ++i) {
			tempArray[i] = arr[i];
		}

		delete[] arr;
		arr = tempArray;
	}
}

void Array::add(Student& student) {
	++size;
	insureSpace();
	student.getTimestamp();
	arr[size - 1] = student;
}

void Array::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i].name << "," << arr[i].age << "," << arr[i].subject << "," << arr[i].grade << "," << arr[i].date << std::endl;
	}
}

void Array::swap(Student& s1, Student& s2) {
	Student tmp;
	tmp = s1;
	s1 = s2;
	s2 = tmp;
}

Student& Array::get(int pos) {
	return arr[pos];
}

void Array::sortGrade(bool asc) {
	buckedSort(asc);
}

void Array::sortAge(bool asc) {
	heapSort(asc);
}

void Array::sortDate(bool asc) {
	quickSort(0, size - 1, asc);
}

void Array::sortName(bool asc) {
	selectionSortForName(asc);
}

void Array::sortSubject(bool asc) {
	selectionSortForSubject(asc);
	
	
}

void Array::buckedSort(bool asc) {

	//create key array
	Array** key = new Array*[5];
	for (int i = 0; i < 5; ++i) {
		key[i] = new Array;
	}

	//fill key array
	for (int i = 0; i < size; ++i) {
		key[arr[i].grade - 2]->add(arr[i]);
	}

	//sort by key
	int index = 0;
	if (asc) {
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < key[i]->size; ++j) {
				arr[index++] = key[i]->get(j);
			}
		}
	} else {
		for (int i = 4; i >= 0; --i) {
			for (int j = 0; j < key[i]->size; ++j) {
				arr[index++] = key[i]->get(j);
			}
		}
	}
	

	//delete key array
	for (int i = 0; i < 5; ++i) {
		delete key[i];
	}
	delete[] key;
}

void Array::heapify(int size, int i, bool asc) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (asc) {
		if (left < size && arr[left].age > arr[largest].age) {
			largest = left;
		}

		if (right < size && arr[right].age > arr[largest].age) {
			largest = right;
		}
	} else {

		if (left < size && arr[left].age < arr[largest].age) {
			largest = left;
		}

		if (right < size && arr[right].age < arr[largest].age) {
			largest = right;
		}
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(size, largest, asc);
	}
	
}

void Array::heapSort(bool asc) {
	for (int i = size / 2 - 1; i >= 0; --i) {
		heapify(size, i, asc);
	}

	for (int i = size - 1; i >= 0; --i) {
		swap(arr[0], arr[i]);
		heapify(i, 0, asc);
	}
}

long Array::partition(int low, int high, bool asc) {
	long pivot = arr[high].timestamp;

	int i = (low - 1);
	for (int j = low; j <= high - 1; ++j) {
		if (asc) {
			if (arr[j].timestamp <= pivot) {
				++i;
				swap(arr[i], arr[j]);
			}

		} else {
			if (arr[j].timestamp >= pivot) {
				++i;
				swap(arr[i], arr[j]);
			}
		}
	}

	swap(arr[i + 1], arr[high]);

	return i + 1;
}

void Array::quickSort(int low, int high, bool asc) {
	if (low < high) {
		int pIndex = partition(low, high, asc);
		quickSort(low, pIndex - 1, asc);
		quickSort(pIndex + 1, high, asc);
	}	
}

void Array::selectionSortForName(bool asc) {
	int min = 0;

	for (int i = 0; i < size; ++i) {
		min = i;
		for (int j = i + 1; j < size; ++j) {
			if (asc) {
				if (std::strcmp(arr[j].name, arr[min].name) < 0) {
					min = j;
				}

			} else {
				if (std::strcmp(arr[j].name, arr[min].name) > 0) {
					min = j;
				}
			}
			
		}

		if (min != i) {
			swap(arr[i], arr[min]);
		}
	}
}

void Array::selectionSortForSubject(bool asc) {
	int min = 0;

	for (int i = 0; i < size; ++i) {
		min = i;
		for (int j = i + 1; j < size; ++j) {
			if (asc) {
				if (std::strcmp(arr[j].subject, arr[min].subject) < 0) {
					min = j;
				}

			} else {
				if (std::strcmp(arr[j].subject, arr[min].subject) > 0) {
					min = j;
				}
			}
			
		}

		if (min != i) {
			swap(arr[i], arr[min]);
		}
	}	
}
