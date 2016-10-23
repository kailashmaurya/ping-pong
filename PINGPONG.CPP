#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
union REGS in,out;
int r=20;
int xm,ym,xoldm=300,yoldm=467,color;
int score=0,speed=5;
void setylimit()
{
in.x.ax=8;
in.x.cx=467;
in.x.dx=467;
int86(51,&in,&out);
}

void setxlimit()
{
in.x.ax=7;
in.x.cx=152;
in.x.dx=448;
int86(51,&in,&out);
}

int callmouse()
{
in.x.ax=1;
int86(51,&in,&out);
return 1;
}

int hidemouse()
{
in.x.ax=2;
int86(51,&in,&out);
return 1;
}

void mouseposi(int &xpos,int &ypos)
{
in.x.ax=3;
int86(51,&in,&out);
xpos=out.x.cx;
ypos=out.x.dx;
}

void setposi(int xpos,int ypos)
{
in.x.ax=4;
in.x.cx=xpos;
in.x.dx=ypos;
int86(51,&in,&out);
}

void draw(int *x,int *y,int *initx,int *inity,int *m,int *s,int *i)
{
   *x=*x+*s;
   *y=*inity+*m*(*x-*initx);

   if(*x>=478)
   {
   *m=(-1)/(*m);
   *s=-1;
   *initx=*x;
   *inity=*y;
   *i=1+random(15);
   }

   if(*y>=getmaxy()-43)
   {
	if(*x>=xm-50&&*x<=xm+50)
	{
	*m=(-1)/(*m);
	*initx=*x;
	*inity=*y;
	*i=1+random(15);
	score++;

	if(score==5)
	{
	speed=4;
	gotoxy(2,4);
	printf(" Speed Up.");
	}
	if(score==10)
	{
	speed=3;
	gotoxy(2,5);
	printf(" Speed Up.");
	}
	if(score==15)
	{
	speed=2;
	gotoxy(2,6);
	printf(" Speed Up.");
	}
	if(score==20)
	{
	speed=1;
	gotoxy(2,7);
	printf(" Speed Up.");
	}
	if(score==25)
	{
	speed=0;
	gotoxy(2,8);
	printf(" Speed Up.");
	}
	if(score==35)
	{
	setcolor(7);
	settextstyle(3,0,4);
	outtextxy(150,getmaxy()/2-30,"YOU WIN!");
	}
	sound(700);
	}
	else
	{
	setcolor(7);
	settextstyle(3,0,4);
	outtextxy(150,getmaxy()/2-30,"YOU ARE DONE!");
	outtextxy(150,getmaxy()/2," GAME OVER ");
	sound(500);
	delay(200);
	nosound();
	getch();
	exit(0);
	}
   }

   if(*x<=122)
   {
   *m=(-1)/(*m);
   *s=1;
   *initx=*x;
   *inity=*y;
   *i=1+random(15);
   }

   if(*y<=22)
   {
   *m=(-1)/(*m);
   *initx=*x;
   *inity=*y;
   *i=1+random(15);
   }

   setcolor(*i);
   circle(*x,*y,r);

}


int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   printf("\n Press a key\n to Start.");
   getch();
   gotoxy(1,1);
   printf("\n            \n          ");
   setposi(300,467);
   callmouse();
   setylimit();
   setxlimit();
   hidemouse();
   rectangle(100,1,500,getmaxy());
   int x1=300,y1,initx1=300,inity1=200,m1=-1,s1=1,i1=5;

   while(!kbhit())
   {
   mouseposi(xm,ym);
   if(xoldm!=xm)
   {
   color=getcolor();
   setcolor(0);
   rectangle(xoldm-50,yoldm-10,xoldm+50,yoldm+10);
   setcolor(15);
   rectangle(xm-50,ym-10,xm+50,ym+10);
   setcolor(color);
   xoldm=xm;
   yoldm=ym;
   }
   draw(&x1,&y1,&initx1,&inity1,&m1,&s1,&i1);
   gotoxy(1,10);
   printf(" Score : %d",score);
   delay(speed);
   nosound();
   setcolor(0);
   circle(x1,y1,r);

   }

   getch();
   closegraph();
   return 0;
}

