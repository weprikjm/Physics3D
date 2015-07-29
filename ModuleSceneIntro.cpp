#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update(float dt)
{
	Cube c(2.0f);

	static float a = 0;
	c.SetRotation(a++, vec3(1, 1, 0));
	
	c.color = Blue;
	c.Render();

	Sphere s(2.0f);
	s.SetRotation(a, vec3(1, 0, 0));
	s.SetPos(5, 0, 0);
	s.wire = true;
	s.color = Red;
	s.Render();

	return UPDATE_CONTINUE;
}


void ModuleSceneIntro::OnCollision(PhysBody* body1, PhysBody* body2)
{
}
