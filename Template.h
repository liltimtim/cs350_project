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
	struct Query_Results& getTemplateResults();

	// vector<std::thread> workerThreads;
private:

	string templateName;
	vector<vector<double> > data;
	map<string, vector<double> > queries;

	struct Query_Results
	{
		string name;
		vector<pair<double, int> > results_vector;
	};

	void print_top_10(vector<pair<double,int> > results);
	// vector<struct Template::Query_Results> all_query_results;

	// map<string, vector<double> > results;
	
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