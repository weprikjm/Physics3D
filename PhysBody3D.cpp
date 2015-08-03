#include "PhysBody3D.h"
#include "glmath.h"
#include "Bullet\src\btBulletDynamicsCommon.h"
#include "Primitive.h"

// ---------------------------------------------------------
PhysBody3D::PhysBody3D(btCollisionShape* shape, btRigidBody* body, Primitive* primitive) : collision_shape(shape), body(body), debug_draw(primitive)
{
	primitive->wire = true;
	primitive->axis = true;
}

// ---------------------------------------------------------
PhysBody3D::~PhysBody3D()
{
	delete debug_draw;
}

// ---------------------------------------------------------
void PhysBody3D::GetTransform(float* matrix) const
{
	if(body != NULL && matrix != NULL)
	{
		body->getWorldTransform().getOpenGLMatrix(matrix);
	}
}

// ---------------------------------------------------------
void PhysBody3D::SetTransform(float* matrix) const
{
	if(body != NULL && matrix != NULL)
	{
		btTransform t;
		t.setFromOpenGLMatrix(matrix);
		body->setWorldTransform(t);
	}
}

// ---------------------------------------------------------
void PhysBody3D::SetPos(float x, float y, float z)
{
	btTransform t = body->getWorldTransform();
	t.setOrigin(btVector3(x, y, z));
	body->setWorldTransform(t);
}

// ---------------------------------------------------------
void PhysBody3D::DebugDraw() const
{
	GetTransform(&(debug_draw->transform));
	debug_draw->Render();
}