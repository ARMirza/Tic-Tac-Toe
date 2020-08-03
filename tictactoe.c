#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int human(char box[],char coh,char change,int player,int i,int num);
int pc(char box[],char coh,char change,int player,int i,int num);
int check(char box[]);
void board(char box[]);
int winner(char box[],char coh,int i,int player);
char again();

int main()
{
    system("cls");
    int player=1,i=0,num=0;
    char box[10] = {'0','1','2','3','4','5','6','7','8','9'};
	char change,coh;
    printf( "\t\tTic Tac Toe\n");
	printf("Do u want to play with computer or human :\nC for computer \nH for human\n");
	scanf(" %c",&coh);
	if(coh=='c' || coh=='C')
    {
        pc(box,coh,change,player,i,num);
    }
    else
    {
        human(box,coh,change,player,i,num);
    }
    again();
	return 0;
}
int pc(char box[],char coh,char change,int player,int i,int num)
{
	int computer=0;

     do
	{

		board(box);
		printf( "Player 1 (X)  -  Computer (O)\n");
		if(player%2==1)
        {
            player=1;
            printf( "Enter a number :  ");
            scanf("%d",&num);
        }
        else
        {
            srand (time(NULL));
            num = (rand()%9)+1;
        }
		if(player == 1)
		 change='X' ;
		 else
		 change= 'O';
		if (num == 1 && box[1] == '1')
			box[1] = change;
		else if (num == 2 && box[2] == '2')
			box[2] = change;
		else if (num == 3 && box[3] == '3')
			box[3] = change;
		else if (num == 4 && box[4] == '4')
			box[4] = change;
		else if (num == 5 && box[5] == '5')
			box[5] = change;
		else if (num == 6 && box[6] == '6')
			box[6] = change;
		else if (num == 7 && box[7] == '7')
			box[7] = change;
		else if (num == 8 && box[8] == '8')
			box[8] = change;
		else if (num == 9 && box[9] == '9')
			box[9] = change;
		else
		{
			player--;
		}
		i=check(box);
		player++;
	}while(i==2);
    winner(box,coh,i,player);
    return 0;
}
int human(char box[],char coh,char change,int player,int i,int num)
{

   	do
	{

		board(box);
		printf( "Player 1 (X)  -  Player 2 (O)\n");
		if(player%2==1)
            player=1;
        else
            player=2;
		printf( "Player %d",  player);
        printf(" enter a number:  ");
		scanf("%d",&num);
		if(player == 1)
		 change='X' ;
		 else
		 change= 'O';
		if (num == 1 && box[1] == '1')
			box[1] = change;
		else if (num == 2 && box[2] == '2')
			box[2] = change;
		else if (num == 3 && box[3] == '3')
			box[3] = change;
		else if (num == 4 && box[4] == '4')
			box[4] = change;
		else if (num == 5 && box[5] == '5')
			box[5] = change;
		else if (num == 6 && box[6] == '6')
			box[6] = change;
		else if (num == 7 && box[7] == '7')
			box[7] = change;
		else if (num == 8 && box[8] == '8')
			box[8] = change;
		else if (num == 9 && box[9] == '9')
			box[9] = change;
		else
		{
			player--;
		}
		i=check(box);
		player++;
	}while(i==2);
    winner(box,coh,i,player);
    return 0;
}
void board(char box[])
{
    system("cls");
    printf( "\t\tTic Tac Toe\n\n");
	printf( "     |     |     \n" );
	printf( "  %c",  box[1]  );
	printf( "  |  %c",  box[2]    );
	printf( "  |  %c",  box[3]    );
	printf( "\n_____|_____|_____\n" );
	printf( "     |     |     \n" );
    printf( "  %c",  box[4]  );
	printf( "  |  %c",  box[5]    );
	printf( "  |  %c",  box[6]    );
	printf( "\n_____|_____|_____\n" );
	printf( "     |     |     \n" );
	printf( "  %c",  box[7]  );
	printf( "  |  %c",  box[8]    );
	printf( "  |  %c",  box[9]    );
	printf( "\n     |     |     \n" );
	printf( "\n\n" );

}
int check(char box[])
{
	if (box[1] == box[2] && box[2] == box[3])
		return 1;
	else if (box[4] == box[5] && box[5] == box[6])
		return 1;
	else if (box[7] == box[8] && box[8] == box[9])
		return 1;
	else if (box[1] == box[4] && box[4] == box[7])
		return 1;
	else if (box[2] == box[5] && box[5] == box[8])
		return 1;
	else if (box[3] == box[6] && box[6] == box[9])
		return 1;
	else if (box[1] == box[5] && box[5] == box[9])
		return 1;
	else if (box[3] == box[5] && box[5] == box[7])
		return 1;
	else if (box[1] != '1' && box[2] != '2' && box[3] != '3'
                    && box[4] != '4' && box[5] != '5' && box[6] != '6'
                  && box[7] != '7' && box[8] != '8' && box[9] != '9')

		return 0;
	else
		return 2;
}
int winner(char box[],char coh,int i,int player)
{
	system("cls");
	board(box);
	if(i==1)
	{
	    if((coh=='C'||coh=='c')&&player%2==1)
            printf( "Computer wins");
        else
            player--;
		printf( "Player %d", player);
		printf(" wins ");
	}
	else
		printf( "Game draw");
    return 0;
}
char again()
{
    char num;
    printf( "\nDo you want to play again Y/N : ");
    scanf(" %c", &num);
    if(num=='Y' || num=='y')
       main();
    else
        return 0;
}
