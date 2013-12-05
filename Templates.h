/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

File: Templates.h
*****************************************************/
#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <map>
#include <iostream>
#include <vector> 
#include "Utilities/Scanner.h"
#include "Utilities/ScanLine.h"
#include "Utilities/Utils.h"
#include "Template.h"

using namespace std;

class Templates {
public:
	//public functions
	Templates();

	bool exists(string templateName);
	void push_template(string id, string file);
	void push_query(string id, string filename, string filePath);
	void calculate_distances(); 


private:

	 map<string, Template> templates;


	 
	 void openFile();
};

#endif // TEMPLATES_H