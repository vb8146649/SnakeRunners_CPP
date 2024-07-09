#pragma once
#include <raylib.h>
#include "snake.h"
#include "food.h"
#include <vector>
#include<iostream>
using namespace std;
class Game{
    public:
        Game();
        ~Game();
        int speed;
        void Draw();
        void Update();
        void HandleInputs();
        Snake snake;
        vector<Food> foods;
        Food food;
        void Collisions();
        void GameOver();
        vector<Vector2> grid;
        bool gameOver;
        int score;
        void GameReset();
        void DrawScore(Font font);
        Sound wall;
        Music music;
    private:
        Vector2 direction;
        float lastTimeSnake;
        float lastTimeFood;
        Sound eat;
};