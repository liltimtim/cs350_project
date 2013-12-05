/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

File: Template.h
*****************************************************/
#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <fstream>

using namespace std;

class Template{

public:
	Template();

	string getName();
	void addItem(vector<double> input);
	void calculate_distances();
	void addQuery(string queryName, double valueToAdd);
	unsigned int sizeQuery();
	struct Query_Results& getTemplateResults();

private:

	struct Query_Results
	{
		string name;
		vector<pair<double, int> > results_vector;
	};

	string templateName;
	vector<vector<double> > data;
	map<string, vector<double> > queries;

	//private functions
	void print_top_10(struct Template::Query_Results results);
	double calculateDotProductOfVectors(vector<double> vec1, vector<double> vec2);

	

};

#endif // TEMPLATE_H