#include "objects/texture/texture.h"
#include "modules/graphics/graphics.h"

#include "common/vector.h"
#include "common/matrix.h"

#include "deko3d/deko.h"

using namespace love;

Texture::Texture(TextureType type) : common::Texture(type)
{}

Texture::~Texture()
{
    ::deko3d::instance().UnRegisterResHandle(this->handle);
}

void Texture::SetHandle(DkResHandle handle)
{
    this->handle = handle;
}

DkResHandle Texture::GetHandle()
{
    return this->handle;
}

bool Texture::SetWrap(const Wrap & wrap)
{
    ::deko3d::instance().SetTextureWrap(this, wrap);
    return true;
}

void Texture::SetFilter(const Filter & filter)
{
    ::deko3d::instance().SetTextureFilter(this, filter);
}

void Texture::Draw(Graphics * gfx, const Matrix4 & localTransform)
{
    this->Draw(gfx, this->quad, localTransform);
}

void Texture::Draw(Graphics * gfx, love::Quad * quad, const Matrix4 & localTransform)
{
    const Matrix4 & tm = gfx->GetTransform();
    bool is2D = tm.IsAffine2DTransform();

    Matrix4 t(tm, localTransform);

    std::vector<vertex::Vertex> points(TEXTURE_QUAD_POINT_COUNT);

    if (is2D)
    {
        Vector2 transformed[4];
        t.TransformXY(transformed, quad->GetVertexPositions(), 4);
        points = vertex::GenerateTextureFromVectors(transformed, quad->GetVertexTexCoords(), points.size(), gfx->GetColor());
    }

    ::deko3d::instance().RenderTexture(this->handle, points.data(), 4);
}
