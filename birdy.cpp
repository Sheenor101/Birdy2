// Include the raylib library resource
#include "raylib.h"



struct Anim
{ Rectangle rec;
  Vector2 pos;
  int frame;
  float updateTime;
  float runningTime;
  };


struct can
{ Rectangle rec;
  Vector2 speed;
  bool active;
  Color color;
  };


//ENTRY POINT TO GET INTO cpp CODING
int main(){
// declaring the variables for the window size
 const int windowWidth{700};
 const int windowHeight{450};


 
 // Array to use more than one character
 char WindowName[] = "Birdy";

 
 //function to create a window with the above values

 int rectangle_posX = 700;
 int rectangle_posY = 100;
 

InitWindow(windowWidth,windowHeight,WindowName);
int canVel{-100};


Texture2D sky = LoadTexture("resources/sky.png");
Texture2D birdy = LoadTexture ("resources/birdy.png");
Texture2D can = LoadTexture("resources/can.png");

Rectangle skyRec;
skyRec.width = sky.width*10;
skyRec.height = sky.height;
skyRec.x = 0;
skyRec.y = 0;
Vector2 skyPos;
skyPos.x = windowWidth/2 - skyRec.width/2;
skyPos.y = windowHeight - skyRec.height;

Anim birdyAnim;
birdyAnim.rec.width = birdy.width/6;
birdyAnim.rec.height = birdy.height;
birdyAnim.rec.x = 0;
birdyAnim.rec.y = 0;
birdyAnim.pos.x = windowWidth/2 - birdyAnim.rec.width/2;
birdyAnim.pos.y = windowHeight - birdyAnim.rec.height;
birdyAnim.frame = 0;
birdyAnim.updateTime = 1.0/12.0;
birdyAnim.runningTime = 0.0;


Rectangle canRec;
canRec.width = can.width;
canRec.height = can.height;
canRec.x = 0;
canRec.y = 0;
Vector2 canPos;
canPos.x = windowWidth- can.width;
canPos.y = windowHeight - can.height;


int velocity{0};


int speed{200};


// Setting the frame per second rate of the game
SetTargetFPS(60);

// loop to keep window open until x button is pressed
while (WindowShouldClose() == false){
		const float deltaTime{GetFrameTime()};



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
	{birdyAnim.frame = 1;
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
{birdyAnim.frame = 2;
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
{birdyAnim.frame = 3;
birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;}

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
{birdyAnim.frame = 4;
birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;}


BeginDrawing();



birdyAnim.pos.y += velocity * deltaTime; 
canPos.x += canVel * deltaTime;




ClearBackground(SKYBLUE);

DrawTextureRec(sky, skyRec,skyPos, WHITE); skyPos.x -= 1;
DrawTextureRec(birdy,birdyAnim.rec,birdyAnim.pos,WHITE);
DrawTextureRec(can,canRec,canPos,WHITE);
DrawRectangle(rectangle_posX, rectangle_posY, 10, 5, BLACK);
rectangle_posX -= 4;



EndDrawing();
}
UnloadTexture (birdy);
UnloadTexture (sky);
UnloadTexture (can);
CloseWindow();
}
