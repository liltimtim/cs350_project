#include "ScanLine.h"

using namespace std;

static const string TAG = "ScanLine: ";

// ifstream Utils::inStream; // deprecated
// ofstream Utils::outStream; // deprecated
//ofstream ScanLine::zorklogStream;
//ostringstream ScanLine::zorkoss;
//stringstream ScanLine::zorkss;

//stringstream ScanLine::myss;

/****************************************************************
 * Constructor.
**/
ScanLine::ScanLine()
{
}
/****************************************************************
 * Destructor.
**/
ScanLine::~ScanLine()
{
}

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function 'hasMoreData'.
 *
 * Returns:
 *   true if there are ANY more characters in the input 'string'
**/
bool ScanLine::hasMoreData()
{
  bool returnValue = true;
#ifdef EBUGS
  Utils::logStream << TAG << "enter hasMoreData" << endl;
  Utils::logStream.flush();
#endif
  
  if(scanLineSS.eof())
  {
    returnValue = false;
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave hasMoreData '" << returnValue << "'" << endl;
  Utils::logStream.flush();
#endif

  return returnValue;
} 

/****************************************************************
 * Initialization. This because I can't make constructors work.
**/
void ScanLine::openString(string line)
{
  string token;

#ifdef EBUGS
  Utils::logStream << TAG << "enter openString '" << line << "'" << endl;
  Utils::logStream.flush();
#endif
  
  scanLineSS.clear();
  scanLineSS.str(line);

#ifdef EBUGS
  Utils::logStream << TAG << "leave openString" << endl;
  Utils::logStream.flush();
#endif
} 

/****************************************************************
 * Function 'next' to return the next string.
 *
 * The definition of a 'token' is anything other than whitespace.
 * In this implementation, whitespace includes newline, carriage
 * return, and tab.
 *
 * Returns:
 *   the 'string' versin of the next token
**/
string ScanLine::next()
{
  string token;

#ifdef EBUGS
  Utils::logStream << TAG << "enter next" << endl;
  Utils::logStream.flush();
#endif
  
  token = "";
  if(!scanLineSS.eof())
  {
    scanLineSS >> token;
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave next '" << token << "'" << endl;
  Utils::logStream.flush();
#endif

  return token;
} 

/****************************************************************
 * Function 'nextInt' to return the next integer.
 *
 * This function does not really trap erorrs. Errors inconverting
 * from 'string' to 'int' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'int'
**/
int ScanLine::nextInt()
{
  int nextValue = 0;
  string token = "";

#ifdef EBUGS
  Utils::logStream << TAG << "enter nextInt" << endl;
  Utils::logStream.flush();
#endif
  
  if(!scanLineSS.eof())
  {
    scanLineSS >> token;
    nextValue = Utils::stringToInteger(token); 
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave nextInt '" << nextValue << "'" << endl;
  Utils::logStream.flush();
#endif

  return nextValue;
} 

/****************************************************************
 * Function 'nextLine' to return the rest of the line.
 *
 * This is just a wrapper for the 'getline' function.
 * Note that this does not trim whitespace at the beginning
 * or at the end.
 *
 * CAVEAT: We have put a max of 1024 characters that can be
 *         parsed with this function.
 *
 * Returns:
 *   the 'string' version of the rest of the line
**/
string ScanLine::nextLine()
{
  char xx[1025];
  string token;

#ifdef EBUGS
  Utils::logStream << TAG << "enter nextLine" << endl;
  Utils::logStream.flush();
#endif
  
  scanLineSS.getline(xx,1024);
  token = string(xx);

#ifdef EBUGS
  Utils::logStream << TAG << "leave nextLine '" << token << "'" << endl;
  Utils::logStream.flush();
#endif

  return token;
} 

/****************************************************************
 * Function 'nextLONG' to return the next LONG.
 *
 * This function does not really trap errors. Errors in converting
 * from 'string' to 'LONG' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'LONG'
**/
LONG ScanLine::nextLONG()
{
  LONG nextValue = 0;
  string token = "";

#ifdef EBUGS
  Utils::logStream << TAG << "enter nextLONG" << endl;
  Utils::logStream.flush();
#endif
  
  if(!scanLineSS.eof())
  {
    scanLineSS >> token;
    nextValue = Utils::stringToLONG(token); 
  }

#ifdef EBUGS
  Utils::logStream << TAG << "leave nextLONG '" << nextValue << "'" << endl;
  Utils::logStream.flush();
#endif

  return nextValue;
} 

/****************************************************************
 * Test function to read.
void ScanLine::zork()
{
  string token;

#ifdef EBUGS
  Utils::logStream << TAG << "enter zork" << endl;
  Utils::logStream.flush();
#endif
  
// while(!scanLineSS.eof())
  while(this->hasNext())
  {
    token = next();

    Utils::logStream << TAG << "mytoken '" << token << "'" << endl;
    Utils::logStream.flush();
  }
  scanLineSS.clear();

#ifdef EBUGS
  Utils::logStream << TAG << "leave zork" << endl;
  Utils::logStream.flush();
#endif
} 
**/

