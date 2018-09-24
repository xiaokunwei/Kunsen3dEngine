#ifndef VEC2I_H
#define VEC2I_H
#include"Export.h"
namespace KunSen
{
	class EXPORT_API Vec2i
	{
	public:

		/** Type of Vec class.*/
		typedef int value_type;

		/** Number of vector components. */
		enum { num_components = 2 };

		/** Vec member varaible. */
		value_type _v[2];

		Vec2i() { _v[0] = 0; _v[1] = 0; }

		Vec2i(value_type x, value_type y) { _v[0] = x; _v[1] = y; }

		inline bool operator == (const Vec2i& v) const { return _v[0] == v._v[0] && _v[1] == v._v[1]; }
		inline bool operator != (const Vec2i& v) const { return _v[0] != v._v[0] || _v[1] != v._v[1]; }
		inline bool operator <  (const Vec2i& v) const
		{
			if (_v[0]<v._v[0])      return true;
			else if (_v[0]>v._v[0]) return false;
			else return (_v[1] < v._v[1]);
		}

		inline value_type* ptr() { return _v; }
		inline const value_type* ptr() const { return _v; }

		inline void set(value_type x, value_type y)
		{
			_v[0] = x; _v[1] = y;
		}

		inline void set(const Vec2i& rhs)
		{
			_v[0] = rhs._v[0]; _v[1] = rhs._v[1];
		}

		inline value_type& operator [] (int i) { return _v[i]; }
		inline value_type operator [] (int i) const { return _v[i]; }

		inline value_type& x() { return _v[0]; }
		inline value_type& y() { return _v[1]; }

		inline value_type x() const { return _v[0]; }
		inline value_type y() const { return _v[1]; }

		inline value_type& r() { return _v[0]; }
		inline value_type& g() { return _v[1]; }

		inline value_type r() const { return _v[0]; }
		inline value_type g() const { return _v[1]; }

		inline Vec2i operator * (value_type rhs) const
		{
			return Vec2i(_v[0] * rhs, _v[1] * rhs);
		}

		inline Vec2i operator / (value_type rhs) const
		{
			return Vec2i(_v[0] / rhs, _v[1] / rhs);
		}

		inline Vec2i operator + (value_type rhs) const
		{
			return Vec2i(_v[0] + rhs, _v[1] + rhs);
		}

		inline Vec2i operator - (value_type rhs) const
		{
			return Vec2i(_v[0] - rhs, _v[1] - rhs);
		}

		inline Vec2i operator + (const Vec2i& rhs) const
		{
			return Vec2i(_v[0] + rhs._v[0], _v[1] + rhs._v[1]);
		}

		inline Vec2i operator - (const Vec2i& rhs) const
		{
			return Vec2i(_v[0] - rhs._v[0], _v[1] - rhs._v[1]);
		}

		inline Vec2i operator * (const Vec2i& rhs) const
		{
			return Vec2i(_v[0] * rhs._v[0], _v[1] * rhs._v[1]);
		}

	};
}

#endif
