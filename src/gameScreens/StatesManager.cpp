#include <raylib.h>

#include "statesManager.h"
#include "GameStates.h"
#include "menuState.h"
#include "../gameObjects/spaceShip.h"


void initProgram()
{
	gameStates = GameStates::Menu;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1920, 1000, "Ship Example");
	InitAudioDevice();
	SetWindowMinSize(1024, 768);
	Texture2D wallpaper;
	extern Texture2D shipTexture;
	extern Texture2D bulletTexture;
	extern Texture2D asteroidTexture;
	extern Texture2D asteroidMediumTexture;
	extern Sound deathSound;
	extern Sound collisionSound;
	extern Font customFont;
	collisionSound = LoadSound("resources/collision.wav");

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



	GenTextureMipmaps(&customFont.texture);
	SetTextureFilter(customFont.texture, TEXTURE_FILTER_ANISOTROPIC_16X);
	SetMusicVolume(mainTheme, 0.5);
	PlayMusicStream(mainTheme);
	while (!WindowShouldClose())
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
			break;
		case GameStates::HowTo:
			break;
		case GameStates::Credits:
			break;
		case GameStates::Exit:
			break;

		}
		UpdateMusicStream(mainTheme);
			BeginDrawing();
		switch (gameStates)
		{
		case GameStates::Menu:



			DrawTexture(wallpaper, 0, 0, WHITE);
			drawMenu();



			break;
		case GameStates::Game:
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
