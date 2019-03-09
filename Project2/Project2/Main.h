#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char byte;

typedef enum Team
{
	RED,
	BLUE
}team;

struct Character
{
	struct Character *self;

	char *name;	
	unsigned int health;
	int AD;                 //Attack Damage
	team team;
	int Frags;


	void(*attack) (struct Character * self, struct Character * enemy);
	void(*heal) (struct Character *self);
	int(*HPbar) (struct Character *self);
};

void attack(struct Character *self, struct Character *enemy)
{
	if (!(self->team == enemy->team))
	{
		printf("%s(ad-%d, hp-%d) -> %s(%d, %d)",
			self->name, self->AD, self->HPbar(self),
			enemy->name, enemy->AD, enemy->HPbar(self));
		enemy->health -= self->AD;
		if (enemy->HPbar <= 0)
		{
			self->AD += 5;
			self->Frags += 1;
			printf("%s expired, RIP", enemy->name);
			free(enemy);
		}
		return;
	}
	printf("%s tried to kill he's teammate ! What a coinsidence...", self->name);
	
}

void heal(struct Character *self)
{
	printf("%s Healed !", self->name);
	self->health += self->AD-1;
}
int HPbar(struct Character *self)
{
	return self->health;
}

void Init(struct Character *self, const char *name, enum Team team)
{
	char * strteam;
	if(team == BLUE)
	{
		strteam = "Blue";
	}
	else if (team == RED)
	{
		strteam = "Red";
	}

	self->AD = 11;
	self->health = 100;
	self->name = (char *) name;
	self->team = team;
	self->Frags = 0;
	self->attack = attack;
	self->heal = heal;
	self->HPbar = HPbar;
	printf("%s %s Is ready to fight!\n",strteam, self->name);
}