#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	if(App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
	{
		Sphere s(1);
		s.SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
		App->physics3D->AddBody(s);
	}
	return UPDATE_CONTINUE;
}



