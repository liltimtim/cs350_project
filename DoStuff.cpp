#include "DoStuff.h"

DoStuff::DoStuff(){}

// Iterates over a directory, sending files
// to the templates class to be stored based 
// on file type.
// 
// Types include template and query
void DoStuff::feed(DIR* dir, string path) {
	
	FileIterator fileIter;
	fileIter.IterateDir(dir, path);
	fileIter.calculations();
	// // TO DO: need to return back from the feeder the new Templates
	// temps = fileIter.returnLoaderTemplates();

}

// void DoStuff::write_distances(DIR* outdir) {
// 	distances = temps.get_distances();

// 	for (unsigned int i = 0; i < distances.size(); ++i)
// 	{
// 		struct Template::Query_Results cur_result_query;
// 		cur_result_query = distances[i];

// 		string query_name = cur_result_query.name;
		
// 		vector<pair<double, int> > cur_result_vector;
// 		cur_result_vector = cur_result_query.results_vector;

// 		cout << query_name << endl;

// 		for (unsigned int i = 0; i < cur_result_vector.size(); ++i)
// 		{
// 			cout << "hi" << " -- " << "There" << endl;
// 		}

// 	}
// }

//get results from the template instances
// void DoStuff::get_results(){

// 	// temps.calculate_distances();

// 	// //ask templates to return a map of each template reference
// 	// //so that I can ask Template what it's results are
// 	// map<string, Template> tempResults = temps.getTemplates();
// }


// void DoStuff::write_to_file(string filename, data, rows=10) {
// 	ofstream myfile (filepath);
// 	if (outfile.is_open())
// 	{	

// 		outfile << "Distance \t Line" << endl;
// 		for (int i = 0; i < rows-1; ++i) 
// 		{
// 			outfile << data[i]->first << "\t" << data[i]->second;
// 		}
// 		outfile.close();
// 	}
// 	else cout << "Unable to open file";
// }