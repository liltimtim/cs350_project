/****************************************************
Authors: Richard Abercrombie & Timothy Barrett
Project: CSCE 350 Facial Expression Recognition
Date: 10/31/2013

File: Template.cpp
*****************************************************/

#include "Template.h"

Template::Template(){

}

/******
* Return the top 10 distances for each query in the template
* c(A, B) = ( A * B ) / ( sqrt(A*A) * sqrt(B*B) ) <-- cosine of two vectors
**/
void Template::calculate_distances(){

	unsigned int j = 0;
	for(map<string, vector<double> >::iterator it=queries.begin(); it != queries.end(); ++it){ //iterates queries

		struct Query_Results query;
		query.name = it->first;

		//compare the query iteration 
		for(unsigned int i = 0; i < data.size(); i++){ //this loop iterates over each template in data
			
			double vectorADotA; //A*A
			double vectorBDotB; //B*B
			double vectorADotB; //A*B

			//MAKE SURE TO NOT COMPARE SAME ROW
			if(i != j){
				double cosCalculation = 0.0;
				vectorADotA = calculateDotProductOfVectors(it->second, it->second);
				vectorBDotB = calculateDotProductOfVectors(data[i], data[i]);
				vectorADotB = calculateDotProductOfVectors(it->second, data[i]);

				cosCalculation = vectorADotB / (sqrt(vectorADotA)*sqrt(vectorBDotB));

				//add distances to the query results structure 
				pair<double, int> cur_pair;
				cur_pair = make_pair(cosCalculation, i+1);
				query.results_vector.push_back(cur_pair);
			}

		}

		//Sort the vector to determine the top 10 similarity values
		std::sort(query.results_vector.begin(), query.results_vector.end());

		//Write the values to files
		print_top_10(query);

		j++;
	}	

}

void Template::print_top_10(struct Template::Query_Results results) {
	string path;
	path = "./results/"+results.name+"_results.txt";
	
	ofstream myfile (path.c_str());

	if (myfile.is_open())
	{	
		myfile << "Similarity \t Indices" << endl;
		for (unsigned int i = results.results_vector.size()-1; i > results.results_vector.size() - 11; --i)
		{
			myfile << results.results_vector[i].first << " \t " << results.results_vector[i].second+1 << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";


}

double Template::calculateDotProductOfVectors(vector<double> vec1, vector<double> vec2){
	//WILL CALCULATE THE DOT PRODUCT OF TWO VECTORS
	//EXAMPLE:
	/*
	 * LET A = <0, 0, 1, 1>
	 * LET B = <0, 1, 1, 0>
	 * A*B = 0*0 + 0*1 + 1*1 + 1*0 = 1
	 *
	 */
	 
	 double result = 0.0;
	 for(unsigned int i = 0; i < vec1.size(); i++){
		 result = result + vec1[i]*vec2[i];
	  }

	 return result;
}


string Template::getName(){
	return templateName;
}

/*
* function 'addItem'
* 
* Add a double number to the 'data' contained in the Template class
*
* Input: double number
* Output: None
**/
void Template::addItem(vector<double> input){
	data.push_back(input);
	// cout << "DIAGNOSTIC Template::adItem " << number << endl;
}
void Template::addQuery(string queryName, double valueToAdd){
	queries[queryName].push_back(valueToAdd);
	// cout << "addQuery pushing " << valueToAdd << endl;
}

//return the size of the query map
unsigned int Template::sizeQuery(){
	return queries.size();
}

