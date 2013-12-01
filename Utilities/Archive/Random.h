/****************************************************************
 * Header for the 'Random' class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 29 May 2013
 *
**/

#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

#include "Utils.h"
#include "Scanner.h"

#define NDEBUG
#include <cassert>

typedef int64_t LONG;

using namespace std;

class Random
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Random();
  virtual ~Random();

/****************************************************************
 * Variables.
  Scanner localScannerDouble;
  Scanner localScannerGaussian;
**/

/****************************************************************
 * General functions.
**/
  double nextDouble(Scanner inFile);
  double nextGaussian(Scanner inFile);
  double nextRandom(Scanner inFile);
};

#endif // RANDOM_H
