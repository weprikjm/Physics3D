#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	car.chassis_size.Set(1, 0.5, 2);
	car.chassis_offset.Set(0, 1.0, 0);
	car.mass = 800.0f;
	car.suspensionStiffness = 5.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 500.0f;
	car.frictionSlip = 10.5;
	car.maxSuspensionForce = 6000.0f;

	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	float connection_height = 1.2f;
	float wheel_radius = 0.5f;
	float wheel_width = 0.6f;
	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction.Set(0, -1, 0);
	car.wheels[0].axis.Set(-1, 0, 0);
	car.wheels[0].suspensionRestLength = 0.6f;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].front = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction.Set(0, -1, 0);
	car.wheels[1].axis.Set(-1, 0, 0);
	car.wheels[1].suspensionRestLength = 0.6f;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].front = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction.Set(0, -1, 0);
	car.wheels[2].axis.Set(-1, 0, 0);
	car.wheels[2].suspensionRestLength = 0.6f;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].front = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction.Set(0, -1, 0);
	car.wheels[3].axis.Set(-1, 0, 0);
	car.wheels[3].suspensionRestLength = 0.6f;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].front = false;

	vehicle = App->physics3D->AddVehicle(car);
	vehicle->SetPos(0, 3, 0);

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
	if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		Sphere s(1);
		s.SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
		App->physics3D->AddBody(s);
	}

	if(App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		Cube c(1,1,1);
		c.SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
		App->physics3D->AddBody(c);
	}

	if(App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		Cylinder c(0.2,0.5);
		c.SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
		App->physics3D->AddBody(c);
	}

	return UPDATE_CONTINUE;
}



