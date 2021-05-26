#include "modules/font/fontmodule.h"

#include "common/data.h"
#include "utf8/utf8.h"

using namespace love;

class SystemFontData : public love::Data
{
  public:
    SystemFontData(Font::SystemFontType type) : type(type)
    {
        plGetSharedFontByType(&this->fontData, (PlSharedFontType)type);
    }

    Data* Clone() const override
    {
        return new SystemFontData(this->type);
    }
    void* GetData() const override
    {
        return this->fontData.address;
    }
    size_t GetSize() const override
    {
        return this->fontData.size;
    }

  private:
    PlFontData fontData;
    Font::SystemFontType type;
};

FontModule::FontModule()
{
    if (FT_Init_FreeType(&this->library))
        throw love::Exception("TrueTypeFont Loading error: FT_Init_FreeType failed");
}

FontModule::~FontModule()
{
    FT_Done_FreeType(this->library);
}

Data* FontModule::GetSystemFont(Font::SystemFontType type)
{
    return new SystemFontData(type);
}

/* Create from FileData */
Rasterizer* FontModule::NewRasterizer(FileData* data)
{
    if (TrueTypeRasterizer::Accepts(this->library, data))
        return this->NewTrueTypeRasterizer(data, 12, TrueTypeRasterizer::HINTING_NORMAL);

    throw love::Exception("Invalid font file: %s", data->GetFilename().c_str());
}

/* Create from Data with Size and Hinting */
Rasterizer* FontModule::NewTrueTypeRasterizer(Data* data, int size,
                                              TrueTypeRasterizer::Hinting hinting)
{
    return this->NewTrueTypeRasterizer(data, size, 1.0f, hinting);
}

/* Create from Data with Size, DPI Scaling, and Hinting */
Rasterizer* FontModule::NewTrueTypeRasterizer(Data* data, int size, float dpiScale,
                                              love::TrueTypeRasterizer::Hinting hinting)
{
    return new TrueTypeRasterizer(this->library, data, size, hinting);
}

/* Create new System Font with Size */
Rasterizer* FontModule::NewTrueTypeRasterizer(int size, TrueTypeRasterizer::Hinting hinting)
{
    love::StrongReference<SystemFontData> data(
        new SystemFontData(Font::SystemFontType::TYPE_STANDARD), Acquire::NORETAIN);

    return this->NewTrueTypeRasterizer(data.Get(), size, hinting);
}

/* Create new System Font with Size and DPI Scale */
Rasterizer* FontModule::NewTrueTypeRasterizer(int size, float dpiScale,
                                              TrueTypeRasterizer::Hinting hinting)
{
    StrongReference<SystemFontData> data(new SystemFontData(Font::SystemFontType::TYPE_STANDARD),
                                         Acquire::NORETAIN);

    return this->NewTrueTypeRasterizer(data.Get(), size, dpiScale, hinting);
}
