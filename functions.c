
#include "header.h"

void initEnnemi(Ennemi *e)
{

    e->x = 100;
    e->y = 200;


    char filename[50];
    for (int i = 0; i < 25; i++) 
{
        sprintf(filename, "bubble%d.png", i);
        e->sprite[i] = IMG_Load(filename);
}


    e->frame = 0;
}

void afficherEnnemi(Ennemi e, SDL_Surface *screen)
{

    SDL_Rect position;
    position.x = e.x;
    position.y = e.y;
    SDL_BlitSurface(e.sprite[e.frame], NULL, screen, &position);
    SDL_Flip(screen);
}
void animerEnnemi(Ennemi *e)
{
    static int lastTime = 0;
    int currentTime = SDL_GetTicks();
    if (currentTime > lastTime + 500) 
    {
        e->frame = (e->frame + 1) % 20;
        lastTime = currentTime;
    }
}


void move(Ennemi *e)
{

    int direction = rand() % 2;


    switch (direction) 
    {
  
        case 0: 
            e->x -= 5;
            break;
        case 1: 
            e->x += 5; 
            break;
    }
}

int collisionBB(SDL_Rect posp, SDL_Rect pose)
{
    if (posp.x + posp.w < pose.x || posp.x > pose.x + pose.w || posp.y + posp.h < pose.y || posp.y > pose.y + pose.h)
        {
    return 0;
        }
    
    return 1;
}
/*void moveIA(Ennemi *e, Joueur j)
{
    int distance = abs(e->x - j.x);

    if (distance <= 200) 
    {
        if (e->x < j.x) 
        {
            e->x += 5;
        }
        else if (e->x > j.x) 
        {
            e->x -= 5;
        }
    } 
    else 
    {
        int direction = rand() % 2;
        switch (direction) 
        {
            case 0: 
                e->x -= 5;
                break;
            case 1: 
                e->x += 5; 
                break;
        }
    }
}
*/



void initJoueur(Joueur *j)
{
    j->img = IMG_Load("player.png");
    j->x = 450;
    j->y = 200;
    j->speed = 5;
}


void afficherJoueur(Joueur j, SDL_Surface *screen)
{
    SDL_Rect position;
    position.x = j.x;
    position.y = j.y;
    SDL_BlitSurface(j.img, NULL, screen, &position);
    SDL_Flip(screen);
}



void initBoss(Boss *b)
{

    b->x = 760;
    b->y = 300;


    char filename[50];
    for (int i = 0; i < 21; i++) {
        sprintf(filename, "sprite_%d.png", i);
        b->sprite[i] = IMG_Load(filename);
    }


    b->frame = 0;
}

void afficherBoss(Boss b, SDL_Surface *screen)
{

    SDL_Rect position;
    position.x = b.x;
    position.y = b.y;
    SDL_BlitSurface(b.sprite[b.frame], NULL, screen, &position);
    SDL_Flip(screen);
}

void animerBoss(Boss *b)
{
    static int lastTime = 0;
    int currentTime = SDL_GetTicks();
    if (currentTime > lastTime + 250) 
    {
        b->frame = (b->frame + 1) % 24; 
        lastTime = currentTime;
    }
}

void initPluie(Pluie *p)
{

    p->x = 0;
    p->y = 0;


    char filename[25];
    for (int i = 0; i < 21; i++) {
        sprintf(filename, "rain%d.png", i);
        p->sprite[i] = IMG_Load(filename);
    }


    p->frame = 0;
}
void afficherPluie(Pluie p, SDL_Surface *screen)
{

    SDL_Rect position;
    position.x = p.x;
    position.y = p.y;
    SDL_BlitSurface(p.sprite[p.frame], NULL, screen, &position);
    SDL_Flip(screen);
}

void animerPluie(Pluie *p)
{
    static int lastTime = 0;
    int currentTime = SDL_GetTicks();
    if (currentTime > lastTime + 250) 
    {
        p->frame = (p->frame + 1) % 20; 
        lastTime = currentTime;
    }
}

/* Code python pour le Machine Learning
import numpy as np

def move_IA(e, player_pos):
    # Encode current state
    state = np.array([e.x, e.y, player_pos[0], player_pos[1]])

    # Load the trained model
    model = load_model("model.h5")

    # Predict the action to take
    action = model.predict(state.reshape(1, -1))[0]

    # Move the enemy based on the predicted action
    if action[0] > 0.5:
        e.x -= 5
    elif action[1] > 0.5:
        e.x += 5

    if action[2] > 0.5:
        e.y -= 5
    elif action[3] > 0.5:
        e.y += 5
*/

/*Attaque boss : Le missile (erreur code pour l'instant : SEGSEV)
void fireMissile(Boss b, Joueur j, SDL_Surface *screen)
{
    static int lastTime = 0;
    int currentTime = SDL_GetTicks();
    if (currentTime > lastTime + 10000)
    {
        // Create a new missile
        Missile m;
        m.img = IMG_Load("missile.png");
        m.x = b.x - m.img->w;
        m.y = b.y + b.sprite[b.frame]->h/2 - m.img->h/2;

        // Move missile towards player
        float dx = j.x - m.x;
        float dy = j.y - m.y;
        float distance = sqrt(dx*dx + dy*dy);
        m.speedx = dx/distance * MISSILE_SPEED;
        m.speedy = dy/distance * MISSILE_SPEED;

        // Add missile to list of missiles
        addMissileToList(&missileList, m);

        lastTime = currentTime;
    }
}
void addMissileToList(Missile **list, Missile *missile) {
    missile->next = *list;
    *list = missile;
}
(
Déclaration dans le main.c selon cours ESPRIT : 
Missile *m = createMissile(j.x, j.y);
addMissileToList(&missileList, m);
)
Missile *m = createMissile(j.x, j.y);
addMissileToList(&missileList, m);
*/
//Ne9es le design, le code pour renderer le tout et le code pour update toute l'interaction



