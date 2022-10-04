#include  "rulesState.h"
#include  "GameStates.h"
#include <raylib.h>
#include "system/draw.h"
#include "button.h"

extern Font customFont;
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

	float width = static_cast<float>(GetScreenWidth());
	float height= static_cast<float>(GetScreenHeight());
	ClearBackground(BLACK);
	drawButton(escapeButton);
	std::string rulesTitle = "Rules";
	float fontSize = 3 * width/ 190;
	std::string firstSentence = "The Last Slice is a survival game";
	std::string secondSentence = " where you try to not get eaten";

	std::string thirdSentence = "Use the LeftClick to shoot";
	std::string forthSentence = "Use the RightClick to move towards your mouse";
	std::string athirdSentence = "WatchOut! The hands will try to catch you!";
	std::string aforthSentence = "You have 3 lives and you lose one every time an enemy touch you"; 
	std::string fifthSentence = "if you lose all your lives its GameOver!";
	drawText(rulesTitle,	  width/ 2.0f     - static_cast<float>(rulesTitle.length())*1.5f *fontSize, height / 10,fontSize* 8.0f, DARKBROWN, customFont);
	drawText(firstSentence, width/ 2.0f  - static_cast<float>(firstSentence.length())/1.5f  * fontSize, height / 4, fontSize*2.0f, BLACK, customFont);
	drawText(secondSentence,width / 2.0f - static_cast<float>(secondSentence.length())/1.5f * fontSize, height / 3.5f, fontSize * 2.0f, BLACK, customFont);
	drawText(thirdSentence, width / 2.0f  - static_cast<float>(thirdSentence.length())/1.5f  *fontSize, height / 3.0f, fontSize * 2.0f, BLACK, customFont);
	drawText(forthSentence, width / 2.0f  - static_cast<float>(forthSentence.length())/1.5f  *fontSize, height / 2.5f, fontSize * 2.0f, BLACK, customFont);
	DrawRectangle(GetScreenWidth() / 2, 0, 10, GetScreenHeight(), BLUE);
	//DrawText(firstSentence.c_str(), GetScreenWidth() / 3 - firstSentence.length(), (GetScreenHeight() / 4 + fontSize), fontSize, BLACK);
	//DrawText(secondSentence.c_str(), GetScreenWidth() / 3 - secondSentence.length(), (GetScreenHeight() / 5 + fontSize), fontSize, BLACK);
	//DrawText(thirdSentence.c_str(), GetScreenWidth() / 3 - thirdSentence.length(), (GetScreenHeight() / 2 - GetScreenHeight() / 5) + fontSize, fontSize, BLACK);
	//DrawText(forthSentence.c_str(), GetScreenWidth() / 3 - forthSentence.length(), (GetScreenHeight() / 2 - GetScreenHeight() / 6) + fontSize, fontSize, BLACK);
	//DrawText(fifthSentence.c_str(), GetScreenWidth() / 3 - fifthSentence.length(), (GetScreenHeight() / 2 - GetScreenHeight() / 7) + fontSize, fontSize, BLACK);
	//DrawText(rulesTitle.c_str(), ((GetScreenWidth() / 2) - rulesTitle.length() * fontSize), GetScreenHeight() / 10, fontSize * 4, RED);

	drawButton(escapeButton);


}