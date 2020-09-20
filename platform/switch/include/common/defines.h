#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include <switch.h>

#include "common/mmath.h"

using love::Rect;

#define MAX_GAMEPADS 1

typedef SDL_Renderer Renderer;

typedef SDL_Window Frame;

typedef SDL_Texture * TextureHandle;

typedef TTF_Font * FontHandle;

typedef SDL_Texture * ImageHandle;

typedef struct _TickCounter {
} TickCounter;

typedef struct _TextBuffer {
} TextBuffer;

typedef struct _TextHandle {
} TextHandle;
