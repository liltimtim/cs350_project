/****************************************************************
 * Header for the 'Scanner' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 9 May 2013
 *
**/

#ifndef SCANNER_H_
#define SCANNER_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

#include "Utils.h"

#define NDEBUG
#include <cassert>

typedef int64_t LONG;

using namespace std;

class Scanner
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Scanner();
//  Scanner(ifstream& inStream);
//  Scanner(string inFileName);
  virtual ~Scanner();

/****************************************************************
 * Variables.
**/
  ifstream localStream;

/****************************************************************
 * General functions.
**/
  void close();
  bool hasMoreData();
  char nextChar();
  double nextDouble();
  string next();
  string nextLine();
  void openFile(string fileName);
  int nextInt();
  LONG nextLONG();
};

#endif // SCANNER_H_
