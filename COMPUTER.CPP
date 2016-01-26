#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>

/*GLOBAL VARIABLES */
int k=0,permission,QA=0,questionchanged=0;
long double ncash=0;
char playername[25];


//FUNTIONS
void straightline(void);
void netcash(int a);
void questionshow(char question[], char opt1[],char opt2[], char opt3[], char opt4[]);
int pwchk(char gpw[25]);
void changepw(char paswrd[25]);
long double hmoney();
void crhighest(long double n);
void hname(char name[]);
void highest(void);
void titlend(void);
void title(void);
void interval(int interval);
void mainscreen(void);
void pchange(void);
void quest12(void);
void quest11(void);
void quest10(void);
void quest9(void);
void quest8(void);
void quest7(void);
void quest6(void);
void quest5(void);
void quest4(void);
void quest3(void);
void quest2(void);
void quest1(void);
void wpwrd(void);
void screen4(void);
void screen3(void);

//MAIN PROGRAM
void main()
{
	clrscr();
	mainscreen();
	if(5-k==0)
	{
		wpwrd();
	}
	else
	{
		screen3();
	}
	getch();
}
void straightline()
{
	for(int i=0;i<80;i++)
	cout<<"_";
}
void netcash(int a)
{
	if(ncash>hmoney())
	{
		crhighest(ncash);
		hname(playername);
		cout<<"your score is highest";
	}
	int h=0;
	clrscr();
	if(ncash!=0)
	{
		cout<<"The right answer was: "<<a;
		cout<<"YOU ANSWERED "<<QA<<" QUESTIONS AND HAVE WON "<<ncash<<"$\n)";
		cout<<"\nPRESS 0 to exit         ";
		cin>>h;
		if(h==0)
		exit(0);
	}
	else
	{
		gotoxy(0,15);
		cout<<"The right answer was: "<<a;
		cout<<"\n\nSORRY BUT YOU DID NOT EARN ANYTHING BETTER LUCK NEXT TIME!";
		cout<<"\nPRESS 0 to exit   ";
		cin>>h;
		if(h==0)
		exit(0);
	}

}
void questionshow(char question[], char opt1[],char opt2[], char opt3[], char opt4[])
{
	cout<<"\n";
	straightline();
	cout<<question<<endl;
	straightline();
	cout<<opt1<<endl;
	cout<<opt2<<endl;
	cout<<opt3<<endl;
	cout<<opt4<<endl;
	straightline();
}

int pwchk(char gpw[25])
{
	ifstream pwf("password.txt");
	char ch[25];
	while(!pwf.eof())
	{
		pwf>>ch;
	}
	if(strcmp(ch,gpw)==0)
	{
		return 1;
	}
	else return 0;
}
void changepw(char paswrd[25])
{
	unlink("password.txt");
	ofstream file("password.txt");
	file<<paswrd;
	file.close();
}
void titlend()
{       struct time t1;
	gettime(&t1);
	textmode(C40);
	gotoxy(15,1);
	cout<<"QUIZ !!!";
	cout<<"\n";
	for(int ka=0;ka<40;ka++)
	{
	cout<<"*";
	}
	cout<<"\n time->"<<int(t1.ti_hour)<<":"<<int(t1.ti_min);
}

void title()
{       struct time t1;
	gettime(&t1);
	textmode(C40);
	gotoxy(15,1);
	cout<<"QUIZ !!!\n";
	for(int ka=0;ka<40;ka++)
	{
	cout<<"*";
	delay(50);
	}
	cout<<"\n time->"<<int(t1.ti_hour)<<":"<<int(t1.ti_min)<<endl;
}
void interval(int interval)
{
	while(interval!=0)
	{
		if(interval/10==0)
		{
			cout<<"0"<<interval;
		}
		else
		{
			cout<<interval;

		}
		cout<<"\b\b";
		delay(1000);
		interval--;
	}
}
void mainscreen()
{       sound(101);
	clrscr();
	textmode(C40);		//screen 1
	char c[10][100],pw[25];
	title();
	strcpy(c[0],"Welcome!!\tdated:20/10/2012");
	strcpy(c[1],"This project work has been prepared by:");
	strcpy(c[2],"Bhaskar Jha");
	strcpy(c[3],"______________");
	strcpy(c[4],"Under: Mr. Tejendra Pachhai");
	strcpy(c[5],"For any questions, please contact:");
	strcpy(c[6],"http://www.facebook.com/bhaskarworld");
	strcpy(c[7],"http://www.twitter.com/bhaskar985");
	strcpy(c[8],"bhaskaron9@yahoo.com");
	strcpy(c[9],"mailbhaskar.jha@gmail.com");
	for(int ind=0;ind<10;ind++)
	{
	cout<<c[ind]<<endl;
	delay(1000);
	}
		cout<<"Enter Password\n";
	while(k!=5)
	{
		gets(pw);
		k++;
		if(pwchk(pw)==0)
		{
			cout<<"\t\t\t\t\t\t";
			cout<<"\n\t\aWrong password... \nplease try again you have ";
			cout<<5-k<<" trials left\n";
		}
		else
		{	clrscr(); //screen2
			break;
		}


	}

}
void pchange()
{
	    titlend();
	    char op[25],np[25],cnp[25];
	    gotoxy(0,5);
	    cout<<"\nEnter old password:\t";
	    gets(op);
	    cout<<"\nNew password:\t\t";
	    gets(np);
	    cout<<"\nConfirm password:\t";
	    gets(cnp);
	    if(pwchk(op)==1&&strcmp(np,cnp)==0)
	    {
	    changepw(np);
	    cout<<"\n\n\n\n\n\t\tdone!!";
	    sound(102);
	    int ch;
	    cout<<"\npress 0 to go back";
	    cin>>ch;
	    if(ch==0)
	    screen3();
	    }
	    else
	    pchange();

}

void quest12()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 12.	20th Summit of ASEAN was held on April3-4,2012 in -"," 	1	Phnom Penh(Cambodia)"," 	2	Bankok (Thailand)"," 	3	Singapore"," 	4	Jakarta (Indonesia)");
			Ans=1; break;
		case 2: questionshow("Q 12.	2nd Africa - India Summit was recently held in -"," 	1	Ethiopia","	2	Sudan"," 	3	South Africa"," 	4	Uganda");
			Ans=1; break;
		case 3: questionshow("Q 12.	34th National Game 2011 was held in"," 	1	Bihar"," 	2.	uttar pradesh"," 	3	Jharkhand"," 	4	Madhya Pradesh");
			Ans=3; break;
		case 4: questionshow("Q 12.	4th Advance Estimates of Ministry of Agriculture, puts oilseeds production for 2011-12 at -"," 	1	30.01 MT"," 	2	28.89 MT","	3	32.32 MT"," 	4	31.01 MT");
			Ans=1; break;
		case 5: questionshow("Q 12.	4th July, 1776 is important in world history because"," 	1	Battle of Plassey started"," 	2	Sea route to India was discovered"," 	3	English King Charles II was executed","	4	American congress adopted the Declaration of Independence");
			Ans=4; break;
		case 6: questionshow("Q 12.	6 MMTPA pellet making plant in Odisha has been commissioned by -","	1	Tata Steels"," 	2	Essar Steels"," 	3	Jindal Steels","	4	Steel Authority of India Ltd.");
			Ans=2; break;
		case 7: questionshow("Q 12.	60° is equal to","	1	?/3 radians"," 	2	2?/3 radian","	3	3/? radians"," 	4	3?/2 radians");
			Ans=1; break;
		case 8: questionshow("Q 12.	6th G-20 Summit 2011 was held in-","	1	Cannes"," 	2	New York","	3	Kyoto","	3	Kyoto");
			Ans=1; break;
		case 9: questionshow("Q 12.	8 Export Processing Zones have been converted into Special Economic Zone. Whih one of the following is not a location of one of these SEZs?"," 	1	Noida"," 	2	Surat"," 	3	Vadodara","	4	Vishakhapatnam");
			Ans=3; break;
		case 10: questionshow("Q 12.	A 'biological death' occurs/takes place when"," 	1	there is no pulse and heartbeat"," 	2	pupils show no reaction to light"," 	3	all the body cells die after a few hours of clinical death","	4	pupils are fixed and dilated");
			Ans=3; break;
	}
	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				netcash(Ans);
			}
			else netcash(Ans);
		case 2: QA--; ncash-=ncash/5;
			quest12();
			questionchanged++;
		case 3: netcash(Ans);
	}

}
void quest11()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 11.	12th plan (2012-17) approach paper targets annual growth rate in agriculture, forestry and fishing at"," 	1	4.0%"," 	2	3.5%"," 	3	3.8%"," 	4	4.2%");
			Ans=1; break;
		case 2: questionshow("Q 11.	13 the constituted commission was constituted under the chairmanship of-"," 	1	C. Rangrajan","	2	Vijay L. Kelkar","	3	Deepak Parekh"," 	4	Indira Bhargava");
			Ans=2; break;
		case 3: questionshow("Q 11.	14 N.E.L.P Blocks, 1 J.V. Blocks, 2 Nomination Blocks and 4 C.B.M. Blocks are related to:"," 	1	Gypsum belt"," 	2	Gold belt"," 	3	Petroleum Exploration"," 	4	Lignite belt");
			Ans=3; break;
		case 4: questionshow("Q 11.	16th NAM Summit recently held at","	1	Singapore"," 	2	Cairo","	3	Teheran","	4	Manila");
			Ans=3; break;
		case 5: questionshow("Q 11.	18th ASEAN Summit was recently held in -"," 	1	Kuala Lumpur"," 	2	Brunei","	3	Jakarta","	4	Manila");
			Ans=3; break;
		case 6: questionshow("Q 11.	19th summit of ASEAN was organised between 17-19th November, 2011 in-"," 	1	Bali, Indonesia"," 	2	Kuala Lumpur, Malaysia","	3	New Delhi, India"," 	4	Cebu, Philippines");
			Ans=1; break;
		case 7: questionshow("Q 11.	2, 4-d is-"," 	1	an insecticide"," 	2	an explosive"," 	3	a fungicide"," 	4	a herbicide");
			Ans=4; break;
		case 8: questionshow("Q 11.	2009 Dadasaheb Phalke award was received by —"," 	1	Amitabh Bachan"," 	2	Nasiruddin Shah"," 	3	Rajnikant"," 	4	D.Ramanaidu");
			Ans=4; break;
		case 9: questionshow("Q 11.	2010 Nobel Literature Prize winner Mario Vargas Llosa is from which of the following countries?"," 	1	Brazil"," 	2	Peru"," 	3	Argentina","	4	Canada");
			Ans=2; break;
		case 10: questionshow("Q 11.	2018 FIFA World Cup would be held in"," 	1	France"," 	2	Russia"," 	3	Qatar"," 	4	Netherlands");
			Ans=2; break;
	}
	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest12();

			}
			else netcash(Ans);
		case 2: quest11();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}

}

void quest10()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 10.	`Sakshat' is"," 	1	A website"," 	2	A missile","	3	An artificial satellite"," 	4	A railway project");
			Ans=1; break;
		case 2: questionshow("Q 10.	`Satish Dhawan Space Centre' is located at-Q 10.	`Satish Dhawan Space Centre' is located at-Q 10.	`Satish Dhawan Space Centre' is located at-"," 	1	Vishakhapatnam"," 	2	Goa"," 	3	Shri Hari Kota","	4	Chennai");
			Ans=3; break;
		case 3: questionshow("Q 10.	‘Definitely Male’ this advertisement line is for which Motor Cycle?"," 	1	Hero Honda"," 	2	TVS"," 	3	Bajaj"," 	4	LML");
			Ans=3; break;
		case 4: questionshow("Q 10.	‘Fire Temple’ is the worship place of which of the following"," 	1	Christians","	2	Jews"," 	3	Muslims"," 	4	Parses");
			Ans=4; break;
		case 5: questionshow("Q 10.	‘Golden Ball’ winner of 2010 World Cup Football Championship was —"," 	1	Diego Forlan"," 	2	Carlos Borges"," 	3	Antonio Campolo","	4	Alvaro Farnandez");
			Ans=1; break;
		case 6: questionshow("Q 10.	‘Subroto Cup’ is associated with —"," 	1	Chess"," 	2	Football"," 	3	Cricket"," 	4	Table Tennis");
			Ans=2; break;
		case 7: questionshow("Q 10.	‘Yuan’ is the currency of which one of the following countries?"," 	1	South Korea"," 	2	Japan"," 	3	China"," 	4	North Korea");
			Ans=3; break;
		case 8: questionshow("Q 10.	'Asian Drama', by gunnar Karl Myrdal, is a book on which of the following subjects?"," 	1	Theatre Movements in asia"," 	2	Economics","	3	International Politics"," 	4	Look East Policy of India");
			Ans=2; break;
		case 9: questionshow("Q 10.	1 Joule is equivalent to"," 	1	103ergs"," 	2	105 ergs"," 	3	107ergs"," 	4	1011");
			Ans=3; break;
		case 10: questionshow("Q 10.	1024 bytes equals:"," 	1	1 KB"," 	2	2 MB"," 	3	1 GB"," 	4	1TB");
			Ans=1; break;
	}

	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest11();

			}
			else netcash(Ans);
		case 2: quest10();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}

}

void quest9()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 9.	____ Harbour is protected by a rocky headland called Dolphin's Nose."," 	1	Paradeep"," 	2	Cochin","	3	Kolkata"," 	4	Visakhapatnam");
			Ans=4; break;
		case 2: questionshow("Q 9.	____ is extracted from Bauxite."," 	1	Mica","	2	Copper","	3	Aluminium","	4	Tin");
			Ans=3; break;
		case 3: questionshow("Q 9.	_____ is an example of ionic solids."," 	1	Diamond"," 	2	copper","	3	Dry Ice"," 	4	Sodium Chloride");
			Ans=1; break;
		case 4: questionshow("Q 9.	_____ is processed by the computer into information"," 	1	Number"," 	2	Data"," 	3	Picture"," 	4	None of these");
			Ans=2; break;
		case 5: questionshow("Q 9.	_____ transforms one interface into another interface"," 	1	Program"," 	2	Software"," 	3	Data"," 	4	None");
			Ans=2; break;
		case 6: questionshow("Q 9.	_________ is a semi conductor memory."," 	1	Dynamic"," 	2	Static"," 	3	Bubble"," 	4	Both a & b");
			Ans=4; break;
		case 7: questionshow(" Q 9.	_________ is the first program run on a computer when computer boots up"," 	1	System Software"," 	2	Operating Software"," 	3	Systems Operations"," 	4	None");
			Ans=2; break;
		case 8: questionshow("Q 9.	`Benchamark' means -"," 	1	Products lined up on a bench"," 	2	Salesmen sitting on a bench"," 	3	Set standards"," 	4	Mark on a bench");
			Ans=3; break;
		case 9: questionshow("Q 9.	`Garib Rath' is"," 	1	The first AC train for the poor"," 	2	A portal","	3	A project launched by Ministry of HRD","	4	A low price car");
			Ans=1; break;
		case 10: questionshow("Q 9.	`Rainbow' is"," 	1	An ice-cream","	2	Prasar Bharti's FM Channel"," 	3	A suitcase"," 	4	A musical group");
			Ans=2; break;
	}
	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest10();

			}
			else netcash(Ans);
		case 2: quest9();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}

}
void quest8()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 8.	............ runs on computer hardware and serve as platform for other software's to run on"," 	1	Operting System"," 	2	Application Software"," 	3	System Software"," 	4	All");
			Ans=1; break;
		case 2: questionshow("Q 8.	............... was the founder of the Mughal empire."," 	1	Akbar"," 	2	Humayun"," 	3	Babur"," 	4	Ala-ud-din Khilji");
			Ans=3; break;
		case 3: questionshow("Q 8.	......IBSA Summit 2010 was recently held in Brasilia."," 	1	Third"," 	2	Fourth","	3	Fifth"," 	4	Sixth");
			Ans=2; break;
		case 4: questionshow("Q 8.	.....are attempts by individuals to obtain confidential information from you by falsifying their identity."," 	1	Phishing trips"," 	2	Computer viruses"," 	3	Spyware scams"," 	4	Phishing Scams");
			Ans=4; break;
		case 5: questionshow("Q 8.	.....coal has the highest percentage of carbon."," 	1	Anthracite"," 	2	Bituminous"," 	3	Lignite"," 	4	Peat");
			Ans=1; break;
		case 6: questionshow("Q 8.	.....is a port-based industrial region."," 	1	Hooghly"," 	2	Mumbai"," 	3	Haldia"," 	4	Chennai");
			Ans=2; break;
		case 7: questionshow("Q 8.	.....is a tributary of the Brahmaputra."," 	1	Tsang Po"," 	2	Son"," 	3	Subansiri"," 	4	Mahananda");
			Ans=1; break;
		case 8: questionshow("Q 8.	....is the largest oil refinery in India."," 	1	Haldia"," 	2	Koyali"," 	3	Digboi"," 	4	Trombay");
			Ans=2; break;
		case 9: questionshow("Q 8.	...signal will become zero when the feedback signal and reference signs are equal."," 	1	Input"," 	2	Actuating"," 	3	Feedback"," 	4	Reference");
			Ans=2; break;
		case 10: questionshow("Q 8.	Recently we read about the Goldstone report in the newspapers. Goldstone report is related to which of the following?"," 	1	The fact-finding report on the Swine Flu"," 	2	Violation of Human Rights in Gaza Conflict"," 	3	International trade and embargo"," 	4	The menace of somalian sea pirates");
			Ans=2; break;
	}
int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest9();

			}
			else netcash(Ans);
		case 2: quest8();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}

}

void quest7()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 7.	-, on December 8, 2009, announced to deposit with the Reserve Bank of India the donations made by devotees in the form of gold and silver."," 	1	Tamil Nadu"," 	2	Uttar Pradesh"," 	3	Himachal pradesh"," 	4	Uttarakhand");
			Ans=3; break;
		case 2: questionshow("Q 7.	-, the ship-based anti-surface missile, was successfully launched from INS Subhadra, in the Bay of Bengal, off Orissa, on December 13, 2009."," 	1	Astra"," 	2	Surya"," 	3	Nag"," 	4	Dhanush");
			Ans=4; break;
		case 3: questionshow("Q 7.	-. on December 18, 2009, announced to institute awards for promotion of `energy conservation buildings' and setting up of green energy and energy conservation fund."," 	1	HCL Infosystems and Motorola"," 	2	MTNL"," 	3	Bharti Airtel and BSNL"," 	4	All of the above");
			Ans=1; break;
		case 4: questionshow("Q 7.	.... has the highest number of cotton mills in India."," 	1	Tamil Nadu"," 	2	Maharashtra"," 	3	Gujarat"," 	4	West Bengal");
			Ans=1; break;
		case 5: questionshow("Q 7.	.... is an important cash crop of Eastern India."," 	1	Jute"," 	2	Rice"," 	3	Cotton"," 	4	Coffee");
			Ans=1; break;
		case 6: questionshow("Q 7.	..... are the second major source of irrigation in India."," 	1	Canals"," 	2	Tanks"," 	3	Oceans"," 	4	Wells and Tubewells");
			Ans=4; break;
		case 7: questionshow("Q 7.	..... is a set of Keywords, s symbols, and a system of rules for constructing statements by which humans can communicate the instructions to be executed by a computer..."," 	1	A Computer Program"," 	2	A Programming Language","	3	An Assembler"," 	4	Syntax");
			Ans=2; break;
		case 8: questionshow("Q 7.	..... is the largest milk producing organization in India."," 	1	Amul"," 	2	Abishek Anand","	3	Haringhata"," 	4	Metro");
			Ans=1; break;
		case 9: questionshow("Q 7.	..... is the process finding errors in software code."," 	1	compiling"," 	2	Assembling"," 	3	Interpreting"," 	4	Debugging");
			Ans=4; break;
		case 10: questionshow("Q 7.	...... is a procedure that requires users to enter an identification code and a matching password."," 	1	Paging"," 	2	Logging on"," 	3	Time-Sharing"," 	4	Multitasking");
			Ans=2; break;
	}

	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest8();

			}
			else netcash(Ans);
		case 2: quest7();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}

}
void quest6()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 6.	""The Vedas contain all the truth"" was interpreted by"," 	1	Swami Vivekanand"," 	2	Swami Dayanand","	3	Swami Shraddhanand"," 	4	S.Radhakrishnan");
			Ans=2; break;
		case 2: questionshow("Q 6.	""The Vedas contain all the truth"", was interpreted by:"," 	1	Swami Vivekanand"," 	2	Swami Dayanand","	3	Swami Shraddhanand"," 	4	S.Radhakrishnan");
			Ans=2; break;
		case 3: questionshow("Q 6.	""Vachaspati Puraskars"" are given by the"," 	1	Madhya Pradesh Government"," 	2	Uttar Pradesh Hindi Akademy"," 	3	Birla Foundation"," 	4	None of these");
			Ans=3; break;
		case 4: questionshow("Q 6.	""Yen"" is the currency of __"," 	1	China"," 	2	Japan"," 	3	Italy"," 	4	South Korea");
			Ans=2; break;
		case 5: questionshow("Q 6.	a & ß-tubulins are protein components of--"," 	1	Actin filaments"," 	2	Microtubules","	3	Intermediate"," 	4	All of these");
			Ans=4; break;
		case 6: questionshow("Q 6.	---, architect of Russia's ""shock"" market reforms in the 1990s, died in Moscow on December 16, 2009.","	1	Yuri Sanchez"," 	2	Mikhail Rasputin"," 	3	Alexander Lukhov"," 	4	Yegor Gaidar");
			Ans=4; break;
		case 7: questionshow("Q 6.	---, in December 2009, became the first Indian boxer to clinch a gold medal in the inter-continental President's Cup, winning the flyweight (51 kg) final in Baku."," 	1	Suranjoy Singh"," 	2	Avinash Duggal"," 	3	Mohnish Sharma","	4	Dinesh Gunjal");
			Ans=1; break;
		case 8: questionshow("Q 6.	---, on December 27, 2009, won the 38th senior National men's handball championship, dethroning Services in the final in Kolkata."," 	1	Railways"," 	2	State Bank of India"," 	3	Jharkhand"," 	4	Chhattisgarh");
			Ans=4; break;
		case 9: questionshow("Q 6.	-, on December 3, 2009, decided to implement a 'Jawahar Social Infrastructure Mission' focusing on the disability sector, senior citizens and children."," 	1	Delhi"," 	2	Orissa"," 	3	Punjab"," 	4	Haryana");
			Ans=4; break;
		case 10: questionshow("Q 6.	-, on December 5, 2009, announced to establish a natural fibres bank to conserve and promote planting material for commercial exploitation."," 	1	Uttar Pradesh"," 	2	Himachal Pradesh"," 	3	Uttarakhand"," 	4	Jharkhand");
			Ans=3; break;
	}
	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest7();

			}
			else netcash(Ans);
		case 2: quest6();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}


}

void quest5()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow(" 	4	Bankim Chandra Chatterjee"," 	1	Hockey"," 	2	Cricket"," 	3	Tennis"," 	4	Boxing");
			Ans=4; break;
		case 2: questionshow("Q 5.	'Referrals' means......"," 	1	Leads provided by operation"," 	2	Sales persons"," 	3	Front-office staff"," 	4	Management staff");
			Ans=1; break;
		case 3: questionshow("Q 5.	'Relationship' in karketing means ......"," 	1	Relation between salesperson"," 	2	Relation between buyer and seller"," 	3	Relation between company and consumer"," 	4	All of these");
			Ans=3; break;
		case 4: questionshow("Q 5.	'Swayamsidha' is a scheme launched by the Government of India to help."," 	1	Women only"," 	2	School children only"," 	3	Health workers only"," 	4	None of these");
			Ans=1; break;
		case 5: questionshow("Q 5.	'The Doing Business Report' is prepared by which of the following organizations every year?"," 	1	World Bank"," 	2	Asian Development Bank (ADB)"," 	3	International Monetary Fund (IMF)"," 	4	World Trade Organization(WTO)");
			Ans=1; break;
		case 6: questionshow("Q 5.	'The Fundamental Rights and Directive Principles of State Policy are complementary to each other .it is not necessary to sacrifice either of them for teh sake of the other.' This statement can be traced to"," 	1	Maneka Gandhi Case"," 	2	Minerva Mills Case"," 	3	Golaknath Case"," 	4	Kesanananda Bharti case");
			Ans=2; break;
		case 7: questionshow("Q 5.	'The Home Rule Movement' during the First World War was launched by"," 	1	Mahatma Gandhi"," 	2	Motilal Nehru and C.R. Das"," 	3	Gopal Krishna Gokhale"," 	4	Mrs. A. Besant and B.G. Tilak");
			Ans=4; break;
		case 8: questionshow("Q 5.	'The man who knew infinity' is a biography written by Robert Kanigel. This biography belongs to which one of the following?"," 	1	Srinivasa Ramanujan"," 	2	Jagdish Bhagvati"," 	3	Dr. C. V. Raman"," 	4	V. Ramakrishanan");
			Ans=1; break;
		case 9: questionshow("Q 5.	'The Right to Public Office' is a"," 	1	Moral right"," 	2	Civil right"," 	3	Political right"," 	4	Economic right");
			Ans=2; break;
		case 10: questionshow("Q 5.	'The social contract theory has been criticized as bad history ,bad logic and bad ethics..' who said it?"," 	1	Henny Maine"," 	2	H.J.Laski"," 	3	F.Wilson"," 	4	Ernest Broker");
			Ans=1; break;
	}

	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest6();

			}
			else netcash(Ans);
		case 2: quest5();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}


}

void quest4()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 4.	First Aakash slate developed in IIT Institute of ___________"," 	1	Los Angeles"," 	2	Kathmandu"," 	3	Varanasi"," 	4	Kanpur");
			Ans=4; break;
		case 2: questionshow("Q 4.	'Nadi Ke Dweep' is the creation of"," 	1	Nirmala Verma"," 	2	Krishna Sobit"," 	3	Gajanan Madhav Muktibodh"," 	4	Sachidananda Heeranand Vatsyayan Agyeya");
			Ans=4; break;
		case 3: questionshow("Q 4.	'Namibia' was earlier known as"," 	1	South- West Africa"," 	2	New Guinea"," 	3	British Guyana"," 	4	British Columbia");
			Ans=1; break;
		case 4: questionshow("Q 4.	'Nature does not drive man along a particular road, but it offers a number of opportunities from among which man is free to select'. This statement implies-"," 	1	Deterministic approach"," 	2	Possibilistic approach"," 	3	Deterministic and possibilistic both approach"," 	4	Probabilistic approach");
			Ans=4; break;
		case 5: questionshow("Q 4.	'Navratna Status' is awarded to which of the following organizations/ units?"," 	1	Those IITs/IIMs who are doing good research work"," 	2	Defence production units/factories who are showing good profits"," 	3	Defence production units/factories who are showing good profits"," 	4	A public sector bank rated very hing by the RBI in the area of customer service and recovery of NPAs");
			Ans=3; break;
		case 6: questionshow("Q 4.	'Nomadic Elephant' was the joint military exercise recently held in India between India and"," 	1	Sri Lanka"," 	2	Malaysia"," 	3	Indonesia"," 	4	Mongolia");
			Ans=4; break;
		case 7: questionshow("Q 4.	'Operation Black Board' refers to providing schools with"," 	1	Enough number of black boards"," 	2	New type of black boards"," 	3	Training for using new type of black boards"," 	4	All essential learning materials.");
			Ans=4; break;
		case 8: questionshow("Q 4.	'Oscar Awards' are given for the excellence in the field of ______."," 	1	Social Service"," 	2	Film"," 	3	Sports"," 	4	Journalism");
			Ans=2; break;
		case 9: questionshow("Q 4.	'Parliament has no right to reduce or abolish fundamental rights'. This refers to Supreme Court decision in the matter of:"," 	1	A.K.Gopalan vs State of Madras"," 	2	Golaknath vs State of Punjab"," 	3	Shankar Prasad vs Union of India"," 	4	Keshvanand Bharti vs State of Kerala");
			Ans=4; break;
		case 10: questionshow("Q 4.	'Patriotism is religion and religion is love for India' - Whose utterance is this ?"," 	1	Raj Narain Bose"," 	2	Swami Vivekanand"," 	3	Bal Gangadhar Tilak"," 	4	Bankim Chandra Chatterjee");
			Ans=4; break;
	}

	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest5();

			}
			else netcash(Ans);
		case 2: quest4();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}


}


void quest3()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 3.	'Abhinava Bharat' a secret society of revolutionaries, was organized by"," 	1	Khudiram Bose"," 	2	V.D. Savarkar"," 	3	Prafulla Chaki","	4	Bhagat Singh");
			Ans=2; break;
		case 2: questionshow("Q 3.	'Goodbye Shahzadi' is a book written by"," 	1	Shyam Bhatia"," 	2	Janardan Thakur"," 	3	Ashok Mehta"," 	4	Dhirendra Sharma");
			Ans=1; break;
		case 3: questionshow("Q 3.	'Green House Effect' means"," 	1	Pollution in houses in tropical regions"," 	2	Trapping of solar energy due to atmospheric oxygen"," 	3	Trapping of Solar energy due to atmospheric carbon dioxide"," 	4	Cultivation in green houses so as to check pollution");
			Ans=3; break;
		case 4: questionshow("Q 3.	'India for the Indians.' Who said?"," 	1	Swami Vivekanand"," 	2	Madan Mohan Malaviya"," 	3	Dayanand"," 	4	Bal Gangadhar Tilak");
			Ans=3; break;
		case 5: questionshow("Q 3.	'India: A Portrait' has been written by"," 	1	Patrick French"," 	2	Khuswant Singh"," 	3	Kuldip Nayar"," 	4	J.M. Keynes");
			Ans=1; break;
		case 6: questionshow("Q 3.	'Irani Trophy' is associated with which of the following games?"," 	1	Badminton"," 	2	Golf"," 	3	Cricket"," 	4	Football");
			Ans=3; break;
		case 7: questionshow("Q 3.	'Liberty is the positive power or capacity of doing or enjoying'. Who said this?"," 	1	Socrates"," 	2	Plato"," 	3	Kant"," 	4	Green");
			Ans=4; break;
		case 8: questionshow("Q 3.	'Let a hundred flowers bloom and let a thousand schools of thought contend' was said by"," 	1	Lenin"," 	2	Karl Marx"," 	3	Tolstoy"," 	4	Mao Tse-tung");
			Ans=4; break;
		case 9: questionshow("Q 3.	'James Bond' is a character created by"," 	1	Ian Fleming"," 	2	Perry Masion"," 	3	Agatha Christie"," 	4	Wode House");
			Ans=1; break;
		case 10: questionshow("Q 3.	'Making a Call' means ....."," 	1	Calling on a prospective customer"," 	2	Explaining product details"," 	3	Negotiating a deal"," 	4	Arguing with a customer");
			Ans=1; break;
	}
	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest4();

			}
			else netcash(Ans);
		case 2: quest3();
			questionchanged++;
			QA--; ncash-=ncash/5;
		case 3: netcash(Ans);
	}

}

void quest2()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 2.	Astra which was in news in recent past is the name of a newly developed-"," 	1	Air-to-air Missile"," 	2	Battle Tank"," 	3	Spy Rocket"," 	4	Submarine");
			Ans=1; break;
		case 2: questionshow("Q 2.	Azlan Shah Cup is associated with the game of"," 	1	Cricket"," 	2	Hockey"," 	3	Badminton"," 	4	Table Tennis");
			Ans=2; break;
		case 3: questionshow("Q 2.	Bhanu Singha was the pen name of famous writer?"," 	1	Bankin Chandra Chattopadhaye"," 	2	Rabindra Nath Tagore"," 	3	Abanindra Nath Thakur"," 	4	Sarat Chandra Chattopadhaye");
			Ans=2; break;
		case 4: questionshow("Q 2.	Black Pagoda is in"," 	1	Egypt"," 	2	Srilanka"," 	3	Madurai"," 	4	Konark");
			Ans=4; break;
		case 5: questionshow("Q 2.	Brahmanical reaction was responsible for the downfall of the Mauryan Empire. Who said?"," 	1	Harprasad Shastri"," 	2	U. N. Ghoshal"," 	3	D. D. Koshambi"," 	4	Romila Thapar");
			Ans=1; break;
		case 6: questionshow("Q 2.	City of Golden Gates is"," 	1	Hawan"," 	2	San Francisco"," 	3	London"," 	4	Paris");
			Ans=2; break;
		case 7: questionshow("Q 2.	Conversion in sales language means ......"," 	1	converting a buyer into a seller"," 	2	converting a seller into a buyer"," 	3	converting a prospect into a client"," 	4	All of these");
			Ans=3; break;
		case 8: questionshow("Q 2.	Does IT matter is a book written by"," 	1	Nicholas Carr"," 	2	Bill Gates"," 	3	N. R. Narayanan"," 	4	Thomas D. Harris");
			Ans=1; break;
		case 9: questionshow("Q 2.	Federation Cup in India is associated with which game?"," 	1	Badminton"," 	2	Football"," 	3	Hockey"," 	4	Basketball");
			Ans=2; break;
		case 10: questionshow("Q 2.	GOD Knows man's virtues and enquires not his caste, in the next world there is no caste! This was the theory of which Bhakti Saint?"," 	1	Ramanand"," 	2	Dadu"," 	3	Nanak"," 	4	Ramanuja");
			Ans=3; break;
	}
	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash+=100;
				quest3();

			}
			else netcash(Ans);
		case 2: QA--; ncash-=ncash/5;
			quest2();
			questionchanged++;
		case 3: netcash(Ans);
	}
}
void quest1()
{
	clrscr();
	textmode(C40);
	QA++;
	randomize();
	titlend();
	int rv=10, uv;
	int Ans;
	cout<<"\n\n\nWelcome "<<playername<<" you are playing question no."<<QA;
	cout<<"\nTill now you have won "<<ncash<<"$";
	uv=random(rv)+1;
	switch(uv)
	{
		case 1: questionshow("Q 1.	 Magnetic disk a medium known as","	1	Serial access","	2	Direct access"," 	3	Sequential access"," 	4	Sequential and rotational access");
			Ans=2; break;
		case 2: questionshow("Q 1.	 Which of the following terms could be used to describe the concurrent processing of computer programs via CRTs, on one computer system?"," 	1	Time sharing"," 	2	On-line processing"," 	3	Interactive processing"," 	4	All of these");
			Ans=4; break;
		case 3: questionshow("Q 1.	 Which one of the following travelers is not associated with the description of the glories of Vijayanagar kingdom?"," 	1	Paes"," 	2	Abdul Razzaq"," 	3	Ibn Batutach"," 	4	Nuniz");
			Ans=3; break;
		case 4: questionshow("Q 1.	 A great tank, now called the Great Bath, was found in"," 	1	Harappa"," 	2	Chanhudaro"," 	3	Lothal"," 	4	Mohenjodaro");
			Ans=4; break;
		case 5: questionshow("Q 1.	- based Institute of Genomics and INtegrative Biology, on December 8, 2009, announced to have succeeded in completely sequencing the genome of an individual."," 	1	Hyderabad"," 	2	Nasik"," 	3	Jaipur"," 	4	New Delhi");
			Ans=4; break;
		case 6: questionshow("Q 1.	 In which of the following cities in the Uttar Pradesh is sulehkul festival, the symbol of Hindu Muslim unity organised?"," 	1	Meerut"," 	2	Aligarh"," 	3	Lucknow"," 	4	Agra");
			Ans=4; break;
		case 7: questionshow("Q 1.	 In which of the following places is the Civil Aviation Training Centre situated in the Uttar Pradesh?"," 	1	Allahabad"," 	2	Lucknow"," 	3	Varanasi"," 	4	Amethi");
			Ans=1; break;
		case 8: questionshow("Q 1.	- Phosphates Ltd. in December 2009, won the Fertiliser Association of India Award for the Best Overall Performance of an operating fertilizer until for phosphoric acid."," 	1	Sindri"," 	2	Paradip"," 	3	Kanpur"," 	4	Ghaziabad");
			Ans=2; break;
		case 9: questionshow("Q 1.	- was appointed the president of the Bharatiya Janata Party, succeeding Rajnath Singh, on December 19, 2009."," 	1	Mrinal Patekar"," 	2	Nitin Gadkari"," 	3	Goloknath Borde"," 	4	Shivshankar Bhosale");
			Ans=2; break;
		case 10: questionshow("Q 1.	 In 1989, which municipal town of Kerala became the first fully literate municipal town in India ?"," 	1	Adoor"," 	2	Kottayam"," 	3	Alappuzha"," 	4	Palakkad");
			Ans=2; break;
	}
	int response,a;
	cout<<"\n\t|Options|";
	cout<<"\n1.Enter The answer directly.";
	cout<<"\n2.Change the Question";
	cout<<"\n3.Leave the Game\n";
	cin>>response;
	switch(response)
	{
		case 1:	cout<<"Enter your Answer: ";
			cin>>a;
			if(a==Ans)
			{
				ncash=100;
				quest2();

			}
			else netcash(Ans);
		case 2: QA--; ncash-=ncash/5;
			quest1();
			questionchanged++;

		case 3: netcash(Ans);
	}
}

void wpwrd()
{       clrscr();
	gotoxy(5,15);
	cout<<"YOU DON'T DESERVE TO PLAY";
}
void screen4(void)
{       clrscr(); //screen 4
	titlend();
	gotoxy(5,5);
	cout<<"Enter Player Name:\n\t\t\t\t";
	gets(playername);
	gotoxy(5,10);
	cout<<"time left:\t";
	interval(10);
	clrscr();
	quest1();
}
void screen3()
{
	clrscr();  //screen3
	titlend();
	gotoxy(5,3);
	delay(500);
	cout<<"\n\n\nRULEZZ OF THE GAME ";
	delay(500);
	cout<<"\n1. Here you will be asked 12 questions";
	delay(500);
	cout<<"\n2. You can leave the game at any time";
	delay(500);
	cout<<"\n3. Your game will start from 100 $ increasing upto ";
	delay(1500);
	cout<<"\n\t\t1200 $\n";
	for(int st=0;st<80;st++)
	cout<<"$";
	delay(500);
	cout<<"\n4. You have 1 advantage to change the question but your cash will also decrease by 20%";
	cout<<"\n5.If at any time, your answer becomes wrong your game will be over";
	delay(500);
	cout<<"\n\t\t Choose your option\n\t\t";
	cout<<"1-Play\n\t\t";
	cout<<"2-See the highest score\n\t\t";
	cout<<"3-Change password\n\t\t";
	cout<<"4-Exit\n\t\t\t";
	cin>>permission;
	while(permission<1&&permission<4)
	{
			cout<<"error :press 1 or 2 or 3 or 4!!";
			cin>>permission;
			break;
	}

	if(permission==1)
	{
		screen4();
	}
	else if(permission==2)
	{
	       int cha;
	       highest();
	       cout<<"\n\n\n press 0 to go back";
	       cin>>cha;
	       if(cha==0)
	       screen3();
	}
	else if(permission==4)
	{
		exit(0);
	}
	else if(permission==3)
	{
	    clrscr();
	    pchange();
	    }

}
long double hmoney()
{
	ifstream file("highest.txt");
	long double n;
	while(file)
	{
		file>>n;
	}
	file.close();
	return n;
}


void crhighest(long double n)
{
	unlink("highest.txt");
	ofstream file("highest.txt");
	while(1)
	{
		file<<n;
		break;
	}
	file.close();
}
void hname(char name[])
{
	unlink("hname.txt");
	int jt=0;
	ofstream file("hname.txt");
	while(jt!=1)
	{
		file<<name;
		jt++;
	}
	file.close();
}

void highest()
{
	clrscr();
	ifstream file("highest.txt"), nfile("hname.txt");
	titlend();
	char ch;
	cout<<"\n\n\n";
	while(file)
	{
		file>>ch;
		cout<<ch;
	}
	cout<<" by  ";
	while(nfile)
	{
		nfile>>ch;
		cout<<ch;
	}
	file.close();
	nfile.close();
}