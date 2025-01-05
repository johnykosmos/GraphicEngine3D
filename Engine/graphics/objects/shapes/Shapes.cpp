#include "Mesh.hpp"
#include "Shapes.hpp"


namespace eng {
    std::unique_ptr<Mesh> CubeShape::mesh = nullptr;
    std::unique_ptr<Mesh> SphereShape::mesh = nullptr;
    std::unique_ptr<Mesh> PyramidShape::mesh = nullptr;

    CubeShape::CubeShape() {
        if (!mesh) {
            mesh = std::make_unique<Mesh>(cubeVertices, 24, cubeIndices, 36);
        }
    }

    Mesh& CubeShape::getMesh() const {
        return *mesh;
    }

    SphereShape::SphereShape() {
        if (!mesh) {
            mesh = std::make_unique<Mesh>(sphereVertices, 561, sphereIndices, 3072);
        }
    }

    Mesh& SphereShape::getMesh() const {
        return *mesh;
    }

    PyramidShape::PyramidShape() {
        if (!mesh) {
            mesh = std::make_unique<Mesh>(pyramidVertices, 16, pyramidIndices, 18);
        }
    }

    Mesh& PyramidShape::getMesh() const {
        return *mesh;
    }
    

} // namespace eng
