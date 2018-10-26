#pragma once

#include <string>
#include <vector>
#include <map>

#include "socket/common.h"
#include <citro2d.h>

typedef struct
{
    double ox;
    double oy;

    double r;

    double sx;
    double sy;

    double kx;
    double ky;
} StackMatrix;

typedef enum
{
    BOOLEAN,
    LUSERDATA,
    NIL,
    NUMBER,
    STRING,
    TABLE,
    UNKNOWN,
    USERDATA
} VARIANTS;

typedef enum
{
    OBJECTS
} REGISTRY;

typedef struct
{
    char * buffer;
    char * ip;
    int port;
} Datagram;

typedef struct
{
    float r;
    float g;
    float b;
    float a;
} Color;

typedef struct
{
    int id;

    int xoffset;
    int yoffset;

    int width;
    int xadvance;

    Tex3DS_SubTexture subTexture;
} Glyph;

typedef struct
{
    GPU_TEXTURE_FILTER_PARAM minFilter;
    GPU_TEXTURE_FILTER_PARAM magFilter;
} TextureFilter;

extern std::vector<const char *> FILE_MODES;

extern std::vector<const char *> SOURCE_TYPES;

extern std::vector<const char *> DRAW_MODES;