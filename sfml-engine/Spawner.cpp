#include "Spawner.h"
#include "LogManager.h"

Spawner::Spawner()
{
}

Spawner::~Spawner()
{
}

void Spawner::spawnEnemy(int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		Enemies* en = new Enemies;
		en->setPosition(rand() % (DM.getWidth()), rand() % (DM.getHeight()));
		LM.consoleLog("%f %f", en->getPosition().x, en->getPosition().y);
	}
}