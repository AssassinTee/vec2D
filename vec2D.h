#ifndef __VEC2_H__
#define __VEC2_H__

#include <cmath>
#include <bitset>
#include <iostream>

//Make sure M_PI is defined!!!
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

template <class T>
class vec2D {
public:
    union {
        T data[2];
        struct{
            T x;
            T y;
        };
        std::bitset<2*sizeof(T)*CHAR_BIT> hash;
    };

	vec2D() :x(0), y(0) {}
	vec2D(T z) : x(z), y(z) {}
	vec2D(T x, T y) : x(x), y(y) {}
	vec2D(const vec2D& v) : x(v.x), y(v.y) {}

	vec2D& operator=(const vec2D& v) {
		x = v.x;
		y = v.y;
		return *this;
	}

	vec2D operator+(vec2D& v) {
		return vec2D(x + v.x, y + v.y);
	}
	vec2D operator-(vec2D& v) {
		return vec2D(x - v.x, y - v.y);
	}

	vec2D& operator+=(vec2D& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	vec2D& operator-=(vec2D& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	vec2D operator+(double s) {
		return vec2D(x + s, y + s);
	}
	vec2D operator-(double s) {
		return vec2D(x - s, y - s);
	}
	vec2D operator*(double s) {
		return vec2D(x * s, y * s);
	}
	vec2D operator/(double s) {
		return vec2D(x / s, y / s);
	}


	vec2D& operator+=(double s) {
		x += s;
		y += s;
		return *this;
	}
	vec2D& operator-=(double s) {
		x -= s;
		y -= s;
		return *this;
	}
	vec2D& operator*=(double s) {
		x *= s;
		y *= s;
		return *this;
	}
	vec2D& operator/=(double s) {
		x /= s;
		y /= s;
		return *this;
	}

	void set(T x, T y) {
		this->x = x;
		this->y = y;
	}

	void rotateDegree(double deg) {
		rotateRadian(deg / 180.0 * M_PI);
	}

	void rotateRadian(double theta) {
        double c = cos(theta);
		double s = sin(theta);
		double tx = x * c - y * s;
		double ty = x * s + y * c;
		x = tx;
		y = ty;
	}

	vec2D& normalize() {
		if (length() == 0) return *this;
		*this *= (1.0 / length());
		return *this;
	}

	float dist(vec2D v) const {
		vec2D d(v.x - x, v.y - y);
		return d.length();
	}

	float distManhattan(vec2D v) const {
        return std::abs(v.x - x)+std::abs(v.y - y);
	}

	float length() const {
		return std::sqrt(x * x + y * y);
	}
	void truncate(double length) {
		double angle = atan2f(y, x);
		x = length * cos(angle);
		y = length * sin(angle);
	}

	vec2D ortho() const {
		return vec2(y, -x);
	}

	unsigned long long getHash()
	{
	    return hash.to_ullong();
	}

	static float dot(vec2D v1, vec2D v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}
	static float cross(vec2D v1, vec2D v2) {
		return (v1.x * v2.y) - (v1.y * v2.x);
	}

    friend std::ostream& operator<< (std::ostream& stream, const vec2D v) {
        stream << "vec2D("<<(float)v.x<<"/"<<(float)v.y<<")";
        return stream;
    }
};

typedef vec2D<int8_t> vec2;
typedef vec2D<float> vec2f;

#endif
