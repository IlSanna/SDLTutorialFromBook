#pragma once
#include<math.h>

class Vector2D {
public:
	Vector2D():m_x(0), m_y(0) {}
	Vector2D(float x, float y) : 
		m_x(x), m_y(y) {}

	float length() { return sqrt(m_x * m_x + m_y * m_y); }
	void normalize() {
		float l = length();
		if (l > 0) // we never want to attempt to divide by 0
		{
			(*this) *= 1 / l;
		}
	}
	//PLUS
	//add together the individual components of each vector
	Vector2D operator+(const Vector2D& v2) const {
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}
	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;
		return v1;
	}
	//MULTIPLY
	//multiply each component of the vector by the scalar number
	Vector2D operator*(float scalar) {
		return Vector2D(m_x * scalar, m_y * scalar);
	}
	Vector2D& operator*=(float scalar) {
		m_x *= scalar;
		m_y *= scalar;
		return *this;
	}
	//SUBTRACT
	Vector2D operator-(const Vector2D& v2) const {
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) {
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1;
	}
	//DIVIDE
	Vector2D operator/(float scalar) {
		return Vector2D(m_x / scalar, m_y / scalar);
	}
	Vector2D& operator/=(float scalar) {
		m_x /= scalar;
		m_y /= scalar;
		return *this;
	}

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	const float getX() const { return m_x; }
	const float getY() const { return m_y; }

private:
	float m_x;
	float m_y;
};