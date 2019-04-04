#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include <stdio.h>
#include <iomanip>

using namespace std;
const int longueur=20;
const int largeur=10;

struct tower
{
       int damage, range ;

};


struct monster
{
    int health, speed ;

};

struct position
{

    bool bm = false;
    bool bt = false;
    monster M;
    tower T;
};

struct jeu
{
    int ty = largeur;
    int tx = longueur;
    int victory=0 ;
    position grille[largeur][longueur];

};

void affiche_terrain(jeu J)
{
    int i,j;
    for (i=0;i<J.ty;i++)
    {
        for (j=0;j<J.tx;j++)
        {
            if (J.grille[i][j].bm==true)
            {
                cout << "M" << " " ;
            }
            else if (J.grille[i][j].bt==true)
            {
                cout << "T" << " " ;
            }
            else
            {
                cout << "0" << " " ;
            }

        }
        cout << endl ;
    }
    cout << endl << endl;
}

position iniposition(int d=0, int r=0, int s=0, int h=0)
{
    position P ;
    P.T.range=r ;
    P.T.damage=d ;
    P.M.speed=s ;
    P.M.health=h ;

}



    jeu inijeu()
    {
        int i,j ;
        jeu J;
        for (i=0;i<J.ty;i++)
    {
        for (j=0;j<J.tx;j++)
        {
        J.grille[i][j]=iniposition() ;
        }
    }
    return J ;

    }

    void addmonster (jeu &J, int s=1, int h=1)
    {
        int i, j;
        do {
        j=longueur-1 ;
        i=rand()%(largeur) ;
        }
        while((J.grille[i][j].bt==true)||(J.grille[i][j].bm==true)) ;
        J.grille[i][j].M.speed=s ;
        J.grille[i][j].M.health=h ;
        J.grille[i][j].bm=true ;

    }

    void addtower (jeu &J, int r=1, int d=1)
    {
        int i, j;
        do {
        affiche_terrain(J);
        cout << "position ?" << endl;
        cin >> i >> j ;
        }
        while((J.grille[i][j].bt==true)||(J.grille[i][j].bm==true)) ;
        J.grille[i][j].T.range=r ;
        J.grille[i][j].T.damage=d ;
        J.grille[i][j].bt=true ;

    }

void rush(jeu &J, int i, int j)
{
    position p;
    p=J.grille[i][j];


}

void nextturn(jeu &J)
{
    int i, j ;
    for (i=0;i<J.ty;i++)
    {
        for (j=0;j<J.tx;j++)
        {
        if (J.grille[i][j].bm==true)
            {
                rush(J,i,j) ;
            }
            else if (J.grille[i][j].bt==true)
            {
                cout << "T" << " " ;
            }
        }
    }

}

int main()
{
    srand(time(NULL)) ;
    jeu J = inijeu() ;
    addmonster(J);
    affiche_terrain(J);
    return 0;

}
