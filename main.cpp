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

        // overload += con reale a dx
        complex& operator+=(const T& other) {
        pre += other;
        return *this;
	}
   
	
        // overload + con reale a dx
        complex operator+(const T& other) const {
        complex ret = *this;
        ret += other;
        return ret;
        }

        complex operator-() const {
        return complex(-pre,-pim);
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

        // overload *= con reale a dx
        complex& operator*=(const T& other) {
        pre *= other;
        pim *= other;
        return *this;
	}
   
	
        // overload * con reale a dx
        complex operator*(const T& other) const {
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

// overload + con reale a sx
template<typename T>
complex<T>
operator+(const T& r, const complex<T>& c)
{
    return c + r;
}

// overload * con reale a sx
template<typename T>
complex<T>
operator*(const T& r, const complex<T>& c)
{
    return c * r;
}





int main()
{ 
  complex c1(0.0,8.0);
  complex c2(1.2,3.5);
  complex c3(1.4);
  cout<<"c1: "<<c1<<endl;
  cout<<"la somma è "<<c1+c2<<endl;
  cout<<"il prodotto è "<<c1*c2<<endl;
  cout<<"la differenza è "<<c1+(-c2)<<endl;
  cout<<"il coniugato è "<<conj(c2)<<endl;
  cout<<"il coniugato del reale: "<<conj(c3)<<endl;
  cout<<"somma con reale: "<<8.9+c2<<endl;
  cout<<"prodotto con reale: "<<0.5*c2<<endl;
  return 0;
}

  