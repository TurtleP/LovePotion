#pragma once

#include "objects/texture/texturec.h"
#include "c2d/base.h"

namespace love
{
    class Texture : public common::Texture
    {
        public:
            Texture(TextureType type);

            void Draw(Graphics * gfx, const Matrix4 & localTransform) override;

            void Draw(Graphics * gfx, love::Quad * quad, const Matrix4 & localTransform) override;

            bool SetWrap(const Wrap & wrap) override;

            void SetFilter(const Filter & filter) override;

        protected:
            C2D_Image texture;
    };
}