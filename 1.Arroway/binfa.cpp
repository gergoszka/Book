#ifndef BIN_FA__H
#define BIN_FA__H

#include <iostream>

template <class CsomopontTartalomTipus> class BinFa
{
  class Csomopont
  {
  public:
    Csomopont (CsomopontTartalomTipus s):szo (s), hanyszor (1), bal (0), jobb (0) {};
    ~Csomopont () {};
    Csomopont *balra () {
      return bal;
    }
    Csomopont *jobbra ()
    {
      return jobb;
    }
    void balra (Csomopont * bal) 
    {
      this->bal = bal;
    }
    void jobbra (Csomopont * jobb)
    {
      this->jobb = jobb;
    }
    CsomopontTartalomTipus & tartalma ()
    {
      return szo;
    }
    void novel ()
    {
      ++hanyszor;
    }
    int volt ()
    {
      return hanyszor;
    }
    
  private:
    friend class BinFa <CsomopontTartalomTipus>;
    CsomopontTartalomTipus szo;
    int hanyszor;
    Csomopont *bal;
    Csomopont *jobb;
    Csomopont (const Csomopont &);
    Csomopont & operator= (const Csomopont &);
  };
  
  Csomopont *gyoker;
  Csomopont *csomopont;
  int melyseg;
  
  void kiir (Csomopont * elem, std::ostream& os);
  void szabadit (Csomopont * elem);
  
  BinFa (const BinFa &);
  BinFa & operator= (const BinFa &);
  
  
public:
  BinFa ():gyoker (0), csomopont (0) {}
  ~BinFa () {
    if (gyoker)
      szabadit();
  }
  
  void operator<< (CsomopontTartalomTipus s);
  friend std::ostream& operator<< (std::ostream& os, BinFa& bf)
  {
    bf.kiir(os);
    return os;
  }
  
  void kiir (std::ostream& os)
  {
    melyseg = 0;
    kiir (gyoker, os);
  }
  
  void kiir (void)
  {
    melyseg = 0;
    kiir (gyoker, std::cout);
  }
  
  void szabadit (void)
  {
    szabadit (gyoker);
    gyoker = 0;
  }
  
  
};

template <class CsomopontTartalomTipus>
void BinFa<CsomopontTartalomTipus>::operator<< (CsomopontTartalomTipus s)
{
  int e;
  
  if (csomopont == NULL)
  {
    
    csomopont = new Csomopont (s);
    gyoker = csomopont;
    
  }
  else if ((e = csomopont->tartalma ().compare (s)) == 0)
  {
    
    csomopont->novel ();
    
  }
  else if (e > 0)
  {
    
    if (csomopont->balra () == NULL)
    {
      csomopont->balra (new Csomopont (s));
    }
    else
    {
      csomopont = csomopont->balra ();
      *this << s;
    }
    
  }
  else if (e < 0)
  {
    
    if (csomopont->jobbra () == NULL)
    {
      csomopont->jobbra (new Csomopont (s));
    }
    else
    {
      csomopont = csomopont->jobbra ();
      *this << s;
    }
    
  }
  
  csomopont = gyoker;
  
}

template <class CsomopontTartalomTipus>
void BinFa<CsomopontTartalomTipus>::kiir (Csomopont * elem, std::ostream& os)
{
  if (elem != NULL)
  {
    ++melyseg;
    kiir (elem->jobb, os);
    // ez a postorder bejáráshoz képest
    // 1-el nagyobb mélység, ezért -1
    for (int i = 0; i < melyseg; ++i)
      os << "---";
    os << elem->
    tartalma () << "(" << elem->volt () << ", " << melyseg - 1 << ")" << std::endl;
    kiir (elem->bal, os);
    --melyseg;
  }
}

template <class CsomopontTartalomTipus>
void BinFa<CsomopontTartalomTipus>::szabadit (Csomopont * elem)
{
  if (elem != NULL)
  {
    szabadit (elem->jobb);
    szabadit (elem->bal);
    delete elem;
  }
}

#endif
