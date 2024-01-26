#include "snake.h"

// draws the game window and the score
void Draw(struct snake *snake) 
{
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            if (i == snake->y && j == snake->x)
                printf("O");
            else if (i == snake->fruitY && j == snake->fruitX)
                printf("F");
			else if (i == snake->bombY && j == snake->bombX && snake->bombExists)
                printf("B");
            else {
                int printTail = 0;
                for (int k = 0; k < snake->nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        printTail = 1;
                    }
                }
                if (!printTail)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
    printf("Score: %d\n", snake->score);
}

// get input from user keyboard
void Input(struct snake *snake) 
{
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                if (dir != RIGHT) // Ignore input if snake is moving right
                    dir = LEFT;
                break;
            case 'd':
                if (dir != LEFT) // Ignore input if snake is moving left
                    dir = RIGHT;
                break;
            case 'w':
                if (dir != DOWN) // Ignore input if snake is moving down
                    dir = UP;
                break;
            case 's':
                if (dir != UP) // Ignore input if snake is moving up
                    dir = DOWN;
                break;
            case 'x':
                snake->gameOver = 1;
                break;
        }
    }
}

// updates the snake position and tail and checks for any collision
void Logic(struct snake *snake) 
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snake->x;
    tailY[0] = snake->y;
    for (int i = 1; i < snake->nTail; i++) 
	{
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) 
	{
    case LEFT:
        snake->x--;
        break;
    case RIGHT:
        snake->x++;
        break;
    case UP:
        snake->y--;
        break;
    case DOWN:
        snake->y++;
        break;
    }

    if (snake->x >= WIDTH)
        snake->x = 0;
    else if (snake->x < 0)
        snake->x = WIDTH - 1;

    if (snake->y >= HEIGHT)
        snake->y = 0;
    else if (snake->y < 0)
        snake->y = HEIGHT - 1;

    for (int i = 0; i < snake->nTail; i++) 
	{
        if (tailX[i] == snake->x && tailY[i] == snake->y) {
            snake->gameOver = 1;
            break;
        }
    }

    if (snake->x == snake->fruitX && snake->y == snake->fruitY) 
	{
        snake->score += 10;
        snake->fruitX = rand() % WIDTH;
        snake->fruitY = rand() % HEIGHT;
        snake->nTail++;
		if (snake->score >= 50) // if score is >= 50, a random bomb will spawn
		{
			snake->bombX = rand() % WIDTH;
			snake->bombY = rand() % HEIGHT;
			snake->bombExists = 1;
		}
	}
    if (snake->bombExists && snake->x == snake->bombX && snake->y == snake->bombY) 
	{
		snake->bombExists = -1;
        snake->gameOver = 1;
	}	
}
