#include <cmath>


inline bool floatNearlyEqual(float d1, float d2, float tolerance = 0.000001f)
{
	return (abs(d1 - d2) < tolerance);
}