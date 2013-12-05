/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

File: FileIterator.cpp
*****************************************************/

#include "FileIterator.h"

FileIterator::FileIterator(){}

// Iterates over directory and calls ProcessFile
// on each file
void FileIterator::IterateDir(DIR *dir, string path) {
    while ( (entity = readdir(dir)) ) {
    	//If entity is regular file
	    if (entity->d_type == DT_REG)
	    {
	    	FileIterator::ProcessFile(entity->d_name, path);
	    }
    }
    closedir(dir);
}

// Tokenizes the file string and determines the file id
// and whether the file is a template or a query; sends
// the file and id to the Templates class using Templates 
// function push_template or push_query
void FileIterator::ProcessFile(string file, string path) {
	vector<string> tokens = tokenize(file, '_');
	string id = tokens.at(0);
	string type = tokens.at(1);
	string pathToFile = path + "/" + file;

	tokens = tokenize(file, '.');
	file = tokens.at(0);

	//Send file to Templates class
	if (type.find("template") != string::npos) { //If type contains template
		// cout << "DIAGNOSTIC " << id << endl;
		temps.push_template(id, pathToFile);
	} else { //If type !contains template, ie. query file
		temps.push_query(id, file, pathToFile);
	}
	
}

//Tell templates class to perform 
//similarity calculations on all templates
void FileIterator::calculations(){
	temps.calculate_distances();
}

// Tokenizes a given string by a given delimiter
vector<string> FileIterator::tokenize(string var, char delimiter) {
	istringstream ss(var);
	string token;
	vector<string> tokens;

	//Tokenizes the filename into a vector
	while(getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}	

	return tokens;
}