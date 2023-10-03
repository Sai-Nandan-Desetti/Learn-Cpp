#ifndef POINT2D_H
#define POINT2D_H

class Point2d
{
private:
    double m_x{};
    double m_y{};

public:
    Point2d(double x = 0.0, double y = 0.0) : m_x{ x }, m_y{ y }
    {        
    }

    void print();
    double distanceTo(const Point2d&);
    friend double distanceFrom(const Point2d& p, const Point2d& q);
};

#endif
