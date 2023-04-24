// main.c

#include "header.h"

int main(int argc, char *argv[])
{
    SDL_Surface *screen,*background;
    Ennemi e;
    Joueur j;
    Boss b;
    Pluie p;

    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(1366, 631, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    // Initialize the fish
    background = SDL_LoadBMP("background.bmp");
    
    initBoss(&b);
    initEnnemi(&e);
    initJoueur(&j);
    initPluie(&p);

    // Game loop
    while (1)
    {
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                exit(0);
        }
        SDL_BlitSurface(background, NULL, screen, NULL);
        move(&e);
        // Animate the fish
        animerBoss(&b);
        animerEnnemi(&e);
        animerPluie(&p);
        // Update the screen

        afficherBoss(b, screen);
        afficherEnnemi(e, screen);
	afficherJoueur(j, screen);
	afficherPluie(p, screen);
        
        SDL_Flip(screen);
    }

    // Free resources and quit SDL
    for (int i = 0; i < 25; i++) 
    {
        SDL_FreeSurface(e.sprite[i]);
    }
    for (int i = 0; i < 21; i++) 
    {

        SDL_FreeSurface(b.sprite[i]);
    }
    for (int i = 0; i < 21; i++) 
    {
        SDL_FreeSurface(p.sprite[i]);
    }


    SDL_FreeSurface(background);
    SDL_Quit();
    return 0;
}
