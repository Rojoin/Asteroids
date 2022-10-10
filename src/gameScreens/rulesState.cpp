#include <raylib.h>
#include  "rulesState.h"
#include  "GameStates.h"
#include "system/draw.h"
#include "button.h"

extern Font customFont;
Button escapeButton = createButton(" GO BACK", RED);
void statesRules()
{
	Vector2 mousePoint = GetMousePosition();
	escapeButton = createButton(0, (float)GetScreenHeight() - escapeButton.rec.height * 2, escapeButton.buttonTittle, escapeButton.color);
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
	float height = static_cast<float>(GetScreenHeight());
	ClearBackground(BLACK);
	drawButton(escapeButton);
	float fontSize = 3 * width / 190;
	const std::string rulesTitle = "Rules";
	const std::string rulesFirstSentence = "The Last Slice is a survival game";
	const std::string rulesSecondSentence = " where you try to not get eaten.";
	const std::string rulesThirdSentence = "WatchOut! The hands will try to catch you!";
	const std::string rulesForthSentence = "You have 3 lives";
	const std::string rulesFifthSentence = "You will lose one if they caught you";
	const std::string rulesSixthSentence = "if you lose all your lives its GameOver!";
	const std::string controlsTitle = "Controls";
	const std::string controlsFirstSentence = "Use the LeftClick to shoot";
	const std::string controlsSecondSentence = "Use the RightClick to move towards your mouse";

	drawText(rulesTitle,         width / 2.0f - static_cast<float>(rulesTitle.length()) * 1.5f * fontSize, height / 40, fontSize * 8.0f, DARKBROWN, customFont);
	drawText(rulesFirstSentence, width / 2.0f - static_cast<float>(rulesFirstSentence.length()) / 1.5f * fontSize, height / 5, fontSize * 2.0f, BLACK, customFont);
	drawText(rulesSecondSentence,width / 2.0f - static_cast<float>(rulesSecondSentence.length()) / 1.5f * fontSize, height / 4.0f, fontSize * 2.0f, BLACK, customFont);
	drawText(rulesThirdSentence, width / 2.0f - static_cast<float>(rulesThirdSentence.length()) / 1.5f * fontSize, height / 3.5f, fontSize * 2.0f, BLACK, customFont);
	drawText(rulesForthSentence, width / 2.0f - static_cast<float>(rulesForthSentence.length()) / 1.5f * fontSize, height / 3.0f, fontSize * 2.0f, BLACK, customFont);
	drawText(rulesFifthSentence, width / 2.0f - static_cast<float>(rulesFifthSentence.length()) / 1.5f * fontSize, height / 2.5f, fontSize * 2.0f, BLACK, customFont);
	drawText(rulesSixthSentence, width / 2.0f - static_cast<float>(rulesSixthSentence.length()) / 1.5f * fontSize, height / 2.2f, fontSize * 2.0f, BLACK, customFont);


	drawText(controlsTitle, width / 2.0f - static_cast<float>(controlsTitle.length()) * 1.5f * fontSize, height / 2, fontSize * 8.0f, DARKBROWN, customFont);
	drawText(controlsFirstSentence, width / 2.0f - static_cast<float>(controlsFirstSentence.length()) / 1.5f * fontSize, height / 1.5f, fontSize * 2.0f, BLACK, customFont);
	drawText(controlsSecondSentence, width / 2.0f - static_cast<float>(controlsSecondSentence.length()) / 1.5f * fontSize, height / 1.4f, fontSize * 2.0f, BLACK, customFont);
	DrawRectangle(GetScreenWidth() / 2, 0, 10, GetScreenHeight(), BLUE);
	
	drawButton(escapeButton);


}