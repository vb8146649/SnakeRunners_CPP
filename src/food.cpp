#include "food.h"

Texture2D Food::image;

Food::Food()
{
    if(image.id==0){
        image=LoadTexture("src/food.png");
    }
}

// Food::~Food(){
//     UnloadTexture(image);
// }

void Food::Draw()
{
    DrawTextureV(image,position,WHITE);
}

void Food::Spawn(vector<Vector2> grid)
{
    position=grid[GetRandomValue(0,grid.size()-1)];
}

