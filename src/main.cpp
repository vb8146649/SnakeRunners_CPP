#include <raylib.h>
#include "game.h"

int main(){
    int windowHeight=700,windowWidth=700;
    Color backgroundColor={207, 207, 19, 170};
    InitWindow(windowWidth,windowHeight,"SnakeRunner");
    Font font=LoadFont("src/monogram.ttf");
    SetTargetFPS(60);
    Game game;
    while(WindowShouldClose()==false){
        UpdateMusicStream(game.music);
        game.HandleInputs();
        game.Collisions();
        BeginDrawing();
        ClearBackground(backgroundColor);
        DrawRectangleLines(50,50,600,600,BLACK);
        game.Draw();
        game.Update();
        game.DrawScore(font);
        EndDrawing();
    }
    CloseWindow();
}