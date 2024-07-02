#pragma once
#ifndef __COMMAND_H__

namespace ActorCommand
{
	class GameActor
	{
	public:
		void Jump() {}
		void FireGun() {}
		void SwapWeapon() {}
		void LurchInEffectively() {}
	};

	class Command
	{
	public:
		virtual ~Command();
		virtual void Execute(GameActor& Actor) = 0;
	};

	class JumpCommand : public Command
	{
	public:
		virtual void Execute(GameActor& Actor) { Actor.Jump(); }
	};

	class FireCommand : public Command
	{
	public:
		virtual void Execute(GameActor& Actor) { Actor.FireGun(); }
	};

	class SwapWeaponCommand : public Command
	{
	public:
		virtual void Execute(GameActor& Actor) { Actor.SwapWeapon(); }
	};

	class Lurch : public Command
	{
	public:
		virtual void Execute(GameActor& Actor) { Actor.LurchInEffectively(); }
	};
}

namespace UndoRedoCommand
{
	class Unit
	{
	public:
		void MoveTo(int x, int y) { this->x = x; this->y = y; }
		int GetX() { return x; }
		int GetY() { return y; }

	private:
		int x;
		int y;
	};

	class Command
	{
	public:
		virtual ~Command();
		virtual void Execute() = 0;
		virtual void Undo() = 0;
	};

	class MoveUnitCommand : public Command
	{
	public:
		MoveUnitCommand(Unit* unit, int x, int y) 
			: unit_(unit), x_(x), y_(y), xBefore_(0), yBefore_(0) {}

		virtual void Execute()
		{
			xBefore_ = unit_->GetX();
			yBefore_ = unit_->GetY();
			unit_->MoveTo(x_, y_);
		}

		virtual void Undo()
		{
			unit_->MoveTo(xBefore_, yBefore_);
		}
		

	private:
		Unit* unit_;
		int xBefore_;
		int yBefore_;
		int x_;
		int y_;
	};
}

#endif //__COMMAND_H__