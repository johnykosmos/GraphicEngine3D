#pragma once

#include "Camera.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"


namespace eng {
    class Renderer{
        private:
            const Camera* camera;

        public:
            Renderer(const Camera* camera) : camera(camera) {};
            void draw(const VertexArray& va, const Shader& shader);
            void drawInstanced(const VertexArray& vao, const Shader& shader, unsigned int instancesCount);
    };

}

