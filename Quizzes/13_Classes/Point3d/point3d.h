#ifndef POINT3D_H
#define POINT3D_H

class Point3d
{
private:
    int x{};
    int y{};
    int z{};

public:
    Point3d();
    Point3d(int x, int y, int z);
    void setValues(int x, int y, int z);
    void print();
    bool isEqual(const Point3d&);
};

#endif
