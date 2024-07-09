#pragma once
#include <raylib.h>
#include <deque>
#include<vector>
#include<map>
using namespace std;
class Snake{
    public:
        Snake();
        void Draw();
        void Update(Vector2 heading);
        void Ate();
        void MappedSnake();
        void GridInitialization();
        deque<Vector2> body;
        vector<Vector2> grid;
        map<pair<float,float>,int> M;
    private:
        Vector2 head;
        int size;
        float cellSize;
};