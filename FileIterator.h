/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

File: FileIterator.h
*****************************************************/

#ifndef FILE_ITERATOR_H
#define FILE_ITERATOR_H

#include <cstdlib>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "Templates.h"

using namespace std;

class FileIterator{
	public:

		FileIterator();

		void IterateDir(DIR* dir, string path);
		void ProcessFile(string file, string path);
		void calculations();

	private:
		dirent* entity;
		vector<string> tokenize(string var, char delimiter);
		Templates temps;

};

#endif // FILE_ITERATOR_H