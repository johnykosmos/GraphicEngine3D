#include "ModelLoader.hpp"
#include "ModelParser.hpp"

#include <vector>


namespace eng {

    bool ModelLoader::loadModel(const std::string& filename, Mesh& modelMesh) {
        ModelParser parser;

        if (!parser.parseFile(filename)) {
            return false;
        }
        
        auto vertices = parser.getVertices();
        auto indices = parser.getIndices();

        modelMesh.updateData(vertices.data(), vertices.size(), indices.data(), indices.size());

        return true;
    }




} // namespace eng
