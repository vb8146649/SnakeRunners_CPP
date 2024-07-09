#pragma once
#include <raylib.h>
#include <vector>
using namespace std;
class Food{
    public:
        Food();
        // ~Food();
        Vector2 position;
        void Draw();
        void Spawn(vector<Vector2> grid);
    private:
        static Texture2D image;
};