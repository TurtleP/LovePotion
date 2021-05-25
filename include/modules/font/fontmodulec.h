#pragma once

#include "common/data.h"
#include "utf8/utf8.h"

#include "objects/filedata/filedata.h"
#include "objects/font/font.h"
#include "objects/rasterizer/rasterizer.h"

#include "common/module.h"

namespace love::common
{
    class FontModule : public Module
    {
        FontModule();

        virtual ~FontModule();

        ModuleType GetModuleType() const
        {
            return M_FONT;
        }

        const char* GetName() const override
        {
            return "love.font";
        }

        virtual Rasterizer* NewRasterizer(FileData* data) = 0;

        GlyphData* NewGlyphData(Rasterizer* rasterizer, const std::string& glyph);

        GlyphData* NewGlyphData(Rasterizer* rasterizer, uint32_t glyph);
    };
} // namespace love::common
