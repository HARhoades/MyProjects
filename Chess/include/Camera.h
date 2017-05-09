#ifndef CAMERA_H
#define CAMERA_H

#include "Vec3d.h"

class Camera
{
    public:
        Camera();

        void moveCameraTo(Vec3d newPos);
        void moveCameraBy(Vec3d deltaPos);
        void cameraLookAt(Vec3d lookPos);
        void cameraPan(Vec3d lookPos, double azimuth, double dist, double elev);

        void setUpVec(Vec3d newVec);
        void changeDist(double mag);
        double findAzimuth();
        double findDist();

        Vec3d getPos();
        Vec3d getLook();

        void setView();
        void setClip(double nearC, double farC);
        void setFOV(double fov);

        double zoomDist;

    private:
        Vec3d pos;
        Vec3d lookAt;
        Vec3d upVec;

        double aspectRatio;
        double camFOV;
        double nearClip;
        double farClip;

        void setAspect(double newAspect);
        void setAspectByScreen();

};

#endif // CAMERA_H
