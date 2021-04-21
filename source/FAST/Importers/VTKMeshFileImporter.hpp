#pragma once

#include "Importer.hpp"
#include <string>
#include <map>
#include <FAST/Data/MeshVertex.hpp>

namespace fast {

/**
 * @brief Reads gemoetry mesh data from a .vtk polydata file.
 *
 * This importer reads geometry data such as vertices, lines and triangles from the VTK polydata format (.vtk) and
 * outputs it as a FAST Mesh.
 *
 * - Output 0: Mesh
 *
 * @ingroup importers
 */
class FAST_EXPORT  VTKMeshFileImporter : public Importer {
    FAST_OBJECT(VTKMeshFileImporter)
    public:
        void setFilename(std::string filename);
    private:
        VTKMeshFileImporter();
        void execute();

        void processPoints(std::ifstream& file, std::string& line);
        void processLines(std::ifstream& file, std::string& line);
        void processTriangles(std::ifstream& file, std::string& line);
        void processNormals(std::ifstream& file, std::string& line);
        void processVectors(std::ifstream& file, std::string& line);

        std::string mFilename;
        std::vector<MeshVertex> mVertices;
        std::vector<MeshLine> mLines;
        std::vector<MeshTriangle> mTriangles;
        std::map<std::string, std::function<void(std::ifstream&, std::string&)>> mFunctions;
};

} // end namespace fast
