#include <iostream>
#include "Header.h"

std::string HelloText() {
	return "����� ���������� � ��������� ���������� ������������ �����!\n";
}

std::string InputLabNum() {
	std::string LabNum;

	returnTag:
	std::cout << "������� ����� ������������ ������ (��� ������ ������� exit)\n>>>";
	std::cin >> LabNum;

	if ((LabNum[0] - '0') >= 1 && (LabNum[0] - '0') <= 4) return LabNum;
	else {
		if (LabNum == "exit") return LabNum;
		std::cout << "���������� ����� ����� ������������ ������. ���������� ��� ���." << std::endl;
		LabNum = "";
		goto returnTag;
	}
}

std::string LabDoneMessage() {
	return "���������� ������������ ������ ���������.\n"
		"�� ������ ��������� ���������� ������������ ������? (Y/N) >>> ";
}