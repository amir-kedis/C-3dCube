#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

#define CUBE_SIZE 5.0f

#define CUBE_COLOR 0xEF959CFF
#define CUBE_WIRES_COLOR 0x8D697AFF
#define BACKGROUND_COLOR 0x1E1E1EFF

#define CAMERA_SPEED 2.0f

void updateCamera(Camera3D *camera, float *theta, float *phi,
                  float *camera_mag) {
  // TODO: Add mouse input to rotate the camera
  if (IsKeyDown(KEY_W))
    *phi += CAMERA_SPEED * GetFrameTime();
  if (IsKeyDown(KEY_S))
    *phi -= CAMERA_SPEED * GetFrameTime();
  if (IsKeyDown(KEY_A))
    *theta += CAMERA_SPEED * GetFrameTime();
  if (IsKeyDown(KEY_D))
    *theta -= CAMERA_SPEED * GetFrameTime();
  if (IsKeyDown(KEY_Q))
    *camera_mag += CAMERA_SPEED * GetFrameTime();
  if (IsKeyDown(KEY_E))
    *camera_mag -= CAMERA_SPEED * GetFrameTime();

  camera->position = (Vector3){.x = *camera_mag * cosf(*theta) * sinf(*phi),
                               .y = *camera_mag * cosf(*phi),
                               .z = *camera_mag * sinf(*theta) * sinf(*phi)};
}

int main() {

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(1280, 720, "3D Cube");

  float camera_mag = CUBE_SIZE * 3.0f;
  float theta = 45.0f;
  float phi = -45.0f;

  Camera3D camera = {
      // .position = {CUBE_SIZE * 2.0f, CUBE_SIZE * 2.0f, CUBE_SIZE * 2.0f},
      .position =
          {
              .x = camera_mag * cosf(theta) * sinf(phi),
              .y = camera_mag * cosf(phi),
              .z = camera_mag * sinf(theta) * sinf(phi),
          },
      .target = {0.0f, 0.0f, 0.0f}, // Camera looks at the origin
      .up = {0.0f, 1.0f, 0.0f},     // Camera is oriented with +Y up
      .fovy = 45.0f,
      .projection = CAMERA_PERSPECTIVE, // NOTE: paly with this more
                                        //  .projection = CAMERA_PERSPECTIVE,
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(BACKGROUND_COLOR));
    float dt = GetFrameTime();

    updateCamera(&camera, &theta, &phi, &camera_mag);

    BeginMode3D(camera);

    DrawGrid(40, 1.0f);

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
