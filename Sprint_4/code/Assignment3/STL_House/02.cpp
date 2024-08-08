#include <iostream>
#include <fstream>
#include"getnormal.h"

using namespace std;



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
    float nodes[9][3] = {
        {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0},{0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1},
         {.5, .5, 1.5}
    };
    int triangles[14][3] = {
        {0, 1, 4}, {4, 1, 5}, {1, 2, 6}, {1,6,5},
        {0, 7,3}, {0, 4, 7}, {2, 3, 7}, {2, 7,6},
        {0, 2,1}, {0, 3, 2}, {4, 5,8}, {5, 6,8},
        {4, 8,7}, {6, 7,8}
    };
    const char* filename = "house.stl";
   
    writeSTL_ASCII(9, 14, nodes, triangles, filename);

    return 0;
}
