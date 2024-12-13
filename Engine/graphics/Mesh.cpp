#include "Mesh.hpp"

namespace eng {

    Mesh::Mesh(const Vertex vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount) :
        vb(VertexBuffer(vertices, vertexCount * sizeof(Vertex))),
        ib(IndexBuffer(indices, indexCount * sizeof(unsigned int))){
            layout.push<float>(3);
            layout.push<float>(3);

            va.addVertexBuffer(vb, layout);
            va.addIndexBuffer(ib);    
        }

    const VertexArray& Mesh::getVertexArray() const {
        return va;
    }


}
