#pragma once

class Primitive;
class Cube;
class Sphere;
struct PhysBody3D;
class ModulePhysics3D;

struct PhysPrimitive
{
	Primitive* primitive;
	PhysBody3D* body;

	PhysPrimitive(PhysBody3D* body, const Cube& primitive);
	PhysPrimitive(PhysBody3D* body, const Sphere& primitive);
	~PhysPrimitive();

	void Render();
	void SetPos(float x, float y, float z);
};