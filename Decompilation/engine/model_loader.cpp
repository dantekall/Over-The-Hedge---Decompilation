#include <vector>
#include <string>
#include <cstdint>

namespace EOREngine {
    struct Vector3 {
        float x, y, z;
    };

    struct Vector2 {
        float u, v;
    };

    struct Vertex {
        Vector3 position;
        Vector3 normal;
        Vector2 uv;
        uint32_t color; // RGBA packed color for PS2 GS
    };

    struct SubMesh {
        std::string materialName;
        std::vector<Vertex> vertices;
        std::vector<uint16_t> indices;
    };

    class ModelObject {
    private:
        std::string modelName;
        std::vector<SubMesh> subMeshes;
        bool isVisible;

    public:
        ModelObject(const std::string& name) : modelName(name), isVisible(true) {}

        void AddSubMesh(const SubMesh& mesh) {
            subMeshes.push_back(mesh);
        }

        void Render() {
            if (!isVisible) return;
            // Dispatches vertex data to the PS2 Graphics Synthesizer DMA pipeline
            for (const auto& subMesh : subMeshes) {
                // Render call stub for subMesh.vertices and subMesh.indices
            }
        }
    };
}