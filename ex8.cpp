#include <cstdio>
#include <iostream>
#include <cstring>
#include "ex7.h"
using namespace std;

unsigned char* readBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);

    // write 
    unsigned char red[height][width], green[height][width], blue[height][width]; 
    for(i = 0; i < size; i += 3)
    {
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
            // cout << "R: "<< (int)data[i] << " G: " << (int)data[i+1]<< " B: " << (int)data[i+2]<< endl;
    }

    int cnt = 0;
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++){
            red[i][j] = data[cnt++];
            green[i][j] = data[cnt++];
            blue[i][j] = data[cnt++];
        }

    writeBMP(height, width, red, green, blue);


    return data;
}

int main(){
    char *name = "dig10k_penguin.bmp";
    unsigned char* data = readBMP(name);

    return 0;
}