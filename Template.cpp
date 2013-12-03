#include "Template.h"

Template::Template(){

}

/******
* Return the top 10 distances for each query in the template
* c(A, B) = ( A * B ) / ( sqrt(A*A) * sqrt(B*B) ) <-- cosine of two vectors
**/
void Template::calculate_distances(){
	//for each query compare to template vector
	// cout << "Size of Queries " << sizeQuery() << endl;
	// for(map<string, vector<double> >::iterator it=queries.begin(); it != queries.end(); ++it){
	// 	//spawn threads and do work


	// 	//compare the query iteration 
	// 	for(unsigned int i = 0; i < data.size(); i++){
	// 		// workerThreads.push_back(thread(threadWork(it->first, it->second, data[i])));
	// 		workerThreads.push_back(thread(test()));
	// 	}
	// }

	/**********************************************
	*			Richards modifications
	*				start
	**********************************************/
	

	unsigned int j = 0;
	for(map<string, vector<double> >::iterator it=queries.begin(); it != queries.end(); ++it){ //iterates queries

		//Create a vector to contain all of the cosine values

		//compare the query iteration 
		for(unsigned int i = 0; i < data.size(); i++){ //this loop iterates over each template in data
			
			//Vector A is query 
			//Vector B is template
			
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

				cout << "Template " << i << " cosCalculation: " << cosCalculation << endl;
			}
		}
		j++;
		cout << "QUERY " << j << " maxCosineCoefValue: " << maxCosineCoefValue << endl;
	}	
	cout << "********************TEMPLATE END*********************" << endl;
	/**********************************************
	*			Richards modifications
	*				end
	**********************************************/
}
	/**********************************************
	*			Richards modifications
	*				start
	**********************************************/


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

	/**********************************************
	*			Richards modifications
	*				end
	**********************************************/


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

