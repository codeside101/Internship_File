#include <iostream>
#include <fstream>

using namespace std;

void getNormal(float p1[3], float p2[3], float p3[3], float normal[3])
{
    float v1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
    float v2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
    normal[0] = v1[1] * v2[2] - v1[2] * v2[1];
    normal[1] = v1[2] * v2[0] - v1[0] * v2[2];
    normal[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void writeSTL_ASCII(int numNodes, int numTriangles, float nodes[][3], int triangles[][3], const char *filename)
{
    ofstream f(filename);
    f << "solid " << endl;
    for (int i = 0; i < numTriangles; i++)
    {
        float normal[3];
        getNormal(nodes[triangles[i][0]], nodes[triangles[i][1]], nodes[triangles[i][2]], normal);
        f << "facet normal " << normal[0] << " " << normal[1] << " " << normal[2] << endl;
        f << "   outer loop" << endl;
        for (int j = 0; j < 3; j++)
        {
            f << "vertex " << nodes[triangles[i][j]][0] << " " << nodes[triangles[i][j]][1] << " " << nodes[triangles[i][j]][2] << endl;
        }
        f << "   endloop" << endl;
        f << "endfacet" << endl;
    }
    f << "endsolid " << endl;
}

int main()
{
    float origin[3];
    float length, width, height;

    cout << "Enter the origin coordinates (x, y, z): ";
    cin >> origin[0] >> origin[1] >> origin[2];

    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << "Enter the height of the rectangle: ";
    cin >> height;

    float nodes[8][3] = {
        {origin[0], origin[1], origin[2]},
        {origin[0] + length, origin[1], origin[2]},
        {origin[0] + length, origin[1] + width, origin[2]},
        {origin[0], origin[1] + width, origin[2]},
        {origin[0], origin[1], origin[2] + height},
        {origin[0] + length, origin[1], origin[2] + height},
        {origin[0] + length, origin[1] + width, origin[2] + height},
        {origin[0], origin[1] + width, origin[2] + height}};

    int triangles[12][3] = {
        {0, 1, 5}, {0, 5, 4}, {1, 2, 6}, {1, 6, 5}, {2, 3, 7}, {2, 7, 6}, {3, 0, 4}, {3, 4, 7},{4, 5,6}, {4,6,7} ,{0, 2, 1}, {0, 3, 2} };

    const char *filename = "rectangle.stl";
    writeSTL_ASCII(8, 12, nodes, triangles, filename);

    return 0;
}
