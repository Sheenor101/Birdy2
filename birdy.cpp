// Include the raylib library resource
#include "raylib.h"
//ENTRY POINT TO GET INTO cpp CODING
int main(){
// declaring the variables for the window size
 const int windowWidth{700};
 const int windowHeight{450};
 // Array to use more than one character
 char WindowName[] = "birdvert";
 //function to create a window with the above values

 int rectangle_posX = 700;
 int rectangle_posY = 100;
 


InitWindow(windowWidth,windowHeight,WindowName);


Texture2D sky = LoadTexture("resources/sky.png");

Texture2D birdvert = LoadTexture ("resources/birdvert.png");

Rectangle skyRec;
skyRec.width = sky.width*10;
skyRec.height = sky.height;
skyRec.x = 0;
skyRec.y = 0;
Vector2 skyPos;
skyPos.x = windowWidth/2 - skyRec.width/2;
skyPos.y = windowHeight - skyRec.height;

Rectangle birdvertRec;
birdvertRec.width = birdvert.width;
birdvertRec.height = birdvert.height/6;
birdvertRec.x = 0;
birdvertRec.y = 0;
Vector2 birdvertPos;
birdvertPos.x = windowWidth/2 - birdvertRec.width;
birdvertPos.y = windowHeight/2 - birdvertRec.height/6;


// Setting the frame per second rate of the game
SetTargetFPS(60);

// loop to keep window open until x button is pressed
while (WindowShouldClose() == false){


		
BeginDrawing();

ClearBackground(SKYBLUE);

DrawTextureRec(sky, skyRec,skyPos, WHITE);
skyPos.x -= 1;


DrawTextureRec(birdvert,birdvertRec,birdvertPos,WHITE);





DrawRectangle(rectangle_posX, rectangle_posY, 10, 5, LIGHTGRAY);
rectangle_posX -= 5;



EndDrawing();
}
// Unload Textures to save memory
UnloadTexture(sky);
UnloadTexture(birdvert);
CloseWindow();
}