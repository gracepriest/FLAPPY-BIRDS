
#include "Game.h"
#include "Bird.h"
#include "Pipe.h"





//Author Melvin Kemp
//Program Melty mybird

//----------------------------------------------------------------------------------------------------------------------------------------
//Includes






//----------------------------------------------------------------------------------------------------------------------------------------
//GLOBAL GAME OBJECTS OR Pointers

//mybird * mybird = new mybird();




//----------------------------------------------------------------------------------------------------------------------------------------
//Init/Load Game setting
//create window return greater than 0 if error
Bird mybird;
vector<Pipe> pipes;


float spawnTimer =0;
float Timer = 0;
int loopCount = 3;

int pipeCount =0;

bool IsRunning = true;
float backGroundScroll = 0;
float groundScroll = 0;

const double BACKGROUND_SCROLL_SPEED = 30;
const double GROUND_SCROLL_SPEED = 60;

const float BACKGROUND_LOOPING_POINT = 37;

float  DeltaTime = 0;
string backgScroll = "";
Texture2D backGround;
Texture2D ground;
Font font;
Music gameMusic;

float timePlayed = 0.0f;        // Time played normalized [0.0f..1.0f]
bool pause = false;             // Music playing paused
int score = 0;
int scorePass = 0;

string str_score;

int Game::load()
{
	
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Melty mybird");
	InitAudioDevice();              // Initialize audio device

	srand(time(NULL));
	
	//can load image in the cpp source file
	//font = LoadFontEx("Images/font.ttf", 32, 0, 250);
	 gameMusic = LoadMusicStream("Music/marios_way.mp3");
	 font = LoadFont("font/font.ttf");
	 backGround = LoadTexture("Images/background.png");
	 ground = LoadTexture("Images/ground.png");
	 Pipe::PIPE_IMAGE = LoadTexture("Images/pipe.png");
	 Bird::imgBird = LoadTexture("Images/bird.png");
	 
	 

	
	

	//PlayMusicStream(gameMusic);
	
	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	mybird.Init();
	
	return 0;
}


//----------------------------------------------------------------------------------------------------------------------------------------
//Init Sound

//----------------------------------------------------------------------------------------------------------------------------------------
//Check if KeyPress
bool Game::IsKeyPress()
{
	if ((GetKeyPressed()))
	{
		
		if (IsKeyDown(KEY_ESCAPE))
		{
			//clean up code
		}


		return true;
	}
	return false;
}

//----------------------------------------------------------------------------------------------------------------------------------------
//Used to update all objects
//holds the game loop
void Game::Update()
{

	
	
	
	
	
	 // Main game loop
	while (IsRunning)    // Detect window close button or ESC key windowshouldclose will be replaced by iskeypress
	{
		
		//UpdateMusicStream(gameMusic);
		if (WindowShouldClose())
		{
			pushState(GAMESTATE::OVER);
			mybird.pushState(GAMESTATE::OVER);
			
		}
		
		
		updateState();
		DeltaTime = GetFrameTime();
	   // Update(DetlaTime);
		if (getCurrentState() == GAMESTATE::PLAY or getCurrentState() == GAMESTATE::NEWGAME)
		{
			DrawText(to_string(score).c_str(), 0, 0, 50, WHITE);
			backGroundScroll += BACKGROUND_SCROLL_SPEED * DeltaTime;
			if (backGroundScroll > 1275)
			{
				backGroundScroll = BACKGROUND_LOOPING_POINT;
			}
			
			groundScroll += GROUND_SCROLL_SPEED * DeltaTime;
			if (groundScroll > 1090)
			{
				groundScroll = 0;
			}
			if(getCurrentState() == GAMESTATE::PLAY)
			{
				spawnTimer += DeltaTime;
				if (spawnTimer > 2)
				{
					pipes.push_back(Pipe(true));
					
					pipes.push_back(Pipe(false));
					pipes.back().scored = true;
					
					spawnTimer = 0;
				}
			
				for (Pipe& pipe : pipes)
				{
					pipe.Update(DeltaTime);
					if (!pipe.scored)
					{
						
						if ((pipe.recMask.x + pipe.recMask.width-35) < mybird.recMask.x)
						{
							score++;
							pipe.scored = true;
						}

					}
					
					if (pipe.x < -pipe.width)
					{
						pipes.erase(pipes.begin());
					}
					if (mybird.Collides(pipe))
					{

						mybird.pushState(GAMESTATE::OVER);
						pushState(GAMESTATE::OVER);

					}
			    }
				
			}

			if (mybird.y > 680)
			{
				mybird.pushState(GAMESTATE::OVER);
				pushState(GAMESTATE::OVER);
			}

			
        }
		
		

		mybird.Update(DeltaTime);
		/*
		auto it = std::find_if(pipes.begin(), pipes.end(), [](auto& pipe) { return pipe.x < -pipe.width; });

		if(it != pipes.end())
			pipes.erase(it);*/
		
			
		Draw(DeltaTime);
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------
//Used to update the statemachine
 void Game::updateState()
{
	if (IsKeyPressed(KEY_ENTER) && getCurrentState() == GAMESTATE::PLAY)
	{
		popState();
		pushState(GAMESTATE::PAUSE);
		mybird.pushState(GAMESTATE::PAUSE);
		
	}
	else if (IsKeyPressed(KEY_ENTER) && getCurrentState() == GAMESTATE::PAUSE)
	{
		popState();
		pushState(GAMESTATE::PLAY);
		mybird.pushState(GAMESTATE::PLAY);
	}
	else if (IsKeyPressed(KEY_F1) )
	{
		popState();
		pushState(GAMESTATE::OVER);
		mybird.pushState(GAMESTATE::OVER);
	}
	else if (IsKeyPressed(KEY_ENTER) && getCurrentState() == GAMESTATE::NEWGAME)
	{
		popState();
		pushState(GAMESTATE::COUNTSCREEN);
		mybird.pushState(GAMESTATE::COUNTSCREEN);
	}
	
}

//----------------------------------------------------------------------------------------------------------------------------------------
//Used to draw all objects to screen

void Game::Draw(float dt)
{
	//mybird->Render();
	BeginDrawing();

	ClearBackground(RAYWHITE);
	//ex is used for scaling
	DrawTextureEx(backGround, { -backGroundScroll , 0 }, 0.0f, 3, WHITE);
	if (getCurrentState() == GAMESTATE::PLAY or getCurrentState() ==  GAMESTATE::PAUSE)
	{
	

		//render pipe
		for (Pipe& pipe : pipes)
		{
			pipe.Render();

		}
		mybird.Render();
	}
	
	DrawTextureEx(ground, { -groundScroll, SCREENHEIGHT - 30 }, 0.0f, 2, WHITE);

	backgScroll = to_string(backGroundScroll);
	//used for debugging
	//DrawText(backgScroll.c_str(), 0, 0, 50, WHITE);

	if (getCurrentState() == GAMESTATE::PAUSE)
	{
		DrawText("PAUSE", 300, 0, 150, WHITE);
	}
	
	
	if (getCurrentState() == GAMESTATE::OVER)
	{
		GameOverMenu();
	}
	if (getCurrentState() == GAMESTATE::NEWGAME)
	{
		NewMenu();
	}

	if (getCurrentState() == GAMESTATE::COUNTSCREEN)
	{

		CountScreen(DeltaTime);
		
	}
	if (getCurrentState() == GAMESTATE::PLAY)
	{
		DrawText("SCORE: ", 0, 0, 55, WHITE);
		DrawText(to_string(score).c_str(),200,0,55,WHITE);
	}
	EndDrawing();
}

//----------------------------------------------------------------------------------------------------------------------------------------

Game::Game()
{

}
//----------------------------------------------------------------------------------------------------------------------------------------
//~dest
Game::~Game()
{
	UnloadTexture(backGround);
	UnloadTexture(ground);
	UnloadMusicStream(gameMusic);   // Unload music stream buffers from RAM

	CloseAudioDevice();
	//delete mybird;
	CloseWindow();        // Close window and OpenGL context
}

void Game::Start()
{
	if (load() == 0) 
	{
		pushState(GAMESTATE::NEWGAME);
		mybird.pushState(GAMESTATE::NEWGAME);

	}
	Update();
}

void Game::GameOverMenu()
{
	static const char* text = { "Would You Like To Play Again" };
	static const char* yesNo[] = { "Yes","No" };
	Rectangle gameOverRec( SCREENWIDTH / 8, SCREENHEIGHT / 8, 800.0f, 500.0f);
	Rectangle Button[2] = { 0 };
	int mouseHoverRec = -1;


	for (int i = 0; i < 2; i++)
	{
		Button[i].x = 400 + 128 * i;
		Button[i].y	= (SCREENHEIGHT/2);
		Button[i].width = 100.0f;
		Button[i].height = 30.0f;
	}

	for (int i = 0; i < 2; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), Button[i]))
		{
			mouseHoverRec = i;

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && mouseHoverRec == 0)
			{
				pushState(GAMESTATE::NEWGAME);
				Reset();
				mybird.Reset();

			}
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && mouseHoverRec == 1)
			{
				//pushState(GAMESTATE::PLAY);
				IsRunning = false;
			
				return;
			}
			break;
		}
		else mouseHoverRec = -1;
	}

	DrawRectangleRec(gameOverRec, WHITE);
	DrawText(text, SCREENWIDTH / 8+30, SCREENHEIGHT / 8+150, 50, RED);
	for (int i = 0; i < 2; i++)
	{
		DrawRectangleRec(Button[i], ((i == -1) || (i == mouseHoverRec)) ? DARKBLUE : SKYBLUE);
		DrawText(yesNo[i], Button[i].x,(int)Button[i].y, MeasureText(yesNo[i], 10 / 2),   RED);
	}
}


void Game::Reset()
{
	backGroundScroll = 0;
	groundScroll = 0;
	spawnTimer = 0;
	score = 0;

	pipes.clear();
}

void Game::NewMenu()
{
	DrawTextEx(font, "Melty Bird", Vector2{ 400, SCREENHEIGHT / 2 -100 }, 105,0, WHITE);
	DrawText("Press Enter", 435, SCREENHEIGHT / 2 , 50, WHITE);
}

void Game::CountScreen(float dt)
{
	
	DrawText(to_string(loopCount).c_str(), SCREENWIDTH / 2 - 10, SCREENHEIGHT / 2, 125, WHITE);


	Timer += dt;
	if (Timer > 1)
	{


		Timer = 0;
		loopCount--;

	}

	if (loopCount < 0)
	{
		pushState(GAMESTATE::PLAY);
		mybird.pushState(GAMESTATE::PLAY);
		loopCount = 3;
	}

}

