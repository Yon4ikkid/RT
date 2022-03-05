#pragma once

class Vector
{
private:
	float __xyz[3];

public:
	Vector();
	Vector(const float x, const float y, const float z);
	Vector(const float xyz[3]);

	Vector operator+(const Vector& other) const;
	Vector operator-(const Vector& other) const;
	float operator*(const Vector& other) const;
	Vector operator/(const float& val) const;
	Vector operator*(const float& val) const;
	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(const float& val);
	Vector& operator/=(const float& val);
};
