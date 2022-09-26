
#include "raylib.h"
#include "src/gameLogic/gameLogic.h"

#include "src/system/draw.h"
#include "src/gameObjects/spaceShip.h"


int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1920, 1000, "Ship Example");
	SetWindowMinSize(1024, 768);
	Font customFont = LoadFontEx("resources/LoftygoalsRegular-9Y5Xy.otf", 96, 0, 0);
	extern Texture2D shipTexture;
	extern Texture2D bulletTexture;
	extern Texture2D asteroidTexture;
	extern Texture2D asteroidMediumTexture;
    shipTexture = LoadTexture("resources/pizzaTiledMap.png");
    bulletTexture = LoadTexture("resources/olive.png");
    asteroidTexture = LoadTexture("resources/bigHand.png");
    asteroidMediumTexture = LoadTexture("resources/mediumHand.png");

	extern SpaceShip spaceShip;
	
	initGame();

	GenTextureMipmaps(&customFont.texture);
	SetTextureFilter(customFont.texture, TEXTURE_FILTER_TRILINEAR);

	while (!WindowShouldClose())
	{
		playGame();
		BeginDrawing();
		drawGame();
		drawText(TextFormat("SCORE: %1i", spaceShip.score), 0, 100, 50, WHITE, customFont);
		ClearBackground(BLACK);
		EndDrawing();

	}
	CloseWindow();
	return 0;
}
