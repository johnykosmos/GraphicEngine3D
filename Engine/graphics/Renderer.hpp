#pragma once

#include "Camera.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"


namespace eng {
    class Renderer{
        private:
            const Camera* camera;

        public:
            Renderer(const Camera* camera);
            void draw(const VertexArray& va, const Shader& shader);
            void drawInstanced(const VertexArray& vao, const Shader& shader, const Texture& texture, unsigned int instancesCount);
    };

}

