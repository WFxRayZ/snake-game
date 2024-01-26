#include "snake.h"

// saves the high score to a file called "highscore.txt"
void SaveHighScore(int score) {
    int highScore = GetHighScore(); // Get the current high score
    if (score > highScore) { // Check if the current score is greater than the high score
        FILE* file = fopen("highscore.txt", "w");
        if (file != NULL) {
            fprintf(file, "%d", score);
            fclose(file);
        }
    }
}

// reads the high score from a file called "highscore.txt"
int GetHighScore() {
    int highScore = 0;
    FILE* file = fopen("highscore.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &highScore);
        fclose(file);
    }
    return highScore;
}

// checks if the current score is higher than the high score
void NewHighScore(struct snake *snake) 
{
    int highScore = GetHighScore(); // Get the current high score
    if (snake->score > highScore) { // Check if the current score is greater than the high score
        highScore = snake->score;
        SaveHighScore(highScore);
        printf("New High Score: %d!\n", highScore);

    }
    
    else if (snake->score <= highScore) 
    {
        printf("High Score: %d\n", highScore);
    }

}