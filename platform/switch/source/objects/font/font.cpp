#include "common/runtime.h"

#include "modules/filesystem.h"

#include "common/drawable.h"
#include "objects/font/font.h"
#include "modules/graphics.h"
#include "modules/display.h"

Font::Font(const string & path, float size) : Drawable("Font")
{
    float dpiScale = 1.0f;
    this->size = floorf(size * dpiScale + 0.5f);

    this->font = this->LoadFont(path, this->size);

    this->texture = NULL;
}

TTF_Font * Font::LoadFont(const string & name, float size)
{
    PlFontData fontData;
    PlSharedFontType type;

    if (name == "chinese simplified")
        type = PlSharedFontType_ChineseSimplified;
    else if (name == "extended chinese simplified")
        type = PlSharedFontType_ExtChineseSimplified;
    else if (name == "chinese traditional")
        type = PlSharedFontType_ChineseTraditional;
    else if (name == "korean")
        type = PlSharedFontType_KO;
    else if (name == "nintendo extended")
        type = PlSharedFontType_NintendoExt;
    else if (name == "standard")
        type = PlSharedFontType_Standard;
    else
    {
        TTF_Font * newFont = TTF_OpenFont(name.c_str(), size);

        if (newFont)
            return newFont;
        else
        {
            Love::RaiseError("Could not open file %s. Does not exist.", name.c_str());
            return nullptr;
        }
    }

    plGetSharedFontByType(&fontData, type);

    return TTF_OpenFontRW(SDL_RWFromMem(fontData.address, fontData.size), 1, size);
}

Font::Font(int size) : Drawable("Font")
{
    float dpiScale = 1.0f;
    this->size = floorf(size * dpiScale + 0.5f);

    this->font = this->LoadFont("standard", this->size);
    this->texture = NULL;
}

void Font::Print(const char * text, float x, float y, float rotation, float limit, float offsetX, float offsetY, float scalarX, float scalarY, SDL_Color color)
{
    if (strlen(text) == 0)
        return;

    SDL_Surface * tempSurface = TTF_RenderUTF8_Blended_Wrapped(this->font, text, color, limit);

    this->texture = SDL_CreateTextureFromSurface(Display::GetRenderer(), tempSurface);
    SDL_SetTextureBlendMode(this->texture, SDL_BLENDMODE_BLEND);

    SDL_FreeSurface(tempSurface);

    int width, height = 0;
    SDL_QueryTexture(this->texture, NULL, NULL, &width, &height);

    Viewport viewport = {0, 0, width, height, width, height};

    Drawable::Draw(texture, viewport, x, y, rotation, offsetX, offsetY, scalarX, scalarY, color);

    SDL_DestroyTexture(texture);
}

Font::~Font()
{
    TTF_CloseFont(this->font);
}

int Font::GetSize()
{
    return TTF_FontHeight(this->font);
}

int Font::GetWidth(const char * text)
{
    int width = 0;

    if (strlen(text) != 0)
        TTF_SizeUTF8(this->font, text, &width, NULL);

    return width;
}

TTF_Font * Font::GetFont()
{
    return this->font;
}

bool Font::HasGlyph(uint glyph)
{
    return TTF_GlyphIsProvided(this->font, glyph);
}
