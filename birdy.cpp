#include "raylib.h"

struct Anim
{
	Rectangle rec; 
	Vector2 pos;
	int frame; 
	float updateTime; 
	float runningTime;  
};

int main(){
 const int windowWidth{700};
 const int windowHeight{450};
InitWindow(windowWidth,windowHeight,"My Window");

//const int width{50};
//const int height{80};
const int gravity{1000};

Texture2D obstacle = LoadTexture("resources/Raylib_logo.png");
Texture2D birdy = LoadTexture("resources/birdy.png");
Anim birdyAnim;
birdyAnim.rec.width = birdy.width/6.5; 
birdyAnim.rec.height = birdy.height;
birdyAnim.rec.x = 0;
birdyAnim.rec.y = 0;
birdyAnim.pos.x = windowWidth/2 - birdyAnim.rec.width/2;
birdyAnim.pos.y = windowHeight - birdyAnim.rec.height;
birdyAnim.frame = 0;
birdyAnim.updateTime = 1.0/12.0;
birdyAnim.runningTime = 0.0;

Rectangle obRec;
obRec.width = obstacle.width;
obRec.height = obstacle.height; 
obRec.x = 0;
obRec.y = 0;
Vector2 obPos; 
obPos.x = windowWidth- obRec.width;
obPos.y = windowHeight - obRec.height;

int obVel{-100};

//int posY{windowHeight-height};
int velocity{0};
const int jumpHeight{500};
bool jumped{false};
int speed{200};
bool collision{};
SetTargetFPS(60);  
	while(!WindowShouldClose()){
	const float deltaTime{GetFrameTime()};
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



	if(IsKeyDown(KEY_D)&& !jumped)
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
if(IsKeyReleased(KEY_D)&& !jumped)
{birdyAnim.frame = 0;
birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;}

if(IsKeyDown(KEY_A)&& !jumped)
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
if(IsKeyReleased(KEY_A)&& !jumped)
{birdyAnim.frame = 0;
birdyAnim.rec.x = birdyAnim.frame* birdyAnim.rec.width;}
BeginDrawing();

//if (posY >= windowHeight - height){
if (birdyAnim.pos.y >= windowHeight - birdy.height){

	velocity=0;
	jumped = false; 
}
else 
{velocity += gravity * deltaTime;
jumped = true;
}
if(IsKeyPressed(KEY_SPACE) && !jumped)
{
	velocity -= jumpHeight;
}

//posY += velocity;
birdyAnim.pos.y += velocity * deltaTime; 
obPos.x += obVel * deltaTime; 
ClearBackground(WHITE); 
	if (collision){

	}
	else{
//DrawRectangle(windowWidth/2,posY,width,height,GREEN);
DrawTextureRec(birdy,birdyAnim.rec,birdyAnim.pos,WHITE);
DrawTextureRec(obstacle,obRec,obPos,WHITE);
	}
EndDrawing();
}
UnloadTexture(birdy);
UnloadTexture(obstacle);
CloseWindow();
}