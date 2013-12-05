#include "Template.h"

Template::Template(){

}

/******
* Return the top 10 distances for each query in the template
* c(A, B) = ( A * B ) / ( sqrt(A*A) * sqrt(B*B) ) <-- cosine of two vectors
**/
void Template::calculate_distances(){

	cout << templateName << endl;

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

				// cout << "Template " << i << " cosCalculation: " << cosCalculation << endl;
			}

		}
		std::sort(query.results_vector.begin(), query.results_vector.end());
		
		cout << it->first << endl;
		print_top_10(query.results_vector);


		// all_query_results.push_back(query);

		j++;
	}	
	// cout << "********************TEMPLATE END*********************" << endl;

	// return all_query_results;
}

void Template::print_top_10(vector<pair<double,int> > results) {
	
	for (unsigned int i = results.size()-1; i > results.size() - 11; --i)
	{
		cout << results[i].first << " \t " << results[i].second+1 << endl;
	}
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

//return the results from the template
// struct Query_Results& getTemplateResults(){
// 	return this->Query_Results;
// }
