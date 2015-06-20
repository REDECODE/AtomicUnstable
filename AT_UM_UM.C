/* classe 3 Informatica B */
/* alunno: Picco Dario */
/* data: 1 Ottobre 2006 */
/* descrizione: Atomic */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <values.h>
#include <time.h>

#define MAXI 7
#define MAXN 6
#define N_GIO_1 1
#define N_GIO_2 2
#define DELAY 50

void IA (int n_cpu, int n[MAXI][MAXI], int g[MAXI][MAXI], int *col, int *rig);
void conta (int n[MAXI][MAXI], int g[MAXI][MAXI], int pl, int *punti, int *caselle, float *instabili);
void risolviSchema (int n[MAXI][MAXI], int g[MAXI][MAXI], int mx, int my, int pl);
void copiaSchema (int n1[MAXI][MAXI], int g1[MAXI][MAXI], int n2[MAXI][MAXI], int g2[MAXI][MAXI]);
void umano (int *col, int *rig, int *esci);
int  scelta (int n_cpu, int n[MAXI][MAXI], int g[MAXI][MAXI], int col, int rig, int *punti, int *caselle, float *instabili);

int inizio;

int main (void)
{
int n[MAXI][MAXI],g[MAXI][MAXI],x,y,esci,mx,my,px[3],py[3],espl,
	 rip,m[MAXI][MAXI],p[MAXI][MAXI],pl,puntiG1,puntiG2;

  _setcursortype(_SOLIDCURSOR);
  randomize();
for (y=1; y<=MAXN; y++)
  for (x=1; x<=MAXN; x++)
	{
	n[x][y]=0;
	g[x][y]=0;
	}
	inizio=1;
mx=1;
my=1;
 for (x=1; x<=2; x++)
	{
	 px[x]=1;
	 py[x]=1;
	 }
x=1;
y=1;
esci=0;
textcolor(LIGHTGREEN);
textbackground(BLACK);
clrscr();
pl=1;
 do {
	 if (x==81)
	  {
	  x=x-80;
	  y=y+1;
	  }
	gotoxy(x,y);
	if ((x==1 || x==9 || x==17 || x==25 || x==33 || x==41 || x==49) ||
	 ((y==1 || y==5 || y==9 || y==13 || y==17 || y==21 || y==25) && (x<=49)))
	  cprintf("Û");
	x++;
	}
while (x!=80 || y!=25);
do
 {
  gotoxy(51,5);
  textbackground(0);
  textcolor(10+pl);
  cprintf("Giocatore %d, fai la tua Mossa:",pl);
  conta(n,g,N_GIO_1,&puntiG1,NULL,NULL);
  conta(n,g,N_GIO_2,&puntiG2,NULL,NULL);
  gotoxy(71,7);
  cprintf("          ");
  gotoxy(51,7);
  textcolor(11);
  cprintf("Atomi P1: %d",puntiG1);
  gotoxy(68,7);
  textcolor(12);
  cprintf("Atomi P2: %d",puntiG2);
  mx=px[pl];
  my=py[pl];
  esci = 0;
  espl = 100;
  copiaSchema(m, p, n, g);

  do
	{
	  if (pl == N_GIO_1)
		 umano (&mx,&my,&esci);
	  else
		 umano (&mx,&my,&esci);

	 if (!(--espl))
		esci = 3;
	}
  while (!((mx>=1 && mx<=MAXN && my>=1 && my<=MAXN && g[mx][my] != 3-pl) || esci));

	 gotoxy(-3+8*mx,-1+4*my);

  px[pl]=mx;
  py[pl]=my;
  n[mx][my]=n[mx][my]+1;
  g[mx][my]=pl;
  textcolor(15);
  if (!esci)
  do
	{
	if (inizio!=1)
		esci=1;
	else
		esci=0;

	espl = 0;
	 for (y=1; y<=MAXN; y++)
		for (x=1; x<=MAXN; x++)
		 {
			if (((x==1 || x==MAXN) && (y==1 || y==MAXN)) && n[x][y]>1)
				{
			  if (x+1<=MAXN)
				{
				 n[x+1][y]+=1;
				 g[x+1][y]=g[x][y];
				}
			  if (x-1>=1)
				{
				 n[x-1][y]+=1;
				 g[x-1][y]=g[x][y];
				}
			  if (y+1<=MAXN)
				{
				 n[x][y+1]+=1;
				 g[x][y+1]=g[x][y];
				}
			  if (y-1>=1)
				{
				 n[x][y-1]+=1;
				 g[x][y-1]=g[x][y];
				}
				n[x][y]-=2;
				espl = 1;
				delay(DELAY);
			  }
			else if (((x==1 || x==MAXN) || (y==1 || y==MAXN)) && n[x][y]>2)
				{
			  if (x+1<=MAXN)
				{
				 n[x+1][y]+=1;
				 g[x+1][y]=g[x][y];
				}
			  if (x-1>=1)
				{
				 n[x-1][y]+=1;
				 g[x-1][y]=g[x][y];
				}
				if (y+1<=MAXN)
				{
				 n[x][y+1]+=1;
				 g[x][y+1]=g[x][y];
				}
				if (y-1>=1)
				{
				 n[x][y-1]+=1;
				 g[x][y-1]=g[x][y];
				}
				n[x][y]-=3;
				espl = 1;
				delay(DELAY);
			  }
			else if (n[x][y]>3)
				{
				 n[x+1][y]+=1;
				 g[x+1][y]=g[x][y];
				 n[x-1][y]+=1;
				 g[x-1][y]=g[x][y];
				 n[x][y+1]+=1;
				 g[x][y+1]=g[x][y];
				 n[x][y-1]+=1;
				 g[x][y-1]=g[x][y];
				 n[x][y]-=4;
				 espl = 1;
				 delay(DELAY);
				}
		 if (pl==1)
		  {
		  if (g[x][y]==2)
			 esci=0;
		  }
		 else
		  if (g[x][y]==1)
			 esci=0;

		  if ( n[x][y]!=0)
			{
			 textbackground(3*(g[x][y]-1)+1);
			 gotoxy(-6+8*x,-2+4*y);
			 cprintf("       ");
			 gotoxy(-6+8*x,-1+4*y);
			 cprintf("   %d   ",n[x][y]);
			 gotoxy(-6+8*x,4*y);
			 cprintf("       ");
			}
		  else
			{
			 textbackground(0);
			 gotoxy(-6+8*x,-2+4*y);
			 cprintf("       ");
			 gotoxy(-6+8*x,-1+4*y);
			 cprintf("       ");
			 gotoxy(-6+8*x,4*y);
			 cprintf("       ");
			 g[x][y]=0;
			}
		 }
  }
 while (espl && !esci);
 if (!esci)
  if (pl==1)
	 pl=2;
  else
	 pl=1;
 inizio=0;
	  if (kbhit())
		if (getch() == 27)
		  esci = 2;
 }
while(!esci);

  gotoxy(51,5);
  textbackground((pl-1)*3+1);
  textcolor(WHITE+BLINK);
  if (esci == 1)
	 cprintf("Giocatore %d, hai VINTO !!!    ",pl);
  else if (esci == 2)
	 cprintf("La partita Š stata terminata. ");
  else if (esci == 3)
	 cprintf("La IA non risponde correttam. ");
  _setcursortype(_NORMALCURSOR);
while (!(kbhit()));
	return 0;
}
//-------------------------------- umano ---------------------------------
//   Permette a un giocatore umano di poter partecipare alla partita 
//------------------------------------------------------------------------
void umano (int *col, int *rig, int *esci)
{
 char mossa;
     gotoxy(-3+8*(*col) , -1+4*(*rig));
  do
   {
        mossa = getch();
		if (mossa == 27)
		  *esci = 2;
		else if (mossa==77 && (*col)!=MAXN)
		  (*col)++;
		else if (mossa==75 && (*col)!=1)
		  (*col)--;
		else if (mossa==80 && (*rig)!=MAXN)
		  (*rig)++;
		else if (mossa==72 && (*rig)!=1)
		  (*rig)--;
	 gotoxy(-3+8*(*col),-1+4*(*rig));
   }
  while ((mossa!=13 && !(*esci)) || (*col)<1 || (*rig)<1);
}
//---------------------------- risolviSchema -------------------------------
// Input: n (matrice dei numeri), g (matrice dei giocatori),
//        mx , my (x e y della casella in cui si vuol aggiungere un "Atomo"),
//        pl (numero del giocatore che inserisce l'Atomo);
//Output: la matrice dei numeri e dei giocatori dopo aggiunta Atomo.
//--------------------------------------------------------------------------
void  risolviSchema (int n[MAXI][MAXI], int g[MAXI][MAXI], int mx, int my, int pl)
{
 int esci,espl,y,x;
  n[mx][my] = n[mx][my] + 1;
  g[mx][my] = pl;
  textcolor(15);
  do
   {
	if (inizio != 1)
		esci = 1;
	else
		esci = 0;

	espl = 0;
	 for (y=1; y<=MAXN; y++)
	     for (x=1; x<=MAXN; x++)
	       {
			if (((x==1 || x==MAXN) && (y==1 || y==MAXN)) && n[x][y]>1)
			 {
			  if (x+1<=MAXN)
			   {
					n[x+1][y]+=1;
			      g[x+1][y]=g[x][y];
				}
			  if (x-1>=1)
			   {
				 n[x-1][y]+=1;
				 g[x-1][y]=g[x][y];
				}
			  if (y+1<=MAXN)
				{
				 n[x][y+1]+=1;
				 g[x][y+1]=g[x][y];
				}
			  if (y-1>=1)
				{
				 n[x][y-1]+=1;
				 g[x][y-1]=g[x][y];
				}
				n[x][y]-=2;
				espl = 1;
			 }
			else if (((x==1 || x==MAXN) || (y==1 || y==MAXN)) && n[x][y]>2)
			 {
			  if (x+1<=MAXN)
			   {
				 n[x+1][y]+=1;
				 g[x+1][y]=g[x][y];
				}
			  if (x-1>=1)
				{
				 n[x-1][y]+=1;
				 g[x-1][y]=g[x][y];   
				}
				if (y+1<=MAXN)
				{
				 n[x][y+1]+=1;
				 g[x][y+1]=g[x][y];
				}
				if (y-1>=1)
				{
				 n[x][y-1]+=1;
				 g[x][y-1]=g[x][y];
				}
				n[x][y]-=3;
				espl = 1;
			 }
			else if (n[x][y]>3)
			 {
				 n[x+1][y]+=1;
				 g[x+1][y]=g[x][y];
				 n[x-1][y]+=1;
				 g[x-1][y]=g[x][y];
				 n[x][y+1]+=1;
				 g[x][y+1]=g[x][y];
				 n[x][y-1]+=1;
				 g[x][y-1]=g[x][y];
				 n[x][y] -= 4;
				 espl = 1;
			 }
		 if (pl==1)
		  {
		  if (g[x][y]==2)
			 esci=0;
		  }
		 else
		  if (g[x][y]==1)
			 esci=0;
					}
   }
  while (espl==1 && esci==0);
}
//------------------------------ copiaSchema -------------------------------
// Input: n2 (matrice sorgente dei numeri),
//        g2 (matrice sorgente dei giocatori).
//Output: n1 (matrice di destinazione dei numeri),
//        g1 (matrice di destinazione dei giocatori).
//---------------------------------------------------------------------------
void copiaSchema (int n1[MAXI][MAXI], int g1[MAXI][MAXI], int n2[MAXI][MAXI], int g2[MAXI][MAXI])
{
  int i,j;
		 for (i=1; i<=MAXN; i++)
         for (j=1; j<=MAXN; j++)
          {
	    n1[j][i] =  n2[j][i];
            g1[j][i] =  g2[j][i];
          }
}
//------------------------------- conta ------------------------------------
// Input: n (matrice dei numeri), g (matrice dei giocatori),
//        pl (numero del giocatore di cui si vogliono contare gli Atomi),
//Output: punti (numero di Atomi controllati dal giocatore).
//        caselle (numero di caselle controllate del giocatore).
//	  instabili (numero di caselle instabili ).
//--------------------------------------------------------------------------
void conta (int n[MAXI][MAXI], int g[MAXI][MAXI], int pl, int *punti, int *caselle, float *instabili)
{
  int i,j;

	*punti = 0;
	*caselle = 0;
	*instabili = 0;

		for (i=1; i<=MAXN; i++)
			for (j=1; j<=MAXN; j++)
			 {
		 if (g[j][i] == pl)
				 {
					*punti += n[j][i];
					*caselle += 1;
					  if ((i==1 || i==MAXN) && (j==1 || j==MAXN))
						*instabili += n[j][i];
					  else if (i==1 || i==MAXN || j==1 || j==MAXN)
						*instabili += n[j][i] / 2.0;
					  else
						*instabili += n[j][i] / 3.0;

				 }
			 }
}
//-------------------------------- IA --------------------------------------
// Input: n (matrice dei numeri),
//        g (matrice dei giocatori).
//Output: col (colonna della casella in cui si vuole inserire l'Atomo).
//        rig (riga della casella in cui si vuole inserire l'Atomo).
//--------------------------------------------------------------------------
void IA (int n_cpu, int n[MAXI][MAXI], int g[MAXI][MAXI], int *col, int *rig)
{
int m[MAXI][MAXI],p[MAXI][MAXI],i,j,x,y,caselle,punti,maxPunti,minCas,cont;
float instabili,maxInst;

  maxPunti = -MAXINT;
  minCas = MAXINT;
  maxInst = -MAXFLOAT;

  i = random (MAXN) + 1;
  j = random (MAXN) + 1;
  cont = MAXN * MAXN;
  while (cont--)
		{
		  if (g[j][i] != 3-n_cpu)
			{
			  copiaSchema(m, p, n, g);

	  scelta (n_cpu, m, p, j, i, &punti, &caselle, &instabili);
			  if (punti > maxPunti || (punti == maxPunti && caselle < minCas) ||
				  (punti==maxPunti && caselle==minCas && instabili>maxInst))
				{
					maxPunti = punti;
					minCas = caselle;
					maxInst = instabili;
					*rig = i;
					*col = j;
				}
			}
		 if (j == MAXN)
		  {
			j = 1;
			  if (i == MAXN)
				 i = 1;
			  else
				 i++;
		  }
		 else
			j++;
		}
		delay(500);
}
//--------------------------------------------------------------------------
int scelta (int n_cpu, int n[MAXI][MAXI], int g[MAXI][MAXI], int col, int rig, int *punti, int *caselle, float *instabili)
{
 int m[MAXI][MAXI],p[MAXI][MAXI],i,j,pt,cs;
 float in;

	 *punti = MAXINT;
	 *caselle = -MAXINT;
	 *instabili = MAXFLOAT;

	 risolviSchema (n, g, col, rig, n_cpu);

	 conta (n, g, 3-n_cpu, &pt, &cs, &in);
 if (!inizio && !pt)
  {
	 *punti = 1000;
  }
 else
  {
	for (i=1; i<=MAXN; i++)
	  for (j=1; j<=MAXN; j++)
		{
		 if (g[j][i] != n_cpu)
			{
			 copiaSchema(m, p, n, g);
			 risolviSchema (m, p, j, i, 3-n_cpu);
			 conta (m, p, n_cpu, &pt, &cs, &in);

			  if (pt < *punti || (pt == *punti && cs > *caselle) ||
				  (pt== *punti && cs == *caselle && in < *instabili))
				{
					*punti = pt;
					*caselle = cs;
					*instabili = in;
				}
			}
		}
  }
  return 0;
}

