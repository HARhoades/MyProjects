#ifndef LIGHT_H
#define LIGHT_H

#include "Vec3d.h"
#include "Vec4f.h"
#include "GL/freeglut.h"

class Light
{
    public:
        Light(int num);

        void enableLight();
        void disableLight();

        void makeLocal();       // Converts light into a local light source
        void makeInfDist();     // Converts light into a light at inf. distance

        void setPos(Vec3d newPos);
        void changePos(Vec3d deltaPos);
        void setRadialAtten(Vec3d newAtten);

        void setAmbCol(Vec3d newCol);
        void setDiffCol(Vec3d newCol);
        void setSpecCol(Vec3d newCol);

        void drawLight();

    protected:

    private:
        void setLight();

        int lightNum;

        Vec3d pos;
        Vec3d radAtten;
        Vec4f ambLight;
        Vec4f diffLight;
        Vec4f specLight;
        bool enabled;
        bool localLight;


};

#endif // LIGHT_H
