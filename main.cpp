#include <iostream>
#include "game.cpp"

// 実行方法
// g++ -o main main.cpp card.cpp

using namespace std;

int main()
{
    // ゲームの開始
    Game game;
    game.startGame();

    return 0;
}