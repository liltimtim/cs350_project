/****************************************************************
 * Header for the 'Form' class for binary quadratid forms.
 *
 * Author/copyright:  Duncan Buell
 * Date: 14 January 2010
 *
 * This code is the basic data class for forms.
**/


#ifndef FORM_H_
#define FORM_H_

#include <iostream>
//#include <fstream>
//#include <cstdlib>
#include <string>
//#include <time.h>
//#include <sys/time.h>
//#include <sys/resource.h>
#include <cmath>

#ifdef WORK
#include "/acct/f1/buell/LINUX/progs/progs.cpp/Utilities/Utils.h"
#include "/acct/f1/buell/LINUX/progs/progs.cpp/Utilities/Arith.h"
#elif HOME
#include "/home/duncan/progs/progs.cpp/Utilities/Utils.h"
#include "/home/duncan/progs/progs.cpp/Utilities/Arith.h"
#else
#error One of 'HOME' or 'WORK' must be defined.
#endif

using namespace std;

class Form
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Form();
  virtual ~Form();

/****************************************************************
 * Functions
**/
  void computeDisc();
  long long getA() const;
  long long getB() const;
  long long getC() const;
  long long getDisc() const;
  void setA(long long what);
  void setB(long long what);
  void setC(long long what);
  void setDisc(long long what);
  void setForm(long long a, long long b, long long c);

  Form compound(const Form& g);
  long long cycleInd();
  Form duplicate();
  void reduceDef();
  long long reduceInd();
  long long findc(long long a, long long b, long long disc);
  string toString();

/****************************************************************
 * Overloads
**/
  const Form operator -() const;
  bool operator ==(const Form& f2) const;
  const Form operator *(const Form& f2) const;

/****************************************************************
 * Testing routines.
**/
  static void testformsdef(ifstream inStream);
  static void testformsind(ifstream inStream);

private:

  long long a, b, c;
  long long disc;
};

#endif /*FORM_H_*/
