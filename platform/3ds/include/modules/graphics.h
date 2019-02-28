/*
** modules/graphics.h
** @brief : Used for rendering graphics (primitives, images, text)
*/

#pragma once


#define CONFIG_3D_SLIDERSTATE (*(volatile float *)0x1FF81080)

namespace Graphics
{
    void Initialize();

    //Löve2D Functions
    int Clear(lua_State * L);
    int Present(lua_State * L);

    int Circle(lua_State * L);
    int Rectangle(lua_State * L);

    int Set3D(lua_State * L);
    int SetDepth(lua_State * L);

    int Draw(lua_State * L);
    int Print(lua_State * L);

    int SetBackgroundColor(lua_State * L);
    int SetColor(lua_State * L);

    int GetWidth(lua_State * L);
    int GetHeight(lua_State * L);

    int GetRendererInfo(lua_State * L);

    int SetScreen(lua_State * L);
    int SetFont(lua_State * L);
    
    int SetScissor(lua_State * L);

    int Push(lua_State * L);
    int Pop(lua_State * L);

    int Translate(lua_State * L);
    int Scale(lua_State * L);
    int Rotate(lua_State * L);
    int Origin(lua_State * L);

    //End Löve2D Functions
    C3D_RenderTarget * GetScreen(gfxScreen_t screen, gfx3dSide_t side);
    void Clear(gfxScreen_t screen, gfx3dSide_t side);
    void DrawOn(gfxScreen_t screen, gfx3dSide_t side);

    u32 ConvertColor(Color & color);

    int Register(lua_State * L);

    void Exit();
}