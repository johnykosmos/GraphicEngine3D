#pragma once

#include <sstream>
#include <vector>
#include <string>
#include "Typedefs.hpp"
#include "GLBuffers.hpp"


namespace eng {
    
    
    /**
     * @class ModelParser
     * @brief Class responsible for parsing an OBJ model file and storing the parsed data.
     * 
     * This class handles reading data from an OBJ file, parsing vertices, normals, 
     * texture coordinates, and faces, and storing them in appropriate containers.
     * It also manages a vertex cache to avoid redundant vertex data.
     */
    class ModelParser {
        private:
            /**
             * @brief List of vertex positions.
             */
            std::vector<Vec3> positions;

            /**
             * @brief List of vertex normals.
             */
            std::vector<Vec3> normals; 

            /**
             * @brief List of texture coordinates.
             */
            std::vector<Vec2> texPositions;

            /**
             * @brief List of unique vertices constructed from positions, normals, and texture coordinates.
             */
            std::vector<Vertex> vertices;

            /**
             * @brief A cache to avoid redundant vertices by mapping vertex strings to indices.
             */
            std::unordered_map<std::string, unsigned int> vertexCache;

            /**
             * @brief A list of indices representing the faces of the model.
             */
            std::vector<unsigned int> indices;

        private:
            /**
             * @brief Reads a Vec2 (texture coordinates) from the given stream and stores it in the provided storage vector.
             * 
             * @param stream The input string stream containing the texture coordinates data.
             * @param storage The vector to store the parsed Vec2 data.
             */
            void readVec2(std::istringstream& stream, std::vector<Vec2>& storage);

            /**
             * @brief Reads a Vec3 (position or normal) from the given stream and stores it in the provided storage vector.
             * 
             * @param stream The input string stream containing the Vec3 data.
             * @param storage The vector to store the parsed Vec3 data.
             */
            void readVec3(std::istringstream& stream, std::vector<Vec3>& storage);

            /**
             * @brief Parses a vertex string and adds the corresponding vertex to the vertex list.
             * 
             * This function handles parsing the vertex format "v/vt/vn" and resolves the indices 
             * to the appropriate positions, normals, and texture coordinates.
             * 
             * @param vertexString The string representing the vertex in the "v/vt/vn" format.
             */
            void readVertex(const std::string& vertexString);

            /**
             * @brief Parses face data from the given stream and stores the face indices.
             * 
             * Faces are described by a set of vertex indices in the format "v/vt/vn". This function reads the face data,
             * resolves the vertex, texture, and normal indices, and stores them in the indices list.
             * 
             * @param stream The input string stream containing the face data.
             */
            void readFaces(std::istringstream& stream);

        public:
            /**
             * @brief Parses an OBJ file and extracts vertices, normals, texture coordinates, and faces.
             * 
             * This function reads the OBJ file, processes each line, and parses vertex, normal, texture, and face data.
             * The parsed data is stored in internal vectors and caches.
             * 
             * @param filename The path to the OBJ file to be parsed.
             * @return `true` if the file was successfully parsed, `false` otherwise.
             */
            bool parseFile(const std::string& filename);

            /**
             * @brief Retrieves the list of vertices parsed from the OBJ file.
             * 
             * @return The vector of vertices.
             */
            std::vector<Vertex> getVertices() const;

            /**
             * @brief Retrieves the list of indices representing the faces in the OBJ file.
             * 
             * @return The vector of face indices.
             */
            std::vector<unsigned int> getIndices() const;
    };



} // namespace eng
