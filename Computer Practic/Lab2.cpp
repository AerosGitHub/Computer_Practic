#include <iostream>
#include <fstream>
#include <iomanip>
#include "Header.h"

struct TrailConfig {
    int TrainNum = 0;
    char DestinationCity[100];
    int DepartureTime = 0;
    int TravelTime = 0;
    int ValidSeats = 0;
};

const int LineCounter(){
    std::ifstream in;
    int counter = 0;
    std::string line;

    in.open("state.txt");

    while (!in.eof()) {
        std::getline(in, line);
        if (line != "") counter++;
    }

    in.close();
    
    return counter;
};

void MakeTxtFile() {

    srand(std::time(NULL));

    std::string city[10] = { "adler", "tula", "krasnodar", "rostov-na-donu", "pyatigorsk", "sankt-peterburg", "tver", "yalta", "voronezh", "yakutsk"};
    std::ofstream out;
    int LinesNum;

    out.open("state.txt", std::ios::out);

    std::cout << "Number of lines" << std::endl << ">>>";
    std::cin >> LinesNum;

    for (int i = 0; i < LinesNum; i++) {
        out << 100 + rand() % 800 << ' ' << city[rand() % 10] << ' ' << rand() % 86400 << ' ' << rand() % 900 << ' ' << rand() % 2000 << ' ' << std::endl;
    }

    out.close();
    
    std::cout << "File generated" << std::endl;
}

void lab_2() {
    TrailConfig Help;
    std::string cheak = "";

    std::ifstream in;
    std::ofstream out;

    std::cout << "Do you wanna auto-generate trails data? (Y/N)" << std::endl << ">>>";
    std::cin >> cheak;
    if (cheak == "Y" || cheak == "y") MakeTxtFile();

    int LCount = LineCounter();

    TrailConfig* Trails = new TrailConfig[LCount];

    in.open("state.txt");

    if (in.is_open()) {
        for (int i = 0; i < LCount; i++) {
            in >> Trails[i].TrainNum;
            in >> Trails[i].DestinationCity;
            in >> Trails[i].DepartureTime ;
            in >> Trails[i].TravelTime;
            in >> Trails[i].ValidSeats;
        }

        for (int i = 0; i < LCount; i++) {             
            std::cout << Trails[i].TrainNum << ' ';
            std::cout << Trails[i].DestinationCity << ' ';
            std::cout << Trails[i].DepartureTime << ' ';
            std::cout << Trails[i].TravelTime << ' ';
            std::cout << Trails[i].ValidSeats << std::endl;
        }

    }
    else {
        std::cout << "File state didn't open";
    }
    
    in.close();

    out.open("Trails.dat", std::ios::binary | std::ios::out);

    if (out.is_open()) {
        out.write((char*)Trails, sizeof(TrailConfig)*LCount);

        std::cout << "Writing is done" << std::endl;
    }
    else {
        std::cout << "File Trails.dat didn't open for writing";
    }

    out.close();

    delete[] Trails;

    TrailConfig* Trails_new = new TrailConfig[LCount];

    in.open("Trails.dat", std::ios::binary | std::ios::in);

    if (in.is_open()) {
        in.read((char*)Trails_new, sizeof(TrailConfig) * LCount);
        std::cout << "Reading is done" << std::endl;
    }
    else {
        std::cout << "File Trails.dat didn't open for reading";
    }

    in.close();

    for (int i = 0; i < LCount; i++) {
        std::cout << Trails_new[i].TrainNum << ' ';
        std::cout << Trails_new[i].DestinationCity << ' ';
        std::cout << Trails_new[i].DepartureTime << ' ';
        std::cout << Trails_new[i].TravelTime << ' ';
        std::cout << Trails_new[i].ValidSeats << std::endl;
    }

    int min;
    int indx;

    for (int i = 0; i < LCount; i++) {
        min = Trails_new[i].DepartureTime;
        indx = i;
        if (LCount > 1) {
            for (int j = i + 1; j < LCount; j++) {
                if (min > Trails_new[j].DepartureTime) {
                    min = Trails_new[j].DepartureTime;
                    indx = j;
                }
            }
        }
        Help = Trails_new[i];
        Trails_new[i] = Trails_new[indx];
        Trails_new[indx] = Help;
    }

    std::cout << "Sort is done" << std::endl;

    for (int i = 0; i < LCount; i++) {
        std::cout << Trails_new[i].TrainNum << ' ';
        std::cout << Trails_new[i].DestinationCity << ' ';
        std::cout << Trails_new[i].DepartureTime / 3600 << ':' << (Trails_new[i].DepartureTime / 60) % 60 << ':' << Trails_new[i].DepartureTime % 60 << ' ';
        std::cout << Trails_new[i].TravelTime << ' ';
        std::cout << Trails_new[i].ValidSeats << std::endl;
    }

    delete[] Trails_new;
}