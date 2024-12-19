#pragma once

#include "Camera.hpp"
#include "Material.hpp"
#include "VertexArray.hpp"


namespace eng {
    class Renderer{
        private:
            const Camera* camera;

        private:
            void bindMaterial(const Material& material);

        public:
            Renderer(const Camera* camera);
            void drawIndexed(const VertexArray& va, const Material& material);
            void drawInstanced(const VertexArray& vao, const Material& material, unsigned int instancesCount);
    };

}

