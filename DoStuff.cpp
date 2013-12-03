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

}

// Calls Templates::doCalculation() which 
// runs the similarity formula on all queries
// and templates within each Template class
//
// return results vector<similarity_value, vector<template> >
// vector<pair<double, vector<double> > > DoStuff::calculate_distances() {
// 	return temps.calculate_distances();
// }
void DoStuff::calculate_distances(){
	temps.calculate_distances();
}

void DoStuff::write_distances(DIR* outdir) {
	temps.calculate_distances();
}
 