#include<iostream>
#include<conio.h>
#include<random>//used in n_value
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int mat[17];
int emove(int mat[17]){
	
	int ttr[17][2];
	for(int i=1;i<3;i++){
		
		for(int a=1;a<17;a++)
		{
			ttr[a][i]=1;
		}
	}
	for(int i=1;i<17;i++){
		 
		ttr[i][0]=mat[i];
		switch(i)
		{
			case 1:
			case 5:
			case 9:
			case 13: ttr[i][1]=1; break;
			case 2:
			case 6:
			case 10:
			case 14: ttr[i][1]=2; break;
			case 3:
			case 7:
			case 11:
			case 15: ttr[i][1]=3; break;
			case 4:
			case 8:
			case 12:
			case 16: ttr[i][1]=4; break;
		}
	}
	//starting the process of emove
	for(int i=16;i>0;i--)
	{
	
		switch(ttr[i][1])
		{
		case 4:{
					break;
		}
		case 3:{
			if(ttr[i+1][0]==1)
			{
				ttr[i+1][0]=ttr[i][0];
				ttr[i][0]=1;
			}
			else if(ttr[i+1][0]==ttr[i][0])
			{
				ttr[i][0]=1;	
				ttr[i+1][0]+=1;
			} 
			else if(ttr[i+1][0]!=ttr[i][0])
			{
				ttr[i][0]=ttr[i][0];
				ttr[i+1][0]=ttr[i+1][0];
			}
			break;
		}
		case 2:{
			if(((ttr[i+1][0]==1)&&(ttr[i+2][0]==1))&&(ttr[i+1][0]==ttr[i+2][0]))
			{
				ttr[i+2][0]=ttr[i][0];
				ttr[i][0]=1;		
			}		
			else if((ttr[i+1][0]==1)&&(ttr[i][0]==ttr[i+2][0]))
			{
					ttr[i+2][0]+=1;
					ttr[i][0]=1;
			}
			else if((ttr[i+1][0]==1)&&(ttr[i+2][0]!=ttr[i][0]))
				{
					ttr[i+1][0]=ttr[i][0];
					ttr[i][0]=1;
				}
			else if((ttr[i][0]==ttr[i+1][0])&&(ttr[i+1][0]!=1))
			{	
				ttr[i+1][0]+=1;
				ttr[i][0]=1;	
			}
			else if(ttr[i+1][0]!=ttr[i][0])
			{
				ttr[i][0]=ttr[i][0];
				ttr[i+1][0]=ttr[i+1][0];
			}
			break;
		}
		case 1:{
			if( ((ttr[i+3][0]==1)&&(ttr[i+2][0]==1))   &&  (ttr[i+3][0]==ttr[i+1][0]    ))
			{
				ttr[i+3][0]=ttr[i][0];
				ttr[i][0]=1;
			}
			else if(((ttr[i+1][0]==1)&&(ttr[i+2][0]==1)) && (ttr[i][0]==ttr[i+3][0]))
			{
					ttr[i+3][0]+=1;
					ttr[i][0]=1;				
			}	
			else if (((ttr[i+1][0]==1)&&(ttr[i+2][0]==1)) && (ttr[i][0]!=ttr[i+3][0]))
			{
				ttr[i+2][0]=ttr[i][0];
				ttr[i][0]=1;	
			}			
			else if ((ttr[i+1][0]==1)&&(ttr[i+2][0]==ttr[i][0]))
			{
				ttr[i+2][0]+=1;
				ttr[i][0]=1;
			}			
			else if ((ttr[i+1][0]==1)&&(ttr[i+2][0]!=ttr[i][0]))
			{
				ttr[i+1][0]=ttr[i][0];
				ttr[i][0]=1;
			}
		else if((ttr[i][0]==ttr[i+1][0])&&(ttr[i+1][0]!=1))
			{	
				ttr[i+1][0]+=1;
				ttr[i][0]=1;	
			}
			else if(ttr[i+1][0]!=ttr[i][0])
			{
				ttr[i][0]=ttr[i][0];
				ttr[i+1][0]=ttr[i+1][0];
			}
			break;
		}

		}//end of switch
	}//end of for loop
	//ending the process of emove
	for(int i=1;i<17;i++){

		mat[i]=ttr[i][0];
	}
		return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];	

}
int qmove(int mat[17]){
	
	int ttr[17][2];
	//[0]---------value of mat[]
	//[1]---------positiom of mat[]
	for(int i=1;i<17;i++)
	{	
		//value of mat 
		ttr[i][0]=mat[i];
		//position of mat
		switch(i)
		{
			case 1:
			case 5:
			case 9:
			case 13: ttr[i][1]=1; break;
			case 2:
			case 6:
			case 10:
			case 14: ttr[i][1]=2; break;
			case 3:
			case 7:
			case 11:
			case 15: ttr[i][1]=3; break;
			case 4:
			case 8:
			case 12:
			case 16: ttr[i][1]=4; break;
		}
	}
	//starting the process of emove
	for(int i=1;i<17;i++)
	{
		switch(ttr[i][1])
		{
			case 4:{
			if( ((ttr[i-3][0]==1)&&(ttr[i-2][0]==1))   &&  (ttr[i-3][0]==ttr[i-1][0]    ))
			{
			
				ttr[i-3][0]=ttr[i][0];
				ttr[i][0]=1;
			}
			else if(((ttr[i-1][0]==1)&&(ttr[i-2][0]==1)) && (ttr[i][0]==ttr[i-3][0]))
			{
					ttr[i-3][0]+=1;
					ttr[i][0]=1;				
			}	
			else if (((ttr[i-1][0]==1)&&(ttr[i-2][0]==1)) && (ttr[i][0]!=ttr[i-3][0]))
			{
				ttr[i-2][0]=ttr[i][0];
				ttr[i][0]=1;	
			}			
			else if ((ttr[i-1][0]==1)&&(ttr[i-2][0]==ttr[i][0]))
			{
				ttr[i-2][0]+=1;
				ttr[i][0]=1;
			}			
			else if ((ttr[i-1][0]==1)&&(ttr[i-2][0]!=ttr[i][0]))
			{
				ttr[i-1][0]=ttr[i][0];
				ttr[i][0]=1;
			}
		else if((ttr[i][0]==ttr[i-1][0])&&(ttr[i-1][0]!=1))
			{	;
				ttr[i-1][0]+=1;
				ttr[i][0]=1;	
			}
			else if(ttr[i-1][0]!=ttr[i][0])
			{
				ttr[i][0]=ttr[i][0];
				ttr[i-1][0]=ttr[i-1][0];
			}
			break;
		}
			case 3:{
			if(((ttr[i-1][0]==1)&&(ttr[i-2][0]==1))&&(ttr[i-1][0]==ttr[i-2][0]))
			{
				ttr[i-2][0]=ttr[i][0];
				ttr[i][0]=1;		
			}		
			else if((ttr[i-1][0]==1)&&(ttr[i][0]==ttr[i-2][0]))
			{
					ttr[i-2][0]+=1;
					ttr[i][0]=1;
			}
			else if((ttr[i-1][0]==1)&&(ttr[i-2][0]!=ttr[i][0]))
				{
					ttr[i-1][0]=ttr[i][0];
					ttr[i][0]=1;
				}
			else if((ttr[i][0]==ttr[i-1][0])&&(ttr[i-1][0]!=1))
			{	
				ttr[i-1][0]+=1;
				ttr[i][0]=1;	
			}
			else if(ttr[i-1][0]!=ttr[i][0])
			{
				ttr[i][0]=ttr[i][0];
				ttr[i-1][0]=ttr[i-1][0];
			}
			break;
		}
			case 2:{
			if(ttr[i-1][0]==1)
			{
				ttr[i-1][0]=ttr[i][0];
				ttr[i][0]=1;
			}
			else if(ttr[i-1][0]==ttr[i][0])
			{
				ttr[i][0]=1;	
				ttr[i-1][0]+=1;
			} 
			else if(ttr[i-1][0]!=ttr[i][0])
			{
				ttr[i][0]=ttr[i][0];
				ttr[i-1][0]=ttr[i-1][0];
			}
			break;
		}	
			case 1:{
			break;
		} 
	}
	}
	//ending the process of emove
	for(int i=1;i<17;i++)
	{
		mat[i]=ttr[i][0];
	}
		return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];	

}//----------------------------------------------------
int smove(int mat[17]){
	
	int ttr[17][2];

		for(int i=1;i<3;i++){
		
		for(int a=1;a<17;a++)
		{
			ttr[a][i]=1;
		}
	}
	for(int i=1;i<17;i++){
		 
		ttr[i][0]=mat[i];
		switch(i)
		{
			case 1:
			case 2:
			case 3:
			case 4: ttr[i][1]=1; break;
			case 5:
			case 6:
			case 7:
			case 8: ttr[i][1]=2; break;
			case 9:
			case 10:
			case 11:
			case 12: ttr[i][1]=3; break;
			case 13:
			case 14:
			case 15:
			case 16: ttr[i][1]=4; break;
		}
	}
	//starting the process of emove
	for(int i=16;i>0;i--)
	{
		switch(ttr[i][1])
		{
			case 4:{
				
				break;
			}
			case 3:{
				if(ttr[i+4][0]==1)
				{
					ttr[i+4][0]=ttr[i][0];
					ttr[i][0]=1;
				}
				else if(ttr[i+4][0]==ttr[i][0])
				{
				ttr[4+i][0]+=1;
				ttr[i][0]=1;	
				}
				else if(ttr[i+4][0]!=ttr[i][0])
				{
				ttr[4+i][0]=ttr[i+4][0];
				ttr[i][0]=ttr[i][0];	
				}								
				break;
			}
			case 2:{
			if(((ttr[i+4][0]==1)&&(ttr[i+8][0]==1))&&(ttr[i+4][0]==ttr[i+8][0]))
			{
				ttr[i+8][0]=ttr[i][0];
				ttr[i][0]=1;		
			}		
			else if((ttr[i+4][0]==1)&&(ttr[i][0]==ttr[i+8][0]))
			{
				ttr[i+8][0]+=1;
				ttr[i][0]=1;
			}
			else if((ttr[i+4][0]==1)&&(ttr[i+8][0]!=ttr[i][0]))
				{	
					ttr[i+4][0]=ttr[i][0];
					ttr[i][0]=1;
				}
			else if((ttr[i][0]==ttr[i+4][0])&&(ttr[i+4][0]!=1))
			{	
				ttr[i+4][0]+=1;
				ttr[i][0]=1;	
			}
			else if(ttr[i+4][0]!=ttr[i][0])
			{	
				ttr[i][0]=ttr[i][0];
				ttr[i+4][0]=ttr[i+4][0];
			}
			break;

				break;
			}
			case 1:{
			if( ((ttr[i+12][0]==1)&&(ttr[i+8][0]==1))   &&  (ttr[i+12][0]==ttr[i+4][0]    ))
			{
			
				ttr[i+12][0]=ttr[i][0];
				ttr[i][0]=1;
			}
			else if(((ttr[i+4][0]==1)&&(ttr[i+8][0]==1)) && (ttr[i][0]==ttr[i+12][0]))
			{
					ttr[i+12][0]+=1;
					ttr[i][0]=1;				
			}	
			else if (((ttr[i+4][0]==1)&&(ttr[i+8][0]==1)) && (ttr[i][0]!=ttr[i+12][0]))
			{
				ttr[i+8][0]=ttr[i][0];
				ttr[i][0]=1;	
			}			
			else if ((ttr[i+4][0]==1)&&(ttr[i+8][0]==ttr[i][0]))
			{
				ttr[i+8][0]+=1;
				ttr[i][0]=1;
			}			
			else if ((ttr[i+4][0]==1)&&(ttr[i+8][0]!=ttr[i][0]))
			{
				ttr[i+4][0]=ttr[i][0];
				ttr[i][0]=1;
			}
		else if((ttr[i][0]==ttr[i+4][0])&&(ttr[i+4][0]!=1))
			{
				ttr[i+4][0]+=1;
				ttr[i][0]=1;	
			}
			else if(ttr[i+4][0]!=ttr[i][0])
			{
				ttr[i][0]=ttr[i][0];
				ttr[i+4][0]=ttr[i+4][0];
			}
			break;
		
		}
	}
}
	//ending the process of emove
	for(int i=1;i<17;i++){

		mat[i]=ttr[i][0];
	}
		return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];	

}
int wmove(int mat[17]){
	
	int ttr[17][2];
	for(int i=1;i<3;i++){
		
		for(int a=1;a<17;a++)
		{
			ttr[a][i]=1;
		}
	}
	for(int i=1;i<17;i++){
		 
		ttr[i][0]=mat[i];
		switch(i)
		{
			case 1:
			case 2:
			case 3:
			case 4: ttr[i][1]=1; break;
			case 5:
			case 6:
			case 7:
			case 8: ttr[i][1]=2; break;
			case 9:
			case 10:
			case 11:
			case 12: ttr[i][1]=3; break;
			case 13:
			case 14:
			case 15:
			case 16: ttr[i][1]=4; break;
		}
	}
	//starting the process of emove
	for(int i=1;i<17;i++)
	{
		switch(ttr[i][1])
		{
			case 1:{
				
				break;
			}
			case 2:{
				if(ttr[i-4][0]==1)
				{
					ttr[i-4][0]=ttr[i][0];
					ttr[i][0]=1;
				}
				else if(ttr[i-4][0]==ttr[i][0])
				{
				ttr[i-4][0]+=1;
				ttr[i][0]=1;	
				}
				else if(ttr[i-4][0]!=ttr[i][0])
				{
				ttr[i-4][0]=ttr[i-4][0];
				ttr[i][0]=ttr[i][0];	
				}
				else
				{
					std::cout<<"\nerror found\n";
				}								
				break;
			}
			case 3:{
			if(((ttr[i-4][0]==1)&&(ttr[i-8][0]==1))&&(ttr[i-4][0]==ttr[i-8][0]))
			{
				ttr[i-8][0]=ttr[i][0];
				ttr[i][0]=1;		
			}		
			else if((ttr[i-4][0]==1)&&(ttr[i][0]==ttr[i-8][0]))
			{
				ttr[i-8][0]+=1;
				ttr[i][0]=1;
			}
			else if((ttr[i-4][0]==1)&&(ttr[i-8][0]!=ttr[i][0]))
				{	
					ttr[i-4][0]=ttr[i][0];
					ttr[i][0]=1;
				}
			else if((ttr[i][0]==ttr[i-4][0])&&(ttr[i-4][0]!=1))
			{	
				ttr[i-4][0]+=1;
				ttr[i][0]=1;	
			}
			else if(ttr[i-4][0]!=ttr[i][0])
			{	
				ttr[i][0]=ttr[i][0];
				ttr[i-4][0]=ttr[i-4][0];
			}
			else
			{	
				std::cout<<"\nerror found\n";
			}
			break;

				break;
			}
			case 4:{
			if( ((ttr[i-12][0]==1)&&(ttr[i-8][0]==1))   &&  (ttr[i-12][0]==ttr[i-4][0]    ))
			{
			
				ttr[i-12][0]=ttr[i][0];
				ttr[i][0]=1;
			}
			else if(((ttr[i-4][0]==1)&&(ttr[i-8][0]==1)) && (ttr[i][0]==ttr[i-12][0]))
			{
					ttr[i-12][0]+=1;
					ttr[i][0]=1;				
			}	
			else if (((ttr[i-4][0]==1)&&(ttr[i-8][0]==1)) && (ttr[i][0]!=ttr[i-12][0]))
			{
				ttr[i-8][0]=ttr[i][0];
				ttr[i][0]=1;	
			}			
			else if ((ttr[i-4][0]==1)&&(ttr[i-8][0]==ttr[i][0]))
			{
				ttr[i-8][0]+=1;
				ttr[i][0]=1;
			}			
			else if ((ttr[i-4][0]==1)&&(ttr[i-8][0]!=ttr[i][0]))
			{
				ttr[i-4][0]=ttr[i][0];
				ttr[i][0]=1;
			}
		else if((ttr[i][0]==ttr[i-4][0])&&(ttr[i-4][0]!=1))
			{
				ttr[i-4][0]+=1;
				ttr[i][0]=1;	
			}
			else if(ttr[i-4][0]!=ttr[i][0])
			{
				ttr[i][0]=ttr[i][0];
				ttr[i-4][0]=ttr[i-4][0];
			}
			else
			{
				std::cout<<"\nerror found\n";
			}
			break;
		
		}
	}
	}
	//ending the process of emove
	for(int i=1;i<17;i++){

		mat[i]=ttr[i][0];
	}
	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];	
}
int goto_move(char move,int mat[17]){
	
	switch(move)
	{
		case 'E': emove(mat); 	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16]; break;
		case 'Q': qmove(mat); 	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16]; break;
		case 'S': smove(mat); 	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16]; break;
		case 'W': wmove(mat); 	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16]; break;
		case '+': 	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];break;
	}
	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];	
}
//-----------------small letters------------------ 
#define q 113
#define w 119
#define e 101
#define s 115
#define r 114
#define t 116
#define y 121
#define u 117
#define i 105
#define o 111
#define p 112
#define a 97
#define d 100
#define f 102
#define g 103
#define h 104
#define j 106
#define k 107
#define l 108
#define z 122
#define x 120
#define c 99
#define v 118
#define b 98
#define n 110
#define m 109
//------------------------capital letters----------------------
#define Q 81
#define W 87
#define E 69
#define S 83
#define R 82
#define T 84
#define Y 89
#define U 85
#define I 73
#define O 79
#define P 80
#define L 76
#define K 75
#define J 74
#define H 72
#define G 71
#define F 70
#define D 68
#define A 65
#define Z 90
#define X 88
#define C 67
#define V 86
#define B 66
#define N 78
#define M 77
#define cls (system("cls"))
int down_arrow=25,	up_arrow=24,
	left_arrow=27,	right_arrow=26,
	blank_space=255;
//------------------end of macro--------------------------
int pm[4]={Q,W,E,S},score=0;
int v_v(int var,int s_c_o_r_e__change){

	switch(var)
	{
		case 1:{std::cout<<"      ";s_c_o_r_e__change+=0;break;}
		case 2:{std::cout<<"  2   ";s_c_o_r_e__change+=2;break;}
		case 3:{std::cout<<"  4   ";s_c_o_r_e__change+=4;break;}
		case 4:{std::cout<<"  8   ";s_c_o_r_e__change+=8;break;}
		case 5:{std::cout<<"  16  ";s_c_o_r_e__change+=16;break;}
		case 6:{std::cout<<"  32  ";s_c_o_r_e__change+=32;break;}
		case 7:{std::cout<<"  64  ";s_c_o_r_e__change+=64;break;}
		case 8:{std::cout<<" 128  ";s_c_o_r_e__change+=128;break;}
		case 9:{std::cout<<" 256  ";s_c_o_r_e__change+=256;break;}
	   case 10:{std::cout<<" 512  ";s_c_o_r_e__change+=512;break;}
	   case 11:{std::cout<<" 1024 ";s_c_o_r_e__change+=1024;break;}
	   case 12:{std::cout<<" 2048 ";s_c_o_r_e__change+=2048;break;}
	   case 13:{std::cout<<" 4096 ";s_c_o_r_e__change+=4096;break;}		
	}
	return s_c_o_r_e__change;
}
void intro(){

	system("cls");
	std::cout<<"\n"<<	                                                                                         
    "\n\t\t                                       |||                                   "        <<
    "\n\t\t        .-._________                  (o o)                    ______.-.       "            <<
    "\n\t\t    ----/  _)_______)    +-------------(_)----------------+  (_______(_/ ---- "          <<
    "\n\t\t     (    ()___)          |                             |       (___()     ) "       <<      
    "\n\t\t          ()__)           |          ADD_IT             |        (__()       "    <<        
    "\n\t\t ----/___()_)             |                             |        (_()___/---- " <<         
    "\n\t\t                        +-|-----------------------------|-+                          \n\n";        

}
int structure(int mat[17],int pm[4]){
		
	system("cls");
	system("COLOR 0A");
	intro();//title();
//	std::cout<<"\n \n\t SCORE ="<<score;
	std::cout<<"\t_________________________________	                                                                   ";
	std::cout<<"\n\t| _____________________________ |	               ****MOVES****                                       ";
	std::cout<<"\n\t| |      |      |      |      | |             ^ TO ADD LEFT  TO RIGHT : "<<(char)pm[2]<<"   &  "<<(char)right_arrow;
	std::cout<<"\n\t| |"																							   	;		
	score=v_v(mat[1],score)																									   	;
	std::cout<<"|"																									   	;
	score=v_v(mat[2],score)																											;
	std::cout<<"|"																										;
	score=v_v(mat[3],score)																											;
	std::cout<<"|"                                                                                                      ;
	score=v_v(mat[4],score)                                                                                                         ;
	std::cout<<"| |             ^ TO ADD RIGHT TO LEFT  : "<<(char)pm[0]<<"   &  "<<"<-";
	std::cout<<"\n"
		<<(char)blank_space
		<<(char)blank_space
		<<(char)blank_space
		<<(char)blank_space
		<<(char)blank_space
		<<(char)blank_space
		<<(char)blank_space
		<<(char)blank_space
		<<"| |______|______|______|______| |             ^ TO ADD UP    TO DOWN  : "<<(char)pm[3]<<"   &  "<<(char)down_arrow;
	std::cout<<"\n\t| |      |      |      |      | |             ^ TO ADD DOWN  TO UP    : "<<(char)pm[1]<<"   &  "<<(char)up_arrow;
	std::cout<<"\n\t| |"																								;
	score=v_v(mat[5],score)																											;
	std::cout<<"|"                          																			;
	score=v_v(mat[6],score)																											;
	std::cout<<"|"																										;	
	score=v_v(mat[7],score)																											;
	std::cout<<"|"																										;
	score=v_v(mat[8],score)																											;
	std::cout<<"| |                                                                                                    ";
	std::cout<<"\n\t| |______|______|______|______| |              														";
	std::cout<<"\n\t| |      |      |      |      | |                                                                      ";
	std::cout<<"\n\t| |"																								;
	score=v_v(mat[9],score)																											;
	std::cout<<"|"																										;
	score=v_v(mat[10],score)																										;
	std::cout<<"|"																										;
	score=v_v(mat[11],score)																										;
	std::cout<<"|"																										;
	score=v_v(mat[12],score)                                                                                                        ;
	std::cout<<"| |                                                                                                    ";
	std::cout<<"\n\t| |______|______|______|______| |                                                                      ";
	std::cout<<"\n\t| |      |      |      |      | |                                                                      ";
	std::cout<<"\n\t| |"                                                                                                ;
	score=v_v(mat[13],score)																										;
	std::cout<<"|"                                                                                                      ;
	score=v_v(mat[14],score)                                                                                                        ;
	std::cout<<"|"                                                                                                      ;
	score=v_v(mat[15],score)                                                                                                        ;
	std::cout<<"|"																										;
	score=v_v(mat[16],score)                                                                                                        ;
	std::cout<<"| |                                                                                                    ";
	std::cout<<"\n\t| |______|______|______|______| |                            ";
	std::cout<<"\n\t|_______________________________|	                                                                   ";
	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];
}
int new_value(int mat[17]){	

	int n_v;
	do
	{
	std::random_device rd;
	std::uniform_int_distribution<int> dist(1,16);
	n_v=dist(rd);
	if(mat[n_v]==1)
	{
		mat[n_v]=2;
		break;
	}
	}while(443);
	
	mat[n_v]=2;
	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];	
}
int mat_val(int mat[17]){

	mat[0]=1;
	for(int ii=0;ii<17;ii++)
	{
		mat[ii]=1;
	}
	return 	mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15],mat[16];
}
#define DOWN_ARROW 80
#define UP_ARROW 72
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define ARROW 224
#define ENTER 13
void move_def(bool can_run_program,char &move_def_var){	

	 if((can_run_program==1)||(can_run_program==true))
	{
		int key__pressed;
		char key__pressed_char;
		bool end=false;
		std::cout<<"\n\n\tENTER YOUR MOVE O_O... ";
		int plus='+';
		while(!end)
		{
			key__pressed=getch();
			char key__pressed_char=toupper((char)key__pressed);
			key__pressed=key__pressed_char;
			if((key__pressed==pm[0])||(key__pressed==LEFT_ARROW))//---------------------Q
			{
				move_def_var='Q';				
				end=true;
			}
			else if((key__pressed==pm[1])||(key__pressed==UP_ARROW))//-----------------W
			{
				move_def_var='W';							
				end=true;
			}
			else if((key__pressed==pm[2])||(key__pressed==RIGHT_ARROW))//-----------------E
			{
				move_def_var='E';							
				end=true;
			}
			else if((key__pressed==pm[3])||(key__pressed==DOWN_ARROW))//-----------------S
			{
				move_def_var='S';							
				end=true;
			}
			else if(key__pressed==plus)//--------------------+
			{
				move_def_var='+';							
				end=true;			
			}			
		}
	}
	else //if((can_run_program==0)||(can_run_program==false))
	{
		std::cout<<"\n\n\tTHE GAME OVER";
		move_def_var='D';			
	}
	//return move_def_var;
}
bool check_for_out(int mat[17],char move){
	
	if(move=='+')
	{
	return false;	
	}
	else
	{
		bool check_win_var=false;
		for(int ik=1;ik<16;ik++)
		{
			if(mat[ik]==mat[ik+1])
		{
			check_win_var=true;
			break;
		}
		}
		for(int ik=1;ik<12;ik++)
		{
			if(mat[ik]==mat[ik+4])
		{
			check_win_var=true;
			break;
		}
		}
	return check_win_var;
	}
}
//-----------main function------------------
void start_game(){
	
	bool havemove=true;
	char move;
	score=0;
	mat_val(mat);
	do
	{
		new_value(mat);
		structure(mat,pm);
		move_def(havemove,move);
		havemove=check_for_out(mat,move);
		if(move=='+')
		{
			structure(mat,pm);
			move_def(false,move);
			havemove=false;
			goto end_loop;
		}
		goto_move(move,mat);
		new_value(mat);
		//----------------------
		structure(mat,pm);
		move_def(havemove,move);
		havemove=check_for_out(mat,move);
		if(move=='+')
		{
			structure(mat,pm);
			move_def(false,move);
			havemove=false;
			goto end_loop;
		}
		goto_move(move,mat);		
		end_loop:
		;
	}while(havemove);
}
int program_position;
void kv2_choice(int &pos,int &en,bool &end_loop ){ 

	enter:
	switch(pos)
	{
	case 0:
		  pos=4;
		  en=pos;
		  goto enter;
		  break;			
	case 1:
	std::cout<<"\t\t\t\t\t\t=> START GAME <=\n"
			 <<"\t\t\t\t\t\t   HIGH SCORE\n "
			 <<"\t\t\t\t\t\t    SETTINGS \n"
			 <<"\t\t\t\t\t\t     QUIT\t "
			 ;
			 en=pos;
			 break;
	case 2:
	std::cout<<"\t\t\t\t\t\t   START GAME\n"
			 <<"\t\t\t\t\t\t=> HIGH SCORE <=\n"
			 <<"\t\t\t\t\t\t    SETTINGS \n"
			 <<"\t\t\t\t\t\t     QUIT\t "
			 ;
			 en=pos;
			 break;
	case 3:
	std::cout<<"\t\t\t\t\t\t   START GAME\n"
			 <<"\t\t\t\t\t\t   HIGH SCORE \n"
			 <<"\t\t\t\t\t\t=>  SETTINGS <=\n"
			 <<"\t\t\t\t\t\t     QUIT\t "
			 ;
			 en=pos;
			 break;
	case 4:
	std::cout<<"\t\t\t\t\t\t   START GAME\n"
			 <<"\t\t\t\t\t\t   HIGH SCORE \n"
			 <<"\t\t\t\t\t\t    SETTINGS \n"
			 <<"\t\t\t\t\t\t=>   QUIT   <=\t"
			 ;
			 en=pos;
			 break;
	case 5:
		  pos=pos-4;
		  en=pos;
		  goto enter;
		  break;
	case 100:
		switch(en)
		{
			case 4:             break;
			case 1:start_game();end_loop=true;en=1;break;
			case 2:std::cout<<"\n\t\tITS ON DEVELOPMENT.......\n\t\t\t";system("pause");en=2;pos=2;cls;intro();goto enter;break;
			case 3:std::cout<<"\n\t\tITS ON DEVELOPMENT.......\n\t\t\t";system("pause");en=3;pos=3;cls;intro();goto enter;break;
		}
		break;
	}
}
int king_v2(){
	
	re_com:
	int enter=1;
	bool end=false;//by default
	bool end_loop=false;
	program_position=1;//by default it is in start_game	
	system("cls");
	system("COLOR 09");
	int key__pressed;
	arrow_move:
	intro();//it is in the header file ----------- "basic_structure_ver2.h"
	kv2_choice(program_position,enter,end_loop);
	if(end_loop==true)
	{
		goto re_com;
	}
	arrow_re:
	while(!end)//NOT opertor to invert the value of result
	{
		key__pressed=getch();
		switch(key__pressed)
		{
		case       ARROW:   goto arrow_re;                                                break;
		case  DOWN_ARROW:   program_position+=1;  goto arrow_move; break;
		case    UP_ARROW:   program_position-=1;  goto arrow_move; break;
		case  LEFT_ARROW:   program_position-=1;  goto arrow_move; break;
		case RIGHT_ARROW:   program_position+=1;  goto arrow_move; break;
		case       ENTER:   int rough=program_position;
							if(rough==4)
							{
								end=true;
							}
							else
							{
							program_position=100;
							goto arrow_move;             
							}
							break;
		}
	}
	return 4;
}
int main()//version 002
{
	system("cls");
	system("color 0A");
	king_v2();
	return 1;
}