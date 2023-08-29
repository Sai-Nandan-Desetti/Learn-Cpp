#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x{ x }, m_y{ y }, m_z{ z }
    {
    }
    
    Point operator+() const;
    Point operator-() const;    
    bool operator!() const;    

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend Point operator+(const Point& p, const Point& q);
    friend Point operator-(const Point& p, const Point& q);
};

#endif
