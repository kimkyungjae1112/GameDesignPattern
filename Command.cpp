#include "Command.h"
using namespace ActorCommand;
namespace ActorCommandCpp
{
	enum class InputButton
	{
		BUTTON_X,
		BUTTON_Y,
		BUTTON_A,
		BUTTON_B
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
