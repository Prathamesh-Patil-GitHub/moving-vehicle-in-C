#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<DOS.h>
void draw_man()
{
	circle(400+28,75,10);     //Stoping-Man
	putpixel(398+28,72,WHITE);
	putpixel(402+28,72,WHITE);
	ellipse(400+28,78,180,360,4,2); //Smile
	line(400+28,85,400+28,105);   //Body
	line(400+28,95,392+28,93);    //Right Hand
	line(400+28,95,412+28,96);    //Left Hand
	line(392+28,93,388+28,88);    //Right Palm
	line(400+28,105,395+28,125);  //Right Leg
	line(400+28,105,405+28,125);  //Left Leg
}
void draw_pole()
{
   line(440,60,440,125);  //Pole Bar
   setfillstyle(SOLID_FILL,RED);
   circle(440,40,20);      //MSG Circle
   floodfill(440,40,WHITE);
   outtextxy(426,38,"STOP"); //Actual MSG
}
void main()
{
	int GD=DETECT,GM,i=0,snd=15,horn=1;
	char control;
	clrscr();
	initgraph(&GD,&GM,"C:\\TC\\BGI");

	///////////////////MAIN LOGIC START////////////////
	while(i<=180)
	{
	if(i<100)             //Engine Sound
	snd++;
	else
	snd--;
	clrscr();
	printf("\a");
	sound(snd);
	if(i>150)           //Beeping Horn
	{
	if(snd%2)
	   sound(300*horn);
	else
	   sound(1500*horn);
	}
	setbkcolor(4);
	setcolor(WHITE);
	setlinestyle(0,0,0);
	draw_man();               //Draws Stopping Man
	draw_pole();              //Draws STOP Pole
	setcolor(0);
	setlinestyle(0,0,3);
	outtextxy(10,130,"PRESS D TO MOVE FORWARD    PRESS A TO MOVE BACKWARdD    PRESS E TO EXIT");
	line(10,125,470,125);     //Road
	delay(0.01);           //Time Delay
	setlinestyle(0,0,3);
	setcolor(8);
	line(20+i,10,20+i,70);       //Skeleton Of Vehicle
	line(40+i,10,40+i,70);
	rectangle(10+i,10,200+i,70);    //MAIN BOX
	rectangle(50+i,20,70+i,40);
	rectangle(80+i,20,100+i,40);
	rectangle(110+i,20,130+i,40);     //WINDOW1
	rectangle(140+i,20,160+i,40);     //WINDOW2
	rectangle(170+i,20,190+i,40);     //WINDOW3
	rectangle(200+i,40,230+i,70);     //HOOD
	rectangle(2+i,55,10+i,70);        //BACKSIDE
	line(200+i,10,230+i,40);          //MIRRIOR
	setfillstyle(SLASH_FILL,8);
	floodfill(60+i,14,8);             //CLR-MIDDLE_BOX
	setfillstyle(SLASH_FILL,14);
	floodfill(215+i,45,8);            //CLR-HOOD
	floodfill(7+i,65,8);              //CLR-BACKSIDE
	floodfill(14+i,14,8);             //Colouring Vehicle- BACK_BOX
	setlinestyle(0,0,0);
	setcolor(WHITE);
	circle(30+i,20,10);        //Vehicle Man
	line(30+i,30,30+i,55);
	line(30+i,42,25+i,30);     //Right Hand
	line(30+i,42,35+i,30);     //Left Hand
	line(30+i,55,20+i,70);     //Left Leg
	line(30+i,55,35+i,70);     //Right Leg
	ellipse(30+i,22,180,360,4,2);  //Smile
	putpixel(28+i,18,WHITE);
	putpixel(32+i,18,WHITE);
	setlinestyle(2,0,3);
	setcolor(8);
	circle(52+i,100,2);      //Tyres Of vehicle
	circle(170+i,100,2);
	circle(52+i,100,25);
	circle(170+i,100,25);
	circle(170+i,100,18);
	circle(52+i,100,18);
	setfillstyle(9,6);
	floodfill(72+i,100,8);   //Filling Tyres
	floodfill(191+i,100,8);
	nosound();
	control=getche();
	if(control=='d')
	i++;
	if(control=='a')
	i--;
	if(control=='e')
	break;
	}
	printf("\n\n\n\n\n\n\n\nPress Enter to Exit");
	//////////////////MAIN LOGIC END////////////////////
	getch();
	closegraph();
}
