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


InitWindow(windowWidth,windowHeight,WindowName);
// loop to keep window open until x button is pressed
	while (WindowShouldClose() == false){

// Setting the frame per second rate of the game
SetTargetFPS(60);
		
BeginDrawing();
ClearBackground(SKYBLUE);


DrawCircle(circle_posX,circle_posY,50, RED);

if (IsKeyDown(KEY_W))
{
	circle_posY = circle_posY-5;
}
if (IsKeyDown(KEY_S))
{
	circle_posY = circle_posY+5;
}
if (IsKeyDown(KEY_A))
{
	circle_posX = circle_posX-5;
}
if (IsKeyDown(KEY_D))
{
	circle_posX = circle_posX+5;
}

EndDrawing();
}
}