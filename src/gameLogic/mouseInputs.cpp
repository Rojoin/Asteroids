#include "mouseInputs.h"
#include "raylib.h"

namespace Inputs
{
	Vector2 getMouseInput()
{
	return GetMousePosition();
}
bool isMouseKeyDown(int mouse)
{
	if (IsMouseButtonDown(mouse))
	{
		return true;
	}
	else return false;
}
	bool isMouseKeyPressed(int mouse)
{
	if (IsMouseButtonPressed(mouse))
	{
		return true;
	}
	else return false;
}
}


