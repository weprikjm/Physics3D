#pragma once

class btCollisionShape;
class btRigidBody;
class mat4x4;
class Primitive;

struct PhysBody3D
{
	PhysBody3D(btCollisionShape* shape, btRigidBody* body, Primitive* primitive);
	~PhysBody3D();

	btCollisionShape* collision_shape;
	btRigidBody* body;
	Primitive* debug_draw;

	void GetTransform(float* matrix) const;
	void SetTransform(float* matrix) const;
	void SetPos(float x, float y, float z);
	void DebugDraw() const;
};