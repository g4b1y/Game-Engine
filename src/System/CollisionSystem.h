 #ifndef __COLLISIONSYSTEM_H__
#define __COLLISIONSYSTEM_H__

#include "../ECS/ECS.h"
#include "../EventBus/EventBus.h"
#include "../Events/CollisionEvent.h"


#include "../Components/TransformComponent.h"
#include "../Components/BoxColliderComponent.h"

class CollisionSystem : public System
{
public: 
	CollisionSystem() 
	{
		RequireComponent<BoxColliderComponent>();
		RequireComponent<BoxColliderComponent>();
	}

	void Update(std::unique_ptr<EventBus>& eventBus)
	{
		auto entities = GetSystemEntities(); 

		for (auto i = entities.begin(); i != entities.end(); i++)
		{
			Entity a = *i; 

			auto aTransform = a.GetComponent<TransformComponent>(); 
			auto aCollider = a.GetComponent<BoxColliderComponent>(); 

			//Loop all the entities that still need to be checked 
			for (auto j = i; j != entities.end(); j++)
			{
				Entity b = *j; 

				//Bypass if we trying to test the same entity
				if (a == b) 
				{
					continue; 
				}

				//Perform the AABB collision check between entities a and b
				auto bTransform = b.GetComponent<TransformComponent>();
				auto bCollider = b.GetComponent<BoxColliderComponent>();

				bool collisionHappend = CheckAABBCollision(
					aTransform.position.x,
					aTransform.position.y,
					aCollider.width,
					aCollider.height,

					bTransform.position.x,
					bTransform.position.y,
					bCollider.width,
					bCollider.height
					); 

				if (collisionHappend) 
				{
					Logger::Log("Entity " + std::to_string(a.GetId()) + " is colliding with entity " + std::to_string(b.GetId())); 
					eventBus->EmitEvent<CollisionEvent>(a, b);
				}
			}
		}
	}

	bool CheckAABBCollision(double aX, double aY, double aW, double aH, double bX, double bY, double bW, double bH) 
	{
		return (
			aX < bX + bW &&
			aX + aW > bX &&
			aY < bY + bH &&
			aY + aH > bY
		); 
	}
};

#endif 
