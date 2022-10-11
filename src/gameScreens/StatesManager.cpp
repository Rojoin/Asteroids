#include <ctime>
#include <raylib.h>

#include "statesManager.h"
#include "GameStates.h"
#include "menuState.h"
#include "rulesState.h"
#include "creditsState.h"
#include "initialAnimationScreen.h"
#include "gameObjects/spaceShip.h"
#include "gameLogic/gameLogic.h"
#include "system/draw.h"


GameStates gameStates;

Texture2D wallpaper;
extern Texture2D creditsTexture;
extern Texture2D titleTexture;
extern Texture2D shipTexture;
extern Texture2D bulletTexture;
extern Texture2D asteroidSpecialTexture;
extern Texture2D asteroidBigTexture;
extern Texture2D asteroidMediumTexture;
extern Texture2D asteroidSmallTexture;
extern Texture2D livesTexture;
extern Texture2D splashScreen;
extern Sound deathSound;
extern Sound collisionSound;
extern Font customFont;
extern Sound bulletSound;
	extern SpaceShip spaceShip;
	Music mainTheme;
void loadResources()
{
	customFont = LoadFontEx("resources/LoftygoalsRegular-9Y5Xy.otf", 96, nullptr, 0);
	collisionSound = LoadSound("resources/collision.wav");
	bulletSound = LoadSound("resources/bullet2.wav");
	deathSound = LoadSound("resources/explosion.wav");
	livesTexture = LoadTexture("resources/lives.png");
	splashScreen = LoadTexture("resources/splashScreen.png");
	wallpaper = LoadTexture("resources/pizzaWallpaper.png");
	shipTexture = LoadTexture("resources/pizzaTiledMap.png");
	bulletTexture = LoadTexture("resources/olive.png");
	asteroidSpecialTexture = LoadTexture("resources/mouth.png");
	asteroidBigTexture = LoadTexture("resources/bigHand.png");
	asteroidMediumTexture = LoadTexture("resources/mediumHand.png");
	asteroidSmallTexture = LoadTexture("resources/smallHand.png");
	creditsTexture = LoadTexture("resources/credits.png");
	titleTexture = LoadTexture("resources/titleLogo.png");
	GenTextureMipmaps(&titleTexture);
	SetTextureFilter(titleTexture, TEXTURE_FILTER_ANISOTROPIC_16X);
	GenTextureMipmaps(&customFont.texture);
	SetTextureFilter(customFont.texture, TEXTURE_FILTER_ANISOTROPIC_16X);
	GenTextureMipmaps(&creditsTexture);
	SetTextureFilter(creditsTexture, TEXTURE_FILTER_ANISOTROPIC_16X);
}
void unLoadResources()
{
	UnloadMusicStream(mainTheme);
	UnloadFont(customFont);
	UnloadSound(collisionSound);
	UnloadSound(deathSound);
	UnloadSound(bulletSound);
	UnloadTexture(creditsTexture);
	UnloadTexture(asteroidBigTexture);
	UnloadTexture(asteroidSmallTexture);
	UnloadTexture(asteroidMediumTexture);
	UnloadTexture(asteroidSpecialTexture);
	UnloadTexture(bulletTexture);
	UnloadTexture(shipTexture);
	UnloadTexture(wallpaper);
	UnloadTexture(splashScreen);
	UnloadTexture(livesTexture);
	UnloadTexture(titleTexture);

}
void initProgram()
{
	setGameState(GameStates::InitialAnimation);
	SetRandomSeed(static_cast<unsigned int>(time(NULL)));
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1024, 768, "Ship Example");
	SetExitKey(NULL);
	InitAudioDevice();
	SetWindowMinSize(1024, 768);


	bool isProgramRunning = true;
	loadResources();
	mainTheme = LoadMusicStream("resources/theLastSlice.mp3");
	
	SetMusicVolume(mainTheme, 0.5);
	PlayMusicStream(mainTheme);
	while (!WindowShouldClose()&&isProgramRunning)
	{
		UpdateMusicStream(mainTheme);

		switch (gameStates)
		{
		case GameStates::InitialAnimation:
			statesInitialAnimation();
			break;
		case GameStates::Menu:
			statesMenu(gameStates);
			break;
		case GameStates::Game:
			playGame();
			break;
		case GameStates::Rules:
			statesRules();
			break;
		case GameStates::Credits:
			statesCredits();
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
		case GameStates::InitialAnimation:
			drawInitialAnimation();
			break;
		case GameStates::Menu:
			drawMenu();
			break;
		case GameStates::Game:
			drawGame();
			break;
		case GameStates::Rules:
			drawRules();
			break;
		case GameStates::Credits:
			drawCredits();
			break;
		case GameStates::Exit:
			break;

		}
		ClearBackground(BLACK);
			EndDrawing();
	}
	unLoadResources();
	CloseWindow();
	CloseAudioDevice();
}
