#include <raylib.h>
#include <iostream>
#include <cmath>
#include "game.h"
#include "colours.h"

double lastUpdateTime = 0; // To track when last game event triggered
bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true; // If interval has passed
    }
    return false;
}

int main() {
    // Custom Colours
    Color darkBlue = {44, 44, 120, 255};
    Color translucentBlack = {0, 0, 0, 235};

    // Game Window Settings
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60);

    // Render Texture and Load Font
    RenderTexture2D target = LoadRenderTexture(500, 620);
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();  // Initializing Game

    while(WindowShouldClose() == false){
        game.ManageInput(); // Handling user input

        double speed = 0.3 * pow(0.9, game.level - 1); // Calculating Speed at each level
        if(EventTriggered(speed)){
            game.MoveBlockDown();
        } 

        // Drawing Frame
        BeginDrawing();
        ClearBackground(BLACK);

        // Drawing Renders
        BeginTextureMode(target);
        ClearBackground(darkBlue);

        // Drawing 'Level' Box and Text
        DrawTextEx(font, "LEVEL", {345, 15}, 38, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue); 
        sprintf(levelText, "%d", game.level);
        Vector2 levelSize = MeasureTextEx(font, levelText, 38, 2);
        DrawTextEx(font, levelText, {320 + (170 - levelSize.x)/2, 65}, 38, 2, WHITE);

        // Drawing 'Score' Box and Text
        DrawTextEx(font, "SCORE", {345, 125}, 38, 2, WHITE);
        DrawRectangleRounded({320, 170, 170, 60}, 0.3, 6, lightBlue);
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 TextSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 + (170 - TextSize.x)/2, 180}, 38, 2, WHITE);

        // Drawing 'Next' Box and Text
        DrawTextEx(font, "NEXT", {355, 255}, 38, 2, WHITE);
        DrawRectangleRounded({320, 295, 170, 180}, 0.3, 6, lightBlue);

        // Drawing 'Lines' Box and Text
        DrawTextEx(font, "LINES", {350, 495}, 38, 2, WHITE);
        DrawRectangleRounded({320, 535, 170, 60}, 0.3, 6, lightBlue);
        char linesText[10];
        sprintf(linesText, "%d", game.totalLinesCleared);
        Vector2 linesSize = MeasureTextEx(font, linesText, 38, 2);
        DrawTextEx(font, linesText, {320 + (170 - linesSize.x)/2, 545}, 38, 2, WHITE);

        // Game Over Screen
        if(game.GameOver){
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), translucentBlack);
            DrawTextPro(font, "GAME OVER", {250, 365}, {300, 250}, 90.0f, 95, 2, YELLOW);

            // Display Level
            DrawTextEx(font, "LEVEL", {327, 20}, 25, 2, WHITE);
            DrawRectangleRounded({317, 45, 100, 50}, 0.3, 6, lightBlue);
            char levelText[10];
            sprintf(levelText, "%d", game.level);
            Vector2 levelSize = MeasureTextEx(font, levelText, 38, 2);
            DrawTextEx(font, levelText, {320 + (100 - levelSize.x)/2, 60}, 25, 2, WHITE);

            // Display Score
            DrawTextEx(font, "SCORE", {325, 295}, 25, 2, WHITE);
            DrawRectangleRounded({317, 320, 100, 50}, 0.3, 6, lightBlue);
            char scoreText[10];
            sprintf(scoreText, "%d", game.score);
            Vector2 TextSize = MeasureTextEx(font, scoreText, 38, 2);
            DrawTextEx(font, scoreText, {325 + (100 - TextSize.x)/2, 335}, 25, 2, WHITE);

            // Display Lines
            DrawTextEx(font, "LINES", {327, 530}, 25, 2, WHITE);
            DrawRectangleRounded({317, 555, 100, 50}, 0.3, 6, lightBlue);
            char linesText[10];
            sprintf(linesText, "%d", game.totalLinesCleared);
            Vector2 LinesSize = MeasureTextEx(font, linesText, 38, 2);
            DrawTextEx(font, linesText, {320 + (100 - LinesSize.x)/2, 570}, 25, 2, WHITE);
        }

        game.Draw(); // Drawing Game grid and tetrominoes 

        EndTextureMode();

        // Window Resizing
        float scaleX = (float)GetScreenWidth() / 500.0f;
        float scaleY = (float)GetScreenHeight() / 620.0f;
        float scale = fmin(scaleX, scaleY);
        int scaledWidth = (int)(500 * scale);
        int scaledHeight = (int)(620 * scale);
        int offsetX = (GetScreenWidth() - scaledWidth) / 2;
        int offsetY = (GetScreenHeight() - scaledHeight) / 2;

        DrawTexturePro(
            target.texture,
            {0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height}, // Flip Y
            {(float)offsetX, (float)offsetY, (float)scaledWidth, (float)scaledHeight},
            {0, 0},
            0.0f,
            WHITE
        );

        EndDrawing();
    }
    
    CloseWindow(); 
}
