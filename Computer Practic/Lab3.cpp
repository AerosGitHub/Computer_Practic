#include <iostream>
#include "Header.h"
#include "ODA.h"
#include "ODAS.h"
#include <iomanip>

using namespace std;

void part1() {
    ODA class_test;
    ODA class_test1(class_test);

    class_test.out();
    class_test.less_P();
};

void part2() {
    ODAS class_test;
    ODAS class_test1(class_test);

    class_test.out();

    int num = 0;
    cout << "¬ведите число P:" << endl;
    cin >> num;

    class_test - num;
}

void lab_3() {
    int help;

    cout << "¬ведите номер части, которую хотите выполнить:" << endl;;
    cin >> help;

    if (help == 1) {
        part1();
    }
    else {
        part2();
    }



}