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
void Templates::push_template(string id, string file){
	Scanner scanner;
	scanner.openFile(file);
	ScanLine scanLine;
	Template newTemplate;
	// cout << "DIAGNOSTIC push_template " << id << " " << file << endl;
	//while file has more data get each double in the template
	templates.insert(pair<string, Template>(id, newTemplate)); //insert template

	//read in each line and parse for double
	while (scanner.hasMoreData()){
		// string newLine = scanner.nextLine();
		// double newDouble = scanner.nextDouble();
		// cout << "DIAGNOSTIC push_template double " << newDouble << endl;
		// templates[id].addItem(newDouble);
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
void Templates::push_query(string id, string filename, string filePath){
	Scanner scanner;
	scanner.openFile(filePath);
	Template newTemplate;
	// cout << "DIAGNOSTIC push_query " << id << " " << filename << " " << endl;

	templates.insert(pair<string, Template>(id, newTemplate));
	while(scanner.hasMoreData()){
		double newDouble = scanner.nextDouble();
		templates[id].addQuery(filename, newDouble);
	}
}

void Templates::calculate_distances(){
	//for each template in templates calculate the distances 
	for(map<string, Template>::iterator it=templates.begin(); it!=templates.end(); ++it){
		cout << it->first << endl;
		it->second.calculate_distances();
	}
}
Template Templates::getTemplate(string input){
	Template newTemplate;

	return newTemplate;
}

map<string, Template> Templates::getData(){
	return templates;
}
