#include  "howToStates.h"
#include  "GameStates.h"
#include <raylib.h>

#include "button.h"


Button escapeButton = createButton(" GO BACK", RED);
void statesRules()
{
	Vector2 mousePoint = GetMousePosition();
	escapeButton = createButton(0, (float)GetScreenHeight() - escapeButton.rec.height*2, escapeButton.buttonTittle, escapeButton.color);
	if (CheckCollisionPointRec(mousePoint, escapeButton.rec))
	{
		escapeButton.isOverThisButton = true;


		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			setGameState(GameStates::Menu);
		}

	}
	else
	{
		escapeButton.isOverThisButton = false;
	}
}
void drawRules()
{


	ClearBackground(BLACK);
	drawButton(escapeButton);
	std::string rules = "Rules";
	int fontSize = 3 * GetScreenWidth() / 190;
	std::string firstSentence = "The Last Slice is a survival game where you try to not get eaten";
	std::string secondSentence = "The objective is simple,score 5 points to win before your opponent.";
	std::string thirdSentence = "Player 1(At the left) will use W S while Player 2 will use the up and down key.";
	std::string forthSentence = "When the ball turns Violet avoid it or your oponnent will get a point!.";
	std::string fifthSentence = "And watchout, you can get Shrink with the YELLOW powerUp.";
	
	DrawText(firstSentence.c_str(), GetScreenWidth() / 3 - firstSentence.length(), (GetScreenHeight() / 4 + fontSize), fontSize, BLACK);
	DrawText(secondSentence.c_str(), GetScreenWidth() / 3 - secondSentence.length(), (GetScreenHeight() / 5 + fontSize), fontSize, BLACK);
	DrawText(thirdSentence.c_str(), GetScreenWidth() / 3 - thirdSentence.length(), (GetScreenHeight() / 2 - GetScreenHeight() / 5) + fontSize, fontSize, BLACK);
	DrawText(forthSentence.c_str(), GetScreenWidth() / 3 - forthSentence.length(), (GetScreenHeight() / 2 - GetScreenHeight() / 6) + fontSize, fontSize, BLACK);
	DrawText(fifthSentence.c_str(), GetScreenWidth() / 3 - fifthSentence.length(), (GetScreenHeight() / 2 - GetScreenHeight() / 7) + fontSize, fontSize, BLACK);
	DrawText(rules.c_str(), ((GetScreenWidth() / 2) - rules.length() * fontSize), GetScreenHeight() / 10, fontSize * 4, RED);

	drawButton(escapeButton);


}