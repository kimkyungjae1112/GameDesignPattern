#pragma once
#ifndef __COMMAND_H__

namespace HActorCommand
{
	enum class InputButton
	{
		BUTTON_X,
		BUTTON_Y,
		BUTTON_A,
		BUTTON_B
	};

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

	class InputHandler
	{
	public:
		InputHandler();

		Command* HandleInput();

		void SetInputButton(InputButton button);


	private:
		Command* ButtonX;
		Command* ButtonY;
		Command* ButtonA;
		Command* ButtonB;

		InputButton CurrentButton;
	};

	InputHandler::InputHandler() : CurrentButton(InputButton::BUTTON_X)
	{
		ButtonX = new JumpCommand;
		ButtonY = new FireCommand;
		ButtonA = new SwapWeaponCommand;
		ButtonB = new Lurch;
	}

	Command* InputHandler::HandleInput()
	{
		switch (CurrentButton)
		{
		case InputButton::BUTTON_X:
			return ButtonX;
		case InputButton::BUTTON_Y:
			return ButtonY;
		case InputButton::BUTTON_A:
			return ButtonA;
		case InputButton::BUTTON_B:
			return ButtonB;
		default:
			return nullptr;
		}
	}

	void InputHandler::SetInputButton(InputButton button)
	{
		CurrentButton = button;
	}

	void ApplyActor(GameActor& Actor, InputButton button)
	{
		InputHandler inputHandler;
		inputHandler.SetInputButton(button);
		Command* command = inputHandler.HandleInput();
		if (command)
		{
			command->Execute(Actor);
		}
	}
}

namespace HUndoRedoCommand
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