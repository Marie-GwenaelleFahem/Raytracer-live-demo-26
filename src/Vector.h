#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
    Vector(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    Vector add(const Vector& other) const;
    Vector subtract(const Vector& other) const;

private:
    double m_x;
    double m_y;
    double m_z;
};

#endif
