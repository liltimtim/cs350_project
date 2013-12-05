#include "Templates.h"
//Constructor
Templates::Templates(){
	// all_template_results.reserve( 47*3 );
}

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

		//Calculate the Queries top distances 
		it->second.calculate_distances();

	}

	// cout << "FIRST::: Size of all_template_results: " << all_template_results.size() << endl;
}

//return a reference to all the template contained in templates
map<string, Template>& Templates::getTemplate(string whichTemplate){
	return this->templates;
}

// map<string, Template> Templates::getData(){
// 	return templates;
// }

