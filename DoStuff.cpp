/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

File: DoStuff.cpp
*****************************************************/

#include "DoStuff.h"

DoStuff::DoStuff(){}

// Iterates over a directory, sending files
// to the templates class to be stored based 
// on file type.
// 
// Similarity calculations are then performed
void DoStuff::feed(DIR* dir, string path) {
	
	FileIterator fileIter;
	fileIter.IterateDir(dir, path);
	fileIter.calculations();

}
