#include "Mesh.hpp"

namespace eng {

    Mesh::Mesh() {
        layout.push<float>(3);
        layout.push<float>(3);
        layout.push<float>(2);
    }

    Mesh::Mesh(const Vertex vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount) :
        vb(VertexBuffer(vertices, vertexCount * sizeof(Vertex))),
        ib(IndexBuffer(indices, indexCount)){
            layout.push<float>(3);
            layout.push<float>(3);
            layout.push<float>(2);

            updateData(vertices, vertexCount, indices, indexCount);
        }

    VertexArray& Mesh::getVertexArray() {
        return va;
    }

    void Mesh::updateData(const Vertex vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount) {
        va.configureAttributes(vb, layout, false);
        va.addIndexBuffer(ib);    
        va.unbind();
    }


}
