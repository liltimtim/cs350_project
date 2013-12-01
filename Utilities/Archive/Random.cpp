#include "Random.h"

static const char TAG[] = "Random: ";

/****************************************************************
 * Constructor.
**/
Random::Random()
{
}

/****************************************************************
 * Destructor.
**/
Random::~Random()
{
}

/****************************************************************
 * Accessors and mutators.
**/

/****************************************************************
 * General functions.
**/
/****************************************************************
 * open the files
void Random::openFiles()
{
  string s = "zrandomdouble10m.txt";
  Utils::FileOpen(localStreamDouble, s);
  string s = "zrandomgaussian10m.txt";
  Utils::FileOpen(localStreamGaussian, s);
}
**/

/****************************************************************
 * close the file
void Random::close()
{
  Utils::FileClose(localStreamDouble);
  Utils::FileClose(localStreamGaussian);
}
**/

/****************************************************************
 * Function for returning a next double.
**/
double Random::nextDouble(Scanner inFile)
{
  int sequence;
  double returnValue;
//  Utils::logStream << TAG << "enter nextDouble" << endl;
//  Utils::logStream.flush();

  sequence = inFile.nextInt();
  returnValue = inFile.nextDouble();

  Utils::logStream << TAG << "seq nextDouble " << sequence << " " << returnValue << endl;
  Utils::logStream.flush();

//  Utils::logStream << TAG << "leave nextDouble" << endl;
//  Utils::logStream.flush();
  return returnValue;
} // double Random::nextDouble(Scanner inFile)

/****************************************************************
 * Function for returning a next gaussian.
**/
double Random::nextGaussian(Scanner inFile)
{
  int sequence;
  double returnValue;
//  Utils::logStream << TAG << "enter nextGaussian" << endl;
//  Utils::logStream.flush();

  sequence = inFile.nextInt();
  returnValue = inFile.nextDouble();

  Utils::logStream << TAG << "seq nextGaussian " << sequence << " " << returnValue << endl;
  Utils::logStream.flush();

//  Utils::logStream << TAG << "leave nextGaussian" << endl;
//  Utils::logStream.flush();
  return returnValue;
} // double Random::nextGaussian(Scanner inFile)

/****************************************************************
 * Function for returning a next random.
**/
double Random::nextRandom(Scanner inFile)
{
  int sequence;
  double returnValue;
//  Utils::logStream << TAG << "enter nextDouble" << endl;
//  Utils::logStream.flush();

  sequence = inFile.nextInt();
  returnValue = inFile.nextDouble();

  Utils::logStream << TAG << "seq nextRandom " << sequence << " " << returnValue << endl;
  Utils::logStream.flush();

//  Utils::logStream << TAG << "leave nextDouble" << endl;
//  Utils::logStream.flush();
  return returnValue;
} // double Random::nextRandom(Scanner inFile)

