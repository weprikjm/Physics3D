#pragma once

class btCollisionShape;
class btRigidBody;
class mat4x4;
class Primitive;

struct PhysBody3D
{
public:
	PhysBody3D(btRigidBody* body);
	~PhysBody3D();

	void GetTransform(float* matrix) const;
	void SetTransform(float* matrix) const;
	void SetPos(float x, float y, float z);

private:
	btRigidBody* body;
};
