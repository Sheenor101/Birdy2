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
InitWindow(windowWidth,windowHeight,"Birdy");
InitAudioDevice();
//const int width{50};
//const int height{80};


Texture2D obstacle = LoadTexture("resources/Drone.png");
Texture2D birdy = LoadTexture("resources/birdy.png");
Texture2D sky = LoadTexture("resources/sky.png");

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

Rectangle obRec;
obRec.width = obstacle.width;
obRec.height = obstacle.height; 
obRec.x = 0;
obRec.y = 0;
Vector2 obPos; 
obPos.x = windowWidth- obRec.width;
obPos.y = windowHeight - obRec.height;

Rectangle skyRec;
skyRec.width = sky.width*10;
skyRec.height = sky.height;
skyRec.x = 0;
skyRec.y = 0;
Vector2 skyPos;
skyPos.x = windowWidth/2 - skyRec.width/2;
skyPos.y = windowHeight - skyRec.height;




//int posY{windowHeight-height};
int obVel{0};
int velocity{0};


int speed{400};
bool collision{};

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
	if (collision){

	}
	else{
//DrawRectangle(windowWidth/2,posY,width,height,GREEN);
DrawTextureRec(birdy,birdyAnim.rec,birdyAnim.pos,WHITE);
DrawTextureRec(obstacle,obRec,obPos,WHITE);
DrawTextureRec(sky, skyRec,skyPos, WHITE); skyPos.x -= 1;
	}
EndDrawing();
}
UnloadTexture(birdy);
UnloadTexture(obstacle);
CloseWindow();
}