//2D SQUASH Game by Onkar J. Sathe

#include<dos.h>
#include<math.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	int gd = DETECT;
	int gm,x,y,s=0,x1=100,x2=110,x3=500,x4=510,y1=10,y2=80,y3=10,y4=80,f=0;
	char a,a1='t',p;
	void over(int );
	x=120;
	y=400;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	settextstyle(3,0,3);
	outtextxy(60,20," FOR LEFT BAR USE UP & DOWN ARROW \n");
	outtextxy(60,60," FOR RIGHT BAR USE LEFT & RIGHT ARROW ");
	getch();
	rectangle(x1,y1,x2,y2);
	rectangle(x3,y3,x4,y4);
	rectangle(100,getmaxy()-10,510,getmaxy());
	rectangle(100,0,510,10);
	while(1)
	 {      s++;
		if( kbhit() )
		a=getch();
		circle(x,y,10);
		setfillstyle(1,RED);
		floodfill(x,y,WHITE);
		delay(5);
		if(x==120)
		{
			if(a1=='r')
			{
				p='b';
				a1='l';
			}
			else
			{
				p=a1;
				a1='l';
			}
		}
		else  if(y==getmaxy()-20)
		{
			p=a1;
			a1='b';
		}
		else if(x==490)
		{
			if(a1=='l')
			{
				p='b';
				a1='r';
			}
			else
			{
				p=a1;
				a1='r';
			}
		}
		else  if(y==20)
		{
			p=a1;
			a1='t';
		}
		switch(a1)
		{
		case 'l':

			if(p=='t')
			{
				x++;
				y++;
			}
			else  if(p=='b')
			{
				x++;
				y--;
			}
			break;
		case 'r':
			if(p=='b')
			{
				x--;
				y--;
			}
			else  if(p=='t')
			{
				x--;
				y++;
			}
		       break;
		case 't':
			if(p=='r')
			{
				x--;
				y++;
			}
			else  if(p=='l')
			{
				x++;
				y++;
			}
			break;
		case 'b':
			if(p=='r')
			{
				x--;
				y--;
			}
			else  if(p=='l')
			{
				x++;
				y--;
			}
			break;
		}

		circle(x,y,10);
		setfillstyle(1,RED);
		floodfill(x,y,WHITE);
		rectangle(x1,y1,x2,y2);
		setfillstyle(1,BLUE);
		floodfill(x1+2,y1+2,WHITE);
		rectangle(x3,y3,x4,y4);
		setfillstyle(1,GREEN);
		floodfill(x3+2,y3+2,WHITE);
		rectangle(100,getmaxy()-10,510,getmaxy());
		setfillstyle(1,YELLOW);
		floodfill(102,getmaxy()-7,WHITE);
		rectangle(100,0,510,10);
		setfillstyle(1,YELLOW);
		floodfill(102,2,WHITE);
		delay(7);
		cleardevice();
		switch (a)
		{
			case 72:
			if(y1>10&&y2<=getmaxy()-10)
			{
			       y1--;
			       y2--;
			}
			break;
			case 80:
			if(y1>=10&&y2<getmaxy()-10)
			{
			       y1++;
			       y2++;
			}
			break;
			case 77:
			if(y3>=10&&y4<getmaxy()-10)
			{
				y3++;
				y4++;
			}
			break;
			case 75:
			if(y3>10&&y4<=getmaxy()-10)
			{
				y3--;
				y4--;
			}
			break;
			case 'e':
			return 0;
			default:
			break;
		}
		if(x==120)
		{
			if(x2==x-10&&y>=y1&&y<=y2)
			f=0;
			else
			f=1;
		}
		if(x==490)
		{
			if(x3==x+10&&y>=y3&&y<=y4)
			f=0;
			else
			f=1;
		}
		if(a=='e')
		break;
		if(f)
		{	over(s);
			break;
		}
	 }
getch();
closegraph();
}
void over(int s)
{
	cleardevice();
	settextstyle(3,0,6);
	outtext("  G A M E   O V E R ");
//	printf("\n\n\n\n\n\n\n     YOUR SCORE: %d ",s*5/60);
	return ;
}
