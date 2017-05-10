#include "Board.h"
#include "GamePiece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "ImportObject.h"
#include "Camera.h"
#include "Light.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int frameRate = 60;     // Limit on FPS rate
int frameRateMS = 1000 / frameRate;

int windowSize[] = {800, 800};
double orthoSize[] = {5.0, 5.0};
int lastFrame = 0;

Board * gameboard = new Board();
Camera cam = Camera();
Light topLight = Light(0);
Light sideLight = Light(1);
vector<GamePiece*> pieceArray;


void initGame(){
    gameboard->initBoard();
    cam.moveCameraTo(Vec3d(0, 30, -15));
    cam.cameraLookAt(Vec3d(0,0,0));
    int colorCounter;
    for(int counter=0; counter<32; counter++){
        colorCounter = (counter % 16) + 1;
        if (colorCounter == 1 || colorCounter == 8) pieceArray.push_back(new Rook());
        if (colorCounter == 2 || colorCounter == 7) pieceArray.push_back(new Knight());
        if (colorCounter == 3 || colorCounter == 6) pieceArray.push_back(new Bishop());
        if (colorCounter == 4) pieceArray.push_back(new Queen());
        if (colorCounter == 5) pieceArray.push_back(new King());
        if (colorCounter > 8) pieceArray.push_back(new Pawn());

        if (counter < 16) {
                pieceArray.at(counter)->setColor(true);
                pieceArray.at(counter)->setY(counter/8); //White pawns at row 1, all other white at row 0
                pieceArray.at(counter)->import.importAll("white"+pieceArray.at(counter)->pieceName);
        }
        else {
                pieceArray.at(counter)->setColor(false);
                pieceArray.at(counter)->setY(8 - (counter/24)); //Black pawns at row 7, all other black at row 8
                pieceArray.at(counter)->import.importAll("black"+pieceArray.at(counter)->pieceName);

        }
        pieceArray.at(counter)->setX(counter%8); //Sets all pieces to starting column
    }
    topLight.enableLight();
	topLight.makeInfDist();
    topLight.setAmbCol(Vec3d(.1, .1, .1));
    topLight.setDiffCol(Vec3d(.7, .7, .7));
    topLight.setSpecCol(Vec3d(.5, .5, .5));
    topLight.setPos(Vec3d(0.0, 0.0, 0.0));
    topLight.setRadialAtten(Vec3d(.50, .10, 0.0));

    sideLight.enableLight();
	sideLight.makeLocal();
    sideLight.setAmbCol(Vec3d(.1, .1, .1));
    sideLight.setDiffCol(Vec3d(1.0, 1.0, 1.0));
    sideLight.setSpecCol(Vec3d(1.0, 1.0, 1.0));
    sideLight.setPos(Vec3d(0.0, 2.5, -10.0));
    sideLight.setRadialAtten(Vec3d(.50, .10, 0.0));
}

void testHarness()
{
    Pawn p = Pawn();
    Knight k = Knight();
    Bishop b = Bishop();
    Rook r = Rook();
    Queen q = Queen();
    King ki = King();
    cout << p.pieceName << endl;
    cout << k.pieceName << endl;
    cout << b.pieceName << endl;
    cout << r.pieceName << endl;
    cout << q.pieceName << endl;
    cout << ki.pieceName << endl;
    cout << gameboard->boardArray[0][2] << endl;
    p.setColor(true);
    p.movePieceTo(1,1);
    cout << !p.captureTargetSquare(6,2) << endl;
    p.setColor(false);
    cout << p.captureTargetSquare(0,0) << endl;
    b.setColor(true);
    b.movePieceTo(4,4);
    cout << b.captureTargetSquare(1,1) << endl;
    cout << !b.captureTargetSquare(4, 7) << endl;

    for (int testCount=0; testCount<32; testCount++){
        cout << pieceArray.at(testCount)->pieceName << endl;
        cout << pieceArray.at(testCount)->getColor() << endl;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cam.setView();
	for (int k=0; k<pieceArray.size(); k++) {
        pieceArray.at(k)->import.drawObj(pieceArray.at(k)->getX(), pieceArray.at(k)->getY());
	}
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	glutSwapBuffers();
}

void idle() {}

int main(int argc, char** argv) {
    initGame();
    //testHarness();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowSize[0], windowSize[1]);
	glutInitWindowPosition(700, 0);
	glutCreateWindow("3D Chess");
	lastFrame = glutGet(GLUT_ELAPSED_TIME);
	glutDisplayFunc(display);
	//glutKeyboardFunc(keyboard);
    //glutMouseFunc(mouse);
    //glutMotionFunc(mouseMotion);

    //glutIdleFunc(idle);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);

	glutMainLoop();
}
