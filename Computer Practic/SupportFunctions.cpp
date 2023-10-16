#include <iostream>
#include "Header.h"

std::string HelloText() {
	return "Добро пожаловать в программу исполнения лабораторных работ!\n";
}

std::string InputLabNum() {
	std::string LabNum;

	returnTag:
	std::cout << "Введите номер лабораторной работы (для выходя введите exit)\n>>>";
	std::cin >> LabNum;

	if ((LabNum[0] - '0') >= 1 && (LabNum[0] - '0') <= 4) return LabNum;
	else {
		if (LabNum == "exit") return LabNum;
		std::cout << "Непрвильно введён номер лабораторной работы. Попробуйте ещё раз." << std::endl;
		LabNum = "";
		goto returnTag;
	}
}

std::string LabDoneMessage() {
	return "Выполнение лабораторной работы закончено.\n"
		"Вы хотите повторить выполнение лабораторной работы? (Y/N) >>> ";
}