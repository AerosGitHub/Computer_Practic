#pragma once
#include <iostream>
#include <iomanip>

class ODAS {

	int* my_array;
	int count = 0;

public:

	ODAS();
	ODAS(const ODAS& ODAS1);
	void out();
	int& operator -(int num);
	~ODAS();
};

ODAS::ODAS() {

	srand(time(NULL));
	int n;

	std::cout << "Введите размер массива:" << std::endl;
	std::cin >> n;
	count = n;
	my_array = new int[n];

	for (int i = 0; i < count; i++)
	{
		my_array[i] = rand() % 100;
	}
}

ODAS::ODAS(const ODAS& ODAS1) {
	std::cout << "Конструктор копия" << std::endl;
}

void ODAS::out() {
	for (int i = 0; i < count; i++)
	{
		std::cout << my_array[i] << ' ';
	}
	std::cout << std::endl;
}

int& ODAS::operator-(int num) {
	int counter = 0;

	for (int i = 0; i < count; i++)
	{
		if (my_array[i] < num) {
			counter++;
		}
	}

	std::cout << counter << std::endl;

	return counter;
}

ODAS::~ODAS() {
	delete my_array;
}
