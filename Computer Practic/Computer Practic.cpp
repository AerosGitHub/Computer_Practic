#include <iostream>
#include "Header.h"
#include <map>
#include <functional>
#include <Windows.h>

using namespace std;

struct SupVarStruct {
    string LabNum;
    bool HelloTrigger = false;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct SupVarStruct* SupVar = new struct SupVarStruct;


    map<string, void(*)()> mFunctions;
    mFunctions["lab_1"] = lab_1;
    mFunctions["lab_2"] = lab_2;
    mFunctions["lab_3"] = lab_3;
    mFunctions["lab_4"] = lab_4;

    while (true) {
        if (!SupVar->HelloTrigger) {
            cout << HelloText();
            SupVar->HelloTrigger = true;
        }

        SupVar->LabNum = InputLabNum();

        if (SupVar->LabNum == "exit") break;

        while (true) {
            string cheak;
            mFunctions["lab_" + SupVar->LabNum]();

            cout << LabDoneMessage();
            cin >> cheak;
            if (cheak == "n" || cheak == "N") break;
        }

    }

}