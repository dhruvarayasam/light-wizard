#pragma once

/*
	 This is the ray class. Takes in a generic parameter T,
	 usually float, int, double, etc.Contains operator overloading for all vector operations.
*/
class Ray
{

	float x, y, z;

public:

	Ray();
	Ray(float x, float y, float z);

	// operator overloading
	friend Ray operator+ (Ray const& r1, Ray const& r2);
	friend Ray operator- (Ray const& r1, Ray const& r2); // subtraction of two rays
	friend Ray operator* (Ray const& r1, Ray const& r2); // dot product
	friend Ray operator== (Ray const& r1, Ray const& r2); // equality
	friend Ray operator!= (Ray const& r1, Ray const& r2); // inequality
	friend Ray operator>= (Ray const& r1, Ray const& r2); // greater than or equal to
	friend Ray operator<= (Ray const& r1, Ray const& r2); // less than or equal to
	friend Ray operator< (Ray const& r1, Ray const& r2); // less than
	friend Ray operator> (Ray const& r1, Ray const& r2); // greater than
	Ray operator+= (Ray const& r1); // add and assign
	Ray operator-= (Ray const& r1); // subtract and assign
	Ray* operator= (Ray const& r1); // assignment
	friend std::ostream& operator<< (std::ostream& os, Ray const & r1); // print

		



};
