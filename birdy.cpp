// include the raylib library
#include "raylib.h"

// defining the struct/group
struct Anim
{
	Rectangle rec; 
	Vector2 pos;
	int frame; 
	float updateTime; 
	float runningTime;  
};

//main entry point
int main(){
//specifying the variables value - const int - it cannot be modified by programmer later on
 const int windowWidth{700};
 const int windowHeight{450};
 //initialise the game window along with height, width and name
InitWindow(windowWidth,windowHeight,"Birdy");
//Inialise music
InitAudioDevice();


// load the different textures that will be used in the game
Texture2D obstacle = LoadTexture("resources/Drone.png");
Texture2D birdy = LoadTexture("resources/birdy.png");
Texture2D sky = LoadTexture("resources/sky.png");

//Defining the bird ainimation
Anim birdyAnim;
//
birdyAnim.rec.width = birdy.width/6; 
birdyAnim.rec.height = birdy.height;
birdyAnim.rec.x = 0;
birdyAnim.rec.y = 0;
//starting position of bird - x axis
birdyAnim.pos.x = windowWidth/6 - birdyAnim.rec.width/6;
//starting position of bird - y axis
birdyAnim.pos.y = windowHeight/2 - birdyAnim.rec.height/2;
birdyAnim.frame = 0;
birdyAnim.updateTime = 1.0/12.0;
birdyAnim.runningTime = 0.0;

Rectangle obRec;
obRec.width = obstacle.width;
obRec.height = obstacle.height; 
obRec.x = 0;
obRec.y = 0;

Vector2 obPos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }; 
Vector2 obSpeed = { 7.0f, 5.0f };
//obPos.x = windowWidth- obRec.width;
//obPos.y = windowHeight - obRec.height;

//defining the rectangle for the background sky
Rectangle skyRec;
//defining the width and height of the rectangle that the background will be in
skyRec.width = sky.width*10;
skyRec.height = sky.height;
//the starting position on x and y axis of the background rectangle
skyRec.x = 0;
skyRec.y = 0;
Vector2 skyPos;
skyPos.x = windowWidth/2 - skyRec.width/2;
skyPos.y = windowHeight - skyRec.height;


//int posY{windowHeight-height};
int obVel{0};
int speed {400};
int velocity{0};
bool collision{};
// Vector2 obPos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }; 
// Vector2 obSpeed = { 5.0f, 4.0f };

Music music = LoadMusicStream("resources/Music.wav");
PlayMusicStream(music);

SetTargetFPS(60); 

	while(!WindowShouldClose()){
	const float deltaTime{GetFrameTime()};

UpdateMusicStream(music);

	Rectangle obstacleRec{
		obPos.x,
		obPos.y,
		obRec.height,
		obRec.width,
	
	};
	Rectangle birdyRec{
	birdyAnim.pos.x,
	birdyAnim.pos.y,
	birdyAnim.rec.height,
	birdyAnim.rec.width	
	};
	if(CheckCollisionRecs(birdyRec,obstacleRec)){
		collision = true;
	}



	if(IsKeyDown(KEY_D))
{
	birdyAnim.pos.x += speed*deltaTime;
	birdyAnim.rec.width = birdy.width/6;

	birdyAnim.runningTime += deltaTime; 
	if(birdyAnim.runningTime >= birdyAnim.updateTime)
	{
	birdyAnim.runningTime = 0.0;
	birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;
	birdyAnim.frame++;
	if (birdyAnim.frame>5){
	birdyAnim.frame = 0;
	}

	}
}
if(IsKeyReleased(KEY_D))
{birdyAnim.frame = 2;
birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;}


if(IsKeyDown(KEY_A))
{
	birdyAnim.pos.x -= speed*deltaTime;
	birdyAnim.rec.width = -birdy.width/6;

	birdyAnim.runningTime += deltaTime; 
	if(birdyAnim.runningTime >= birdyAnim.updateTime)
	{
	birdyAnim.runningTime = 0.0;
	birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;
	birdyAnim.frame++;
	if (birdyAnim.frame>5){
	birdyAnim.frame = 0;
	}

	}
}
if(IsKeyReleased(KEY_A))
{birdyAnim.frame = 3;
birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;}


if(IsKeyDown(KEY_W))
{
	birdyAnim.pos.y -= speed*deltaTime;
	birdyAnim.rec.width = -birdy.width/6;

	birdyAnim.runningTime += deltaTime; 
	if(birdyAnim.runningTime >= birdyAnim.updateTime)
	{
	birdyAnim.runningTime = 0.0;
	birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;
	birdyAnim.frame++;
	if (birdyAnim.frame>5){
	birdyAnim.frame = 0;
	}

	}
}
if(IsKeyReleased(KEY_W))
{birdyAnim.frame = 4;
birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;}

// Bouncing ob logic
        obPos.x += obSpeed.x;
        obPos.y += obSpeed.y;
        if ((obPos.x >= (GetScreenWidth() - obRec.width)) || (obPos.x <= obRec.width)) obSpeed.x *= -1.0f;
        if ((obPos.y >= (GetScreenHeight() - obRec.height)) || (obPos.y <= obRec.height)) obSpeed.y *= -1.0f;


if(IsKeyDown(KEY_S))
{
	birdyAnim.pos.y += speed*deltaTime;
	birdyAnim.rec.width = -birdy.width/6;

	birdyAnim.runningTime += deltaTime; 
	if(birdyAnim.runningTime >= birdyAnim.updateTime)
	{
	birdyAnim.runningTime = 0.0;
	birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;
	birdyAnim.frame++;
	if (birdyAnim.frame>5){
	birdyAnim.frame = 0;
	}

	}
}
if(IsKeyReleased(KEY_S))
{birdyAnim.frame = 5;
birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;}


BeginDrawing();

//if (posY >= windowHeight - height){



//posY += velocity;
birdyAnim.pos.y += velocity * deltaTime; 
obPos.x += obVel * deltaTime; 
ClearBackground(WHITE); 
	if (collision){DrawText("Birdy Died!!",290,200,30,BLACK);
	// animate dead birdy dropping until off screen
		if(birdyAnim.pos.y <= (GetScreenHeight())){
// draw dead birdy 
DrawTextureRec(birdy,birdyAnim.rec,birdyAnim.pos,RED);
// draw obstacle
DrawTextureRec(obstacle,obRec,obPos,WHITE);
//birdy drops down 1 
birdyAnim.pos.y += 1;}
	}
	else{


//draw each image/texture to the screeen. the background goes first
DrawTextureRec(sky, skyRec,skyPos, WHITE); skyPos.x -= 1;
DrawTextureRec(birdy,birdyAnim.rec,birdyAnim.pos,WHITE);
DrawTextureRec(obstacle,obRec,obPos,WHITE);

// debug collision rectangles
DrawRectangleLines(obPos.x, obPos.y, obRec.width, obRec.height, BLACK);
DrawRectangleLines(birdyAnim.pos.x, birdyAnim.pos.y, birdyRec.width, birdyRec.height, BLACK);

DrawText("Save Birdy from the Drone!",10,10,12,DARKGRAY);
	}
EndDrawing();
}
UnloadTexture(birdy);
UnloadTexture(obstacle);
UnloadTexture(sky);
CloseWindow();
}