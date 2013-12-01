/****************************************************************
 * Header for the 'FormMPZ' class for binary quadratic forms
 * using gmp for the underlying arithmetic.
 *
 * Author/copyright:  Duncan Buell
 * Date: 14 January 2010
 *
 * This code is the basic data class for forms.
**/


#ifndef FORMMPZ_H_
#define FORMMPZ_H_

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

class FormMPZ
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  FormMPZ();
  virtual ~FormMPZ();

/****************************************************************
 * Functions
**/
  void computeDisc();
  mpz_class getA() const;
  mpz_class getB() const;
  mpz_class getC() const;
  mpz_class getDisc() const;
  void setA(const mpz_class what);
  void setB(const mpz_class what);
  void setC(const mpz_class what);
  void setDisc(const mpz_class what);
  void setForm(const mpz_class a, const mpz_class b, const mpz_class c);

  FormMPZ compound(const FormMPZ& g);
  mpz_class cycleInd();
  FormMPZ duplicate();
  void reduceDef();
  mpz_class reduceInd();
  mpz_class findc(const mpz_class a, const mpz_class b,
                  const mpz_class disc);
  string toString();

/****************************************************************
 * Overloads
**/
  const FormMPZ operator -() const;
  bool operator ==(const FormMPZ& f2) const;
  const FormMPZ operator *(const FormMPZ& f2) const;

/****************************************************************
 * Testing routines.
**/
  static void testformsdef();
//  static void testformsind();

private:

  mpz_class a, b, c;
  mpz_class disc;
};

#endif /*FORMMPZ_H_*/
