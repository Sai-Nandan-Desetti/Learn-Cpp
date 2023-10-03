#ifndef FRACTIONS_H
#define FRACTIONS_H

class Fraction
{
private:    
    int m_nr{};
    int m_dr{};

public:    
    explicit Fraction(
        int nr = 0,
        int dr = 1
    ) :
    m_nr{ nr },
    m_dr{ dr }
    {        
    }

    void getFraction();
    Fraction multiply(const Fraction& other) const;
    void print() const;
};

#endif
