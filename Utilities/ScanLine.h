/****************************************************************
 * Header for the 'ScanLine' class for utility programs.
 *
 * Author/copyright:  Duncan Buell
 * Date: 16 July 2013
 *
 * This code performs the utility function of being a 'Scanner'
 * for a string, analogous to what a 'Scanner' does on a file.
**/

#ifndef SCANLINE_H
#define SCANLINE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "../Utilities/Utils.h"
#include "../Utilities/Scanner.h"

#define NDEBUG
#include <cassert>

typedef unsigned int UINT;
typedef int64_t LONG;

using namespace std;

class ScanLine
{
public:
//  static const string WHITESPACE;
/****************************************************************
 * Input, output, and log streams.
**/
//  static ofstream zorklogStream;

//  static stringstream zorkss;
//  static ostringstream zorkoss;

  stringstream scanLineSS;

/****************************************************************
 * Constructors and destructors for the class. 
**/
  ScanLine();
  virtual ~ScanLine();

/****************************************************************
 * General functions.
**/
  bool hasMoreData();
  void openString(string line);
  string next();
  int nextInt();
  LONG nextLONG();
  string nextLine();

private:

};

#endif // SCANLINE_H
