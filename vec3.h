#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {

	public:
		double e[3]; 

		vec3() : e{0,0,0} {} 
		vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} // declaring this as a vec w/ placeholder variables?

		double x() const {return e[0]; } // why semi colon after return and not the one liner?
		double y() const {return e[1]; } // what does const do again?
		double z() const {return e[2]; } 

		vec3 operator-() const { return vec3(-e[0],-e[1],-e[2]);} // why can't I call my functions / why index? --> pass it "self?"
		double operator[] (int i) const { return e[i]; } //
		double& operator[] (int i) {return e[i]; } // & prevents the const? why? 

		vec3& operator+=(const vec3& v) {
			e[0] += v.e[0]; // assuming accessing v.e instead of v[] for reasons?
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this; // why can't I return e?
		}

		vec3& operator*=(double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this; 
		}

		vec3& operator/=(double t) {
			return *this *= (1/t); // why can't I have *= *this *= t;?
		}

		double length() const {
			return std::sqrt(length_squared()); // why does this get to access other functions?
		}

		double length_squared() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}

}; // why does this get a semicolon but the methods don't?

//point3 is just an alias for vec3, but useful for geomtric clarity.

using point3 = vec3;


//Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
	// what does inline mean? what does the first std::ostream mean? Is that a type?

}

inline vec3 operator+(const vec3& u,const vec3& v) {
	return vec3(
		u.e[0] + v.e[0],
		u.e[1] + v.e[1],
		u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 u,const vec3& v) {
	return vec3(
		u.e[0] - v.e[0],
		u.e[1] - v.e[1],
		u.e[2] - v.e[2]); // why can't I use the prior functoin with "-"" on v? 
}

// actually kinda hate this definition, this is just an unsummed dot product
inline vec3 operator*(const vec3 u, const vec3& v) {
	return vec3(
		u.e[0] * v.e[0],
		u.e[1] * v.e[1],
		u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
	return vec3(
		t * v.e[0],
		t * v.e[1],
		t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v; // why is this a valid implemetnation compared to the other priors?
}

inline vec3 operator/(const vec3&v, double t){
	return (1/t) * v; // why don't I have to flip the argument order for this def?
}

inline double dot(const vec3& u, const vec3& v) {
	return 
		u.e[0] * v.e[0] +
		u.e[1] * v.e[0] +
		u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3 u) {
	return u / u.length() ; // why not define this above?
}

#endif

































