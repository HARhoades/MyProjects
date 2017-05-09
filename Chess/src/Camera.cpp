#include <cmath>
#include <iostream>

#include "stdio.h"
#include "GL/freeglut.h"
#include "Helpers.h"
#include "Camera.h"
#include "math.h"

using namespace std;

Camera::Camera(){
    this->moveCameraTo(Vec3d(0.0, 10.0, 20.0));
    this->cameraLookAt(Vec3d(0.0, 0.0, 0.0));
    this->setFOV(90.0);
    this->setClip(0.1, 100.0);
    this->setUpVec(Vec3d(0.0, 1.0, 0.0));
    this->zoomDist = 0.5;
}

void Camera::moveCameraTo(Vec3d newPos) {
    this->pos = newPos;
}

void Camera::moveCameraBy(Vec3d deltaPos) {
    this->pos.x += deltaPos.x;
    this->pos.y += deltaPos.y;
    this->pos.z += deltaPos.z;
}

void Camera::cameraLookAt(Vec3d lookPos) {
    this->lookAt = lookPos;
}

void Camera::setUpVec(Vec3d newVec) {
    this->upVec = newVec;
}

void Camera::changeDist(double mag) {
    this->pos.x = cos(toRadians(this->findAzimuth()))*mag;
    this->pos.z = sin(toRadians(this->findAzimuth()))*mag;
}

Vec3d Camera::getPos() {
    return this->pos;
}

Vec3d Camera::getLook() {
    return this->lookAt;
}

double Camera::findDist() {
    return sqrt(pow((this->pos.z - this->lookAt.z), 2) + pow((this->pos.x - this->lookAt.x), 2)); //+ pow((this->pos.y - this->lookAt.y), 2));
}

double Camera::findAzimuth(){
    double xVal = this->pos.x - this->lookAt.x;
    if (xVal == 0) xVal = .01;
    double zVal = this->pos.z - this->lookAt.z;
    double temp = atan(zVal/xVal) - M_PI_2;
   // if(temp == NULL) temp = 0;
    return temp;
}

void Camera::cameraPan(Vec3d lookPos, double azimuth, double dist, double elev) {
    this->lookAt = lookPos;

    //double verticalAngle = atan( fmod((elev / dist), M_PI) );
    double newX = (sin((azimuth)) * dist) + lookPos.x;
    double newY = elev;
    double newZ = (cos((azimuth))* dist) + lookPos.z;
    moveCameraTo(Vec3d(newX, newY, newZ));
    cameraLookAt(this->lookAt);
}

void Camera::setView() {
    this->setAspectByScreen();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(this->camFOV, this->aspectRatio, this->nearClip, this->farClip);
    gluLookAt(this->pos.x, this->pos.y, this->pos.z,
              this->lookAt.x, this->lookAt.y, this->lookAt.z,
              this->upVec.x, this->upVec.y, this->upVec.z);

    glutPostRedisplay();
}

void Camera::setClip(double nearC, double farC) {
    this->nearClip = nearC;
    this->farClip = farC;
}

void Camera::setFOV(double fov) {
    if (fov > 0 && fov <= 180) this->camFOV = fov;
}

void Camera::setAspect(double newAspect) {
    this->aspectRatio = newAspect;
}

void Camera::setAspectByScreen() {
    double actualRatio = glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT);
    this->setAspect(actualRatio);
}
