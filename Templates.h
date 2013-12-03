/**
Templates Header File
Authors: Richard Abercrombie and Timothy Barrett

*/
#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <map>
#include <iostream>

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
	Template getTemplate(string input);
	void calculate_distances(); //run distance calculations on each Template
	map<string, Template> getData();
private:
	/**************
	 * Private Variables
	 **/
	 string templateName;
	 //map<a ID, a template>
	 map<string, Template> templates;

	 //something to hold structure of results

	 //private functions

	 
	 void openFile();
};

#endif // TEMPLATES_H