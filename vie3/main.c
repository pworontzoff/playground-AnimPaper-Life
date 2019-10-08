#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "paper.h"

void initJeu(int,int);
int getNbVoisines(int,int,int,int);

int main()
{
    int nbl=40,nbc=60;
    int tab_nb_voisines[nbl][nbc];
    int i=0,j=0;
    init_paper(nbl,nbc,10,0.05,1);
    
    initJeu(nbl,nbc);

    repeat(400) {
        
        // 1ere passe : calcul des nombres de voisines :
        repeat(nbl) { 
            repeat(nbc) { 
                move_to(i,j); //pour chaque case en ligne i, colonne j, sans examiner les bords :
                tab_nb_voisines[i][j] = getNbVoisines(i,j,nbl,nbc);
                j++;
            } loop;
            j = 0;
            i++;
        } loop;
        i = 0;

        // 2eme passe : morts ou naissances :
        repeat(nbl) { 
            repeat(nbc) { 
                move_to(i,j); //pour chaque case en ligne i, colonne j, sans examiner les bords :
                if (is_colored()) { // mort probable (isolement ou surpopulation)
                    if (tab_nb_voisines[i][j] != 2 && tab_nb_voisines[i][j] != 3) { // mort !
                        erase();
                    }
                } else { // naissance probable (si 3 voisines)
                    if (tab_nb_voisines[i][j] == 3) { // naissance !
                        colorize();
                    }
                }
                j++;
            } loop;
            j = 0;
            i++;
        } loop;
        i = 0;
        step_display();
    } loop;

    
    display_paper();    
    return 0;
}

void initJeu(int nbl, int nbc) {
    int i=0,j=0;
    time_t t;
    
    srand((unsigned) time(&t));
    
    repeat(nbl) { 
        repeat(nbc) { 
            move_to(i,j);
            if (rand()%5==0) {
                colorize();
            }
            j++;
        } loop;
        j = 0;
        i++;
    } loop;
    i = 0;
    
    move_to(0,0);
    step_display();
}

int getNbVoisines(int i, int j, int nbl, int nbc) {
    int cpt = 0;
    if (j>0) {
        move_to(i,j-1);
        if (is_colored()) cpt++;
    }
    if (j>0 && i>0) {
        move_to(i-1,j-1);
        if (is_colored()) cpt++;
    }
    if (i>0) {
        move_to(i-1,j);
        if (is_colored()) cpt++;
    }
    if (i>0 && j<nbc-1) {
        move_to(i-1,j+1);
        if (is_colored()) cpt++;
    }
    if (j<nbc-1) {
        move_to(i,j+1);
        if (is_colored()) cpt++;
    }
    if (j<nbc-1 && i<nbl-1) {
        move_to(i+1,j+1);
        if (is_colored()) cpt++;
    }
    if (i<nbl-1) {
        move_to(i+1,j);
        if (is_colored()) cpt++;
    }
    if (i<nbl-1 && j>0) {
        move_left(i+1,j-1);
        if (is_colored()) cpt++;
    }
    move_to(i,j);
    return cpt;
}
