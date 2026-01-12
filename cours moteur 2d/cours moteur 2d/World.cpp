#include "World.h"
#include "StaticObject.h"
#include "BreakableObject.h"
#include "Mob.h"
#include "Player.h"
#include <iostream>

void World::InitWorld()
{
	entities.push_back(new StaticObject(0, 0));
	entities.push_back(new BreakableObject(1, 0, 1, 1));
	entities.push_back(new Mob(5, 2, 20, 20, Vector2(1, 1), 1));
	entities.push_back(new Player(30, 12, 10, 10, Vector2(1, 1), 1));
}

bool World::Step()
{
	bool stopSteps = true;
	Mob* lastMob = nullptr;
	BreakableObject* lastBreakableObject = nullptr;
	for (auto entity : entities)
	{
		if (Mob* mob = dynamic_cast<Mob*>(entity))
		{
			if (mob->GetCurrentHealth() > 0)
			{
				stopSteps = false;
				lastMob = mob;
			}
		}
		else if (BreakableObject* breakableObject = dynamic_cast<BreakableObject*>(entity))
		{
			if (breakableObject->GetCurrentHealth() > 0)
			{
				stopSteps = false;
				lastBreakableObject = breakableObject;
			}
		}
	}

	if (stopSteps == true)
	{
		std::cout << "Simulation Finished" << std::endl;
		return stopSteps;
	}

	for (auto entity : entities)
	{
		if (Mob* mob = dynamic_cast<Mob*>(entity))
		{
			if (lastBreakableObject != nullptr)
			{
				float distanceX = lastBreakableObject->GetPosition().GetX() - mob->GetPosition().GetX();
				float distanceY = lastBreakableObject->GetPosition().GetY() - mob->GetPosition().GetY();

				if (distanceX != 0 && distanceY != 0)
				{
					mob->SetDirection(Vector2(distanceX, distanceY));
					mob->Move();
				}

				if (sqrtf(pow(distanceX, 2) + pow(distanceY, 2)) <= 1)
				{
					lastBreakableObject->TakeDamage(1);
				}
			}
		}

		else if (Player* player = dynamic_cast<Player*>(entity))
		{
			if (lastMob != nullptr)
			{
				float distanceX = lastMob->GetPosition().GetX() - player->GetPosition().GetX();
				float distanceY = lastMob->GetPosition().GetY() - player->GetPosition().GetY();

				if (distanceX != 0 && distanceY != 0)
				{
					player->SetDirection(Vector2(distanceX, distanceY));
					player->Move();
				}

				if (sqrtf(pow(distanceX, 2) + pow(distanceY, 2)) <= 1)
				{
					player->Attack(lastMob);
				}
			}
		}
	}

	return false;
}
