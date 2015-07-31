#include "PhysPrimitive.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "Bullet\src\btBulletDynamicsCommon.h"

PhysPrimitive::PhysPrimitive(PhysBody3D* body, const Cube& primitive) : body(body)
{
	this->primitive = new Cube(primitive);
}

PhysPrimitive::PhysPrimitive(PhysBody3D* body, const Sphere& primitive) : body(body)
{
	this->primitive = new Sphere(primitive);
}

PhysPrimitive::~PhysPrimitive()
{
	delete primitive;
}

void PhysPrimitive::Render()
{
	body->GetTransform(&(primitive->transform));
	primitive->Render();
}

void PhysPrimitive::SetPos(float x, float y, float z)
{
	mat4x4 m;
	body->GetTransform(&m);
	m.translate(x, y, z);
	body->SetTransform(&m);
}
