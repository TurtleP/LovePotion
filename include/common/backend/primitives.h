/*
** render.h
** Renderer superclass
*/

#pragma once

#include "modules/window/window.h"
#include "modules/graphics/graphics.h"

namespace Primitives
{
    void Rectangle(const std::string & mode, float x, float y, float width, float height, float rx, float ry, float lineWidth, const Colorf & color);

    void Arc(const std::string & mode, float x, float y, float radius, float startAngle, float endAngle, const Colorf & color);

    void Ellipse(const std::string & mode, float x, float y, float radiusX, float radiusY, const Colorf & color);

    void Circle(const std::string & mode, float x, float y, float radius, float lineWidth, const Colorf & color);

    void Polygon(const std::string & mode, std::vector<love::Graphics::Point> points, float lineWidth, const Colorf & color);

    void Line(float x1, float y1, float x2, float y2, float lineWidth, const Colorf & color);

    void Points(std::vector<std::vector<float>> points, const Colorf & color);

    void Points(std::vector<float> points, const Colorf & color);

    void Scissor(bool enabled, int x, int y, int width, int height);

    void Stencil();
}
