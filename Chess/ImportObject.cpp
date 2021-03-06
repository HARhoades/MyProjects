/* CS473: Computer Graphics
 * OpenGL .OBJ/.MTL file importer
 * Author: CPT Boyles
 */

#include "ImportObject.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "GL/freeglut.h"

/* Reads an .OBJ file and stores the resulting vertices and normal values
 * Ignores texture coordinates
 */
void ImportObject::readObj(std::string fName) {
    std::ifstream infile(fName.c_str());
    std::string line;
    int curMat = 0;     // Tracks current material being used to draw the object
    bool textFlag = false;

    // Push placeholder Vec3ds to vertices and normals;
    // Allows index numbers to align directly with the vertex# or normal#
    // from the .OBJ file.
    this->vertecies.push_back(Vec3d(-1.0, -1.0, -1.0));
    this->normals.push_back(Vec3d(-1.0, -1.0, -1.0));
    this->textures.push_back(Vec3d(0.0, 0.0, 0.0));
    // Reads from file line by line
    while (std::getline(infile, line)) {

        // .OBJ lines are prefixed to indicate what information they contain
        // We designate an input string stream to capture this prefix
        std::string linePrefix;
        std::istringstream iss(line, std::istringstream::in);
        iss >> linePrefix;

        // Vertex
        if (linePrefix == "v") {
            this->vertecies.push_back(this->getV3D(line));
        }

        // Vertex normal
        else if (linePrefix == "vn") {
            this->normals.push_back(this->getV3D(line));
        }

        // Vertex texture - ignored in this implementation

        //TODO
        else if (linePrefix == "vt") {
             this->textures.push_back(this->getTextVec(line));
        }

        // Switches the current material being used
        else if (linePrefix == "usemtl") {
            // Capture the name of the material
            std::string matName = line.substr(7);

            // Access our matAbbrev map to get the material # for this string
            curMat = this->matAbbrev.find(matName)->second;
        }

        // Face
        else if (linePrefix == "f") {
            Face newFace = Face();

            // We need to parse the line, starting after our prefix,
            // to get the vertex/normals for each corner of the face
            int indx = 2;
            while (indx != -1) {
                int nextDelim = line.find(" ", indx + 1);
                std::string chunk = line.substr(indx, nextDelim - indx);
                indx = nextDelim;

                // We need to break up our chunk around the //

                int indxA = chunk.find("/");
                int indxB = chunk.find_last_of("/");

                int text = -1;
                int vert = (int)strtol(chunk.substr(0, indxA).c_str(), NULL, 10);
                int norm = (int)strtol(chunk.substr(indxB + 1).c_str(), NULL, 10);

                if (indxA - indxB > 1) {
                    text = (int)strtol(chunk.substr(indxA,indxB).c_str(), NULL, 10);
                }

                newFace.addVertNorm(vert, norm, curMat, text);
            }
            this->faces.push_back(newFace);
        }
    }

    std::cout << fName << " file parsed.\n";
    std::cout << vertecies.size() << " vertecies parsed.\n";
    std::cout << textures.size() << " texture vertecies parsed.\n";
    std::cout << normals.size() << " normals parsed.\n";
    std::cout << faces.size() << " faces parsed.\n";

    infile.close();
}

/* Reads an .MTL file
 * Ignores everything except diffuse color values
 */
void ImportObject::readMatl(std::string fName) {
    std::ifstream infile(fName.c_str());
    std::string line;
    std::string linePrefix;
    std::string matName;
    Vec3d matValTracker[3] = {Vec3d(), Vec3d(), Vec3d()};
    int matCount = 0;           // Index of next material to be added

    while (std::getline(infile, line)) {
        std::istringstream iss(line, std::istringstream::in);
        iss >> linePrefix;

        if (linePrefix == "newmtl") {
            matName = line.substr(7);
        }
        else if (linePrefix == "Kd") {
            matValTracker[0] = getV3D(line);
        }
            // Updates our map with the name of the material as the key
            // and the value is an integer representing the material
            // Didn't implement a direct string to Vec3d map to make comparisons
            // quicker in the drawing phase (only need to compare one integer
            // to see if the color needs to be changed versus three doubles)
        else if (linePrefix == "Ka") {
            matValTracker[1] = getV3D(line);
        }

        else if (linePrefix == "Ks") {
            matValTracker[2] = getV3D(line);
        }

    }

    this->matAbbrev.insert(std::pair<std::string, int>(matName, matCount));
    this->materials.push_back(matValTracker[0]);
    this->materials.push_back(matValTracker[1]);
    this->materials.push_back(matValTracker[2]);

    matCount++;

    std::cout << fName << " parsed.\n";
    std::cout << matCount << " materials parsed.\n";

    infile.close();
}

/* Draws our object in the world
 *
 */
void ImportObject::drawObj(double xPos, double yPos) {
    if (!this->filesRead) {
        std::cout << "ERROR: Object not initialized.  Cannot draw.\n";\
        return;
    }

    glColor3f(1.0, 1.0, 1.0);
    int curMatNum = -1;

    // Goes through each face that has been read from the .OBJ file
    for (unsigned int i = 0; i < this->faces.size(); i ++) {
        Face curFace = this->faces.at(i);

        glBegin(GL_POLYGON);
        for (int v = 0; v < curFace.numVertecies(); v++) {

            // Gets the vertex and normal Vec3d for this corner of the polygon
            Vec3d vertex = this->vertecies.at(curFace.getFaceVert(v));
            vertex.x += xPos*2.5;
            vertex.z += yPos*2.5;
            Vec3d norm = this->normals.at(curFace.getFaceNorm(v));
            int textCheck = curFace.getFaceTexture(v);
            if (textCheck > -1) {
                Vec3d texture = this->textures.at(textCheck);
            }
            int matNum = curFace.getFaceMat(v);

            // Compare the material associated with this point to the
            // previous one used
            //TODO
            if (matNum != curMatNum) {
                curMatNum = matNum;
                Vec3d amb = this->materials.at(matNum*3+1);
                Vec3d spec = this->materials.at(matNum*3+2);
                Vec3d diff = this->materials.at(matNum*3); //Uses diffuse value
                glColor3f(diff.x, diff.y, diff.z);
                GLfloat ambient[] = {amb.x, amb.y, amb.z, 1.0};
                GLfloat specular[] = {spec.x, spec.y, spec.z, 1.0};
                GLfloat diffuse[] = {diff.x, diff.y, diff.z, 1.0};
                glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
                glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
                glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
                glMaterialf(GL_FRONT, GL_SHININESS, 1.0);
            }

            glNormal3d(norm.x, norm.y, norm.z);
            glVertex3d(vertex.x, vertex.y, vertex.z);
        }
        glEnd();
    }

}


void ImportObject::importAll(std::string baseName) {
    this->vertecies.clear();
    this->normals.clear();
    this->materials.clear();
    this->matAbbrev.clear();
    this->textures.clear();

    std::string matName = baseName + ".mtl";
    std::string objName = baseName + ".obj";
    this->readMatl(matName);
    this->readObj(objName);
    this->filesRead = true;     // Can now draw the object
}

ImportObject::ImportObject() {
    this->dlProcessed = false;
    this->filesRead = false;
}

void ImportObject::initObjDL() {
    if (!this->filesRead) {
        std::cout << "ERROR: Object not initialized.  Cannot store as display list.\n";\
        return;
    }
    this->dlNumber = glGenLists(1);
    glNewList(this->dlNumber, GL_COMPILE);
    this->drawObj(0, 0);
    glEndList();
    this->dlProcessed = true;
}

void ImportObject::drawObjDL() {
    if (!this->dlProcessed) {
        this->initObjDL();
    }
    glCallList(this->dlNumber);
}



Vec3d ImportObject::getV3D(std::string line) {
    int indexX = line.find(" ", 0) + 1;
    int indexY = line.find(" ", indexX) + 1;
    int indexZ = line.find(" ", indexY) + 1;
    double x = strtod(line.substr(indexX, line.find(" ", indexX)).c_str(), NULL);
    double y = strtod(line.substr(indexY, line.find(" ", indexY)).c_str(), NULL);
    double z = strtod(line.substr(indexZ, line.find (" ", indexZ)).c_str(), NULL);
    return Vec3d(x, y, z);
}

Vec3d ImportObject::getTextVec(std::string line) {
    int indexX = line.find(" ", 0) + 1;
    int indexY = line.find(" ", indexX) + 1;
    double x = strtod(line.substr(indexX, line.find(" ", indexX)).c_str(), NULL);
    double y = strtod(line.substr(indexY, line.find(" ", indexY)).c_str(), NULL);
    return Vec3d(x, y, 0.0);
}

// Face class

Face::Face() {
}

void Face::addVertNorm(int vertexNum, int normNum, int matNum, int textNum) {
    this->faceVert.push_back(vertexNum);
    this->faceNorm.push_back(normNum);
    this->faceMat.push_back(matNum);
    this->faceText.push_back(textNum);
}

int Face::getFaceVert(int num) {
    return this->faceVert.at(num);
}

int Face::getFaceNorm(int num) {
    return this->faceNorm.at(num);
}

int Face::getFaceTexture(int num) {
    return this->faceText.at(num);
}

int Face::getFaceMat(int num) {
    return this->faceMat.at(num);
}

int Face::numVertecies() {
    return this->faceVert.size();
}

