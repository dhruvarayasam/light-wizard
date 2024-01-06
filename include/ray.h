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
		*Ray<T> operator+ (Ray<T> const& r1, Ray<T> const& r2); // addition of two rays
		*Ray<T> operator* (Ray<T> const& r1, Ray<T> const& r2); // dot product
		*Ray<T> operator- (Ray<T> const& r1, Ray<T> const& r2); // subtraction of two rays
		*Ray<T> operator== (Ray<T> const& r1, Ray<T> const& r2); // equality
		*Ray<T> operator!= (Ray<T> const& r1, Ray<T> const& r2); // inequality
		*Ray<T> operator>= (Ray<T> const& r1, Ray<T> const& r2); // greater than or equal to
		*Ray<T> operator<= (Ray<T> const& r1, Ray<T> const& r2); // less than or equal to
		*Ray<T> operator< (Ray<T> const& r1, Ray<T> const& r2); // less than
		*Ray<T> operator> (Ray<T> const& r1, Ray<T> const& r2); // greater than
		*Ray<T> operator+= (Ray<T> const& r1, Ray<T> const& r2); // add and assign
		*Ray<T> operator-= (Ray<T> const& r1, Ray<T> const& r2); // subtract and assign
		*Ray<T> operator= (Ray<T> const& r1, Ray<T> const& r2); // assignment


};


