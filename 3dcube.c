#include <raylib.h>
#include <stdio.h>

#define CUBE_SIZE 20.0f

#define CUBE_COLOR 0xEF959CFF
#define CUBE_WIRES_COLOR 0x8D697AFF
#define BACKGROUND_COLOR 0x1E1E1EFF

#define CAMERA_SPEED 10.0f

void updateCamera(Camera3D *camera) {
  if (IsKeyDown(KEY_W)) {
    camera->position.z += CAMERA_SPEED * GetFrameTime();
  }
  if (IsKeyDown(KEY_S)) {
    camera->position.z -= CAMERA_SPEED * GetFrameTime();
  }
  if (IsKeyDown(KEY_A)) {
    camera->position.x -= CAMERA_SPEED * GetFrameTime();
  }
  if (IsKeyDown(KEY_D)) {
    camera->position.x += CAMERA_SPEED * GetFrameTime();
  }
  if (IsKeyDown(KEY_Q)) {
    camera->position.y -= CAMERA_SPEED * GetFrameTime();
  }
  if (IsKeyDown(KEY_E)) {
    camera->position.y += CAMERA_SPEED * GetFrameTime();
  }
}

int main() {

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(1280, 720, "3D Cube");

  Camera3D camera = {
      // .position = {CUBE_SIZE * 2.0f, CUBE_SIZE * 2.0f, CUBE_SIZE * 2.0f},
      .position = {CUBE_SIZE, CUBE_SIZE, CUBE_SIZE}, // Camera position
      .target = {0.0f, 0.0f, 0.0f}, // Camera looks at the origin
      .up = {0.0f, 1.0f, 0.0f},     // Camera is oriented with +Y up
      .fovy = 45.0f,
      .projection = CAMERA_ORTHOGRAPHIC, // NOTE: paly with this more
                                         //  .projection = CAMERA_PERSPECTIVE,
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(BACKGROUND_COLOR));
    float dt = GetFrameTime();

    updateCamera(&camera);

    BeginMode3D(camera);

    DrawCube((Vector3){0.0f, 0.0f, 0.0f}, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
             GetColor(CUBE_COLOR));
    DrawCubeWires((Vector3){0.0f, 0.0f, 0.0f}, CUBE_SIZE, CUBE_SIZE, CUBE_SIZE,
                  GetColor(CUBE_WIRES_COLOR));

    EndMode3D();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
