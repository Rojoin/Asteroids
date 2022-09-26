#include <ctime>
#include <raylib.h>

#include "statesManager.h"
#include "GameStates.h"
#include "menuState.h"
#include "../gameObjects/spaceShip.h"
#include "../gameLogic/gameLogic.h"
#include "../system/draw.h"


GameStates gameStates;
void initProgram()
{
	setGameState(GameStates::Menu);
	SetRandomSeed(time(NULL));
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1024, 768, "Ship Example");
	InitAudioDevice();
	SetWindowMinSize(1024, 768);
	Texture2D wallpaper;
	extern Texture2D shipTexture;
	extern Texture2D bulletTexture;
	extern Texture2D asteroidTexture;
	extern Texture2D asteroidMediumTexture;
	 Texture2D livesTexture;
	extern Sound deathSound;
	extern Sound collisionSound;
	extern Font customFont;
	collisionSound = LoadSound("resources/collision.wav");
	livesTexture = LoadTexture("resources/lives.png");
	extern Sound bulletSound;
	Music mainTheme = LoadMusicStream("resources/theLastSlice.mp3");
	float timePlayed = 0.0f;


	bulletSound = LoadSound("resources/bullet2.wav");
	deathSound = LoadSound("resources/explosion.wav");

	customFont = LoadFontEx("resources/LoftygoalsRegular-9Y5Xy.otf", 96, 0, 0);
	wallpaper = LoadTexture("resources/pizzaWallpaper.png");
	shipTexture = LoadTexture("resources/pizzaTiledMap.png");
	bulletTexture = LoadTexture("resources/olive.png");
	asteroidTexture = LoadTexture("resources/bigHand.png");
	asteroidMediumTexture = LoadTexture("resources/mediumHand.png");

	extern SpaceShip spaceShip;

	bool isProgramRunning = true;

	GenTextureMipmaps(&customFont.texture);
	SetTextureFilter(customFont.texture, TEXTURE_FILTER_ANISOTROPIC_16X);
	SetMusicVolume(mainTheme, 0.5);
	PlayMusicStream(mainTheme);
	while (!WindowShouldClose()&&isProgramRunning)
	{
		UpdateMusicStream(mainTheme);
		timePlayed = GetMusicTimePlayed(mainTheme) / GetMusicTimeLength(mainTheme);
		if (timePlayed > 1.0f)timePlayed = 1.0f;



		switch (gameStates)
		{
		case GameStates::Menu:

			stateMenu(gameStates);

			break;
		case GameStates::Game:
			playGame();
			break;
		case GameStates::HowTo:
			break;
		case GameStates::Credits:
			break;
		case GameStates::Exit:
			isProgramRunning = false;
			break;

		}
		UpdateMusicStream(mainTheme);
			BeginDrawing();
			DrawTexture(wallpaper, 0, 0, WHITE);
		switch (gameStates)
		{
		case GameStates::Menu:



			drawMenu();



			break;
		case GameStates::Game:
			drawGame();
			for (int i = 0; i < spaceShip.lives;i++)
			{
				drawTexture(livesTexture, {GetScreenWidth() - livesTexture.width * (i + 1.0f),0}, 0, 1, WHITE);
			}
			drawText(TextFormat("SCORE: %1i", spaceShip.score), 0, 0, 50, BLACK, customFont);
			break;
		case GameStates::HowTo:
			break;
		case GameStates::Credits:
			break;
		case GameStates::Exit:
			break;

		}
		ClearBackground(BLACK);
			EndDrawing();
	}
	CloseWindow();
	CloseAudioDevice();
}
