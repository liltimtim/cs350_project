/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

File: Templates.cpp
*****************************************************/

#include "Templates.h"
//Constructor
Templates::Templates(){}

/*
	Function 'findTemplateName'

	Returns eithers true if template already exists in the template 'data' else
	false if template is not inside the class 'data'

	Input: 
*/
bool Templates::exists(string templateName){
	//search the map for the key specified
	if(templates.find(templateName) != templates.end()){
		return true;
		cout << "template exists" << endl;
	}
	return false;
}

//Pushes template vector to the template class
void Templates::push_template(string id, string file){
	Scanner scanner;
	scanner.openFile(file);
	ScanLine scanLine;
	Template newTemplate;

	//while file has more data get each double in the template
	templates.insert(pair<string, Template>(id, newTemplate)); //insert template

	//read in each line and parse for double
	while (scanner.hasMoreData()){

		string newLine = scanner.nextLine();
		scanLine.openString(newLine);
		vector<double> tempVector;
		while(scanLine.hasMoreData()){
			double newDouble;
			newDouble = scanLine.nextDouble();
			tempVector.push_back(newDouble);
		}
		templates[id].addItem(tempVector);
	}

}

//Pushes a query line to the template class
void Templates::push_query(string id, string filename, string filePath){
	Scanner scanner;
	scanner.openFile(filePath);
	Template newTemplate;

	templates.insert(pair<string, Template>(id, newTemplate));
	while(scanner.hasMoreData()){
		double newDouble = scanner.nextDouble();
		templates[id].addQuery(filename, newDouble);
	}
}

//Runs similarity calculations on each template in the template class
void Templates::calculate_distances(){

	//for each template in templates calculate the distances 
	for(map<string, Template>::iterator it=templates.begin(); it!=templates.end(); ++it){

		//Calculate the Queries top distances 
		it->second.calculate_distances();

	}

}
