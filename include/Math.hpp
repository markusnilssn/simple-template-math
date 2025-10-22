#pragma once


namespace stm
{
	struct Math
	{
		static constexpr float PI = 3.141592f;
		static constexpr float ELIPSON = 0.0001f;
		static constexpr double ELIPSON_D = 0.0001;

		static float RadToDegree(float rad);
		static float DegreeToRad(float degree);

		static float Sign(float value);

		static float Clamp(float value, float min, float max);
		static float Clamp01(float value);

		static float Lerp(float a, float b, float t);
	};
}