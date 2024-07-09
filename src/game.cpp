#include "game.h"
Game::Game()
{
    GameReset();
    InitAudioDevice();
    music=LoadMusicStream("src/music.ogg");
    eat=LoadSound("src/eat.mp3");
    wall=LoadSound("src/wall.mp3");
    PlayMusicStream(music);
}

Game::~Game()
{
    UnloadMusicStream(music);
    UnloadSound(wall);
    UnloadSound(eat);
    CloseAudioDevice();
}

void Game::Draw()
{
    snake.Draw();
    for (auto &it : foods)
    {
        it.Draw();
    }

}

void Game::HandleInputs()
{
    if (gameOver == false)
    {

        if (IsKeyPressed(KEY_UP))
        {
            direction = {0, -1};
        }
        else if (IsKeyPressed(KEY_DOWN))
        {
            direction = {0, 1};
        }
        else if (IsKeyPressed(KEY_LEFT))
        {
            direction = {-1, 0};
        }
        else if (IsKeyPressed(KEY_RIGHT))
        {
            direction = {1, 0};
        }
    }else{
        int key=GetKeyPressed();
        if(key!=0){
            GameReset();
        }
    }
}

void Game::Collisions()
{
    snake.MappedSnake();
    for (auto &i : snake.M)
    {
        if (i.second > 1)
        {
            GameOver();
        }
    }
    if(snake.body[0].x> 649 || snake.body[0].x<50 ||snake.body[0].y>649 || snake.body[0].y<50){
        GameOver();
    }
    for (auto f = foods.begin(); f != foods.end();)
    {
        if (CheckCollisionRecs({f->position.x - 1, f->position.y - 1, 30, 30}, {snake.body[0].x, snake.body[0].y, 30, 30}))
        {
            foods.erase(f);
            score++;
            PlaySound(eat);
            snake.Ate();
        }
        else
        {
            f++;
        }
    }
}

void Game::GameOver()
{
    PlaySound(wall);
    gameOver = true;
}

void Game::GameReset()
{
    direction = {0, -1};
    lastTimeSnake = 0.0;
    lastTimeFood = 0.0;
    gameOver = false;
    score = 0;
    foods.clear();
    snake.body.clear();
    snake.M.clear();
    snake=Snake();
}

void Game::DrawScore(Font font)
{
    DrawTextEx(font,"Score",{400,10},38,2,BLACK);
    char scoreText[10];
    sprintf(scoreText,"%d",score);
    DrawTextEx(font,scoreText,{550,10},38,2,BLACK);
    if(gameOver==true){
        DrawTextEx(font,"GAME OVER",{150,300},64,2,BLACK);
    }
}

void Game::Update()
{
    if (gameOver == false)
    {

        if (GetTime() - lastTimeSnake >= 0.2)
        {
            snake.Update(direction);
            lastTimeSnake = GetTime();
        }
        grid = snake.grid;
        for (auto pos = grid.begin(); pos != grid.end(); pos++)
        {
            for (auto it = foods.begin(); it != foods.end();)
            {
                if (it->position.x == pos->x && it->position.y == pos->y)
                {
                    grid.erase(pos);
                }else{
                    it++;
                }
            }
        }

        if (GetTime() - lastTimeFood >= 2 && foods.size()+snake.M.size()<400)
        {
            food.Spawn(grid);
            foods.push_back(food);
            lastTimeFood = GetTime();
        }
    }
}
