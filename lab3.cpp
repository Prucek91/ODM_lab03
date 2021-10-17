// g++ lab3carpet.cpp -pthread -O3 -o lab3carpet 

#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <thread>
#include <fstream>

using namespace std;

const int carpetHeight = 2187;
const int levelLimit = 4;

unsigned char image[carpetHeight][carpetHeight][3];


void draw_carpet(int x, int y, int level)
{
    int length = carpetHeight / pow(3, level);
    cout << "x: " << x << " y: " << y << " " << length << "lvl: " << level << endl;
    for(int i = x  + length; i < x +  length + length; i++)
    {
        for (int j = y + length ; j < y +  length + length; j++)
        {
            if (i < carpetHeight && j < carpetHeight)
            {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
        }
    }    


    if (level < levelLimit)
    {
        std::thread carpets[9];
        level++;
        
        
        carpets[0] = std::thread(draw_carpet, x, y, level);
        carpets[1] = std::thread(draw_carpet, x, y + length, level);
        carpets[2] = std::thread(draw_carpet, x, y + (length * 2) , level);

        carpets[3] = std::thread(draw_carpet, x + length, y, level);
        carpets[4] = std::thread(draw_carpet, x + length, y + length, level); // bez tego - niepotrzebne
        carpets[5] = std::thread(draw_carpet, x + length, y + (2 * length), level);

        carpets[6] = std::thread(draw_carpet, x+ (2 * length), y, level);
        carpets[7] = std::thread(draw_carpet, x+ (2 * length), y + length, level);
        carpets[8] = std::thread(draw_carpet, x+ (2 * length), y + (2 * length), level);
        
        for (int i = 0; i <= 8; i++)
        {
            carpets[i].join();
        }
    }
}

int main()
{
    FILE *fp;
    char *filename = "sierpinski_carpet.ppm";
    char *comment = "# ";
    fp = fopen(filename, "wb");
    fprintf(fp, "P6\n %s\n %d\n %d\n %d\n", comment, carpetHeight, carpetHeight, 255);

    draw_carpet(0, 0, 0);

    fwrite(image, 1, 3 * carpetHeight * carpetHeight, fp);
    fclose(fp);
    return 0;
}

