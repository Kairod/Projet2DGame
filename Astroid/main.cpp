#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
// bibliotheque dans /usr/include/SFML/
#include <time.h>
#include <list>
#include <iostream>

using namespace sf;

const int W = 1200;
const int H = 800;

float DEGTORAD = 0.017453f;


class Animation
{
public:
	float Frame, speed;
	Sprite sprite;
    std::vector<IntRect> frames;

	Animation(){}

    Animation (Texture &t, int x, int y, int w, int h, int count, float Speed)
	{
	    Frame = 0;
      speed = Speed;

		for (int i=0;i<count;i++)
         frames.push_back( IntRect(x+i*w, y, w, h)  );

		sprite.setTexture(t);
		sprite.setOrigin(w/2,h/2);
        sprite.setTextureRect(frames[0]);
	}


	void update()
	{
    	Frame += speed;
		int n = frames.size();
		if (Frame >= n) Frame -= n;
		if (n>0) sprite.setTextureRect( frames[int(Frame)] );
	}

	bool isEnd()
	{
	  return Frame+speed>=frames.size();
	}

};


class Entity
{
public:
float x,y,dx,dy,R,angle;
bool life;
std::string name;
Animation anim;

Entity()
{
  life=1;
}

void settings(Animation &a,int X,int Y,float Angle=0,int radius=1)
{
  anim = a;
  x=X; y=Y;
  angle = Angle;
  R = radius;
}

virtual void update(){};

void draw(RenderWindow &app)
{
  anim.sprite.setPosition(x,y);
  anim.sprite.setRotation(angle+90);
  app.draw(anim.sprite);

  CircleShape circle(R);
  circle.setFillColor(Color(255,0,0,170));
  circle.setPosition(x,y);
  circle.setOrigin(R,R);
  //app.draw(circle);
}

virtual ~Entity(){};
};


class asteroid: public Entity
{
public:
  asteroid()
  {
    dx=rand()%8-4;
    dy=rand()%8-4;
    name="asteroid";
  }

void  update()
  {
   x+=dx;
   y+=dy;

   if (x>W) x=0;  if (x<0) x=W;
   if (y>H) y=0;  if (y<0) y=H;
  }

};



class bullet: public Entity
{
public:
  bullet()
  {
    name="bullet";
  }

void  update()
  {
   dx=cos(angle*DEGTORAD)*6;
   dy=sin(angle*DEGTORAD)*6;
  // angle+=rand()%6-3;
   x+=dx;
   y+=dy;

   if (x>W || x<0 || y>H || y<0) life=0;
  }

};


class player: public Entity
{
public:
   bool thrust;

   player()
   {
     name="player";
   }

   void update()
   {
     if (thrust)
      { dx+=cos(angle*DEGTORAD)*0.2;
        dy+=sin(angle*DEGTORAD)*0.2; }
     else
      { dx*=0.99;
        dy*=0.99; }

    int maxSpeed=15;
    float speed = sqrt(dx*dx+dy*dy);
    if (speed>maxSpeed)
     { dx *= maxSpeed/speed;
       dy *= maxSpeed/speed; }

    x+=dx;
    y+=dy;

    if (x>W) x=0; if (x<0) x=W;
    if (y>H) y=0; if (y<0) y=H;
   }

};


bool isCollide(Entity *a,Entity *b)
{
  return (b->x - a->x)*(b->x - a->x)+
         (b->y - a->y)*(b->y - a->y)<
         (a->R + b->R)*(a->R + b->R);
}


int main()
{
    srand(time(0));
    int nbRand = rand()%2;
	//
    sf::Music music[10];
    // if (!music[0].openFromFile("./music/makeOnMove.ogg"))
    //     return -1; // erreur
    // if (!music[1].openFromFile("./music/FallenWorld.ogg"))
    //     return -1; // erreur
    if (!music[0].openFromFile("./music/FuryOfTheStorm.ogg"))
        return -1; // erreur
    if (!music[1].openFromFile("./music/HeroesOfOurTime.ogg"))
        return -1; // erreur
    // if (!music[4].openFromFile("./music/ReasonsToLive.ogg"))
    //     return -1; // erreur
    // if (!music[5].openFromFile("./music/Seasons.ogg"))
    //     return -1; // erreur
    // if (!music[6].openFromFile("./music/Starfire.ogg"))
    //     return -1; // erreur
    // if (!music[7].openFromFile("./music/ThroughTheFireAndFlames.ogg"))
    //     return -1; // erreur
    // if (!music[8].openFromFile("./music/ValleyOfTheDamned.ogg"))
    //     return -1; // erreur
    // if (!music[9].openFromFile("./music/WingsofLiberty.ogg"))
    //     return -1; // erreur

    sf::Music tir;
    if(!tir.openFromFile("./sound/soundTir.ogg"))
	return -1;

    sf::Music explosion;
    if(!explosion.openFromFile("./sound/explosion.ogg"))
	return -1;
    sf::Music boum;
    if(!boum.openFromFile("./sound/explosion.ogg"))
	return -1;


    RenderWindow app(VideoMode(W, H), "Asteroids!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3,t3Bis,t4,t5,t6,t7, t7Bis;
    t1.loadFromFile("images/spaceship.png");
    t2.loadFromFile("images/background.jpg");
    t3.loadFromFile("images/explosions/type_C.png");
		//t3Bis.loadFromFile("images/explosions/type_C-2.png");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_red.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B-1.png");
		t7Bis.loadFromFile("images/explosions/type_B-2.png");

    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);

    // Animation sExplosion(t3, 0,0,256,256, 48, 0.5);
		Animation sExplosion(t3, 0,0,256,256, 24, 0.5);
		//Animation sExplosionBis(t3Bis, 0,0,256,256, 24, 0.5);
    Animation sRock(t4, 0,0,64,64, 16, 0.2);
    Animation sRock_small(t6, 0,0,64,64, 16, 0.2);
    Animation sBullet(t5, 0,0,32,64, 16, 0.8);
    sBullet.sprite.setColor(sf::Color::Yellow);
    Animation sPlayer(t1, 40,0,40,40, 1, 0);
    Animation sPlayer_go(t1, 40,40,40,40, 1, 0);
    // Animation sExplosion_ship(t7, 0,0,192,192, 64, 0.5);
		Animation sExplosion_ship(t7, 0,0,192,192, 32, 0.1);
		Animation sExplosion_shipBis(t7, 0,0,192,192, 32, 0.5);


    std::list<Entity*> entities;

    for(int i=0;i<15;i++)
    {
      asteroid *a = new asteroid();
      a->settings(sRock, rand()%W, rand()%H, rand()%360, 25);
      entities.push_back(a);
    }

    player *p = new player();
    p->settings(sPlayer,200,200,0,20);
    entities.push_back(p);
    music[nbRand].play();

    /////main loop/////
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
             if (event.key.code == Keyboard::Space)
              {
                bullet *b = new bullet();
                b->settings(sBullet,p->x,p->y,p->angle,10);
                entities.push_back(b);
		tir.setVolume(10);
		tir.play();
              }
        }

    if (Keyboard::isKeyPressed(Keyboard::Right)) p->angle+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left))  p->angle-=3;
    if (Keyboard::isKeyPressed(Keyboard::Up)) p->thrust=true;
    else p->thrust=false;



    for(auto a:entities)
     for(auto b:entities)
    {
      if (a->name=="asteroid" && b->name=="bullet")
       if ( isCollide(a,b) )
           {
            a->life=false;
            b->life=false;
	    explosion.play();


	    Entity *e = new Entity();
            e->settings(sExplosion,a->x,a->y);
            e->name="explosion";
            entities.push_back(e);
						// moi
						// e->settings(sExplosionBis,a->x,a->y);
						// entities.push_back(e);


            for(int i=0;i<2;i++)
            {
             if (a->R==15) continue;
             Entity *e = new asteroid();
             e->settings(sRock_small,a->x,a->y,rand()%360,15);
             entities.push_back(e);
            }

           }

      if (a->name=="player" && b->name=="asteroid")
       if ( isCollide(a,b) )
           {
            b->life=false;

            Entity *e = new Entity();
            e->settings(sExplosion_ship,a->x,a->y);
            e->name="explosion";
            entities.push_back(e);

						//moi
						Entity *eBis = new Entity();
						eBis->settings(sExplosion_shipBis,a->x,a->y);
						eBis->name="explosion";
            entities.push_back(eBis);

            p->settings(sPlayer,W/2,H/2,0,20);
            p->dx=0; p->dy=0;

	    music[nbRand].stop();
	    nbRand = rand()%10;
	    printf("%d\n",nbRand);
	    music[nbRand].setVolume(10);
	    music[nbRand].play();
	    //explosion.setVolume(15);
	    //explosion.play();
	    boum.play();

           }
    }


    if (p->thrust)  p->anim = sPlayer_go;
    else   p->anim = sPlayer;


    for(auto e:entities)
     if (e->name=="explosion")
      if (e->anim.isEnd()) e->life=0;

    if (rand()%150==0)
     {
       asteroid *a = new asteroid();
       a->settings(sRock, 0,rand()%H, rand()%360, 25);
       entities.push_back(a);
     }

    for(auto i=entities.begin();i!=entities.end();)
    {
      Entity *e = *i;

      e->update();
      e->anim.update();

      if (e->life==false) {i=entities.erase(i); delete e;}
      else i++;
    }



   //////draw//////
   app.draw(background);

   for(auto i:entities)
     i->draw(app);

   app.display();
    }

    return 0;
}
