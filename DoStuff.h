/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

File: DoStuff.h
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


	private:


};

#endif // FILE_ITERATOR_H