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
#include "Templates.h"
#include "Template.h"


using namespace std;

class DoStuff{
	public:

		DoStuff();

		void feed(DIR* dir, string path); 
		// void write_distances(DIR* outdir);
		// void write_to_file(string, filename, data, rows=10);


	private:
		// Templates temps;	
		// vector<struct Template::Query_Results> distances;

};

#endif // FILE_ITERATOR_H