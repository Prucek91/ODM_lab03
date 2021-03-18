// g++ lab3.cpp -pthread -O3 -o lab2 `Magick++-config --cppflags --cxxflags --ldflags --libs`
#include <stdio.h>
#include <math.h>

#include <vector>
#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <thread>

#include <fstream>

//#include <Magick++.h>

using namespace std;
//using namespace Magick;


/* screen ( integer) coordinate */
const int iXmax = 1024;
const int iYmax = 1024;


unsigned char color[iXmax][iYmax][3];

unsigned char colorTheme[][3] = {{191, 228, 118}};

int themeId = 0;

int main(int ac, char ** av)

{


    return 0;
}
