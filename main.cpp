 /************************
Name: Richard Abercrombie
Project: CSCE 350 Facial Expression Recognition 
Date: 10/28/13

Determine the Facial Expression of multiple images
*************************/

#include "main.h"

namespace fs = boost::filesystem; 
using namespace std;

int main(int argc, char *argv[])
{
string inLine;
ifstream inFile;
ofstream outFile;
    
//Determine whether correct arguments are used
if(argc != 3) {
    cout << "Usage: " << argv[0] << " <Input Directory> <Outfile>" << endl;
    exit(1);
}

string dir = argv[1];

//Iterate through the input directory
fs::path targetDir(dir); 
fs::directory_iterator it(targetDir), eod;

// BOOST_FOREACH(fs::path const &p, std::make_pair(it, eod))   
// { 
//     if(is_regular_file(p))
//     {   
//         //Gather file information (name, id, type, aulabel)
//         string filename = p.string();
//         string fileID = filename.substr(21,3);
//         string file_type = "";
//         string auLabel = "";
//         if (filename.substr(25,1) == "t") {
//             file_type = "template";    
//         } else {
//             file_type = "au";
//             auLabel = filename.substr(27,2);
//         }
        
//         //Print out information
//         cout << "Filename: " << filename << endl;
//         cout << "File ID: " << filename.substr(21, 3) << " \t File Type: " << file_type; 
//         if (file_type == "au") {
//             cout << " \t AU Label: " << auLabel;
//         }
//         cout << endl;
//     } 
// }


//INFILE STUFF
// inFile.open(argv[1]);
// if(inFile.fail()) {
//     cout << "Error openning the file " << argv[1] << " \n";
//     exit(1);
// }

// OUTFILE STUFF
// outFile.open(argv[3]);
// if(outFile.fail()) {
//     cout << "Error openning the file " << argv[2] << " \n";
//     exit(1);
// }

// inFile >> MyPDB;
// outFile << MyPDB;


// inFile.close();
// outFile.close();


  return EXIT_SUCCESS;
}