#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Height and width for the game window
#define WIDTH 20
#define HEIGHT 20

// struct for snake game
// it contains information about the snake
struct snake 
{
	int x;
	int y;
	int fruitX;
	int fruitY;
	int bombX;
	int bombY;
	int bombExists;
	int score;
	int nTail;
	int gameOver;
};

// global variable (for now)
// int gameOver;
// int x, y, fruitX, fruitY, score;
// int nTail;
int tailX[100], tailY[100];
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

// Game.c functions
void Draw(struct snake *snake);
void Input(struct snake *snake);
void Logic(struct snake *snake);

// Menu.c functions
void StartMenu();
void EndGame(struct snake *snake);

// Score.c functions
void SaveHighScore(int score);
int GetHighScore();
void NewHighScore(struct snake *snake);


