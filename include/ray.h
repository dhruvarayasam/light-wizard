#pragma once


/*
	 This is the ray class. Takes in a generic parameter T,
	 usually float, int, double, etc.Contains operator overloading for all vector operations.
*/
template <typename T>
class Ray {

	T x, y, z;

	public:
		
		Ray (T a, T b, T c); 
		Ray ();
		// operator overload functions
		friend Ray<T> operator+ (const Ray<T>& r1, const Ray<T>& r2);

 // addition of two rays
		// friend Ray<T> operator- (Ray<T> const& r1, Ray<T> const& r2); // subtraction of two rays
		// friend T operator* (Ray<T> const& r1, Ray<T> const& r2); // dot product
		// friend Ray<T> operator== (Ray<T> const& r1, Ray<T> const& r2); // equality
		// friend Ray<T> operator!= (Ray<T> const& r1, Ray<T> const& r2); // inequality
		// friend Ray<T> operator>= (Ray<T> const& r1, Ray<T> const& r2); // greater than or equal to
		// friend Ray<T> operator<= (Ray<T> const& r1, Ray<T> const& r2); // less than or equal to
		// friend Ray<T> operator< (Ray<T> const& r1, Ray<T> const& r2); // less than
		// friend Ray<T> operator> (Ray<T> const& r1, Ray<T> const& r2); // greater than
		// friend Ray<T> operator+= (Ray<T> const& r1, Ray<T> const& r2); // add and assign
		// friend Ray<T> operator-= (Ray<T> const& r1, Ray<T> const& r2); // subtract and assign
		// friend Ray<T>* operator= (Ray<T> const& r1, Ray<T> const& r2); // assignment


};


