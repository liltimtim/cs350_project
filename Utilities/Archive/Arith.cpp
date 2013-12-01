#include "Arith.h"

static const char TAG[] = "Arith: ";

/****************************************************************
 * Constructor.
**/
Arith::Arith()
{
}
/****************************************************************
 * Destructor.
**/
Arith::~Arith()
{
}

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Compute 'x', such that a*x = b (mod m)
 *      returns x as value of function
 *
 *      returns -m if congruence is 0 = 0
 *               1 if congruence is (0) = (<>0)
 *               g = gcd(a,m) if g does not divide b
**/
long long Arith::axbm(long long ain, long long bin, long long min)
{
  long long a, b, m, n1, n2, n3, q, r, sgn, t, x;

  a = ain % min;
  if(a < 0L)
    a += min;
  if(0L == a)
  {
    if(0L == (bin % min))
    {
      /*      congruence is 0 = 0     */
      return(-min);
    }
    else
    {
      /*      error--congruence is (0) = (<>0)        */
      printf("\nerror--zero is not zero\n");
      return(-1L);
    }
  }

  m = min;
  a = ain % m;
  q = m / a;
  r = m % a;
  n1 = 0L;
  n2 = 1L;
  sgn = 1L;
  while (r != 0L)
  {
    sgn = -sgn;
    n3 = n2 * q + n1;
    n1 = n2;
    n2 = n3;
    m = a;
    a = r;
    q = m / a;
    r = m % a;
  }

  b = bin / a;
  t = bin % a;
  if (t != 0L)
  {
    /*      error--gcd(a,m) does not divide b       */
    printf("\nerror--gcd does not divide b\n");
    return(-a);
  }
  else
  {
    /*      real solution   */
    x = (b*n2) % min;
    if(-1L == sgn)
      x = -x;
    if(x < 0L)
      x += min;
    return(x);
  }
  return x;
} // long long Arith::axbm(long long ain, long long bin, long long m)

/****************************************************************
 * GMP FUNCTION
 * Compute 'x', such that a*x = b (mod m)
 *      returns x as value of function
 *
 *      returns -m if congruence is 0 = 0
 *               1 if congruence is (0) = (<>0)
 *               g = gcd(a,m) if g does not divide b
**/
mpz_class Arith::axbm(const mpz_class& ain, const mpz_class& bin,
                      const mpz_class& min)
{
  mpz_class a, b, m, n1, n2, n3, q, r, sgn, t, x;

  a = ain % min;
  if(a < 0L)
    a += min;
  if(0L == a)
  {
    if(0L == (bin % min))
    {
      /*      congruence is 0 = 0     */
      return(-min);
    }
    else
    {
      /*      error--congruence is (0) = (<>0)        */
      printf("\nerror--zero is not zero\n");
      return(-1L);
    }
  }

  m = min;
  a = ain % m;
  q = m / a;
  r = m % a;
  n1 = 0L;
  n2 = 1L;
  sgn = 1L;
  while (r != 0L)
  {
    sgn = -sgn;
    n3 = n2 * q + n1;
    n1 = n2;
    n2 = n3;
    m = a;
    a = r;
    q = m / a;
    r = m % a;
  }

  b = bin / a;
  t = bin % a;
  if (t != 0L)
  {
    /*      error--gcd(a,m) does not divide b       */
    printf("\nerror--gcd does not divide b\n");
    return(-a);
  }
  else
  {
    /*      real solution   */
    x = (b*n2) % min;
    if(-1L == sgn)
      x = -x;
    if(x < 0L)
      x += min;
    return(x);
  }
  return x;
} // mpz_class Arith::axbm(mpz_class ain, mpz_class bin, mpz_class min)

/****************************************************************
 * Compute 'x', 'y', and 'm' such that a*x + b*y = m
**/
void Arith::euclid(long long ain, long long bin,
                   long long& x, long long& y, long long& m)
{
  long long a, b, q, r, sign, signa, signb, ycurrent, ynext, yprevious;
  long long test;

  if (ain >= 0L)
  {
    signa = 1L;
    a = ain;
  }
  else
  {
    signa = -1L;
    a = -ain;
  }

  if (bin >= 0L)
  {
    signb = 1L;
    b = bin;
  }
  else
  {
    signb = -1L;
    b = -bin;
  }

  if(0L == a)
  {
    x = 0L;
    y = signb;
    m = b;
  }

  if(0L == b)
  {
    x = signa;
    y = 0L;
    m = a;
  }

  yprevious = 0L;
  ycurrent = 1L;
  q = a / b;
  r = a % b;
  sign = 1L;
  while (0L != r)
  {
    sign = -sign;
    ynext = q * ycurrent + yprevious;
    yprevious = ycurrent;
    ycurrent = ynext;
    a = b;
    b = r;
    q = a / b;
    r = a % b;
  }
  y = (sign == signb) ? ycurrent : -ycurrent;
  x = ( b - bin * y ) / ain;
  m = b;

  test = ain*x + bin*y;
  if(test != m)
  {
    cout << "ERROR: euclid fails "
         << ain << " * " << x << " + "
         << bin << " * " << y << " versus ("
         << test << " != " << m << ")" << endl;
    exit(0);
  }
} // void Arith::euclid(long long ain, long long bin,

/****************************************************************
 * Compute 'x', 'y', and 'm' such that a*x + b*y = m
**/
void Arith::euclid(const mpz_class& ain, const mpz_class& bin,
                   mpz_class& x, mpz_class& y, mpz_class& m)
{
  mpz_class a, b, q, r, sign, signa, signb, ycurrent, ynext, yprevious;
  mpz_class test;

  if (ain >= 0L)
  {
    signa = 1L;
    a = ain;
  }
  else
  {
    signa = -1L;
    a = -ain;
  }

  if (bin >= 0L)
  {
    signb = 1L;
    b = bin;
  }
  else
  {
    signb = -1L;
    b = -bin;
  }

  if(0L == a)
  {
    x = 0L;
    y = signb;
    m = b;
  }

  if(0L == b)
  {
    x = signa;
    y = 0L;
    m = a;
  }

  yprevious = 0L;
  ycurrent = 1L;
  q = a / b;
  r = a % b;
  sign = 1L;
  while (0L != r)
  {
    sign = -sign;
    ynext = q * ycurrent + yprevious;
    yprevious = ycurrent;
    ycurrent = ynext;
    a = b;
    b = r;
    q = a / b;
    r = a % b;
  }
//  y = (sign == signb) ? ycurrent : -ycurrent;
  if(sign == signb)
    y = ycurrent;
  else
    y = -ycurrent;
  x = ( b - bin * y ) / ain;
  m = b;

  test = ain*x + bin*y;
  if(test != m)
  {
    cout << "ERROR: euclid fails "
         << ain << " * " << x << " + "
         << bin << " * " << y << " versus ("
         << test << " != " << m << ")" << endl;
    exit(0);
  }
} // void Arith::euclid(mpz_class ain, mpz_class bin,

/****************************************************************
 * Compute Euler phi(n)
**/
long long Arith::eulerphi(long long n)
{
  long long i, p;

  p = 1L;
  i = 2L;

  while (n > 1L)
  {
    if (0L == (n % i))
    {
      p *= (i-1L);
      n /= i;
      while (0L == (n % i))
      {
        p *= i;
        n /= i;
      }
    }
    i += 1L;
  }
  return(p);
} // void Arith::eulerphi(long long nin)

/****************************************************************
 * Compute the GCD of two integers
**/
long long Arith::gcd(long long a, long long b)
{
  long long big, small, rem;

  big = a;
  small = b;

  if (big < 0L)
  {
    big = -big;
  }

  if (small < 0L)
  {
    small = -small;
  }

  if (0L == big)
  {
    return(small);
  }
  else if (0L == small)
  {
    return(big);
  }
  else
  {
    rem = big % small;
    while (0L != rem)
    {
      big = small;
      small = rem;
      rem = big % small;
    }
    return(small);
  }
} // long long Arith::gcd(long long a, long long b)

/****************************************************************
 * Compute Jacobi(p, q)
**/
long long Arith::jacobi(long long p, long long q)
{
  long long j, pmod4, qmod4, qmod8, t;

  if( (0L == p) || (0L == q) )
    return(0L); // RETURN

  if(q < 0L)
    q = -q;

  /* p and q both nonzero, q odd and positive     */
  j = 1L;
  if(1L == q)
    return(j); // RETURN

  if(p <= 0L)
  {
    p = -p;
    if(3L == (q % 4L))
      j = -j;
  }
  /*      p and q both positive, q odd    */
  while(1L == 1L)
  {
    p = p % q;
    if (0L == p)
      return(0L); // RETURN
    if(1L == p)
      return(j); // RETURN
    while(0L == (p % 2L))
    {
      p = p / 2L;
      qmod8 = q % 8L;
      if( (3L == qmod8) || (5L == qmod8) )
        j = -j;
      if(1L == p)
        return(j); // RETURN
    }
    if(1L == p)
      return(j); // RETURN
    pmod4 = p % 4L;
    qmod4 = q % 4L;
    t = p;
    p = q;
    q = t;
    if ((3L == pmod4) && (3L == qmod4) )
      j = -j;
  } // while(1L == 1L)

} // long long Arith::jacobi(long long p, long long q)

/****************************************************************
 * Compute a primitive root of a prime
 *
 * This is done with a very naive algorithm.
**/
long long Arith::primroot(long long p)
{
  long long i, n, pminus1, prod, r;

  pminus1 = p - 1L;
  for(r = 2L; r <= pminus1; ++r)
  {
    prod = 0L;
    n = 1L;
    for(i=1L; (i <= pminus1) && (prod != 1L); ++i)
    {
      prod = (n*r) % p;
      n = prod;
    } // for(i=1L; (i <= pminus1) && (prod != 1L); ++i)

    if(i == p)
    {
      if(prod == 1L)
      {
        return(r);
      }
      else
      {
        return(0L);
      }
    } // if (i == p)
  } // for(r = 2L; r <= pminus1; ++r)

  return 0L;
} // long long Arith::primroot(long long p)

/****************************************************************
 * GMP FUNCTION
 * Compute a primitive root of a prime, gmp version
 *
 * This is done with a very naive algorithm.
**/
mpz_class Arith::primroot(const mpz_class& p)
{
  mpz_class i, n, pminus1, prod, r;

  pminus1 = p - 1L;
  for(r = 2L; r <= pminus1; ++r)
  {
    prod = 0L;
    n = 1L;
    for(i=1L; (i <= pminus1) && (prod != 1L); ++i)
    {
      prod = (n*r) % p;
      n = prod;
    } // for(i=1L; (i <= pminus1) && (prod != 1L); ++i)

    if(i == p)
    {
      if(prod == 1L)
      {
        return(r);
      }
      else
      {
        return(0L);
      }
    } // if (i == p)
  } // for(r = 2L; r <= pminus1; ++r)

  return 0L;
} // mpz_class Arith::primroot(mpz_class p)

/****************************************************************
 * Compute x**n as integers
**/
long long Arith::starstar(long long x, long long n)
{
  long long prod;

  prod = 1;
  for(long long i = 1; i <= n; ++i)
  {
    prod *= x;
  }

  return prod;
} // long long Arith::starstar(long long x, long long n)

/****************************************************************
 * Compute x**n as integers
**/
mpz_class Arith::starstar(const mpz_class& x, const mpz_class& n)
{
  mpz_class prod;

  prod = 1;
  for(mpz_class i = 1; i <= n; ++i)
  {
    prod = prod * x;
  }

  return prod;
} // mpz_class Arith::starstar(mpz_class x, mpz_class n)

/****************************************************************
 * Testing functions.
**/

/****************************************************************
 * Test the extended Euclidean algorithm.
**/
void Arith::testaxbm()
{
  long long a, b, m, x;
  a = 21;
  b = 53;
  m = 37;

  x = Arith::axbm(a, b, m);
  cout << TAG << a << " " << x << " = "
       << b << " mod " << m << endl;
} // void Arith::testaxbm()

/****************************************************************
 * Test the extended Euclidean algorithm.
**/
void Arith::testaxbm_gmp()
{
  mpz_class a, b, m, x;
  a = 21;
  b = 53;
  m = 37;

  x = Arith::axbm(a, b, m);
  cout << TAG << a << " " << x << " = "
       << b << " mod " << m << endl;
} // void Arith::testaxbm()

/****************************************************************
 * Test the extended Euclidean algorithm.
**/
void Arith::testeuclid()
{
  long long a, b, m, x, y;
  a = 21;
  b = 56;
  cout << TAG << Arith::gcd(a, b) << endl;

  Arith::euclid(a, b, x, y, m);
  cout << TAG << a << " " << b << " : "
       << x << " " << y << " " << m << endl;
} // void Arith::testeuclid()

/****************************************************************
 * Test the Euler phi function.
**/
void Arith::testeulerphi()
{
  long long n;

  while ( 1L == 1L)
  {
    printf("\n");
    printf("Find Euler phi(n)\n");
    printf("Enter n: ");
//    scanf("%lld", &n);
    cin >> n;

    printf("Phi of %lld is %lld\n", n, Arith::eulerphi(n));
  }
} // void Arith::testeulerphi()

/****************************************************************
 * Test the Euler phi function.
**/
void Arith::testjacobi()
{
  long long p, q;

  while ( 1L == 1L)
  {
    printf("\n");
    printf("Find Jacobi(p, q)\n");
    printf("Enter p,q: ");
//    scanf("%lld %lld", &p, &q);
    cin >> p >> q;

    printf("Jacobi(%lld,%lld) is %lld\n", p, q, Arith::jacobi(p, q));
  }
} // void Arith::testjacobi()

/****************************************************************
 * Test the primroot function.
**/
void Arith::testprimroot()
{
  long long p;

  while ( 1L == 1L)
  {
    printf("\n");
    printf("Find primroot of p\n");
    printf("Enter p: ");
//    scanf("%lld", &p);
    cin >> p;

    printf("prim root of %lld is %lld\n", p, Arith::primroot(p));
  }
} // void Arith::testprimroot()

/****************************************************************
 * Test the gmp version of a primroot function.
**/
void Arith::testprimroot_gmp()
{
  mpz_class p;

  while ( 1L == 1L)
  {
//    printf("\n");
//    printf("Find primroot of p\n");
//    printf("Enter p: ");
//    scanf("%lld", &p);
    cout << endl;
    cout << "Find primroot of p" << endl;
    cout << "Enter p: ";
    cin >> p;

//    printf("prim root of %lld is %lld\n", p, Arith::primroot(p));
    cout << "prim root of " << p << " is " << Arith::primroot(p);
  }
} // void Arith::testprimroot_gmp()

/****************************************************************
 * Test the long long version of a starstar function.
**/
void Arith::teststarstar()
{
  long long power;

  for(long long x = 2; x < 10; ++x)
  {
    for(long long n = 2; n < 10; ++n)
    {
      power = starstar(x, n);
      cout << "Find " << x << " to power " << n << " " << power << endl;
    }
  }
} // void Arith::teststarstar()

/****************************************************************
 * Test the gmp version of a starstar function.
**/
void Arith::teststarstar_gmp()
{
  mpz_class power;

  for(mpz_class x = 2; x < 10; ++x)
  {
    for(mpz_class n = 2; n < 10; ++n)
    {
      power = starstar(x, n);
      cout << "Find " << x << " to power " << n << " " << power << endl;
    }
  }

  for(mpz_class x = 1001; x < 1009; ++x)
  {
    for(mpz_class n = 20; n < 30; ++n)
    {
      power = starstar(x, n);
      cout << "Find " << x << " to power " << n << " " << power << endl;
    }
  }
} // void Arith::teststarstar()

/****************************************************************
 * GMP functions.
**/
/****************************************************************
 * Print an mp number (mpz_t passed as argument).
**/
void Arith::printbignum(string head, mpz_t mpnum,
                        char c, long long width)
{
  char fmtstring[26], *outstring;
  long long mpsize;

  mpsize = mpz_sizeinbase(mpnum, 10);
  outstring = (char *) malloc(mpsize + 5);
  mpz_get_str(outstring, 10, mpnum);

  snprintf(fmtstring, 25, "%%%llds", width);

  printf("%s", head.c_str());
  printf(fmtstring, outstring);
/*
  mpz_out_str(fpout,10,mpnum);
*/
  printf("%c", c);

  free(outstring);
} // void Arith::printbignum(string head, mpz_t mpnum, char c, long long width)

/****************************************************************
 * Print an mp number (mpz_class passed as argument).
**/
void Arith::printbignum(string head, mpz_class mpnum,
                        char c, long long width)
{
  Arith::printbignum(head, mpnum.get_mpz_t(), c, width);
} // void Arith::printbignum(string head,mpz_class mpnum,char c,long long width)

