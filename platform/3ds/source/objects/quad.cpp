#include "objects/quad/quad.h"

using namespace love;

Quad::Quad(const Viewport& viewport, double sw, double sh) : common::Quad(sw, sh)
{
    this->Refresh(viewport, sw, sh);
}

const Tex3DS_SubTexture& Quad::GetTex3DSViewport() const
{
    return this->subTex;
}

void Quad::Refresh(const Viewport& viewport, double sw, double sh)
{
    this->RefreshViewport(viewport, sw, sh);

    int w = NextPO2(sw);
    int h = NextPO2(sh);

    this->subTex.top  = 1.0f - (viewport.y + 1.0f) / h;
    this->subTex.left = (1.0f + viewport.x) / w;

    this->subTex.right  = (1.0f + viewport.x + viewport.w) / w;
    this->subTex.bottom = 1.0f - ((viewport.y + viewport.h + 1.0f) / h);

    this->subTex.width  = viewport.w;
    this->subTex.height = viewport.h;
}
