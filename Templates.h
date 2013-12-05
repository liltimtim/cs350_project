/**
Templates Header File
Authors: Richard Abercrombie and Timothy Barrett

*/
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
	map<string, Template>& getTemplate(string input);
	void calculate_distances(); //run distance calculations on each Template
	// map<string, Template> getData();
	vector<struct Template::Query_Results> get_distances();

private:
	/**************
	 * Private Variables
	 **/
	 string templateName;
	 //map<a ID, a template>
	 map<string, Template> templates;
	 vector<struct Template::Query_Results> all_template_results;

	 //private functions

	 
	 void openFile();
};

#endif // TEMPLATES_H