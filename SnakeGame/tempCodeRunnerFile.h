#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Height and width for the gui
#define WIDTH 20
#define HEIGHT 20

// global variable (for now)
int gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

// Game.c functions
void Draw();
void Input();
void Logic();
void EndGame();

// Menu.c functions
void StartMenu();

// Score.c functions
void SaveHighScore(int score);
int GetHighScore();
void NewHighScore();