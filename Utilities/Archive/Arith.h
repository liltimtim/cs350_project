/****************************************************************
 * Header for the 'Arith' class for arithmetic programs.
 *
 * Author/copyright:  Duncan Buell
 * Date: 13 January 2010
 *
 * This code performs arithmetic functions for basic number theory.
**/


#ifndef ARITH_H_
#define ARITH_H_

#include <iostream>
//#include <fstream>
#include <cstdlib>
//#include <string>
//#include <time.h>
//#include <sys/time.h>
//#include <sys/resource.h>

#include <gmp.h>
#include <gmpxx.h>

#ifdef WORK
#include "/acct/f1/buell/LINUX/progs/progs.cpp/Utilities/Utils.h"
#elif HOME
#include "/home/duncan/progs/progs.cpp/Utilities/Utils.h"
#else
#error One of 'HOME' or 'WORK' must be defined.
#endif

using namespace std;

class Arith
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Arith();
  virtual ~Arith();

/****************************************************************
 * Testing functions.
**/
  static void testaxbm();
  static void testaxbm_gmp();
  static void testeuclid();
  static void testeulerphi();
  static void testjacobi();
  static void testprimroot();
  static void testprimroot_gmp();
  static void teststarstar();
  static void teststarstar_gmp();

/****************************************************************
 * Number-theoretic functions.
**/
  static long long axbm(long long ain, long long bin, long long min);
  static mpz_class axbm(const mpz_class& ain, const mpz_class& bin,
                        const mpz_class& min);

  static void euclid(long long ain, long long bin,
                     long long& x, long long& y, long long& m);
  static void euclid(const mpz_class& ain, const mpz_class& bin,
                     mpz_class& x, mpz_class& y, mpz_class& m);

  static long long eulerphi(long long n);

  static long long gcd(long long a, long long b);

  static long long jacobi(long long p, long long q);

  static long long primroot(long long p);
  static mpz_class primroot(const mpz_class& p);

  static long long starstar(long long x, long long n);
  static mpz_class starstar(const mpz_class& x, const mpz_class& n);

/****************************************************************
 * GMP functions.
**/
  static void printbignum(string head, mpz_t mpnum,
                          char c, long long width);
  static void printbignum(string head, mpz_class mpnum,
                          char c, long long width);

private:
};

#endif /*ARITH_H_*/
