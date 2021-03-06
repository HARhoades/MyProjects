/* CS473: Computer Graphics
 * OpenGL .OBJ/.MTL file importer
 * Author: CPT Boyles
 */

#ifndef IMPORTOBJECT_H
#define IMPORTOBJECT_H

#include <string>
#include <vector>
#include <map>
#include "Vec3d.h"
#include "GL/freeglut.h"

class Face
{
    public:
        Face();
        void addVertNorm(int vertexNum, int normNum, int matNum, int textNum);
        int getFaceVert(int num);
        int getFaceNorm(int num);
        int getFaceMat(int num);
        int getFaceTexture(int num);
        int numVertecies();

    private:
        std::vector<int> faceVert;
        std::vector<int> faceText;
        std::vector<int> faceNorm;
        std::vector<int> faceMat;
};

class ImportObject
{
    public:
        ImportObject();
        void importAll(std::string name_without_extension);
        void initObjDL();
        void drawObj(double xPos, double yPos);
        void drawObjDL();

    protected:

    private:
        void readMatl(std::string fName);
        void readObj(std::string fName);

        bool filesRead;
        bool dlProcessed;

        GLuint dlNumber;

        std::vector<Vec3d> vertecies;
        std::vector<Vec3d> normals;
        std::vector<Vec3d> textures;
        std::vector<Face> faces;
        std::map<std::string, int> matAbbrev;
        std::vector<Vec3d> materials;

        Vec3d getV3D(std::string line);
        Vec3d getTextVec(std::string line);

};



#endif // IMPORTOBJECT_H
