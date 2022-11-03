// Include the raylib library resource
#include "raylib.h"
//ENTRY POINT TO GET INTO cpp CODING
int main(){
// declaring the variables for the window size
 const int windowWidth{700};
 const int windowHeight{450};
 // Array to use more than one character
 char WindowName[] = "Birdy";
 //function to create a window with the above values
 int circle_posX = 250;
 int circle_posY = 250;
 int rectangle_posX = 700;
 int rectangle_posY = 100;
 


InitWindow(windowWidth,windowHeight,WindowName);

Texture2D sky = LoadTexture("resources/sky.png");

Rectangle skyRec;
skyRec.width = sky.width/6;
skyRec.height = sky.height;
skyRec.x = 0;
skyRec.y = 0; 
Vector2 skyPos;
skyPos.x = windowWidth/2 - skyRec.width/2;
skyPos.y = windowHeight - skyRec.height;

// Setting the frame per second rate of the game
SetTargetFPS(60);

// loop to keep window open until x button is pressed
	while (WindowShouldClose() == false){


		
BeginDrawing();

ClearBackground(SKYBLUE);


DrawCircle(circle_posX,circle_posY,50, RED);

if (IsKeyDown(KEY_W))
{
	circle_posY-=5;
}
if (IsKeyDown(KEY_S))
{
	circle_posY+=5;
}
if (IsKeyDown(KEY_A))
{
	circle_posX-=5;
}
if (IsKeyDown(KEY_D))
{
	circle_posX+=5;
}

DrawRectangle(rectangle_posX, rectangle_posY, 10, 5, LIGHTGRAY);
rectangle_posX -= 5;

DrawTexture(sky,skyRec,skyPos, WHITE);

EndDrawing();
}
}