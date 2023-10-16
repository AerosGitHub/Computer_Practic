#include <iostream>
#include "Header.h"

using namespace std;

struct node {
    int a;
    struct node* next;
};

typedef struct node* NodePtr;

NodePtr create(int n) {
    NodePtr first = nullptr, second = nullptr;

    for (int i = 0; i < n; ++i) {
        first = new struct node;
        first->a = rand() / 1000;
        first->next = second;
        second = first;
    }
    return first;
}
void lab_1() {
    string n;
    double sred = 0;

    while (true) {
        cout << "Введите размер списка с рандомными числами: ";
        cin >> n;

        if (isdigit(n[0]) == 0 || (n[0] - '0') == 0) {
            cout << "Неправильно введён размер массива. Попробуйте ещё раз." << endl;
            n = "";
        }
        else break;

    }


    NodePtr work_node = create(n[0] - '0');

    while (work_node != nullptr) {
        sred += work_node->a;
        cout << work_node->a << endl;
        work_node = work_node->next;
    }

    sred = sred / (n[0] - '0');

    cout << "Среднее значение всех элементов: " << sred << endl;
}