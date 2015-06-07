#pragma once
#define PI 3.14159265f

struct Vec3
{
	Vec3()
		:x(0.f), y(0.f), z(0.f)
	{
	}
	Vec3(float x, float y, float z)
		:x(x), y(y), z(z)
	{
	}

	Vec3 Normalize()
	{
		float distance = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		Vec3 retVec(0.f, 0.f, 0.f);
		if(distance != 0.f)
		{
			retVec = Vec3(x / distance, y / distance, z / distance);
		}
		return retVec;
	};

	float dotVector3D(const Vec3&vec) const
	{
		return x * vec.x + y * vec.y + z * vec.z;
	}

	Vec3 CrossProduct(const Vec3& rhs)
	{
		Vec3 r;
		r.x = y * rhs.z - z * rhs.y;
		r.y = z * rhs.x - x * rhs.z;
		r.z = x * rhs.y - y * rhs.x;
		return r;
	}
	Vec3 operator*( float rhs )
	{
		return Vec3(x*rhs, y*rhs, z*rhs);
	}

	float x;
	float y;
	float z;
};


struct Vec2
{
	Vec2()
		:_u(0.f), _v(0.f)
	{
	}
	Vec2(float u, float v)
		:_u(u), _v(v)
	{
	}

	float	GetX() const {return _u; }
	float	GetY() const {return _v; }
	float	GetU() const {return _u; }
	float	GetV() const {return _v; }

	void	SetX(float x) { _u = x;}
	void	SetY(float y) { _v = y;}
	void	SetU(float u) { _u = u;}
	void	SetV(float v) { _v = v;}

	Vec2 operator+( const Vec2& other )
	{
		Vec2 result;
		result._u = _u + other._u;
		result._v = _v + other._v;

		return result;
	};


	float _u;
	float _v;
};

