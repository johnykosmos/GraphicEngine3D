#pragma once

#include "Mesh.hpp"
#include <string>

namespace eng {


    /**
     * @class ModelLoader
     * @brief A utility class for loading 3D model data from an OBJ file.
     * 
     * The ModelLoader class is responsible for loading and parsing OBJ files, 
     * extracting the vertex positions, normals, texture coordinates, and face indices, 
     * and storing them into a Mesh object. It uses the ModelParser class to handle 
     * the parsing process and converts the parsed data into a format suitable for 
     * rendering.
     */
    class ModelLoader {
        public:
            /**
             * @brief Loads a 3D model from an OBJ file and updates the 
             * given Mesh with the parsed data.
             * 
             * @param filename The path to the OBJ file to be loaded.
             * @param modelMesh The Mesh object that will be updated with the loaded model data.
             * @return `true` if the model was successfully loaded and the Mesh was updated, 
             *         `false` otherwise.
             */
            static bool loadModel(const std::string& filename, Mesh& modelMesh);
    };


} // namespace eng 
