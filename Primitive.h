
#pragma once
#include "glmath.h"
#include "Color.h"

class Primitive
{
public:

	Primitive();

	virtual void Render() const;
	virtual void InnerRender() const;
	void SetPos(float x, float y, float z);
	void SetRotation(float angle, const vec3 &u);
	void Scale(float x, float y, float z);

public:
	
	Color color;
	mat4x4 transform;
	bool wire;
};

// ============================================
class Cube : public Primitive
{
public :
	Cube(float sizeX, float sizeY, float sizeZ);
	void InnerRender() const;
public:
	vec3 size;
};

// ============================================
class Sphere : public Primitive
{
public:
	Sphere(float radius);
	void InnerRender() const;
public:
	float radius;
};