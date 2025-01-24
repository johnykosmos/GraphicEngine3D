#include "ModelParser.hpp"

#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>

namespace eng {

    void ModelParser::readVec2(std::istringstream& stream, 
            std::vector<Vec2>& storage) {
        Vec2 vec;
        stream >> vec.x >> vec.y;
        storage.push_back(vec);
    }

    void ModelParser::readVec3(std::istringstream& stream, 
            std::vector<Vec3>& storage) {
        Vec3 vec;
        stream >> vec.x >> vec.y >> vec.z;
        storage.push_back(vec);
    }

    void ModelParser::readVertex(std::string& vertexString) {
            std::istringstream vertexStream(vertexString);
            std::array<int, 3> indicesArray = {0, 0, 0};
            char slash;

            vertexStream >> indicesArray[0] >> slash >> 
                indicesArray[1] >> slash >> indicesArray[2];

            Vertex vertex = {
                positions[indicesArray[0] - 1],
                normals[indicesArray[2] - 1],
                texPositions[indicesArray[1] - 1]
            };

            vertices.push_back(vertex);

            vertexCache[vertexString] = static_cast<unsigned int>(vertices.size() - 1);
    }

    void ModelParser::readFaces(std::istringstream& stream) {
        std::vector<unsigned int> faceIndices;
        while (!stream.eof()) {
            std::string vertexString;
            stream >> vertexString;

            if (vertexString.empty()) {
                continue;
            }

            if (vertexCache.find(vertexString) == vertexCache.end()) {
                readVertex(vertexString);                                   
            }

            faceIndices.push_back(vertexCache[vertexString]);
        }

        for (size_t i = 1; i < faceIndices.size() - 1; i++) {
            indices.push_back(faceIndices[0]);
            indices.push_back(faceIndices[i]);
            indices.push_back(faceIndices[i + 1]);
        }

    }

    bool ModelParser::parseFile(const std::string& filename) {
        std::ifstream modelFile(filename);
        if (!modelFile.is_open()) {
            std::cerr << "Failed to open the model file for reading.\n";
            return false;
        }

        std::string line;
        while (std::getline(modelFile, line)) {
            std::istringstream stream(line);
            std::string prefix;
            stream >> prefix;

            if (prefix == "v") {
                readVec3(stream, positions); 

            } else if (prefix == "vn") {
                readVec3(stream, normals);

            } else if (prefix == "vt") { 
                readVec2(stream, texPositions);

            } else if (prefix == "f") { 
                readFaces(stream);               
            }
        }

        modelFile.close();

        return true;
    }

    std::vector<Vertex> ModelParser::getVertices() const {
        return vertices;
    }
    std::vector<unsigned int> ModelParser::getIndices() const {
        return indices;
    }

} // namespace eng
