#include "snake.h"

Snake::Snake()
{
    cellSize = 30;
    size = 1;
    head = {((float)GetScreenWidth() -100) / 2+50, ((float)GetScreenHeight() - 100) / 2+50};
    body.push_back(head);
    GridInitialization();
}

void Snake::Draw()
{
    int i = 0;
    for (auto it = body.begin(); it != body.end() && i < size; it++)
    {
        DrawRectangleRounded({it->x, it->y, cellSize, cellSize}, 0.3, 6, WHITE);
        i++;
    }
}

void Snake::Update(Vector2 heading)
{
    body.push_front({body[0].x + heading.x * cellSize, body[0].y + heading.y * cellSize});
    GridInitialization();
}

void Snake::Ate()
{
    size++;
    if (size > 400)
    {
        size--;
        body.pop_back();
    }
}

void Snake::MappedSnake()
{
    int i=0;
    for(auto &it:M){
        it.second=0;
    }
    for (auto it = body.begin(); it != body.end() && i < size; it++)
    {
        M[{it->x,it->y}] +=1;
        i++;
    }
}

void Snake::GridInitialization()
{
    grid.clear();
    for(float i=0;i<20;i++){
        for(float j=0;j<20;j++){
            Vector2 z={i*30+50,j*30+50};
            if(M.count({z.x,z.y})==0 || M[{z.x,z.y}]==0 ){
                grid.push_back({z.x+1,z.y+1});
            }
        }
    }
}
