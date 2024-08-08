#include <iostream>
#include <fstream>

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
    f << "solid "<<endl;
    for (int i = 0; i < numTriangles; i++) {
        float normal[3];
        getNormal(nodes[triangles[i][0]], nodes[triangles[i][1]], nodes[triangles[i][2]], normal);
        f << "facet normal " << normal[0] << " " << normal[1] << " " << normal[2] <<endl;
        f << "   outer loop"<<endl;
        for (int j = 0; j < 3; j++) {
            f << "vertex " << nodes[triangles[i][j]][0] << " " << nodes[triangles[i][j]][1] << " " << nodes[triangles[i][j]][2] << endl;
        }
        f << "   endloop" <<endl;
        f << "endfacet"<<endl; 
    }
    f << "endsolid \n";
}

int main() {
    float nodes[5][3] = {
        {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}, {0.5,0.5,0.7071}
    
    };
    int triangles[6][3] = {
      {1,4,0},{2,4,1},{2,3,4},{3,0,4},{0,2,1},{0,3,2}
    };
    const char* filename = "squarpyramid.stl";
   
    writeSTL_ASCII(5, 6, nodes, triangles, filename);

    return 0;
}
