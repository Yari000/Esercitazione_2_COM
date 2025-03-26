#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
class complex
{
 T pre,pim;
  public:
    
    // costruttore default
    complex()
        : pre(0.0), pim(1.0)
    {}
    
    // converter real-im
    explicit complex(T n)
        : pre(n), pim(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
    // user-defined constructor
    complex(T n, T d)
        : pre(n), pim(d)
    {}
    
    // metodo per la parte reale
    T real(void) const {
        return pre;
    }
    
    // metodo per la parte immaginaria
    T imaginary(void) const {
        return pim;
    }
    
    
        // operatore += overload
        complex& operator+=(const complex& other) {
        T a = pre;
        T b = pim;
        T c = other.pre;
        T d = other.pim;
        pre = a + c;
        pim = b + d;
        return *this;
	}
	
        // operatore + overload
        complex operator+(const complex& other) const {
        complex ret = *this;
        ret += other;
        return ret;
        }

        // operatore *= overload
        complex& operator*=(const complex& other) {
        T a=pre;
        T b=pim;
        T c=other.pre;
        T d=other.pim;
        pre = a*c - b*d;
        pim = a*d + b*c;
        return *this;
        }
      
        // operatore * overload
        complex operator*(const complex& other) const {
        complex ret = *this;
        ret *= other;
        return ret;
        }
       
               
   };
// metodo per il coniugato
    template<typename T>
    complex<T> conj(complex<T> C)
    {
      complex<T> v(C.real(),-1.0*C.imaginary());
      return v;
    }

// overload stampa
template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex<T>& r) {
    if (r.imaginary() != 0)
    { if (r.imaginary()>0.0)
        {os << r.real() <<"+"<< r.imaginary()<<"i";}
     else
     {os << r.real()<<r.imaginary()<<"i";}
    }
    else
        {os << r.real();}

    return os;
}




int main()
{
  complex c1(2.3,1.2);
  complex c2(3.0,-9.2);
  complex r1(4.6);
  cout<<"la somma è "<<c1+c2<<endl;
  cout<<"il prodotto è "<<c1*c2<<endl;
  cout<<"il coniugato è "<<conj(c2)<<endl;
  cout<<"somma con reale: "<<r1+c2<<endl;
  return 0;
}

  