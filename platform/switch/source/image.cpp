#include "common/runtime.h"
#include "objects/image/image.h"

#include "deko3d/deko.h"

using namespace love;

Image::Image(Data * data) : Texture(Texture::TEXTURE_2D)
{
    // CImage can load PNG and JPG files with the proper libraries
    void * buffer = this->texture.load(data->GetData(), data->GetSize(),
                                       this->width, this->height);

    if (buffer == nullptr)
        throw love::Exception("Failed to load imagedata.");

    // Have the deko3d class load our new buffer and register it to the CDescriptorSets
    dk3d.LoadTextureBuffer(this->texture, buffer, this->width * this->height * 4, this, DkImageFormat_RGBA8_Unorm);

    this->InitQuad();
}

Image::Image(TextureType type, int width, int height) : Texture(type)
{
    this->Init(width, height);
}

Image::~Image()
{
    dk3d.UnRegisterResHandle(this);
}

void Image::Init(int width, int height)
{
    this->width = width;
    this->height = height;

    this->InitQuad();
}

void Image::LoadBuffer(void * data, size_t size)
{
    dk3d.LoadTextureBuffer(this->texture, data, size * 4, this, DkImageFormat_RGBA8_Unorm);
}