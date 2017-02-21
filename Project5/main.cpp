#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "creatures.h"

int main()
{
	// Use this file to add the main flow of code. 
	// Keep it clean using creatures.cpp to create utility functions
	// Remember to free all allocated memory with malloc

	printf("\n -----------------------------------------------------------------------------");
	printf("\n                         WELCOME TO RPG FIGHTER 17");
	printf("\n            Where Goblins Spy On You, Learn From You And Betray You");
	printf("\n -----------------------------------------------------------------------------");

	struct hero_data hero;
	hero_name_scan(&(hero.name));
	capitalize(hero.name);

	printf("\n Enter the combat stats (hp / attack-min / attack-max / armor).");
	printf("\n Suggestion, high numbers.\n\n");
	
	//HERO Entities
	int hp;
	int attack_min;
	int attack_max;
	int armor;
	
	fflush(stdin);
	printf(" HP: ");
	scanf_s("%d", &hp);
	printf(" ATTACK_MIN: ");
	scanf_s("%d", &attack_min);
		
	printf(" ATTACK_MAX: ");
	label_attack_max_check:
	scanf_s("%d", &attack_max);

	if (attack_max <= attack_min)
	{
		printf(" Insert a bigger number than ATTACK_MIN, please: ");
		goto label_attack_max_check;
	}

	printf(" ARMOR: ");
	scanf_s("%d", &armor);

	hero.combat.hp = hp;
	hero.combat.attack_min = attack_min;
	hero.combat.attack_max = attack_max;
	hero.combat.armor = armor;
	
	printf("\n NOTE: Potions may help you, but not everyone can handle them correctly... ");
	getchar();

	srand(clock());

	//GOBLIN Entities
	struct monster_data goblin;
	goblin.combat.hp = rand() % (101 - 11) + 11;
	goblin.combat.attack_min = rand() % (16 - 1) + 1;
	goblin.combat.attack_max = rand() % (51 - 16) + 16;
	goblin.combat.armor = rand() % (11 - 1) + 1;

	//COMBAT
	levels(goblin, hero);
	
	//Restart Whole Program (If Victorious)
	char yes_no_check;

	printf("\n _____________________________________________________________________________");
	printf("\n          Would you like to repeat the experience (Yes[Y]/No[Enter])? ");
	scanf_s("%c", &yes_no_check);
	
	while (yes_no_check == 'y' || yes_no_check == 'Y')
	{
		return main();
	}

	fflush(stdin);
	free(hero.name);
	return 0;
} 