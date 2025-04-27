#include "Mesh.hpp"

namespace eng {

    Mesh::Mesh() {
        layout.push<float>(3);
        layout.push<float>(3);
        layout.push<float>(2);
    }

    Mesh::Mesh(const Vertex vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount) {
            layout.push<float>(3);
            layout.push<float>(3);
            layout.push<float>(2);

            updateData(vertices, vertexCount, indices, indexCount);
        }

    const VertexArray& Mesh::getVertexArray() const {
        return va;
    }

    void Mesh::updateData(const Vertex vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount) {
        vb.updateData(vertices, vertexCount * sizeof(Vertex));
        ib.updateData(indices, indexCount);
        va.configureAttributes(vb, layout, false);
        va.addIndexBuffer(ib);    
        va.unbind();
    }


}
