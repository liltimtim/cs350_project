#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
// #include <thread>

using namespace std;

class Template{

public:
	Template();

	string getName();
	void addItem(vector<double> input);
	void calculate_distances();
	void addQuery(string queryName, double valueToAdd);
	unsigned int sizeQuery();


	// vector<std::thread> workerThreads;
private:
	string templateName;
	vector<vector<double> > data;
	map<string, vector<double> > queries;
	map<string, vector<double> > results;
	
	/**********************************************
	*			Richards modifications
	*				start
	**********************************************/	

	double calculateDotProductOfVectors(vector<double> vec1, vector<double> vec2);

	/**********************************************
	*			Richards modifications
	*				end
	**********************************************/
	

};

#endif // TEMPLATE_H