#pragma once
#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

namespace HPrototype
{
	class Monster
	{
	public:
		virtual ~Monster() {}
		virtual Monster* Clone() = 0;
	};

	class Ghost : public Monster
	{
	public:
		Ghost(int InHealth, int InDamage) : Health(InHealth), Damage(InDamage) {}

		virtual Monster* Clone()
		{
			return new Ghost(Health, Damage);
		}

	private:
		int Health;
		int Damage;
	};

	class Spawner
	{
	public:
		Spawner(Monster* Prototype) : Prototype(Prototype) {}
		Monster* SpawnMonster()
		{
			return Prototype->Clone();
		}

	private:
		Monster* Prototype;
	};

	int main()
	{
		Monster* Ghost_ = new Ghost(10, 100);
		Spawner* Spawner_ = new Spawner(Ghost_);
		Spawner_->SpawnMonster();
		return 0;
	}
}



#endif //__PROTOTYPE_H__