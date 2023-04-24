#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


typedef struct {

    SDL_Surface* img;  
    int x, y;          
    int frame;         
    SDL_Surface *sprite[25]; 
    SDL_Rect bounds; 

} Ennemi;


void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e, SDL_Surface *screen);
void animerEnnemi(Ennemi *e);
void move(Ennemi *e);



typedef struct {
    SDL_Surface* img;  
    int x, y;          
    int speed;         
    int frame;         
    SDL_Surface *sprite[20]; 
    SDL_Rect hitbox;   
} Joueur;

void initJoueur(Joueur *j);
void afficherJoueur(Joueur j, SDL_Surface *screen);
void animerJoueur(Joueur *j);


typedef struct {

    SDL_Surface* img;  
    int x, y;          
    int frame;         
    SDL_Surface *sprite[21]; 
    SDL_Rect bounds;

} Boss;
void initBoss(Boss *b);
void afficherBoss(Boss b, SDL_Surface *screen);
void animerBoss(Boss *b);


typedef struct {

    SDL_Surface* img;  
    int x, y;          
    int frame;         
    SDL_Surface *sprite[20]; 
    SDL_Rect bounds;

} Pluie;

void initPluie(Pluie *p);
void afficherPluie(Pluie p, SDL_Surface *screen);
void animerPluie(Pluie *p);
