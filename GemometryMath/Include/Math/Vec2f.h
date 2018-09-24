#ifndef VEC2_H
#define VEC2_H
#include"Export.h"

#include<math.h>
namespace KunSen
{
	class EXPORT_API Vec2f
	{
	public:

		/** Data type of vector components.*/
		typedef float value_type;

		/** Number of vector components. */
		enum { num_components = 2 };

		/** Vec member variable. */
		value_type _v[2];


		/** Constructor that sets all components of the vector to zero */
		Vec2f() { _v[0] = 0.0; _v[1] = 0.0; }
		Vec2f(value_type x, value_type y) { _v[0] = x; _v[1] = y; }


		inline bool operator == (const Vec2f& v) const { return _v[0] == v._v[0] && _v[1] == v._v[1]; }

		inline bool operator != (const Vec2f& v) const { return _v[0] != v._v[0] || _v[1] != v._v[1]; }

		inline bool operator <  (const Vec2f& v) const
		{
			if (_v[0]<v._v[0]) return true;
			else if (_v[0]>v._v[0]) return false;
			else return (_v[1]<v._v[1]);
		}

		inline value_type * ptr() { return _v; }
		inline const value_type * ptr() const { return _v; }

		inline void set(value_type x, value_type y) { _v[0] = x; _v[1] = y; }

		inline value_type & operator [] (int i) { return _v[i]; }
		inline value_type operator [] (int i) const { return _v[i]; }

		inline value_type & x() { return _v[0]; }
		inline value_type & y() { return _v[1]; }

		inline value_type x() const { return _v[0]; }
		inline value_type y() const { return _v[1]; }

		/** Returns true if all components have values that are not NaN. */
		//inline bool valid() const { return !isNaN(); }
		/** Returns true if at least one component has value NaN. */
		//inline bool isNaN() const { return osg::isNaN(_v[0]) || osg::isNaN(_v[1]); }

		/** Dot product. */
		inline value_type operator * (const Vec2f& rhs) const
		{
			return _v[0] * rhs._v[0] + _v[1] * rhs._v[1];
		}

		/** Multiply by scalar. */
		inline const Vec2f operator * (value_type rhs) const
		{
			return Vec2f(_v[0] * rhs, _v[1] * rhs);
		}

		/** Unary multiply by scalar. */
		inline Vec2f& operator *= (value_type rhs)
		{
			_v[0] *= rhs;
			_v[1] *= rhs;
			return *this;
		}

		/** Divide by scalar. */
		inline const Vec2f operator / (value_type rhs) const
		{
			return Vec2f(_v[0] / rhs, _v[1] / rhs);
		}

		/** Unary divide by scalar. */
		inline Vec2f& operator /= (value_type rhs)
		{
			_v[0] /= rhs;
			_v[1] /= rhs;
			return *this;
		}

		/** Binary vector add. */
		inline const Vec2f operator + (const Vec2f& rhs) const
		{
			return Vec2f(_v[0] + rhs._v[0], _v[1] + rhs._v[1]);
		}

		/** Unary vector add. Slightly more efficient because no temporary
		* intermediate object.
		*/
		inline Vec2f& operator += (const Vec2f& rhs)
		{
			_v[0] += rhs._v[0];
			_v[1] += rhs._v[1];
			return *this;
		}

		/** Binary vector subtract. */
		inline const Vec2f operator - (const Vec2f& rhs) const
		{
			return Vec2f(_v[0] - rhs._v[0], _v[1] - rhs._v[1]);
		}

		/** Unary vector subtract. */
		inline Vec2f& operator -= (const Vec2f& rhs)
		{
			_v[0] -= rhs._v[0];
			_v[1] -= rhs._v[1];
			return *this;
		}

		/** Negation operator. Returns the negative of the Vec2f. */
		inline const Vec2f operator - () const
		{
			return Vec2f(-_v[0], -_v[1]);
		}

		/** Length of the vector = sqrt( vec . vec ) */
		inline value_type length() const
		{
			return sqrtf(_v[0] * _v[0] + _v[1] * _v[1]);
		}

		/** Length squared of the vector = vec . vec */
		inline value_type length2(void) const
		{
			return _v[0] * _v[0] + _v[1] * _v[1];
		}

		/** Normalize the vector so that it has length unity.
		* Returns the previous length of the vector.
		*/
		inline value_type normalize()
		{
			value_type norm = Vec2f::length();
			if (norm>0.0)
			{
				value_type inv = 1.0f / norm;
				_v[0] *= inv;
				_v[1] *= inv;
			}
			return(norm);
		}

	};    // end of class Vec2f
}


#endif