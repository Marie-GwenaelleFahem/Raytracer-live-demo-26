#include "Vector.h"

Vector::Vector(double x, double y, double z)
    : m_x(x), m_y(y), m_z(z)
{
}

double Vector::getX() const { return m_x; }
double Vector::getY() const { return m_y; }
double Vector::getZ() const { return m_z; }

Vector Vector::add(const Vector& other) const
{
    return Vector(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

Vector Vector::subtract(const Vector& other) const
{
    return Vector(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
}
