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
    const int numSegments = 24;  // number of segments for the base of the cylinder
    const float radius = 1.0f;   // radius of the base
    const float height = 2.0f;   // hight of the cylinder

    const int numNodes = 2 * numSegments + 2; // top and bottom circle vertices plus centers
    const int numSideTriangles = 2 * numSegments; // side triangles
    const int numCapTriangles = numSegments; // triangles for each cap (top and bottom)
    const int numTriangles = numSideTriangles + 2 * numCapTriangles;

    float nodes[numNodes][3];
    int triangles[numTriangles][3];

    // calculate the top circle nclodes
    for (int i = 0; i < numSegments; ++i) {
        float angle = 2.0f * M_PI * i / numSegments;
        nodes[i][0] = radius * cos(angle);
        nodes[i][1] = radius * sin(angle);
        nodes[i][2] = height;
    }

    // calculate the bottom circle nodes
    for (int i = 0; i < numSegments; ++i) {
        float angle = 2.0f * M_PI * i / numSegments;
        nodes[i + numSegments][0] = radius * cos(angle);
        nodes[i + numSegments][1] = radius * sin(angle);
        nodes[i + numSegments][2] = 0.0f;
    }

    // add the center node for the top face
    nodes[2 * numSegments][0] = 0.0f;
    nodes[2 * numSegments][1] = 0.0f;
    nodes[2 * numSegments][2] = height;

    // add the center node for the bottom face
    nodes[2 * numSegments + 1][0] = 0.0f;
    nodes[2 * numSegments + 1][1] = 0.0f;
    nodes[2 * numSegments + 1][2] = 0.0f;

    // define the side triangles
    for (int i = 0; i < numSegments; ++i) {
        // first triangle of the segment
        triangles[2 * i][0] = i;
        triangles[2 * i][1] = (i + 1) % numSegments;
        triangles[2 * i][2] = i + numSegments;

        // second triangle of the segment
        triangles[2 * i + 1][0] = (i + 1) % numSegments;
        triangles[2 * i + 1][1] = (i + 1) % numSegments + numSegments;
        triangles[2 * i + 1][2] = i + numSegments;
    }

    // define the top cap triangles
    for (int i = 0; i < numSegments; ++i) {
        triangles[numSideTriangles + i][0] = i;
        triangles[numSideTriangles + i][1] = (i + 1) % numSegments;
        triangles[numSideTriangles + i][2] = 2 * numSegments;
    }

    // define the bottom cap triangles
    for (int i = 0; i < numSegments; ++i) {
        triangles[numSideTriangles + numCapTriangles + i][0] = i + numSegments;
        triangles[numSideTriangles + numCapTriangles + i][1] = (i + 1) % numSegments + numSegments;
        triangles[numSideTriangles + numCapTriangles + i][2] = 2 * numSegments + 1;
    }

    const char* filename = "cylinder.stl";
    writeSTL_ASCII(numNodes, numTriangles, nodes, triangles, filename);

    return 0;
}
