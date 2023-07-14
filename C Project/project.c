#include<stdio.h>
typedef struct player
{
	int jeresy_no; 
	int runs;
	int wickets;
	int no_of_matches;
	char name[20];
}player;
 
int t=2;
void top_players_wickets(player*); //function decleration
void top_players_runs(player*); //function decleration
void update(player*); //function decleartion
void delete_player(player*); //function declearation
void store(player*); //function declearation
void display(player*); //function declearation
void search(player*); //function declearation
void main()
{	
    int choice;
    printf("Enter how many player you want add:");
    scanf("%d",&t);  
    player p[t];
   do{
   	   printf("1.Store \n2.Display \n3.Search \n4.Delete \n5.Update \n6.Top 3 players by runs \n7.Top 3 players by wickets\n**************\nEnter your choice:");
   	   scanf("%d",&choice);
   	    switch(choice)
		{
   	   	     case 1:store(p);
   	   	     break; 
   	   	     
   	   	     case 2:display(p);
   	   	     break;
   	   	      
   	   	     case 3:search(p);
   	   	     break;
   	   	     
   	   	     case 4:delete_player(p);
   	   	     break;
   	   	     
   	   	     case 5:update(p);
   	   	     break;
   	   	     
   	   	     case 6:top_players_runs(p);
   	   	     break;
   	   	     
   	   	     case 7:top_players_wickets(p);
   	   	     break;
   	   	       
   	   	     default :
   	   	     	printf("Invalid Choice");     	   
		}
			fflush(stdin);
			printf("\nDo you want to continue?(Y/N): ");
			scanf("%c",&choice);
     }while (choice=='Y'||choice=='y');
}
//store
void store(player* p)
{
	int i;
	for(i=0;i<t;i++)
	{
	printf("Enter the jeresy_no:");
	scanf("%d",&p[i].jeresy_no);
	printf("Enter player name:");
	scanf("%s",&p[i].name);
	printf("Enter player Runs:");
	scanf("%d",&p[i].runs);
	printf("Enter the wickets:");
	scanf("%d",&p[i].wickets);
	printf("Enter the number of matches:");
	scanf("%d",&p[i].no_of_matches);
	printf("***********\n");
	}
}
//display 
void display(player* p)
{
	int i;
	for(i=0;i<t;i++)
	{
		printf("player Jercy No: %d  \nPlayer Name: %s  \nPlayer Runs: %d  \nNo of Matches: %d  \nWickets: %d",p[i].jeresy_no,p[i].name,p[i].runs,p[i].wickets,p[i].no_of_matches);
		printf("\n***********\n");	
	}	
}
//search for number
void search(player* p)
{
	int i,search_jersey,x,flag=0;
	int ch;
	printf("Enter the choice for 1(jersey number) & 2(jersey name): ");
	scanf("%d",&ch);
	if (ch==1 || ch==2)
 {
	if (ch==1)
	{
		printf("\nEnter the jersey number to search: ");
	    scanf("%d",&search_jersey);
	    for(i=0;i<t;i++)
	    {	
		    if(p[i].jeresy_no==search_jersey)
		    {
		    		printf("\nPlayer is found!!!\n");
		    		printf("\nPlayer Name is: %s",p[i].name );
		    		printf("\nplayer Jercy No is: %d",p[i].jeresy_no);
		    		printf("\nRuns: %d",p[i].runs);
		    		printf("\nwickets: %d",p[i].wickets);
		    		printf("\nMatches: %d\n",p[i].no_of_matches);
		    		flag =1;
		    		break;		
			}	   
		}
		if(flag==0)
		{
			 printf("Player is NOT found!!!");
		}     
	}				
	else if (ch==2)
	{
		char n[20];
		flag = 0;
		printf("\nEnter the jersey name to search: \n");
		scanf("%s",&n);
		for(i=0;i<t;i++)
        {	
	    	x=strcmp(n,p[i].name);
	    	if(x==0)
	    	{
	    		printf("\nPlayer is found!\n");
	    		printf("\nPlayer Name is: %s",p[i].name );
	    		printf("\nplayer Jercy No is: %d",p[i].jeresy_no);
	    		printf("\nRuns: %d",p[i].runs);
	    		printf("\nwickets: %d",p[i].wickets);
	    		printf("\nMatches: %d\n",p[i].no_of_matches);
	    		flag =1;
	    	    break;
			}	   
	     }if(flag==0)
			{
				 printf("Player is NOT found!!!");
			}     
	}	   	
 }else
       printf("Invalid Data");  	
}

//delete player	
void delete_player(player* p)
{
	int i,delete_jersey,flag=0;
	int j;
	printf("\nEnter the jersey number of player you want to delete: \n");
	scanf("%d",&delete_jersey);
	for(i=0;i<t;i++)
	{
		if(p[i].jeresy_no==delete_jersey)
		{
			for (j=1; j<t-1; j++)
			{
				p[j]=p[j+1];
			}
			  flag=1;
			  t=t-1; 
		}
	} 
	    if(flag==1)	
	    {
	    	printf("Player with jersey number %d has been deleted \n",delete_jersey);
		}
		else{
			    printf("Player with jersey number %d is Not found \n",delete_jersey);
}
		    }

//update
void update(player* p)
{
	int i,update_player,flag=0;
	printf("Enter the player jersey number you want to update: ");
	scanf("%d", &update_player);
	
	for(i=0; i<t; i++)
	{
		if(p[i].jeresy_no==update_player)
		{
			printf("*******************\n");
			printf("Fill information for update player");
			printf("\nEnter the jeresy_no:");
			scanf("%d",&p[i].jeresy_no);
			printf("Enter player name:");
			scanf("%s",&p[i].name);
			
			printf("Enter player Runs:");
			scanf("%d",&p[i].runs);
			printf("Enter the wickets:");
			scanf("%d",&p[i].wickets);
			printf("Enter the number of matches:");
			scanf("%d",&p[i].no_of_matches);
			flag=1;
			break;
		}
	}if (flag==1)
	       {
	       	printf("Player update successfully...!\n");
		  }
		 else
			{
				printf("\nInvalid entry!!");
			}
}

//top 3 playes by runs
void top_players_runs(player* p)
{
    int i, j;
    player temp;	
    // Sort the array by runs
    for (i = 0; i < t; i++) 
	{ 
        for (j = 0; j < t-i-1; j++) 
        
		{
            if (p[j].runs < p[j+1].runs) 
			{
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    printf("\nTop 3 players by runs=> \n\n");
    // Print the top 3 players
    for (i = 0; i < 3; i++) 
	{
        printf("Name: %s\n", p[i].name);
        printf("Runs: %d\n", p[i].runs);
        printf("Jersey number: %d\n", p[i].jeresy_no);
        printf("\n");
    }
}

//top 3 playes by wickets
void top_players_wickets(player* p)
{ 
    int i, j;
    player temp;
    // Sort the array by wickets
    for (i = 0; i < t; i++)   
	{
        for (j = 0; j < t-i-1; j++)  
		{
            if (p[j].wickets < p[j+1].wickets) 
			{
                temp = p[j];
                p[j] = p[j+1];     
                p[j+1] = temp;
            }
        }
    }
    printf("\nTop 3 players by wickets=> \n\n");
    // Print the top 3 wickets
    for (i = 0; i < 3; i++) 
	{
        printf("Name: %s\n", p[i].name);
        printf("wickets: %d\n", p[i].wickets);
        printf("Jersey number: %d\n", p[i].jeresy_no);
        printf("\n");
    }
}
