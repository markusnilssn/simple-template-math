#include "Math.h"

float stm::Math::RadToDegree(float rad)
{
    return (rad * 180.0f) / PI;
}

float stm::Math::DegreeToRad(float degree)
{
    return (degree * PI) / 180.0f;
}

float stm::Math::Sign(float aValue)
{
return aValue < 0.0f ? -1.0f : 1.0f;
}

float stm::Math::Clamp(float value, float min, float max)
{
    if(value < min)
		return min;
	else if(value > max)
		return max;
	else
		return value;
}

float stm::Math::Clamp01(float value)
{
	if (value < 0.0f)
		return 0.0f;
	else if (value > 1.0f)
		return 1.0f;
	else
		return value;
}

float stm::Math::Lerp(float a, float b, float t) 
{
	return a + (b - a) * t;
}
