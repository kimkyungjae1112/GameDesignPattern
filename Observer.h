#pragma once
#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include <vector>
namespace HObserver
{
	enum class Event {};
	class Entity {};

	class Observer
	{
	public:
		virtual ~Observer() {}
		virtual void OnNotify(const Entity& entity, Event event) = 0;
	};

	class Achievments : public Observer
	{
	public:
		virtual void OnNotify(const Entity& entity, Event event)
		{
			//구현
		}

	private:
		void UnLock(Achievments achievments) { /* 업적 달성 */ }
	};

	class Subject
	{
	public:
		void AddObserver(Observer* observer)
		{
			Observers.push_back(observer);
		}
		void RemoveObserver(Observer* observer)
		{
			Observers.push_back(observer);
		}

	protected:
		void Notify(const Entity& entity, Event event)
		{
			for (auto& observer : Observers)
			{
				observer->OnNotify(entity, event);
			}
		}

	private:
		std::vector<Observer*> Observers;
	};
}

#endif //__OBSERVER_H__