#include<stdio.h>
#ifndef LEAGUE
#define LEAGUE

typedef struct Player{
	int team;
	char *first;
	char *last;
	int number;
	int offensive;
	int defensive;
}Player;

typedef struct Team{
	char *name;
	Player *players;
	void (*delete) (struct Team *);
}Team;

Player *draftPlayers(char *filename, int team, int num_players);
Team *newTeam(char *name, Player *players);
Team * tournament(Team **team, int num_teams);
Team *game(Team *t1, Team *t2);
void deleteTeam(Team *team);

#endif

