#include <iostream>
#include <fstream>
#include <vector>
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
    f << "solid " << endl;
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
    f << "endsolid " << endl;
}

int main() {
    const int numSegments = 120; 
    const float radius = 1.0f;  
    const float height = 2.0f;   
   
    const int numNodes = numSegments + 1;
    const int numTriangles = numSegments; 


    float nodes[numNodes][3];
    int triangles[numTriangles][3];

 
    nodes[0][0] = 0.0f;
    nodes[0][1] = 0.0f;
    nodes[0][2] = height;

 
    for (int i = 0; i < numSegments; ++i) {
        float angle = 2.0f * M_PI * i / numSegments;
        nodes[i + 1][0] = radius * cos(angle);
        nodes[i + 1][1] = radius * sin(angle);
        nodes[i + 1][2] = 0.0f;
    }


    for (int i = 0; i < numSegments; ++i) {
        triangles[i][0] = 0;  
        triangles[i][1] = 1 + i;
        triangles[i][2] = 1 + (i + 1) % numSegments;
    }

    const char* filename = "coneWObase.stl";
    writeSTL_ASCII(numNodes, numTriangles, nodes, triangles, filename);

    return 0;
}
