#include "Utils.h"

using namespace std;

static const string TAG = "Utils: ";
const string Utils::WHITESPACE = " \n\t\r";

// ifstream Utils::inStream; // deprecated
// ofstream Utils::outStream; // deprecated
ofstream Utils::logStream;
ostringstream Utils::oss;
stringstream Utils::ss;

/****************************************************************
 * Constructor.
**/
Utils::Utils()
{
}
/****************************************************************
 * Destructor.
**/
Utils::~Utils()
{
}

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Check for the correct number of arguments.
 *
 * Parameters:
 *   howMany - the expected number of arguments
 *   argc - the usual 'argc' of command line information
 *   argv - the usual 'argv' of command line information
 *   usage - the 'usage' message to display on error
 * Return: none
**/
void Utils::CheckArgs(const int howMany, const int argc,
                      char *argv[], const string usage)
{
  if(argc != howMany + 1)
  {
    cout << TAG << "incorrect argument count" << endl;
    cout << TAG << "usage: " << argv[0] << " " << usage << endl;
    exit(1);
  }
}

/****************************************************************
 * Close an input stream.
 *
 * Parameters:
 *   inStream - the 'ifstream' input stream by reference
 * Return: none
**/
void Utils::FileClose(ifstream& inStream)
{
  cout << TAG << "close the input file" << endl;
  inStream.close();
  cout << TAG << "the input file was closed" << endl;
}

/****************************************************************
 * Close an output stream.
 *
 * Parameters:
 *   outStream - the 'ofstream' output stream by reference
 * Return: none
**/
void Utils::FileClose(ofstream& outStream)
{
  cout << TAG << "close the output file" << endl;
  outStream.close();
  cout << TAG << "the output file was closed" << endl;
}

/****************************************************************
 * Open an input stream.
 *
 * Parameters:
 *   inStream - the 'ifstream' input stream by reference
 *   fileName - the name of the file to be opened
 * Return: none
**/
void Utils::FileOpen(ifstream& inStream, string fileName)
{
  cout << TAG << "open the input file '" << fileName << "'" << endl;
  inStream.open(fileName.c_str());
  if(inStream.fail())
  {
    cout << TAG << "open failed for " << fileName << endl;
    exit(0);
  }
  cout << TAG << "open succeeded for '" << fileName << "'" << endl;
}

/****************************************************************
 * Open an output stream.
 *
 * Parameters:
 *   outStream - the 'ofstream' output stream by reference
 *   fileName - the name of the file to be opened
 * Return: none
**/
void Utils::FileOpen(ofstream& outStream, string fileName)
{
  cout << TAG << "open the output file '" << fileName << "'" << endl;
  outStream.open(fileName.c_str());
  if(outStream.fail())
  {
    cout << TAG << "open failed for " << fileName << endl;
    exit(0);
  }
  cout << TAG << "open succeeded for '" << fileName << "'" << endl;
}

/****************************************************************
 * Open the static input stream.  DEPRECATED
 *
 * Parameters:
 *   fileName - the name of the file to associate with
 *              the 'Utils::inStream'
 * Return: none
void Utils::InFileOpen(string fileName)
{
  cout << TAG << "open the input file '" << fileName << "'" << endl;
  inStream.open(fileName.c_str());
  if(inStream.fail())
  {
    cout << TAG << "open failed for " << fileName << endl;
    exit(0);
  }
  cout << TAG << "open succeeded for '" << fileName << "'" << endl;
}
**/

/****************************************************************
 * Open the static logfile stream.
 *
 * Parameters:
 *   fileName - the name of the file to associate with
 *              the 'Utils::logStream'
 * Return: none
**/
void Utils::LogFileOpen(string fileName)
{
  cout << TAG << "open the logfile '" << fileName << "'" << endl;
  logStream.open(fileName.c_str());
  if(logStream.fail())
  {
    cout << TAG << "open failed for " << fileName << endl;
    exit(0);
  }
  cout << TAG << "open succeeded for '" << fileName << "'" << endl;
}

/****************************************************************
 * Open the static output stream.  DEPRECATED
 *
 * Parameters:
 *   fileName - the name of the file to associate with
 *              the 'Utils::outStream'
 * Return: none
void Utils::OutFileOpen(string fileName)
{
  cout << TAG << "open the output file '" << fileName << "'" << endl;
  outStream.open(fileName.c_str());
  if(outStream.fail())
  {
    cout << TAG << "open failed for " << fileName << endl;
    exit(0);
  }
  cout << TAG << "open succeeded for '" << fileName << "'" << endl;
}
**/

/****************************************************************
 * These are the overloaded formatting functions that all return
 * a 'string' value after having formatted the first argument.
 * 
 * We have the following formatting:
 *   'char*' to a 'string' 
 *   'char*' to a 'string' of 'width' (default right) 
 *   'char*' to a 'string' of 'width' (left or right, default right) 
 *
 *   'string' to a 'string' 
 *   'string' to a 'string' of 'width' (default right) 
 *   'string' to a 'string' of 'width' (left or right, default right) 
 *
 *   'short'     to a 'string'
 *   'short'     to a 'string' of 'width'
 *   'int'       to a 'string'
 *   'int'       to a 'string' of 'width'
 *   'UINT'      to a 'string'
 *   'UINT'      to a 'string' of 'width'
 *   'LONG'      to a 'string'
 *   'LONG'      to a 'string' of 'width'
 *
 *   'double' to a 'string'
 *   'double' to a 'string' of 'width'
 *   'double' to a 'string' of 'width' and 'precision'
 *
**/
/****************************************************************
 * String-ify a 'char*' array, without width formatting.
 *
 * Parameters:
 *   value - the 'char*' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const char* value)
{
  Utils::oss.str("");
  Utils::oss << string(value);
  return oss.str();
} // string Utils::Format(char* value)

/****************************************************************
 * String-ify a 'char*' array, with width formatting.  This
 * justifies using the default left justification.
 *
 * Parameters:
 *   value - the 'char*' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const char* value, const int width)
{
  Utils::oss.str("");
  Utils::oss << setw(width) << string(value);
  return oss.str();
} // string Utils::Format(char* value, LONG width)

/****************************************************************
 * String-ify a 'char*' array, with width formatting and with
 * specified justification.
 *
 * Parameters:
 *   value - the 'char*' variable to be converted and formatted.
 *   width - the width of the output field.
 *   justify - desired justification, either 'right' or 'left'
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const char* value, const int width,
                     const string justify)
{
  Utils::oss.str("");

  if("left" == justify)
  {
    Utils::oss.setf(ios::left, ios::adjustfield);
    Utils::oss << setw(width) << string(value);
  }
  else if("right" == justify)
  {
    Utils::oss.setf(ios::right, ios::adjustfield);
    Utils::oss << setw(width) << string(value);
  }
  else
  {
    Utils::oss << setw(width) << string(value);
  }
  return oss.str();
} // string Utils::Format(char* value, LONG width, string justify)

/****************************************************************
 * String-ify a string, without width formatting and without
 * specified justification.  This is just a pass-through.
 *
 * Parameters:
 *   value - the 'string' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const string value)
{
  return value;
} // string Utils::Format(string value)

/****************************************************************
 * String-ify a string, with width formatting but and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'string' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const string value, const int width)
{
  Utils::oss.str("");
  Utils::oss << setw(width) << value;
  return oss.str();
} // string Utils::Format(string value, LONG width)

/****************************************************************
 * String-ify a 'string', with width formatting and with
 * specified justification.
 *
 * Parameters:
 *   value - the 'string' variable to be converted and formatted.
 *   width - the width of the output field.
 *   justify - desired justification, either 'right' or 'left'
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const string value, const int width,
                     const string justify)
{
  Utils::oss.str("");
  if("left" == justify)
  {
    Utils::oss.setf(ios::left, ios::adjustfield);
    Utils::oss << setw(width) << value;
  }
  else if("right" == justify)
  {
    Utils::oss.setf(ios::right, ios::adjustfield);
    Utils::oss << setw(width) << value;
  }
  else
  {
    Utils::oss << setw(width) << value;
  }
  return oss.str();
} // string Utils::Format(string value, LONG width, string justify)

/****************************************************************
 * String-ify a 'short', without width formatting and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'short' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const short value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
} // string Utils::Format(short value)

/****************************************************************
 * String-ify a 'short', with width formatting but without
 * specified justification.
 *
 * Parameters:
 *   value - the 'short' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const short value, const int width)
{
  Utils::oss.str("");
  Utils::oss << setw(width) << value;
  return oss.str();
} // string Utils::Format(short value, LONG width)

/****************************************************************
 * String-ify an 'int', without width formatting and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'int' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const int value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
} // string Utils::Format(int value)

/****************************************************************
 * String-ify an 'int', with width formatting but without
 * specified justification.
 *
 * Parameters:
 *   value - the 'int' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const int value, const int width)
{
  Utils::oss.str("");
  Utils::oss.setf(ios::right, ios::adjustfield);
  Utils::oss << setw(width) << value;
  return oss.str();
} // string Utils::Format(int value, LONG width)

/****************************************************************
 * String-ify a 'UINT', without width formatting and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'UINT' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const UINT value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
} // string Utils::Format(UINT value)

/****************************************************************
 * String-ify a 'UINT', with width formatting but without
 * specified justification.
 *
 * Parameters:
 *   value - the 'UINT' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const UINT value, const int width)
{
  Utils::oss.str("");
  Utils::oss << setw(width) << value;
  return oss.str();
} // string Utils::Format(UINT value, LONG width)

/****************************************************************
 * String-ify a 'LONG', without width formatting and without
 * specified justification.
 *
 * Parameters:
 *   value - the 'LONG' variable to be converted and formatted.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const LONG value)
{
  Utils::oss.str("");
  Utils::oss << value;
  return oss.str();
} // string Utils::Format(LONG value)

/****************************************************************
 * String-ify a 'LONG', with width formatting but without
 * specified justification.
 *
 * Parameters:
 *   value - the 'LONG' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const LONG value, const int width)
{
  int localWidth = static_cast<int>(width);
  Utils::oss.str("");
  Utils::oss << setw(localWidth) << value;
  return oss.str();
} // string Utils::Format(LONG value, LONG width)

/****************************************************************
 * String-ify a 'double', with width formatting but without
 * specified precision.
 *
 * Parameters:
 *   value - the 'double' variable to be converted and formatted.
 *   width - the width of the output field.
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const double value, const int width)
{
  Utils::oss.str("");
  Utils::oss << setw(width) << value;
  return oss.str();
} // string Utils::Format(double value, LONG width)

/****************************************************************
 * String-ify a 'double', with width formatting and with
 * specified precision.
 *
 * Parameters:
 *   value - the 'int' variable to be converted and formatted.
 *   width - the width of the output field.
 *   precision - desired precision to the right of the point
 * Return: the string-ified version of 'value'
**/
string Utils::Format(const double value, const int width,
                     const int precision)
{
  Utils::oss.str("");
  Utils::oss << fixed << setprecision(precision) << setw(width)
             << value;
  return oss.str();
} // string Utils::Format(const double value, const LONG width,

/****************************************************************
 * Determine if there is more data in the file.
 *
 * This program is intended to mimic the Java 'hasNext' method.
 * This program uses the 'get' and 'peek' functions to read
 * whitespace characters until non-whitespace or EOF is found.
 *
 * Parameters:
 *   inStream - the input stream to test
 * Returns:
 *   the boolean 'true' if there is more nonwhitespace data.
**/
bool Utils::hasMoreData(ifstream& inStream)
{
  bool moreData;
  char c;
//  string whitespace = " \n\r\t";
  size_t foundPos = string::npos;

  moreData = false;
  c = inStream.get();
  if(!inStream.eof())
  {
    while(!inStream.eof())
    {
//      foundPos = whitespace.find(c);
      foundPos = Utils::WHITESPACE.find(c);
      if(foundPos == string::npos)
      {
        moreData = true;
        inStream.putback(c);
        break;
      }
      c = inStream.get();
    }
  }

  return moreData;
} // bool Utils::hasMoreData(ifstream& inStream)

/****************************************************************
 * Replace blanks with another character.
 * This is to allow using an underscore to make a string one string
 * instead of having embedded blanks. 
 *
 * Parameters:
 *   what - the input 'string' to trim blanks from
 * Returns:
 *   the 'what' string less any leading or trailing blanks
**/
string Utils::replaceBlanks(string input, char c)
{
  string returnValue;

  returnValue = input;

  string::size_type pos = returnValue.find(" ");
  while(pos != string::npos)
  {
    returnValue[pos] = c;
    pos = returnValue.find(" ");
  }

  return returnValue;
} // string Utils::replaceBlanks(char c)

/****************************************************************
 * Convert a string to an integer.
 *
 * Parameters:
 *   input - the input 'string' to convert from
 * Returns:
 *   the 'int' value of 'input'
**/
int Utils::stringToInteger(string input)
{
  bool isNegative;
  int returnValue = 0;
  const string digits = "0123456789";

//  Utils::logStream << TAG << "string '" << input << "'" << endl;
//  Utils::logStream.flush();
  isNegative = false;
  if("-" == input.substr(0,1))
  { 
//    Utils::logStream << TAG << "negative '" << input.substr(0,1) << "'" << endl;
//    Utils::logStream.flush();
    isNegative = true;
    input = input.substr(1);
  }
//  Utils::logStream << TAG << "now pos '" << input << "'" << endl;
//  Utils::logStream.flush();

  for(string::iterator iter = input.begin(); iter != input.end(); ++iter)
  {
    int digit = digits.find(*iter);
    if((0 > digit) || (9 < digit))
    {
      Utils::logStream << TAG << "ERROR: string '" << input
                       << "' not a number" << endl;
      Utils::logStream.flush();
      exit(0);
    }
    returnValue = 10*returnValue + digit;
  }

  if(isNegative) returnValue = -returnValue;

  return returnValue;
} // int Utils::stringToInteger(string input)

/****************************************************************
 * Convert a string to a LONG.
 *
 * Parameters:
 *   input - the input 'string' to convert from
 * Returns:
 *   the 'int' value of 'input'
**/
LONG Utils::stringToLONG(string input)
{
  LONG returnValue = 0L;
  const string digits = "0123456789";

  for(string::iterator iter = input.begin(); iter != input.end(); ++iter)
  {
    int digit = digits.find(*iter);
    if((0 > digit) || (9 < digit))
    {
      Utils::logStream << TAG << "ERROR: string '" << input
                       << "' not a number" << endl;
      Utils::logStream.flush();
      exit(0);
    }
    returnValue = 10*returnValue + digit;
  }

  return returnValue;
} // LONG Utils::stringToLONG(string input)

/****************************************************************
 * Call the timing function
 *
 * Parameters:
 *   timestring - the label to be put into the time log
 * Returns: the 'string' version of the timing log
**/
string Utils::timecall(const string timestring)
{
  char s[160];
  string returnValue;
  static bool firsttime = true;
  static double usercurrent = 0.0,userone = 0.0,usertwo = 0.0;
  static double systemcurrent = 0.0,systemone = 0.0,systemtwo = 0.0;
  static double cpupctone,cpupcttwo;
  static double TIMEsystemtotal,TIMEusertotal;
  static struct rusage rusage;
  static time_t TIMEtcurrent,TIMEtone,TIMEttotal = 0.0,TIMEttwo;

  if(firsttime)
  {
    firsttime = false;
    TIMEusertotal = 0.0;
    TIMEsystemtotal = 0.0;
    TIMEtone = time(0);
    TIMEttwo = time(0);
  }

  getrusage(RUSAGE_SELF,&rusage);

  usertwo = (double) rusage.ru_utime.tv_sec;
  usertwo += (double) rusage.ru_utime.tv_usec/1000000.0;
  systemtwo = (double) rusage.ru_stime.tv_sec;
  systemtwo += (double) rusage.ru_stime.tv_usec/1000000.0;

  usercurrent = usertwo - userone;
  systemcurrent = systemtwo - systemone;

  TIMEusertotal += usercurrent;
  TIMEsystemtotal += systemcurrent;

  TIMEttwo = time(0);
  TIMEtcurrent = TIMEttwo - TIMEtone;
  TIMEttotal += TIMEtcurrent;
  if(TIMEtcurrent != 0)
  {
    cpupctone = 100.0 * ((double)usercurrent+systemcurrent) /
                           ((double)(TIMEtcurrent));
    if(cpupctone > 100.0) cpupctone = 100.0;
  }
  else
  {
    cpupctone = 0.0;
  }

  if(TIMEttotal != 0)
  {
    cpupcttwo = 100.0 * ((double)TIMEusertotal+TIMEsystemtotal) /
                           ((double)(TIMEttotal));
    if(cpupcttwo > 100.0) cpupcttwo = 100.0;
  }
  else
  {
    cpupcttwo = 0.0;
  }

  returnValue = "";
  snprintf(s,80,"\nTIME***********************************************************************\n");
  returnValue += string(s);

  snprintf(s,80,"TIME CPU percent  %6.2f %6.2f                    %s",
             cpupctone,cpupcttwo,ctime(&TIMEttwo));
  returnValue += string(s);

  snprintf(s,80,"TIME %-15s %10.2f u   %10.2f s   Res:%12ld\n",
                 timestring.c_str(),usercurrent,systemcurrent, rusage.ru_maxrss);
  returnValue += string(s);

  snprintf(s,80,"TIME %-15s %10.2f u_t %10.2f s_t\n",
                 timestring.c_str(),TIMEusertotal,TIMEsystemtotal);
  returnValue += string(s);

  snprintf(s,80,"TIME***********************************************************************\n");
  returnValue += string(s);

  returnValue += "\n\n";

  userone = usertwo;
  systemone = systemtwo;
  TIMEtone = TIMEttwo;

  return returnValue;
} // string Utils::timecall(const string timestring)

/****************************************************************
 * Convert a string to all lowercase.
 *
 * Parameters:
 *   to - the input 'string' to convert 
 *   from - the output converted 'string'
 * Returns: none
**/
void Utils::toLower(string& to, const string from)
{
  static char c[80];

  snprintf(c, 80, "%s", from.c_str());
  for(UINT i = 0; i < from.length(); ++i)
  {
    if(isupper(c[i])) c[i] = tolower(c[i]);
  }
  to = string(c);
} // void Utils::toLower(string& to, const string from)

/****************************************************************
 * Trim away leading and trailing blanks.
 *
 * Parameters:
 *   what - the input 'string' to trim blanks from
 * Returns:
 *   the 'what' string less any leading or trailing blanks
**/
string Utils::trimBlanks(string what)
{
  int length;
  string returnValue;

  returnValue = what;

  // trim away leading blanks
  while(" " == returnValue.substr(0,1))
  {
    length = returnValue.length();
    returnValue = returnValue.substr(1,length);
  }

  // trim away trailing blanks
  if(!returnValue.empty())
  {
    length = returnValue.length();
    while(" " == returnValue.substr(length-1,1))
    {
      returnValue = returnValue.substr(0,length-1);
      length = returnValue.length();
    }
  }

  return returnValue;
} // string Utils::trimBlanks(string what)

/****************************************************************
 * General function for trimming whitespace from begin and end.
 *
 * Parameters:
 *   s - the input 'string' to trim blanks from
 * Returns:
 *   the 's' string less any leading or trailing whitespace
**/
string Utils::trim(string s)
{
  size_t foundPos = string::npos;
  string returnString = s;

#ifdef EBUG3
  Utils::logStream << TAG << "orig string: '" << returnString << "'" << endl;
  Utils::logStream.flush();
#endif

  foundPos = returnString.find_first_not_of(Utils::WHITESPACE);
#ifdef EBUG3
  Utils::logStream << TAG << "found first: " << foundPos << endl;
  Utils::logStream.flush();
#endif
  if(foundPos != string::npos)
  {
    returnString = s.substr(foundPos);
  }
#ifdef EBUG3
  Utils::logStream << TAG << "new string:  '" << returnString << "'" << endl;
  Utils::logStream.flush();
#endif

  foundPos = returnString.find_last_not_of(Utils::WHITESPACE);
#ifdef EBUG3
  Utils::logStream << TAG << "found last:  " << foundPos << endl;
  Utils::logStream.flush();
#endif
  if(foundPos != string::npos)
  {
    returnString = returnString.substr(0,foundPos+1);
  }
#ifdef EBUG3
  Utils::logStream << TAG << "new string:  '" << returnString << "'" << endl;
  Utils::logStream.flush();
#endif

  return returnString;
} // string Utils::trim(string s)

