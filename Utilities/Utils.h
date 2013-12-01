/****************************************************************
 * Header for the 'Utils' class for utility programs.
 *
 * Author/copyright:  Duncan Buell
 * Date: 11 May 2013
 *
 * This code performs utility functions, including:
 * 1.  check for appropriate number of arguments and print an
 *     output 'usage' message if incorrect.
 * 2.  open/close input, output, and log files.
 * 3.  timing
**/

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define NDEBUG
#include <cassert>

typedef unsigned int UINT;
typedef int64_t LONG;

using namespace std;

class Utils
{
public:
  static const string WHITESPACE;
/****************************************************************
 * Input, output, and log streams.
**/
//  static ifstream inStream; //deprecated
//  static ofstream outStream; //deprecated
  static ofstream logStream;

//  static stringstream utilsss(stringstream::in | stringstream::out);
  static stringstream ss;
  static ostringstream oss;

/****************************************************************
 * Constructors and destructors for the class. 
**/
  Utils();
  virtual ~Utils();

/****************************************************************
 * argument checker
**/
  static void CheckArgs(const int howMany, const int argc,
                        char *argv[], const string usage);

/****************************************************************
 * file open and close functions
**/
  static void FileClose(ifstream& inStream);
  static void FileClose(ofstream& outStream);
  static void FileOpen(ifstream& inStream, const string fileName);
  static void FileOpen(ofstream& outStream, const string fileName);
  static void InFileOpen(const string fileName);
//  static void OutFileOpen(const string fileName);
  static void LogFileOpen(const string fileName);

/****************************************************************
 * all sorts of formatting functions
**/
  static string Format(const char* value);
  static string Format(const char* value, const int width);
  static string Format(const char* value, const int width,
                       const string justify);

  static string Format(const string value);
  static string Format(const string value, const int width);
  static string Format(const string value, const int width,
                       const string justify);

  static string Format(const short value);
  static string Format(const short value, const int width);
  static string Format(const int value);
  static string Format(const int value, const int width);
  static string Format(const UINT value);
  static string Format(const UINT value, const int width);
  static string Format(const LONG value);
  static string Format(const LONG value, const int width);
  static string Format(const double value, const int width);
  static string Format(const double value, const int width,
                       const int precision);

/****************************************************************
 * conversion functions
**/
  static int stringToInteger(string input);
  static LONG stringToLONG(string input);

/****************************************************************
 * miscellaneous utility functions
**/
  static bool hasMoreData(ifstream& inStream);

  static string replaceBlanks(string input, char c);
  static string timecall(const string timestring);
  static void toLower(string& to, const string from);
  static string trimBlanks(string what);
  static string trim(string what);

private:
};

#endif /*UTILS_H_*/
