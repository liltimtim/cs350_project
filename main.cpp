 /************************
Authors: Richard Abercrombie, Tim Barrett
Project: CSCE 350 Facial Expression Recognition 
Date: 10/28/13

File: main.cpp

Determine the Facial Expression of multiple images
*************************/

#include "Main.h"

static const string PATH_1 = "./data_project_part1";
static const string PATH_2 = "./data_project_part2";

int main(int argc, char *argv[]) {
    // Timer tmr;

	DIR* indir1;
	DIR* indir2;
	DoStuff Worker;

    //Define Directories
    indir1 = opendir(PATH_1.c_str());
    indir2 = opendir(PATH_2.c_str());

    //Process files within Directories
    Worker.feed(indir1, PATH_1);
    Worker.feed(indir2, PATH_2);
    
    //timer
    // double timeElap = tmr.elapsed();
    // cout << timeElap << endl;

    return 0;
}
