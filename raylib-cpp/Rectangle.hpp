#ifndef RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_
#define RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./Vector2.hpp"

namespace raylib {
/**
 * RayRectangle type
 */
class RayRectangle : public ::RayRectangle {
 public:
    RayRectangle(const ::RayRectangle& rect) : ::RayRectangle{rect.x, rect.y, rect.width, rect.height} {}

    RayRectangle(float x, float y, float width, float height) : ::RayRectangle{x, y, width, height} {}
    RayRectangle(float x, float y, float width) : ::RayRectangle{x, y, width, 0} {}
    RayRectangle(float x, float y) : ::RayRectangle{x, y, 0, 0} {}
    RayRectangle(float x) : ::RayRectangle{x, 0, 0, 0} {}
    RayRectangle() : ::RayRectangle{0, 0, 0, 0} {}

    RayRectangle(::Vector2 position, ::Vector2 size)
            : ::RayRectangle{position.x, position.y, size.x, size.y} {}
    RayRectangle(::Vector2 size) : ::RayRectangle{0, 0, size.x, size.y} {}
    RayRectangle(::Vector4 rect) : ::RayRectangle{rect.x, rect.y, rect.z, rect.w} {}

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)
    GETTERSETTER(float, Width, width)
    GETTERSETTER(float, Height, height)

    RayRectangle& operator=(const ::RayRectangle& rect) {
        set(rect);
        return *this;
    }

    inline ::Vector4 ToVector4() {
        return {x, y, width, height};
    }

    operator ::Vector4() const {
        return {x, y, width, height};
    }

    /**
     * Draw a color-filled rectangle
     */
    inline void Draw(::Color color) const {
        ::DrawRayRectangleRec(*this, color);
    }

    inline void Draw(::Vector2 origin, float rotation, ::Color color) const {
        ::DrawRayRectanglePro(*this, origin, rotation, color);
    }

    inline void DrawGradientV(::Color color1, ::Color color2) const {
        ::DrawRayRectangleGradientV(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color1, color2);
    }

    inline void DrawGradientH(::Color color1, ::Color color2) const {
        ::DrawRayRectangleGradientH(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color1, color2);
    }

    inline void DrawGradient(::Color col1, ::Color col2, ::Color col3, ::Color col4) const {
        ::DrawRayRectangleGradientEx(*this, col1, col2, col3, col4);
    }

    inline void DrawLines(::Color color) const {
        ::DrawRayRectangleLines(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width),
            static_cast<int>(height), color);
    }

    inline void DrawLines(::Color color, float lineThick) const {
        ::DrawRayRectangleLinesEx(*this, lineThick, color);
    }

    inline void DrawRounded(float roundness, int segments, ::Color color) const {
        ::DrawRayRectangleRounded(*this, roundness, segments, color);
    }

    inline void DrawRoundedLines(float roundness, int segments,
            float lineThick, ::Color color) const {
        ::DrawRayRectangleRoundedLines(*this, roundness, segments, lineThick, color);
    }

    /**
     * Check collision between two rectangles
     */
    inline bool CheckCollision(::RayRectangle rec2) const {
        return ::CheckCollisionRecs(*this, rec2);
    }

    /**
     * Get collision rectangle for two rectangles collision
     */
    inline ::RayRectangle GetCollision(::RayRectangle rec2) const {
        return ::GetCollisionRec(*this, rec2);
    }

    /**
     * Check if point is inside rectangle
     */
    inline bool CheckCollision(::Vector2 point) const {
        return ::CheckCollisionPointRec(point, *this);
    }

    /**
     * Check collision between circle and rectangle
     */
    inline bool CheckCollision(::Vector2 center, float radius) {
        return ::CheckCollisionCircleRec(center, radius, *this);
    }

    inline Vector2 GetSize() {
        return {width, height};
    }

    inline RayRectangle& SetSize(float newWidth, float newHeight) {
        width = newWidth;
        height = newHeight;
        return *this;
    }

    inline RayRectangle& SetSize(const ::Vector2& size) {
        return SetSize(size.x, size.y);
    }

    inline RayRectangle& SetShapesTexture(const ::Texture2D& texture) {
        ::SetShapesTexture(texture, *this);
        return *this;
    }

    inline Vector2 GetPosition() {
        return {x, y};
    }

    inline RayRectangle& SetPosition(float newX, float newY) {
        x = newX;
        y = newY;
        return *this;
    }

    inline RayRectangle& SetPosition(const ::Vector2& position) {
        return SetPosition(position.x, position.y);
    }

 private:
    void set(const ::RayRectangle& rect) {
        x = rect.x;
        y = rect.y;
        width = rect.width;
        height = rect.height;
    }
};
}  // namespace raylib

using RRayRectangle = raylib::RayRectangle;

#endif  // RAYLIB_CPP_INCLUDE_RECTANGLE_HPP_
