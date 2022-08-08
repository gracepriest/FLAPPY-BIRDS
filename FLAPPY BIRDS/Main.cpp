//MAIN.CPP IS USED FOR TESTING
#include <raylib.h>
#include "Common.h"
#include "Bird.h"
#include "Console.h"

using namespace std;


Bird* bird;
int main(void)
{
    
    // Initialization
   //--------------------------------------------------------------------------------------
    const int screenWidth = 1100;
    const int screenHeight = 750;
    

    InitWindow(screenWidth, screenHeight, "Melty Bird");
    HandleConsole console;
    console.HideConsole();
    
    //can load image in the cpp source file

    Texture2D backGround = LoadTexture("Images/background.png");
    Texture2D ground = LoadTexture("Images/ground.png");
    Texture2D img = LoadTexture("Images/bird.png");
   
    bird = new Bird;

    float backGroundScroll = 0;
    float groundScroll = 0;

     const double BACKGROUND_SCROLL_SPEED = 30;
     const double GROUND_SCROLL_SPEED = 60;
    
     const float BACKGROUND_LOOPING_POINT = 37;

     float  DetlaTime = 0;
     string backgScroll = "";
     
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        DetlaTime = GetFrameTime();
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
       // Update(DetlaTime);
        if (backGroundScroll > 1275)
            backGroundScroll = BACKGROUND_LOOPING_POINT;
        backGroundScroll += BACKGROUND_SCROLL_SPEED * DetlaTime;
        
        //backGroundScroll = backGroundScroll + fmod((BACKGROUND_SCROLL_SPEED * DetlaTime),BACKGROUND_LOOPING_POINT);
        //groundScroll = groundScroll + fmod((GROUND_SCROLL_SPEED * DetlaTime), BACKGROUND_LOOPING_POINT);
        groundScroll += GROUND_SCROLL_SPEED * DetlaTime;
        if (groundScroll > 1090)
            groundScroll = 0;
        BeginDrawing();

        ClearBackground(RAYWHITE);
        //ex is used for scaling
        DrawTextureEx(backGround, {-backGroundScroll , 0 }, 0.0f, 3, WHITE);
        DrawTextureEx(ground, { -groundScroll, screenHeight -30 },0.0f ,2, WHITE);

        backgScroll = to_string(backGroundScroll);
        DrawText(backgScroll.c_str(), 0, 0, 50, WHITE);
        bird->Update(DetlaTime);
        bird->Render();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(backGround);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


    
    return 0;
}
