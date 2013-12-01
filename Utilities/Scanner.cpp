#include "Scanner.h"

static const string TAG = "Scanner: ";

/****************************************************************
 * Constructor.
**/
Scanner::Scanner()
{
}

/****************************************************************
 * Destructor.
**/
Scanner::~Scanner()
{
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Function to close the stream.
**/
void Scanner::close()
{
  Utils::FileClose(this->localStream);
}

/****************************************************************
 * Function for testing for more data in the file.
 *
 * Returns:
 *   true if there are ANY more characters of any sort in the file
**/
bool Scanner::hasMoreData()
{
  bool returnValue = true;
//  int cAsInt;

  char c = this->localStream.get();

  returnValue = true;
  if(c == EOF)
  {
    returnValue = false;
  }
  else
  {
    this->localStream.putback(c);
  }

  return returnValue;
} // bool Scanner::hasMoreData()

/****************************************************************
 * Function for returning a next token as a string.
 *
 * The definition of a 'token' is anything other than whitespace.
 * In this implementation, whitespace includes newline, carriage
 * return, and tab.
 *
 * We have two booleans to keep track of three states:
 *   have not yet found NWS (token beginning)
 *   have not yet found WS after finding NWS (token end)
 *
 * We read a character.
 * If there is no next character to be read
 *    Then we throw an error
 * While we are not at end of file:
 *    Test the char for NWS
 *    If NWS
 *       Set the bool that we have found NWS
 *       If we have found WS after NWS, 
 *          put back the NWS--it's the start of the next token
 *          break
 *       Else append the NWS to the token
 *    Else (i.e., if WS)
 *       If we have ever found NWS
 *          Set the bool that we have found WS after NWS
 *    Read the next character.
 *
 * Returns:
 *   the 'string' version of the next token.
**/
string Scanner::next()
{
  bool haveFoundTokenBegin;
  bool haveFoundTokenEnd;
  char c;
  string returnValue;
  size_t foundPos = string::npos;

  // read a character
  // if EOF, that's an error
  haveFoundTokenBegin = false;
  haveFoundTokenEnd = false;
  c = this->localStream.get();
//  cout << "first read X" << c << "X" << endl;

  if(this->localStream.eof())
  {
    Utils::logStream << TAG << "ERROR: no next to read" << endl;
    Utils::logStream.flush();
    exit(0);
  }
  else
  {
    // we toss whitespace if we have not found nonwhitespace
    // we append nonwhitespace to the return value

    // read until end of file or until beginning of next token
    while(!this->localStream.eof())
    {
      foundPos = Utils::WHITESPACE.find(c);
//      cout << "whitespace lookup " << foundPos << endl;

      if(foundPos == string::npos)
      {
//        cout << "not whitespace X" << c << "X" << endl;
        haveFoundTokenBegin = true;
        if(haveFoundTokenEnd)
        {
//          cout << "found end, put back " << c << endl;
          this->localStream.putback(c);
          break;
        }
        returnValue = returnValue.append(1, c);
//        cout << "new returnvalue X" << returnValue << "X" << endl;
      }
      else
      {
//        cout << "yes it is whitespace X" << c << "X" << endl;
        // we found whitespace
        // now read until it isn't white space
        if(haveFoundTokenBegin)
        {
//          cout << "yes whitespace beyond the token X" << c << "X" << endl;
          haveFoundTokenEnd = true;
          this->localStream.putback(c); // new line 20130914
          break;
        }
      } // if(foundPos == string::npos)

      c = this->localStream.get();
//      cout << "next read X" << c << "X" << endl;

    } // while(!localStream.eof())
  } // if(localStream.eof())

  return returnValue;
} // string Scanner::next()

/****************************************************************
 * Function for returning a next character.
 *
 * Returns:
 *   the next character in the file
**/
char Scanner::nextChar()
{
  char c = this->localStream.get();
  return c;
} // char Scanner::nextChar()

/****************************************************************
 * Function for returning a next 'double'.
 *
 * This function does not trap errors. Errors in converting from
 * 'string' to 'double' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as a 'double'
**/
double Scanner::nextDouble()
{
  double returnValue;

  string nextToken = this->next();
  returnValue = atof(nextToken.c_str());

  return returnValue;
} // double Scanner::nextDouble()

/****************************************************************
 * Function for returning the next 'int' value.
 *
 * This function does not really trap errors. Errors in converting
 * from 'string' to 'int' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'int'
**/
int Scanner::nextInt()
{
  int returnValue;
  string nextToken;

  returnValue = 0;
  nextToken = this->next();

  returnValue = Utils::stringToInteger(nextToken);

  return returnValue;
} // int Scanner::nextInt()

/****************************************************************
 * Function for returning the rest of the line as a string.
 *
 * This is just a wrapper for the 'getline' function.
 * Note that this does not trim whitespace at the beginning
 * or at the end.
 *
 * Returns:
 *   the 'string' version of the rest of the line
**/
string Scanner::nextLine()
{
  string returnValue;

  getline(this->localStream, returnValue);

  return returnValue;
} // string Scanner::nextLine()

/****************************************************************
 * Function for returning the next 'LONG' value.
 *
 * This function does not really trap errors. Errors in converting
 * from 'string' to 'LONG' simply cause crashing.
 *
 * Returns:
 *   the next token in the file, parsed as an 'LONG'
**/
LONG Scanner::nextLONG()
{
  LONG returnValue;
  string nextToken;

  returnValue = 0;
  nextToken = this->next();

  returnValue = Utils::stringToLONG(nextToken);

  return returnValue;
} // LONG Scanner::nextLONG()

/****************************************************************
 * Function to open a file as a 'Scanner'.
**/
void Scanner::openFile(string fileName)
{
  Utils::FileOpen(this->localStream, fileName);
}

