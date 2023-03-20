#ifndef __MOVEMENTSYSTEM_H__
#define __MOVEMENTSYSTEM_H__

#include "../ECS/ECS.h"

#include "../Components/RigidBodyComponent.h"
#include "../Components/TransformComponent.h"

class MovementSystem : public System 
{

public: 
	MovementSystem()
	{
		RequireComponent<TransformComponent>(); 
		RequireComponent<RigidBodyComponent>(); 
	}
	void Update(double deltaTime)
	{
		for (auto enity : GetSystemEntities())
		{
			auto& transform = enity.GetComponent<TransformComponent>(); 
			const auto rigidbody = enity.GetComponent<RigidBodyComponent>(); 

			transform.position.x += rigidbody.velocity.x * deltaTime; 
			transform.position.y += rigidbody.velocity.y * deltaTime;

			Logger::Log("Entity id : " + 
				std::to_string(enity.GetId()) + "\tposition is now (" + 
				std::to_string(transform.position.x) + "," + 
				std::to_string(transform.position.y) + ")" 
			);
		}
	}
};

#endif