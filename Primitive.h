
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
	Cube(float size);
	void InnerRender() const;
public:
	float size;
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