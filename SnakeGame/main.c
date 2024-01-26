#include "snake.h"

// initialize snake struct
void setup(struct snake *snake) 
{
    snake->gameOver = 0;
    snake->x = WIDTH / 2;
    snake->y = HEIGHT / 2;
    snake->fruitX = rand() % WIDTH;
    snake->fruitY = rand() % HEIGHT;
	snake->bombX = -1;
    snake->bombY = -1;
    snake->bombExists = 0;
    snake->score = 0;
	snake->nTail = 0;
    dir = STOP;
}

int main() 
{
	struct snake snake;

    StartMenu();
    setup(&snake);
    while (!snake.gameOver)
	{
        Draw(&snake);
        Input(&snake);
        Logic(&snake);
        Sleep(90); // Adjust snake speed
    }
    EndGame(&snake);
    NewHighScore(&snake);
    SaveHighScore(snake.score);
    system("pause");
    return 0;
}