#include <iostream>
#include <fstream>
#include <cmath> 

using namespace std;

void getNormal(float p1[3], float p2[3], float p3[3], float normal[3]) {
    float v1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
    float v2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
    normal[0] = v1[1] * v2[2] - v1[2] * v2[1];
    normal[1] = v1[2] * v2[0] - v1[0] * v2[2];
    normal[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void writeSTL_ASCII(int numNodes, int numTriangles, float nodes[][3], int triangles[][3], const char* filename) {
    ofstream f(filename);
    f << "solid cylinder" << endl;
    for (int i = 0; i < numTriangles; i++) {
        float normal[3];
        getNormal(nodes[triangles[i][0]], nodes[triangles[i][1]], nodes[triangles[i][2]], normal);
        f << "facet normal " << normal[0] << " " << normal[1] << " " << normal[2] << endl;
        f << "   outer loop" << endl;
        for (int j = 0; j < 3; j++) {
            f << "vertex " << nodes[triangles[i][j]][0] << " " << nodes[triangles[i][j]][1] << " " << nodes[triangles[i][j]][2] << endl;
        }
        f << "   endloop" << endl;
        f << "endfacet" << endl; 
    }
    f << "endsolid cylinder" << endl;
}
int main() {
    const  int numSegments = 20; // Increase for smoother sphere
    const float radius = 1.0f;
    
    const  int numNodes = numSegments * (numSegments - 1) + 2; // Vertices plus poles
    const  int numTriangles = 2 * numSegments * (numSegments - 1); // Triangles for the sphere
    
    float nodes[numNodes][3];
  int triangles[numTriangles][3];
     
    int vertexCount = 0;

    // Top pole
    nodes[vertexCount][0] = 0.0f;
    nodes[vertexCount][1] = 0.0f;
    nodes[vertexCount][2] = radius;
    vertexCount++;

    // Latitude rings
    for (int i = 1; i < numSegments; ++i) {
        float theta = M_PI * i / numSegments;
        float z = radius * cos(theta);
        float ringRadius = radius * sin(theta);
        for (int j = 0; j < numSegments; ++j) {
            float phi = 2.0f * M_PI * j / numSegments;
            nodes[vertexCount][0] = ringRadius * cos(phi);
            nodes[vertexCount][1] = ringRadius * sin(phi);
            nodes[vertexCount][2] = z;
            vertexCount++;
        }
    }

    // Bottom pole
    nodes[vertexCount][0] = 0.0f;
    nodes[vertexCount][1] = 0.0f;
    nodes[vertexCount][2] = -radius;
    vertexCount++;

    int triangleCount = 0;

    // Top cap
    for (int j = 0; j < numSegments; ++j) {
        triangles[triangleCount][0] = 0;
        triangles[triangleCount][1] = j + 1;
        triangles[triangleCount][2] = (j + 1) % numSegments + 1;
        triangleCount++;
    }

    // Body
    for (int i = 1; i < numSegments - 1; ++i) {
        for (int j = 0; j < numSegments; ++j) {
            int current = (i - 1) * numSegments + j + 1;
            int next = (i - 1) * numSegments + (j + 1) % numSegments + 1;
            int below_current = i * numSegments + j + 1;
            int below_next = i * numSegments + (j + 1) % numSegments + 1;

            triangles[triangleCount][0] = current;
            triangles[triangleCount][1] = below_current;
            triangles[triangleCount][2] = below_next;
            triangleCount++;

            triangles[triangleCount][0] = current;
            triangles[triangleCount][1] = below_next;
            triangles[triangleCount][2] = next;
            triangleCount++;
        }
    }

    // Bottom cap
    int lastRowStart = (numSegments - 2) * numSegments + 1;
    for (int j = 0; j < numSegments; ++j) {
        triangles[triangleCount][0] = numNodes - 1;
        
        triangles[triangleCount][1] = lastRowStart + (j + 1) % numSegments;
        triangles[triangleCount][2] = lastRowStart + j;
        triangleCount++;
    }

    const char* filename = "sphere.stl";
    writeSTL_ASCII(numNodes, numTriangles, nodes, triangles, filename);

    return 0;
}
