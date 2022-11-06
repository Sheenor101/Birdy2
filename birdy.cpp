// Include the raylib library resource
#include "raylib.h"



//group
struct Anim
{ Rectangle rec;
  Vector2 pos;
  Vector3 collider;
  int frame;
  //used to slow down fram
  float updateTime;
  float runningTime;
  };

struct ball
{Rectangle ball;
Vector2 pos;
};


bool collision{};


//ENTRY POINT TO GET INTO cpp CODING
int main(){

// declaring the variables for the window size
 const int windowWidth{700};
 const int windowHeight{450};


 
 // Array to use more than one character
 char WindowName[] = "Birdy";

 
 //function to create a window with the above values


InitWindow(windowWidth,windowHeight,WindowName);



Texture2D sky = LoadTexture("resources/sky.png");
Texture2D birdy = LoadTexture ("resources/birdy.png");


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





int velocity{0};


int speed{400};

 Vector2 ballPos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    Vector2 ballSpeed = { 8.0f, 6.0f };
    float ballRad = 10;

//Rectangle ball;
//ball.x = GetScreenWidth() / 2;
//ball.y = GetScreenHeight() / 2;
//ball.height = 20;
//ball.width = 20; 


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
	//birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;
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

 // Bouncing ball logic
        ballPos.x += ballSpeed.x;
        ballPos.y += ballSpeed.y;
        if ((ballPos.x >= (GetScreenWidth() - ballRad)) || (ballPos.x <= ballRad)) ballSpeed.x *= -1.0f;
        if ((ballPos.y >= (GetScreenHeight() - ballRad)) || (ballPos.y <= ballRad)) ballSpeed.y *= -1.0f;





BeginDrawing();


birdyAnim.pos.y += velocity * deltaTime; 





ClearBackground(SKYBLUE);

DrawTextureRec(sky, skyRec,skyPos, WHITE); skyPos.x -= 1;
DrawTextureRec(birdy,birdyAnim.rec,birdyAnim.pos,WHITE);
DrawCircleV(ballPos, ballRad, DARKPURPLE);
    



EndDrawing();
}
UnloadTexture (birdy);
UnloadTexture (sky);
CloseWindow();
}
