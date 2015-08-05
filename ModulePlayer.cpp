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

	car.chassis_size.Set(2, 1, 4);
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
	float wheel_width = 0.2f;
	float suspensionRestLength = 1.2f;
	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics3D->AddVehicle(car);
	vehicle->SetPos(0, 1, 0);

	//vehicle = App->physics3D->AddVehicle2(car);

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
	float turn = RADTODEG * 210.0f; // degrees;

	Cylinder c(1, 2);
	c.wire = true;
	c.axis = true;
	c.Render();

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
		Cylinder c(0.5,1);
		c.SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
		App->physics3D->AddBody(c);
	}

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		vehicle->ApplyEngineForce(1000);
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
	{
		vehicle->Turn(turn);
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_UP)
	{
		vehicle->Turn(0);
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
	{
		vehicle->Turn(-turn);
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_UP)
	{
		vehicle->Turn(0);
	}

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		vehicle->Brake(100);
	}

	return UPDATE_CONTINUE;
}



