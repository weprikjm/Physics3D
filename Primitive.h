
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
	bool axis,wire;
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

// ============================================
class Cylinder : public Primitive
{
public:
	Cylinder(float radius, float height);
	void InnerRender() const;
public:
	float radius;
	float height;
};

// ============================================
class Line : public Primitive
{
public:
	Line(float x, float y, float z);
	void InnerRender() const;
public:
	vec3 origin;
	vec3 destination;
};

// ============================================
class Plane : public Primitive
{
public:
	Plane(float x, float y, float z, float d);
	void InnerRender() const;
public:
	vec3 normal;
	float constant;
};