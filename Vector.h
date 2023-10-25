class Vector
{
private:
	float x;
	float y;
	float z;

public:

	Vector(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}
	Vector();

	float length();

	void add(Vector v);

	void subb(Vector v);

	void mul(float a);

	void div(float a);

	float findAngle(Vector v);

	Vector normalize();

	//iloczyn skalarny
	float dot(Vector v);

	//iloczyn wektorowy
	
	Vector cross(Vector v);

	~Vector();
};



