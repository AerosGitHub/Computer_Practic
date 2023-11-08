#pragma once
#include <iostream>
#include <iomanip>

class ODA {

	int* my_array;
	int count = 0;

public:

	ODA();
	ODA(const ODA& ODA1);
	void out();
	void less_P();
	~ODA();
};

ODA::ODA() {

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

ODA::ODA(const ODA &ODA1) {
	std::cout << "Конструктор копия" << std::endl;
}

void ODA::out() {
	for (int i = 0; i < count; i++)
	{
		std::cout << my_array[i] << ' ';
	}
	std::cout << std::endl;
}

void ODA::less_P() {
	int couter = 0;
	int P = 0;
	
	std::cout << "Введите P:" << std::endl;
	std::cin >> P;
	for (int i = 0; i < count; i++)
	{
		if (my_array[i] < P) couter++;
	}
	std::cout << couter << std::endl;
}

ODA::~ODA() {
	delete my_array;
}