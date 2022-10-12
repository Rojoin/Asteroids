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
Image gameIcon;
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
Texture2D mouseCursor;
extern GameObjects::SpaceShip spaceShip;
Music mainTheme;
bool isProgramRunning = true;

int mousePosX;
int mousePosY;
static void logicProgram();
static void drawProgram();
static void loadResources();
static void unLoadResources();
static void loadTextures();
static void unLoadTextures();
static void unLoadAudio();
static void loadAudios();

void initProgram()
{
	setGameState(GameStates::InitialAnimation);
	SetRandomSeed(static_cast<unsigned int>(time(NULL)));
	InitWindow(1024, 768, "The Last Slice");
	HideCursor();
	InitAudioDevice();
	loadResources();
	SetWindowIcon(gameIcon);
	SetExitKey(NULL);
	SetWindowMinSize(1024, 768);


	isProgramRunning = true;
	mainTheme = LoadMusicStream("resources/theLastSlice.mp3");


	SetMusicVolume(mainTheme, 0.5);
	PlayMusicStream(mainTheme);
	while (!WindowShouldClose() && isProgramRunning)
	{
		UpdateMusicStream(mainTheme);

		logicProgram();

		drawProgram();
	}
	unLoadResources();
	CloseWindow();
	CloseAudioDevice();
}

static void logicProgram()
{
	mousePosX = GetMouseX() - mouseCursor.width / 2;
	mousePosY = GetMouseY() - mouseCursor.height / 2;

	switch (gameStates)
	{
	case GameStates::InitialAnimation:
		statesInitialAnimation();
		break;
	case GameStates::Menu:
		statesMenu(gameStates);
		break;
	case GameStates::Game:
		GameLogic::playGame();
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
}

static void drawProgram()
{
	BeginDrawing();
	ClearBackground(BLACK);
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
		GameLogic::drawGame();
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
	DrawTexture(mouseCursor, mousePosX, mousePosY, WHITE);
	EndDrawing();
}

static void loadAudios()
{
	collisionSound = LoadSound("resources/collision.wav");
	bulletSound = LoadSound("resources/bullet2.wav");
	deathSound = LoadSound("resources/explosion.wav");
}

static void loadTextures()
{
	livesTexture = LoadTexture("resources/lives.png");
	splashScreen = LoadTexture("resources/splashScreen.png");
	wallpaper = LoadTexture("resources/pizzaWallpaper.png");
	shipTexture = LoadTexture("resources/pizzaTiledMap.png");
	bulletTexture = LoadTexture("resources/olive.png");
	asteroidSpecialTexture = LoadTexture("resources/specialAsteroidTiled.png");
	asteroidBigTexture = LoadTexture("resources/bigHand.png");
	asteroidMediumTexture = LoadTexture("resources/mediumHand.png");
	asteroidSmallTexture = LoadTexture("resources/smallHand.png");
	creditsTexture = LoadTexture("resources/credits.png");
	titleTexture = LoadTexture("resources/titleLogo.png");
	gameIcon = LoadImage("resources/titleLogo.png");
	mouseCursor = LoadTexture("resources/mousePointer.png");
	GenTextureMipmaps(&titleTexture);
	SetTextureFilter(titleTexture, TEXTURE_FILTER_ANISOTROPIC_16X);
	GenTextureMipmaps(&customFont.texture);
	SetTextureFilter(customFont.texture, TEXTURE_FILTER_ANISOTROPIC_16X);
	GenTextureMipmaps(&creditsTexture);
	SetTextureFilter(creditsTexture, TEXTURE_FILTER_ANISOTROPIC_16X);
}

static void loadResources()
{
	customFont = LoadFontEx("resources/LoftygoalsRegular-9Y5Xy.otf", 96, nullptr, 0);
	loadTextures();
	loadAudios();
}

static void unLoadAudio()
{
	UnloadSound(collisionSound);
	UnloadSound(deathSound);
	UnloadSound(bulletSound);
	UnloadMusicStream(mainTheme);
}

static void unLoadTextures()
{
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
	UnloadImage(gameIcon);
	UnloadTexture(mouseCursor);
}

static void unLoadResources()
{
	UnloadFont(customFont);
	unLoadAudio();
	unLoadTextures();

}