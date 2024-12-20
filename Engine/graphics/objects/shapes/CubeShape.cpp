#include "Mesh.hpp"
#include "Shapes.hpp"


namespace eng {
    std::unique_ptr<Mesh> CubeShape::mesh = nullptr;

    CubeShape::CubeShape() {
        if (!mesh) {
            mesh = std::make_unique<Mesh>(cubeVertices, 24, cubeIndices, 36);
        }
    }

    Mesh& CubeShape::getMesh() const {
        return *mesh;
    }

} // namespace eng
