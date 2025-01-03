#pragma once

#include "objects/Shape.hpp"
#include "Mesh.hpp"
#include <memory>

namespace eng {

    const Vertex cubeVertices[24] = {
        Vertex{ 
            .vertices = Vec3{-0.5f, -0.5f, -0.5f},
            .normal = Vec3{0.0f, 0.0f, -1.0f},
            .texturePos = Vec2{0.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f, -0.5f, -0.5f},
            .normal = Vec3{0.0f, 0.0f, -1.0f},
            .texturePos = Vec2{1.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f,  0.5f, -0.5f},
            .normal = Vec3{0.0f, 0.0f, -1.0f},
            .texturePos = Vec2{1.0f, 1.0f}},
        Vertex{ 
            .vertices = Vec3{-0.5f,  0.5f, -0.5f},
            .normal = Vec3{0.0f, 0.0f, -1.0f},
            .texturePos = Vec2{0.0f, 1.0f}},

        // Front Face
        Vertex{ 
            .vertices = Vec3{-0.5f, -0.5f,  0.5f},
            .normal = Vec3{0.0f, 0.0f, 1.0f},
            .texturePos = Vec2{0.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f, -0.5f,  0.5f},
            .normal = Vec3{0.0f, 0.0f, 1.0f},
            .texturePos = Vec2{1.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f,  0.5f,  0.5f},
            .normal = Vec3{0.0f, 0.0f, 1.0f},
            .texturePos = Vec2{1.0f, 1.0f}},
        Vertex{ 
            .vertices = Vec3{-0.5f,  0.5f,  0.5f},
            .normal = Vec3{0.0f, 0.0f, 1.0f},
            .texturePos = Vec2{0.0f, 1.0f}},

        // Left Face
        Vertex{ 
            .vertices = Vec3{ 0.5f, -0.5f, -0.5f},
            .normal = Vec3{1.0f, 0.0f, 0.0f},
            .texturePos = Vec2{0.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f, -0.5f,  0.5f},
            .normal = Vec3{1.0f, 0.0f, 0.0f},
            .texturePos = Vec2{1.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f,  0.5f,  0.5f},
            .normal = Vec3{1.0f, 0.0f, 0.0f},
            .texturePos = Vec2{1.0f, 1.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f,  0.5f, -0.5f},
            .normal = Vec3{1.0f, 0.0f, 0.0f},
            .texturePos = Vec2{0.0f, 1.0f}},

        // Right Face
        Vertex{ 
            .vertices = Vec3{-0.5f, -0.5f, -0.5f},
            .normal = Vec3{-1.0f, 0.0f, 0.0f},
            .texturePos = Vec2{0.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{-0.5f, -0.5f,  0.5f},
            .normal = Vec3{-1.0f, 0.0f, 0.0f},
            .texturePos = Vec2{1.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{-0.5f,  0.5f,  0.5f},
            .normal = Vec3{-1.0f, 0.0f, 0.0f},
            .texturePos = Vec2{1.0f, 1.0f}},
        Vertex{ 
            .vertices = Vec3{-0.5f,  0.5f, -0.5f},
            .normal = Vec3{-1.0f, 0.0f, 0.0f},
            .texturePos = Vec2{0.0f, 1.0f}},

        // Bottom Face
        Vertex{ 
            .vertices = Vec3{-0.5f,  0.5f, -0.5f},
            .normal = Vec3{0.0f, 1.0f, 0.0f},
            .texturePos = Vec2{0.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f,  0.5f, -0.5f},
            .normal = Vec3{0.0f, 1.0f, 0.0f},
            .texturePos = Vec2{1.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f,  0.5f,  0.5f},
            .normal = Vec3{0.0f, 1.0f, 0.0f},
            .texturePos = Vec2{1.0f, 1.0f}},
        Vertex{ 
            .vertices = Vec3{-0.5f,  0.5f,  0.5f},
            .normal = Vec3{0.0f, 1.0f, 0.0f},
            .texturePos = Vec2{0.0f, 1.0f}},

        // Top Face 
        Vertex{ 
            .vertices = Vec3{-0.5f, -0.5f, -0.5f},
            .normal = Vec3{0.0f, -1.0f, 0.0f},
            .texturePos = Vec2{0.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f, -0.5f, -0.5f},
            .normal = Vec3{0.0f, -1.0f, 0.0f},
            .texturePos = Vec2{1.0f, 0.0f}},
        Vertex{ 
            .vertices = Vec3{ 0.5f, -0.5f,  0.5f},
            .normal = Vec3{0.0f, -1.0f, 0.0f},
            .texturePos = Vec2{1.0f, 1.0f}},
        Vertex{ 
            .vertices = Vec3{-0.5f, -0.5f,  0.5f},
            .normal = Vec3{0.0f, -1.0f, 0.0f},
            .texturePos = Vec2{0.0f, 1.0f}},

    };
 
    const unsigned int cubeIndices[36] = {
    // Back Face
    0, 2, 1, 0, 3, 2,       
    // Front Face
    4, 5, 6, 4, 6, 7,      
    // Left Face
    8, 10, 9, 8, 11, 10,
    // Right Face
    12, 13, 14, 12, 14, 15,
    // Bottom Face
    16, 18, 17, 16, 19, 18,
    // Top Face
    20, 21, 22, 20, 22, 23
    };


    class CubeShape : public Shape {
        private:
            static std::unique_ptr<Mesh> mesh;
        public:
            CubeShape();
            Mesh& getMesh() const override;
    };

} // namespace eng
