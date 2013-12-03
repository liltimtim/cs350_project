/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

main.h file for main.cpp
*****************************************************/

#ifndef DO_STUFF_H
#define DO_STUFF_H

#include <iostream>
#include "FileIterator.h"
// #include "Templates.h"


using namespace std;

class DoStuff{
	public:

		

		DoStuff();

		void feed(DIR* dir, string path); 
		// vector<pair<double, vector<double> > > calculate_distances();
		void calculate_distances();
		void write_distances(DIR* outdir);
		// 	//templates.get_distances() (map)
		// 	//write to files
	private:
		Templates temps;	

};

#endif // FILE_ITERATOR_H