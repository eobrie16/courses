class Fraction
{
  int num;
  int denom;
  int gcd(int a, int b);

public:
  Fraction(): num(1), denom(1)
  {
  }
  
  Fraction(int n, int d): num(n), denom(d)
  {
    reduce();
  }  
  void reduce();
  bool operator< (const Fraction & f2);
  bool operator> (const Fraction & f2);
  bool operator!= (const Fraction & f2);
  bool operator== (const Fraction & f2);

  friend istream& operator>> (istream& istr, Fraction & f);
  friend ostream& operator<< (ostream& ostr, const Fraction & f); 
};

// Implementations

bool Fraction::operator< (const Fraction & f2)
{
    double val2 = (double)f2.num/f2.denom;
    double val = (double)num/denom;
    return (val < val2);
}

bool Fraction::operator> (const Fraction & f2)
{
    double val2 = (double)f2.num/f2.denom;
    double val = (double)num/denom;
    return (val > val2);
}

bool Fraction::operator!= (const Fraction & f2)
{
    if (f2.num == num && f2.denom == denom) return false;
    return true;
}
bool Fraction::operator== (const Fraction & f2)
{
    if (f2.num == num && f2.denom == denom) return true;
    return false;
}

istream & operator>> (istream & istr, Fraction & f)
{
    char c; // Throw away character where user types '/'
    istr >> f.num >> c >> f.denom ;
    return istr;
}
ostream & operator<< (ostream & ostr, const Fraction & f)
{
    ostr << f.num << '/' << f.denom;
    return ostr;
}



int Fraction::gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
void Fraction::reduce()
  {
   // Find the Greatest common denominator
    int theGcd = gcd(num, denom);

    num /= theGcd;
    denom /= theGcd;   
  }