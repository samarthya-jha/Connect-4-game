/*
Developed By Shivam Bairoliya
Version 1.0
Enjoy!!!
*/

#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<ctype.h>
int x,y,n=0,a[9][9]={0};
void tune(int f, int t)
{
	sound(f);
	delay(t);
	nosound();
}
void box(int c)
{
	for(int i=9;i<=15;i++)
	{
		cout<<endl;
		for(int j=32;j<=50;j++)
		{
			if(i==9||i==15||j==32||j==50)
		       {
				gotoxy(j,i);
				textbackground(c);
				cprintf("  ");
		       }
		}
	}
}
void loading()
{
	clrscr();
	box(7);
	textbackground(0);
	gotoxy(37,12);
	textcolor(3);
	cprintf("LOADING");
	for(int j=1;j<=2;j++)
	{
		for(int i=1;i<=4;i++)
		{

			if(j==2&&i==4)
				tune(800,300);
			else
				tune(262,100);
			delay(500);
			cprintf(".");
		}
	clrscr();
	box(7);
	textbackground(0);
	gotoxy(37,12);
	cprintf("LOADING");
	}
}

int checkHorizontal(int r, int c)
{
	int p1=0,p2=0;
	for(int i=0;i<r;i++)
	{
		p1=0;p2=0;
		for(int j=0;j<c;j++)
		{
			if(a[i][j]==1)
			{
				p1++;
				p2=0;
			}
			else if(a[i][j]==2)
			{
				p2++;
				p1=0;
			}
			else
			{
				p1=0;
				p2=0;
			}
			if(p1==4)
			return 1;
			if(p2==4)
			return 2;
		}
	}
	return 0;
}

int checkVertical(int r, int c)
{
	int p1=0,p2=0;
	for(int i=0;i<r;i++)
	{
		p1=0;p2=0;
		for(int j=0;j<c;j++)
		{
			if(a[j][i]==1)
			{
				p1++;
				p2=0;
			}
			else if(a[j][i]==2)
			{
				p1=0;
				p2++;
			}

			else
			{
				p1=0;
				p2=0;
			}
			if(p1==4)
			return 1;
			if(p2==4)
			return 2;
		}
	}
	return 0;
}


int checkRightDiagonal(int r,int c)
{
       int p1=0,p2=0;
       for(int i = r-1; i>=0; i--)
	{
		for(int j =c; j>0; j--)
		{
			for (int z = 0;z<=i && z<=j; z++)
			{
				  if(a[i-z][j-z] == 1)
				  {
					p2=0;
					p1++;
				  }
				  else if(a[i-z][j-z] == 2)
				  {
					 p1=0;
					 p2++;
				  }
				  else
				  {
					 p1=0;
					 p2=0;
				  }
				  if(p1==4)
				  return 1;
				  if(p2==4)
				  return 2;
			}
			p1=0;p2=0;
	       }
	       p1=0;p2=0;
	}

       return 0;
}

int checkLeftDiagonal(int r,int c)
{
       int p1=0,p2=0;
       for(int i = c-1; i>=0; i--)
	{
		for(int j =0; j<r; j++)
		{
			for (int z = 0;z<=i && z<=r-1-j; z++)
			{
				  if(a[i-z][j+z] == 1)
				  {
					p2=0;
					p1++;
				  }
				  else if(a[i-z][j+z] == 2)
				  {
					 p1=0;
					 p2++;
				  }
				  else
				  {
					 p1=0;
					 p2=0;
				  }
				  if(p1==4)
				  return 1;
				  if(p2==4)
				  return 2;
			}
			p1=0;p2=0;
	       }
	       p1=0;p2=0;
	}

       return 0;
}


int checkwin()
{
int c=checkHorizontal(9,9)+checkVertical(9,9)+checkRightDiagonal(9,9)+checkLeftDiagonal(9,9);
return c;
}
void rules()
{
	textbackground(0);
	clrscr();
	textcolor(15+128);
	gotoxy(33,2);
	cprintf("CONNECT FOUR!!!!");
	gotoxy(18,4);
	textcolor(14);
	cprintf(" The Following are the rules for the game:");
	gotoxy(18,6);
	cprintf("-This game is for two players.");
	gotoxy(18,8);
	cprintf("-Both have to insert their coins in a column.");
	gotoxy(18,10);
	cprintf("-The coin goes to the bottomost position in the column");
	gotoxy(18,12);
	cprintf("-The board is a 9 by 9 game board.");
	gotoxy(18,14);
	textcolor(2);
	cprintf("-Each person has to try to connect four coins either:");
	gotoxy(18,15);
	cprintf(":Horizontally");
	gotoxy(18,16);
	cprintf(":Vertically");
	gotoxy(18,17);
	cprintf(":Diagonally");
	textcolor(3);
	gotoxy(18,19);
	cprintf("-The Person who connects his four coins first wins.");
	gotoxy(18,21);
	cprintf("-Press esc to exit anytime");
	gotoxy(18,23);
	textcolor(15+BLINK);
	cprintf("PRESS ANY KEY TO CONTINUE");
	getch();
	textcolor(15);
}

void display()
{
	clrscr();
	int v=4,q=3;
	textcolor(15);
	gotoxy(1,5);
	cprintf("-Press esc to");
	gotoxy(2,6);
	cprintf("exit anytime.");
	gotoxy(17,1);
	textbackground(2);
	cprintf("|  A  |  B  |  C  |  D  |  E  |  F  |  G  |  H  |  I  |");
	gotoxy(17,2);
	textbackground(3);
	textcolor(15);
	cprintf("|_____|_____|_____|_____|_____|_____|_____|_____|_____|");
	gotoxy(17,3);
	textbackground(0);
	cprintf("|");
	for(int i=8;i>=0;i--)
	{

		for(int j=0;j<9;j++)
		{
			if(a[i][j]==1)
			{
				textbackground(4);
				cprintf("  1  ");
			}
			else if(a[i][j]==2)
			{
				textbackground(1);
				cprintf("  2  ");
			}
			else
			{
				textbackground(0);
				cprintf("  0  ");
			}
			cout<<"";
			textbackground(7);
			cprintf("|");
			textbackground(0);
			cout<<"";

		}
		gotoxy(17,q);
		textbackground(7);
		cprintf("|");
		textbackground(0);
		q+=2;
		gotoxy(17,v);
		v+=2;
		textbackground(3);
		cprintf("|_____|_____|_____|_____|_____|_____|_____|_____|_____|");
		gotoxy(18,q);
		textbackground(0);
	}

}
int input(int p)
{
	char m;
	ab:m=getch();

	if(p==1)
	sound(500);
	else
	sound(1000);
	delay(100);
	nosound();
	if(m=='u'||m=='U')
	{
		a[x][y]=0;
		if(n>0)
		goto ab;
		n++;
	}
	if(m==27)
	return 1;
	m=toupper(m);
	if(m<65||m>73)
	{
		clrscr();
		display();
		cout<<"Please enter a row between A to I";
		goto ab;

	}
	int t=m-65;
	if(a[8][t]>0)
	{
		clrscr();
		display();
		cout<<"Please enter a row that is not full";
		goto ab;
	}
	int c=0;
	for(int i =0;i<9&&c==0;i++)
	{
		if(a[i][t]==0)
		{
			a[i][t]=p;
			x=i;
			y=t;
			c=1;
		}
	}
	n=0;
	return 0;
}
void win(int p)
{
	clrscr();
	sound(500);
	delay(100);
	nosound();
	box(2);
	textbackground(0);
	gotoxy(36,12);
	textcolor(3+BLINK);
	if(p==1)
	cprintf("Player 1 Wins");
	else
	cprintf("Player 2 Wins");
	gotoxy(36,13);
	cprintf("CONGRATS!!!!!");
	getch();
}
int checkFull()
{

       for(int i=0;i<9;i++)
       {
		for(int j=0;j<9;j++)
		{
			if(a[i][j]==0)
			return 1;
		}
       }
       return 0;
}
void play()
{
	clrscr();
	rules();
	clrscr();
	loading();
	clrscr();
	int p,z,c1=0,a=1,c2,w=0;
	clrscr();
	display();
	textcolor(15);
	while(c1==0)
	{

		p=z%2+1;
		gotoxy(14,21);
		cout<<" PLAYER "<<((p==1)?1:2)<<" please enter the row to put your coin in-";
		gotoxy(14,22);
		a=input((p==1)?1:2);
		c1=checkwin();
		c2=checkFull();
		if(c2==0)
		c1=6;
		if(a==1)
		c1=5;
		z++;
		w=(p==1)?1:2;
		clrscr();
		display();

	}
	cprintf("PRESS ANY KEY TO CONTINUE");
	getch();
	if(c1>0&&c1<5)
	win(w);
	if(c1==5)
	{
		clrscr();
		box(7);
		gotoxy(37,12);
		textcolor(15);
		textbackground(0);
		cprintf("Thank You");
		getch();
	}
	if(c1==6)
	{
		clrscr();
		box(7);
		gotoxy(38,12);
		textbackground(0);
		cprintf("DRAW!!");
		getch();
	}
}
void main()
{
	play();
}