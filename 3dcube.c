#include <raylib.h>
#include <stdio.h>

int main() {

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(1280, 720, "3D Cube");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(GetColor(0x8DA1B9ff));

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
