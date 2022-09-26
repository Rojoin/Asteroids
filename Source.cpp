
#include "src/gameScreens/statesManager.h"
//
//int main()
//{
//	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
//	InitWindow(1920, 1000, "Ship Example");
//	InitAudioDevice();
//	SetWindowMinSize(1024, 768);
//	Font customFont = LoadFontEx("resources/LoftygoalsRegular-9Y5Xy.otf", 96, 0, 0);
//	 Texture2D wallpaper;
//	extern Texture2D shipTexture;
//	extern Texture2D bulletTexture;
//	extern Texture2D asteroidTexture;
//	extern Texture2D asteroidMediumTexture;
//	extern Sound deathSound	;
//	extern Sound collisionSound;
//	collisionSound =LoadSound("resources/collision.wav");
//	extern Sound bulletSound;
//	Music mainTheme = LoadMusicStream("resources/theLastSlice.mp3");
//	float timePlayed = 0.0f;
//
//
//	bulletSound	 =LoadSound("resources/bullet2.wav");
//	deathSound = LoadSound("resources/explosion.wav");
//	   
//	wallpaper = LoadTexture("resources/pizzaWallpaper.png");
//    shipTexture = LoadTexture("resources/pizzaTiledMap.png");
//    bulletTexture = LoadTexture("resources/olive.png");
//    asteroidTexture = LoadTexture("resources/bigHand.png");
//    asteroidMediumTexture = LoadTexture("resources/mediumHand.png");
//
//	extern SpaceShip spaceShip;
//	
//	initGame();
//
//	GenTextureMipmaps(&customFont.texture);
//	SetTextureFilter(customFont.texture, TEXTURE_FILTER_ANISOTROPIC_16X);
//	SetMusicVolume(mainTheme, 0.5);
//	PlayMusicStream(mainTheme);
//	while (!WindowShouldClose())
//	{
//		UpdateMusicStream(mainTheme);
//		timePlayed = GetMusicTimePlayed(mainTheme) / GetMusicTimeLength(mainTheme);
//		if (timePlayed > 1.0f)timePlayed = 1.0f;
//	
//		playGame();
//		BeginDrawing();
//		DrawTexture(wallpaper, 0, 0, WHITE);
//		drawGame();
//		drawText(TextFormat("SCORE: %1i", spaceShip.score), 0, 0, 50, BLACK, customFont);
//		ClearBackground(BLACK);
//		EndDrawing();
//
//	}
//	CloseWindow();
//	CloseAudioDevice();
//	return 0;
//}
int main ()
{
	initProgram();
}
