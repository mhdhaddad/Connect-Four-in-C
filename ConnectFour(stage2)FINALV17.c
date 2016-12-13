/**********************************
 * ********Connect four********** * 
 * Mohammad Haddad                *
 * Thanks to my dearest teachers  *
 **********************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define col 7
#define row 6
/*
yet to change all 6s and all 7s with these constants to ease any later changes!!!! 
*/

int c[6];
int i=0,j=0,choice=0,turn=1,t=-1,k=2,w=0;
char color,mat[row][col];

void con (char matj[row][col]);
int bestgame(char matf[row][col]);
void print(char matp[row][col]);
void win (void);

int bestgame(char matf[row][col])/*This functun returns value from 1 -> 7*/
{
    int a=0;
	for (i=0;i<6;i++)
	{
		for (j=0;j<4;j++)
		{
            if ((matf[i][j]=='W'||matf[i][j]=='B')&&matf[i][j]==matf[i][j+1]&&matf[i][j+2]==' ')
            {
                a=j+2;
//                printf("Best game is %d",a+1);
//                system("pause");
                return ++a;
            }
        }
        for (j=6;j>2;j--)
        {
            if ((matf[i][j]=='W'||matf[i][j]=='B')&&matf[i][j]==matf[i][j-1]&&matf[i][j-2]==' ')
            {
                a=j-2;
//                printf("Best game is %d",a+1);
//                system("pause");
                return ++a;
            }
        }
    }
    
	for (i=0;i<3;i++)
	{
		for (j=0;j<7;j++)
		{           
            if ((matf[i][j]=='W'||matf[i][j]=='B')&&matf[i][j]==matf[i+1][j]&&matf[i+2][j]==' ')
            {
                a=j;
//                printf("Best game is %d",a+1);
//                system("pause");
                return ++a;
            }
        }
    }
    srand(time(NULL));
    a=rand()%7+1;
//    printf("Rand game is %d",a);system("pause");
    return a;
}

void win (void)
{

/*this print gives false value for some reason 

    print(mat);

*/
    if (turn<0) printf(" White is the winner!!!\n");
    else printf(" Black is the winner!!!\n");
    system("pause");
    exit(0);
}


void con (char matj[row][col])
{
	for (i=0;i<6;i++)
	{
		for (j=0;j<4;j++)
		{
            if ((matj[i][j]=='W'||matj[i][j]=='B')
            &&matj[i][j]==matj[i][j+1]&&matj[i][j]==matj[i][j+2]&&matj[i][j]==matj[i][j+3]) 
            {
                printf("\nwin by row\n\n");
                win ();
            }
        }
    }

	for (i=0;i<3;i++)
	{
		for (j=0;j<7;j++)
		{            
            if ((matj[i][j]=='W'||matj[i][j]=='B')
            &&matj[i][j]==matj[i+1][j]&&matj[i][j]==matj[i+2][j]&&matj[i][j]==matj[i+3][j])
            {
                printf("\nwin by column\n\n");
                win ();
            }
        }
    }

	for (i=0;i<3;i++)
	{
		for (j=0;j<4;j++)
		{
            if ((matj[i][j]=='W'||matj[i][j]=='B')
            &&matj[i][j]==matj[i+1][j+1]&&matj[i][j]==matj[i+2][j+2]&&matj[i][j]==matj[i+3][j+3])
            {
                printf("\nwin by cross to right\n\n");
                win ();
            }
        }
    }

	for (i=0;i<3;i++)
	{
		for (j=3;j<7;j++)
		{
            if ((matj[i][j]=='W'||matj[i][j]=='B')
            &&matj[i][j]==matj[i+1][j-1]&&matj[i][j]==matj[i+2][j-2]&&matj[i][j]==matj[i+3][j-3])
            {
                printf("\nwin by cross to left\n\n");
                win ();
            }
        }
    }
    //draw
    w=0;
 	for (i=0;i<6;i++)
	{
		for (j=0;j<7;j++)
    	{
            if (mat[i][j]!=' ') w++;
        }
    }
    if (w==42)
    {
        printf("Draw!!!");
        system("pause");
        exit (0);
    }   
}

void print(char matp[row][col])
{
    system("cls");
	for (j=1;j<=7;j++)
	{
        printf("%5d\t",j);
    }
    printf("\n");
	for (i=5;i>=0;i--)
	{
        
		for (j=0;j<7;j++)
		{
			printf("|%4c\t",matp[i][j]);
		}
		printf("|\n---------------------------------------------------------\n");
	}
}/*END OF PRINT*/



int main()
{
    //formating the matrix!!!!!
	for (i=0;i<6;i++)
	{
		for (j=0;j<7;j++)
    	{
            mat[i][j]=' ';
        }
    }
    for (i=0;i<row;i++)
    {
        c[i]=0;
    }   
     
    system("color 64");
        
    //Game Start Here!!!!!
    printf("Please enter which color you want to play?(w)hite,(b)lack,(2)for two players!!!!\n");
    scanf("%c",&color);
    if(color=='w')
    {
        k = 1;
    }
    else  if (color=='b')
    {
        k = 2;
    }
    print(mat);  
    for(;;)
    {
        turn = pow(t,k);
        if (turn<0)
        {
            system("color 6f");
            if (color!='b')
            {
                printf("White to play, please enter where to place?\n");
                scanf("%d",&choice);
                if (c[choice-1]>5) {printf("Column is full, try another one"); continue;}
                if ((choice>7)||(choice<1)) {printf("wrong value"); continue;}
                choice--;
                mat[c[choice]][choice]='W';
                print(mat);
            }
            else 
            {                    
                choice=bestgame(mat);
                if (c[choice-1]>5) {printf("Column is full, wrong computer move");system("pause"); continue;}
                choice--;
//                printf("to play in %d",choice);
//                system("pause");
                mat[c[choice]][choice]='W';
                print(mat);  
            }     	
            c[choice]++;
            con(mat);
            k++;
        }
        else if (turn>0)
        {
            system("color 60");
        	
            if (color!='w')
            {
                
                printf("Black to play, Please enter where to place?\n");
                scanf("%d",&choice);
                if (c[choice-1]>5) {printf("Column is full, try another one"); continue;}
                if ((choice>7)||(choice<1)) {printf("wrong value"); continue;}
                choice--;
                mat[c[choice]][choice]='B';
           	    print(mat);
            }
            else 
            {                    
                choice=bestgame(mat);
                if (c[choice-1]>5) {printf("Column is full, wrong computer move");system("pause"); continue;}
                choice--;
//                printf("to play in %d",choice);
//                system("pause");
                mat[c[choice]][choice]='B';
                print(mat);
            } 	
            c[choice]++;
            con(mat);
            k++;
        }            	
    }
    system("pause");
    return 0;
}/*End of MAIN*/ 
