# include "iGraphics.h"
#include<math.h>
struct Position
{
 long int x, y,dx,dy;
}meteor,asteroid,rocket;

long int rocket.x=-3;
long int rocket.y=300;
long int rocket.dx=2;

int i;
int T;
int Cdp=5;//Controlled position changer
char Space[200]={"Space3_1.bmp"};
int SpaceIndex=0;
char Meteor[4][100]={"Fireball_R.bmp","Fireball_U.bmp","Fireball_L.bmp","Fireball_D.bmp"};
int MeteorIndex=0;
char Asteroid[4][100]={"Asteroid1.bmp","Asteroid2.bmp","Asteroid3.bmp","Asteroid4.bmp"};
int AsteroidIndex=0;
char Planet[2][20]={"Mercury1.bmp","Mercury2.bmp"};
int PlanetIndex=0;
char Rocket[4][100]={"Rocket2_R.bmp","Rocket2_U.bmp","Rocket2_L.bmp","Rocket2_D.bmp"};
int RocketIndex=0;
bool CollisionStatus=false;

void iDraw()
{

    iClear();



    iShowBMP(0,0,Space);//screen

    iShowBMP2(rocket.x,rocket.y,Rocket[RocketIndex],0);//rocket
    iShowBMP2(310,310,Planet[PlanetIndex],255);//planet


    for(i=0;i<4;i++)
    {
        if(i==0)
        {
        iShowBMP2(asteroid.x,asteroid.y,Asteroid[AsteroidIndex],0);
        iShowBMP2(meteor.x,meteor.y,Meteor[MeteorIndex],0);
        }
        else if(i==1)
        {
        iShowBMP2(asteroid.x,asteroid.y,Asteroid[AsteroidIndex],0);
        iShowBMP2(meteor.x,meteor.y,Meteor[MeteorIndex],0);
        }
        else if(i==2)
        {
        iShowBMP2(asteroid.x,asteroid.y,Asteroid[AsteroidIndex],0);
        iShowBMP2(meteor.x,meteor.y,Meteor[MeteorIndex],0);
        }
        else if(i==3)
        {
        iShowBMP2(asteroid.x,asteroid.y,Asteroid[AsteroidIndex],0);
        }
        else
        {
        iShowBMP2(asteroid.x,asteroid.y,Asteroid[AsteroidIndex],0);
        }
    }


    iSetColor(255,0,0);
    iCircle(500,420,200);//Gravitational Territory
    iSetColor(0,0,0);
    iFilledCircle(900,600,100);//Blackhole

    iSetColor(rand()%255,rand()%255,rand()%255);
    iText(450,540,"MERCURY",GLUT_BITMAP_TIMES_ROMAN_24);//Planet Marker
    iText(0,50,"Press F1 to start",GLUT_BITMAP_TIMES_ROMAN_24);
}


void iMouseMove(int mx, int my)
{


}

void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {


    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {


    }
}


void iKeyboard(unsigned char key)
{


    //place your codes for other keys here
}


void start()
{

    rocket.x+= rocket.dx;
    PlaySound("CraftMotion.wav",NULL,SND_LOOP|SND_ASYNC);
}
void iSpecialKeyboard(unsigned char key)
{
if(key != GLUT_KEY_F1)
    {

    }
else
    {
    T=iSetTimer(100,start);
    }


    if(key == GLUT_KEY_UP)
    {
    RocketIndex=1;
    rocket.y+=Cdp;
    }
    else if(key == GLUT_KEY_DOWN)
    {   RocketIndex=3;
        rocket.y-=Cdp;
    }
    else if(key == GLUT_KEY_RIGHT)
    {
     RocketIndex=0;
     rocket.x+=Cdp;
    }
    else if(key == GLUT_KEY_LEFT)
    {
      RocketIndex=2;
      rocket.x-=Cdp;
    }


}



void PositionChange()
{
    meteor.x+=meteor.dx;
    meteor.y+=meteor.dy;

    asteroid.x+=asteroid.dx;
    asteroid.y+=asteroid.dy;

    if(asteroid.x>=1300 || asteroid.x<=0)
    {
      asteroid.dx*=-1;
    }

    if(asteroid.y>=750 ||  asteroid.y<=0 )
    {
      asteroid.dy*=-1;

    }



    if(meteor.x>=1300 || meteor.x<=0)
    {
      meteor.dx*=-1;


    }

    if(meteor.y>=750 ||  meteor.y<=0)
    {
      meteor.dy*=-1;

    }

    if((pow(rocket.y-420,2)<=40000-pow(rocket.x-420,2))||
        (pow(rocket.y-600,2)<=10000-pow(rocket.x-900,2)))
    {
        iPauseTimer(T);
        Cdp=0;
        if(rocket.x>500 || rocket.x>900) rocket.x--;
        if(rocket.x<500 || rocket.x<900) rocket.x++;
        if(rocket.y>405 || rocket.y>585) rocket.y--;
        if(rocket.y<405 || rocket.y<585) rocket.y++;
    }
    if(fabs(rocket.x-meteor.x)<=152 && fabs(rocket.y-meteor.y)<=159)
    {
        CollisionStatus=true;

    }
}
void Rotation()
{
 PlanetIndex++;
 if(PlanetIndex>1)
 PlanetIndex=0;

}







int main()
{
    //PlaySound("GameOver.wav",NULL,SND_LOOP|SND_ASYNC);

    iSetTimer(120,PositionChange);
    iSetTimer(100,Rotation);
    /*iSetTimer(100,appear);
    iSetTimer(100,Animation);*/

    iInitialize(1200,700 , "GALAXY TRAVEL");
    return 0;
}
