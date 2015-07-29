
#pragma once

struct Color
{
	Color() : r(0.0f), g(0.0f), b(0.0f)
	{}

	Color(float r, float g, float b) : r(r), g(g), b(b)
	{}

	float r, g, b;
};

extern Color Red;
extern Color Green;
extern Color Blue;
extern Color Black;
extern Color White;