#include "Form.h"

static const char label[] = "Form: ";

/****************************************************************
 * Constructor.
**/
Form::Form()
{
  a = 0;
  b = 0;
  c = 0;
  disc = 0;
}
/****************************************************************
 * Destructor.
**/
Form::~Form()
{
}

/****************************************************************
 * Accessors and mutators.
**/
long long Form::getA() const { return this->a; } 
void Form::setA(long long what) { this->a = what; }

long long Form::getB() const { return this->b; }
void Form::setB(long long what) { this->b = what; }

long long Form::getC() const { return this->c; }
void Form::setC(long long what) { this->c = what; }

long long Form::getDisc() const { return this->disc; }
void Form::setDisc(long long what) { this->disc = what; }

void Form::setForm(long long newA, long long newB, long long newC)
{
  this->a = newA;
  this->b = newB;
  this->c = newC;
  this->computeDisc();
}

/****************************************************************
 * General functions.
**/
/****************************************************************
 * Compute the disc from 'a', 'b', 'c'
**/
void Form::computeDisc()
{
  this->disc = (this->getB())*(this->getB()) -
                    4L*(this->getA())*(this->getC());
} // void Form::computeDisc()

/****************************************************************
 * Compound two forms.
**/
Form Form::compound(const Form& g)
{
  long long locala1, localb1, localc1;
  long long locala2, localb2, localc2;
  long long locala3, localb3, localc3;
  long long a2n, c1bya2n, m, n, t, u, w, x, y, z;
  Form* newForm;

  newForm = new Form;

  locala1 = this->getA();
  localb1 = this->getB();
  localc1 = this->getC();

  locala2 = g.getA();
  localb2 = g.getB();
  localc2 = g.getC();

// cout << endl;
// cout << "one " << " locala1=" << locala1
//                << " localb1=" << localb1
//                << " localc1=" << localc1 << endl;
// cout << "two " << " locala2=" << locala2
//                << " localb2=" << localb2
//                << " localc2=" << localc2 << endl;

  localb3 = (localb1 + localb2) / 2L;
// cout << "thr " << " localb3=" << localb3 << endl;
  if( localb3 != 0L)
  {
    Arith::euclid(locala1, localb3, x, y, m);
// cout << "fou " << " locala1=" << locala1 << " x=" << x
//                << " localb3=" << localb3 << " y=" << y
//                << " m=" << m << endl;
  }
  else
  {
    m = locala1;
    x = 1L;
    y = 0L;
// cout << "fiv " << " x=" << x << " y=" << y << " m=" << m << endl;
  }

  Arith::euclid(m, locala2, t, u, n);
// cout << "six " << " m=" << m << " t=" << t
//                << " locala2=" << locala2
//                << " u=" << u << " n=" << n << endl;
  a2n = locala2 / n;
  c1bya2n = localc1 % a2n;
// cout << "sev " << " a2n=" << a2n << " c1bya2n=" << c1bya2n << endl;
  w = ( (localb3 - localb1) * x - c1bya2n * y) % a2n;
  z = (t * w) % a2n;
// cout << "eig " << " w=" << w << " z=" << z << endl;

  locala3 = locala1 / n;
  localb3 = localb1 + 2L * locala3 * z;
  locala3 = locala3 * a2n;
  localc3 = findc(locala3, localb3, this->disc);
// cout << "nin " << " locala3=" << locala3
//                << " localb3=" << localb3
//                << " localc3=" << localc3 << endl;

  (*newForm).setA(locala3);
  (*newForm).setB(localb3);
  (*newForm).setC(localc3);
  (*newForm).setDisc(disc);

  if((*newForm).getDisc() < 0L)
  {
    (*newForm).reduceDef();
  }
  else
  {
    (*newForm).reduceInd();
  }

  return (*newForm);
} // Form& Form::compound(Form g)

/****************************************************************
 * Cycle an indefinite form to a minimal 'a' value
 * Return the number of adjacency steps taken.
**/
long long Form::cycleInd()
{
//  cout << label << "enter cycle " << this->toString() << endl;

  bool donecycle;
  long long locala, localb, localc;
  long long absc, delta, leasta, leastb, leastc, q, r, rootdisc;
  long long returnValue;

  locala = this->getA();
  localb = this->getB();
  localc = this->getC();

  donecycle = false;
  returnValue = 0;
  rootdisc = (int) (sqrt( (double) this->disc));
  delta = 0L;
  q = locala;
  r = localb;
  leasta = (locala > 0L) ? locala : 1000000000L;
  leastb = localb;
  leastc = localc;
#ifdef DEBUG
  printf("   delta            (a,b,c)               least (a,b,c)\n");
  printf("%8lld--(%7lld,%7lld,%7lld)", delta, locala,localb,localc);
  printf("--(%7lld,%7lld,%7lld)\n",leasta,leastb,leastc);
#endif
  while (!donecycle)
  {
    absc = (localc > 0L) ? localc : -localc;
    delta = (rootdisc + localb) / (absc + absc);
    locala = localc;
    localb = -localb + 2L * absc * delta;
    localc = findc(locala,localb,this->disc);
#ifdef DEBUG
  printf("%8lld--(%7lld,%7lld,%7lld)", delta, locala,localb,localc);
  printf("--(%7lld,%7lld,%7lld)\n",leasta,leastb,leastc);
#endif

    if( (locala == q) && (localb == r) )
    {
      donecycle = true;
    }
    else if( (locala > 0) && (locala < leasta) )
    {
      leasta = locala;
      leastb = localb;
      leastc = localc;
    }
    else if( (locala == leasta) && (localb < leastb) )
    {
      leasta = locala;
      leastb = localb;
      leastc = localc;
    }
    ++returnValue;
  }
  this->setA(leasta);
  this->setB(leastb);
  this->setC(leastc);

  return returnValue;

//  cout << label << "leave cycle " << this->toString() << endl;
} // long long Form::cycleInd()

/****************************************************************
 * Duplicate a form.
**/
Form Form::duplicate()
{
  long long locala3 = -1, localb3 = -1, localc3 = -1;
  long long cbyaa, m, x, y;
  Form* newForm;

  newForm = new Form;

  if(0L == this->getB())
  {
    locala3 = 1L;
    locala3 = 0L;
    locala3 = this->getDisc() / 4L;
  }
  else
  {
    Arith::euclid(this->getA(), this->getB(), x, y, m);
    locala3 = this->getA() / m;
    cbyaa =  this->getC() % (locala3);
    localb3 = this->getB() - 2L * locala3 * ( (cbyaa * y) % locala3 );
    locala3 = locala3 * locala3;
    localc3 = findc(locala3, localb3, this->getDisc());
  }

  (*newForm).setA(locala3);
  (*newForm).setB(localb3);
  (*newForm).setC(localc3);
  (*newForm).setDisc(this->disc);

  if((*newForm).getDisc() < 0)
  {
    (*newForm).reduceDef();
  }
  else
  {
    (*newForm).reduceInd();
  }

  return (*newForm);
} // Form Form::duplicate()

/****************************************************************
 * Reduce a definite form
**/
void Form::reduceDef()
{
//  char s[80];
  long long locala, localb, localc;
  long long absb, c2, delta, sum;

  locala = this->getA();
  localb = this->getB();
  localc = this->getC();

  absb = (localb > 0L) ? localb : -localb;
  while( (absb > locala) || (locala > localc) )
  {
    c2 = localc + localc;
    sum = localb + localc;
    delta = (sum < 0L) ? (sum/c2 - 1L) : sum/c2;
    locala = localc;
    localb = -localb + c2*delta;
    localc = findc(locala, localb, this->disc);
#ifdef DEBUGREDUCE
    printf("Form during reduction %8lld %8lld %8lld\n",locala,localb,localc);
#endif
    absb = (localb > 0L) ? localb : -localb;
  }

  if( (locala == localc) && (localb < 0L) )
  {
    localb = -localb;
  }

  if( (localb < 0L) && (locala == -localb) )
  {
    localb = -localb;
  }

  this->setA(locala);
  this->setB(localb);
  this->setC(localc);
} // void Form::reduceDef()

/****************************************************************
 * Reduce an indefinite form
 * Return the number of adjacency steps taken.
**/
long long Form::reduceInd()
{
  bool donereduce;
  long long locala, localb, localc;
  long long abs2a, abs2c, delta; // , rootdisc;
  long long returnValue;
  double rootdisc;

// cout << label << "enter reduceInd" << this->toString() << endl;
  locala = this->getA();
  localb = this->getB();
  localc = this->getC();

//   printf("%8lld--(%7lld,%7lld,%7lld)\n", delta, locala, localb, localc);

  donereduce = false;
  returnValue = 0;
//  rootdisc = static_cast<long long>(sqrt((static_cast<double>(disc))));
  rootdisc = sqrt((static_cast<double>(disc)));
  abs2a = (locala >= 0L) ? (locala + locala) : -(locala + locala);
  abs2c = (localc >= 0L) ? (localc + localc) : -(localc + localc);
  if( (localb <= rootdisc) &&
      ((rootdisc - localb) < abs2a) &&
       (abs2a < (rootdisc + localb)) )
    donereduce = true;
  delta = 0L;
#ifdef DEBUG
  printf("rootdisc %lf %lld %lld\n", rootdisc, abs2a, abs2c);
  printf("   delta            (a,b,c)\n");
  printf("%8lld--(%7lld,%7lld,%7lld)\n", delta, locala, localb, localc);
#endif
  while(!donereduce)
  {
    delta = (rootdisc + localb) / abs2c;
    if (delta < 0L) delta--;
    if(localc < 0L)
    {
      delta = -delta;
    }
    localb = -localb + 2L * localc * delta;
    locala = localc;
    localc = findc(locala, localb, this->disc);
#ifdef DEBUG
    printf("%8lld--(%7lld,%7lld,%7lld)\n", delta, locala,localb,localc);
#endif
    abs2a = (locala >= 0) ? locala + locala : -(locala + locala);
    abs2c = (localc >= 0) ? localc + localc : -(localc + localc);
  if( (localb <= rootdisc) &&
      ((rootdisc - localb) < abs2a) &&
       (abs2a < (rootdisc + localb)) )
      donereduce = true;

    ++returnValue;
  }

  this->setA(locala);
  this->setB(localb);
  this->setC(localc);

// cout << "leave reduceInd " << this->toString() << endl;

  return returnValue;
} // long long Form::reduceInd()

/****************************************************************
 * Compute 'c' from 'a', 'b', and 'disc'
**/
long long Form::findc(long long a, long long b, long long disc)
{
  long long c;
/*
  double t, u, v, w;

  t = (double) discriminant;
  u = (double) a;
  v = (double) b;
  w = (v*v + t) / (4.0 * u);
  c = (long long) w;
*/

  c = (b*b - disc) / (4L*a);

  return(c);
} // long long Form::findc(long long a, long long b, long long disc)

/****************************************************************
 * toString
**/
string Form::toString()
{
  char s[81];

  snprintf(s, 80, "%17lld(%12lld,%12lld,%12lld)", disc, a, b, c);

  return string(s);
} // string Form::toString()

/****************************************************************
 * Overloads.
**/
/****************************************************************
 * Unary minus to return opposite.
**/
const Form Form::operator -() const
{
  Form* f1;

  f1 = new Form;
  (*f1) = (*this);
  (*f1).setB(-(*f1).getB());

  return (*f1);
} // string Form::toString()

/****************************************************************
 * EqualsEquals to test equality.
**/
bool Form::operator ==(const Form& f2) const
{
  bool returnValue;

  returnValue = false;

  if( (this->getA() == f2.getA()) &&
      (this->getB() == f2.getB()) &&
      (this->getC() == f2.getC()))
  {
    returnValue = true;
  }

  return returnValue;
} // const Form Form::operator *(const Form& f2) const

/****************************************************************
 * Multiplication to return composition. 
**/
const Form Form::operator *(const Form& f2) const
{
  Form* f1;

  f1 = new Form;
  (*f1) = (*this);
  if((*this) == f2)
  {
    return f1->duplicate();
  }
  else
  {
    return f1->compound(f2);
  }

} // const Form Form::operator *(const Form& f2) const

/****************************************************************
 * Testing routines.
**/
/****************************************************************
 * Test definite forms.
**/
void Form::testformsdef(ifstream inStream)
{
  long long a, b, c;
  long long order;
  Form f1, f2, g, h;

  inStream >> a >> b >> c;
  while(!inStream.eof())
  {
    f1.setForm(a, b, c);
    if(f1.getDisc() < 0)
    {
      f1.reduceDef();
      cout << label << "form f1 " << f1.toString() << endl;
    }

    /****************************************************************
     * Compute order of the form directly.
    **/
    order = 1L;
    g = f1;
    cout << label << "form f1 power " << order << " "
         << g.toString() << endl;
    while(g.getA() != 1L)
    {
      g = g * f1;
      ++order;
      cout << label << "form f1 power " << order << " "
           << g.toString() << endl;
    }

    /****************************************************************
     * Compute order of the opposite form
    **/
    order = 1L;
    g = -f1;
    cout << label << "form -f1 power " << order << " "
         << g.toString() << endl;
    while(g.getA() != 1L)
    {
      g = g * (-f1);
      ++order;
      cout << label << "form -f1 power " << order << " "
           << g.toString() << endl;
    }

    cout << endl;
 
    inStream >> a >> b >> c;
  } // while(!inStream.eof())

} // void Form::testformsdef(ifstream inStream)

/****************************************************************
 * Test indefinite forms.
**/
void Form::testformsind(ifstream inStream)
{
  long long a, b, c;
  long long order;
  Form f1, f2, g, h;

  inStream >> a >> b >> c;
  while(!inStream.eof())
  {
    f1.setForm(a, b, c);
    if(f1.getDisc() > 0)
    {
      f1.reduceInd();
      cout << label << "form f1 reduced " << f1.toString() << endl;
      f1.cycleInd();
      cout << label << "form f1 cycled " << f1.toString() << endl;
    }

    /****************************************************************
     * Compute order of the form directly.
    **/
    order = 1L;
    g = f1;
    cout << label << "form f1 power " << order << " "
         << g.toString() << endl;
    while(g.getA() != 1L)
    {
      g = g * f1;
      ++order;
      cout << label << "form f1 power " << order << " "
           << g.toString() << endl;
      g.cycleInd();
      cout << label << "form f1 power cycled " << order << " "
           << g.toString() << endl;
    }

    /****************************************************************
     * Compute order of the opposite form
    **/
    order = 1L;
    g = -f1;
    cout << label << "form -f1 power " << order << " "
         << g.toString() << endl;
    g.reduceInd();
    cout << label << "form -f1 power " << order << " "
         << g.toString() << endl;
    while(g.getA() != 1L)
    {
      g = g * (-f1);
      ++order;
      cout << label << "form -f1 power " << order << " "
           << g.toString() << endl;
      g.cycleInd();
      cout << label << "form -f1 power cycled " << order << " "
           << g.toString() << endl;
    }

    cout << endl;
 
    inStream >> a >> b >> c;
  } // while(!Utils::inStream.eof())

} // void Form::testformsind(ifstream inStream)

