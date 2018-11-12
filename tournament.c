#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tournament.h"

Player * draftPlayers(char *filename, int team, int num_players){
	Player *teamMember = malloc( num_players * sizeof(Player) ); 
	FILE *f = fopen("players.dat" , "r" );
	char str[100];
	int i = 0;
	while(fgets(str, sizeof(str), f)){
		char *ch = strtok(str, ",");
		if(atoi(ch) == team){
			teamMember[i].team = atoi(ch);
			teamMember[i].first = strdup(strtok(NULL, ","));
			teamMember[i].last = strdup(strtok(NULL, ","));
			teamMember[i].number = atoi(strtok(NULL , ","));
			teamMember[i].offensive = atoi(strtok(NULL, ","));
			teamMember[i].defensive = atoi(strtok(NULL, ","));
			i++;
			}
		}
	fclose(f);
	return teamMember;
}

Team * newTeam(char *name, Player *players){
	Team *t = malloc(sizeof(Team));
	t -> name = malloc(sizeof(strlen(name+1)));
	strcpy(t -> name, name);
	t -> players = players;
	t -> delete = &deleteTeam;
	return t;
}

Team * game(Team *t1, Team *t2){
	if(t1 == NULL && t2 == NULL){
		return NULL;
	}
	else{
		int count1 = 0, count2 = 0;
		int t_o1 = 0, t_o2 = 0, t_d1 = 0, t_d2 = 0, i;
		for(i = 0; i < 10; i++){
			t_o1 +=t1->players[i].offensive;
			t_d1 +=t1->players[i].defensive;
		}
		for(i = 0; i < 10; i++){
		       t_o2 += t2->players[i].offensive;
	       	       t_d2 += t2->players[i].defensive;
		}	       
		for(i=0; i<2 ; i++){
			if(t_d1 > rand() % t_o2){
				count2++;
			}
			else
				count1++;
		}
		for(i = 0; i < 2; i++){
			if(t_d2 > rand() % t_o1)
				count1++;
			else
				count2++;
		}
		if(count2 > count1)
			return t2;
		else
			return t1;

			
		
	}
}

Team * tournament(Team ** team, int num_teams){
	int check = 2;
	int count = 1;
	int x = 0;
	while( num_teams > check){
		check = check*2;
		count ++;
	}
	if(check != num_teams){
		return NULL;
	}
	int match[num_teams];
	for(int i = 0 ; i < num_teams; i++){
		match[i] = i;
	}
	for(int i = 0; i < 50; i++){
		int p = rand() % num_teams;
		int q = rand() % num_teams;
		x = match[p];
		match[p] = match[q];
		match[q] = x;
	}
	Team *t = team[match[0]];
	for(int i = 1; i < num_teams; i++){
	       t = game(t, team[match[i]]);
	}	       
	return t;
}


void deleteTeam(Team *team){
//	free(team -> name);
	free(team -> players);
//	free(team -> delete);
//	team = NULL;
	free(team);
	
//	return NULL;
}

