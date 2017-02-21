#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "creatures.h"

// Use this file to add all utility functions, like calculating combat results

void hero_name_scan(char** pheroname)//Ask Hero Name
{
	printf("\n\n Enter your hero name: ");
	int name_space = 15;
	*pheroname = (char*)malloc(name_space);
	fflush(stdin);
	scanf("%s", *pheroname);
}

void capitalize(char* capital)//Capitalizes All Hero Name
{
	unsigned int counter = 0;

	while (capital[counter] != '\0')
	{
		if (capital[counter] >= 97 && capital[counter] <= 122)
		{
			capital[counter] -= 32;
		}
		counter++;
	}
}

void levels(monster_data goblin, hero_data hero)
{
	hero.xp = 0;
	hero.coins = 0;

	for (int level = 1; level < 5; level++)//4 Levels Vs. Goblins, 1 Level Vs. GOBLOOM (Boss)
	{
		char market;

		if (level = 1)
		{
			getchar();

			printf("\n + Let's see what you're made of. ");
			getchar();

			printf("\n + GET READY FOR THE FIRST LEVEL! ");
			getchar();

			combat(goblin, hero);

			if (hero.combat.hp > 0)//HERO UPDATES (1ST LEVEL)
			{
				int xp = rand() % (26 - 11) + 11;
				int coins = rand() % (76 - 21) + 21;

				printf("\n + Along this battle you gained %d XP and %d COINS. ", xp, coins);
				getchar();
				
				hero.xp += xp;
				hero.coins += coins;

				if (hero.coins >= 25)
				{
					printf("\n _____________________________________________________________________________");
					printf("\n            You now have %d COINS, do you want to trade them (- 25)? ", hero.coins);
					printf("\n  ([H] to increase HP and ARMOR / [A] to increase ATTACKS / [ENTER] to avoid) ");
					scanf("%c", &market);

					if (market == 'h' || market == 'H')
					{
						hero.combat.hp += 100;
						hero.combat.armor += 25;

						hero.coins -= 25;

						printf("\n                Your HP has been raised to %d and ARMOR to %d! ", hero.combat.hp, hero.combat.armor);
						printf("\n                        %d COINS left in your pocket. ", hero.coins);
						getchar();
					}

					else if (market == 'a' || market == 'A')
					{
						hero.combat.attack_min += 50;
						hero.combat.attack_max += 100;

						hero.coins -= 25;

						printf("\n          Your ATTACK_MIN has been raised to %d and ATTACK_MAX to %d! ", hero.combat.attack_min, hero.combat.attack_max);
						printf("\n                        %d COINS left in your pocket. ", hero.coins);
						getchar();
					}
				}
				else if (hero.coins < 25)
				{
					printf("\n _____________________________________________________________________________");
					printf("\n                  You don't have enough COINS to purchase. ");
				}
			}
		}

		if (level = 2)
		{
			getchar();

			printf("\n\n + You survived. Not bad. ");
			getchar();

			printf("\n + GET READY FOR THE SECOND LEVEL! ");
			getchar();
			
			goblin.combat.hp  += (rand() % (76 - 26) + 26);
			goblin.combat.attack_min += (rand() % (56 - 26) + 26);
			goblin.combat.attack_max += (rand() % (76 - 56) + 56);
			goblin.combat.armor += (rand() % (56 - 26) + 26);

			combat(goblin, hero);

			if (hero.combat.hp > 0)//HERO UPDATES (1ST LEVEL)
			{
				int xp = rand() % (51 - 26) + 26;
				int coins = rand() % (101 - 56) + 56;

				printf("\n + Along this battle you gained %d XP and %d COINS. ", xp, coins);
				getchar();

				hero.xp += xp;
				hero.coins += coins;

				if (hero.coins >= 75)
				{
					printf("\n _____________________________________________________________________________");
					printf("\n            You now have %d COINS, do you want to trade them (- 75)? ", hero.coins);
					printf("\n  ([H] to increase HP and ARMOR / [A] to increase ATTACKS / [ENTER] to avoid) ");
					scanf("%c", &market);

					if (market == 'h' || market == 'H')
					{
						hero.combat.hp += 200;
						hero.combat.armor += 50;

						hero.coins -= 75;

						printf("\n                Your HP has been raised to %d and ARMOR to %d! ", hero.combat.hp, hero.combat.armor);
						printf("\n                        %d COINS left in your pocket. ", hero.coins);
						getchar();
					}

					else if (market == 'a' || market == 'A')
					{
						hero.combat.attack_min += 100;
						hero.combat.attack_max += 200;

						hero.coins -= 75;

						printf("\n          Your ATTACK_MIN has been raised to %d and ATTACK_MAX to %d! ", hero.combat.attack_min, hero.combat.attack_max);
						printf("\n                        %d COINS left in your pocket. ", hero.coins);
						getchar();
					}
				}
				else if (hero.coins < 75)
				{
					printf("\n _____________________________________________________________________________");
					printf("\n         You don't have enough COINS to purchase, control your pocket. ");
				}
			}
		}

		if (level = 3)
		{
			getchar();

			printf("\n\n + Hmm... You seem to be enough brave to fight some goblins. ");
			getchar();

			printf("\n + GET READY FOR THE THIRD LEVEL! ");
			getchar();

			goblin.combat.hp += (rand() % (151 - 101) + 101);
			goblin.combat.attack_min += (rand() % (76 - 26) + 26);
			goblin.combat.attack_max += (rand() % (126 - 76) + 76);
			goblin.combat.armor += (rand() % (76 - 26) + 26);

			combat(goblin, hero);

			if (hero.combat.hp > 0)//HERO UPDATES (1ST LEVEL)
			{
				int xp = rand() % (76 - 56) + 56;
				int coins = rand() % (151 - 101) + 101;
				printf("\n + Along this battle you gained %d XP and %d COINS. ", xp, coins);
				getchar();

				hero.xp += xp;
				hero.coins += coins;

				if (hero.coins >= 125)
				{
					printf("\n _____________________________________________________________________________");
					printf("\n           You now have %d COINS, do you want to trade them (- 125)? ", hero.coins);
					printf("\n  ([H] to increase HP and ARMOR / [A] to increase ATTACKS / [ENTER] to avoid) ");
					scanf("%c", &market);

					if (market == 'h' || market == 'H')
					{
						hero.combat.hp += 300;
						hero.combat.armor += 100;

						hero.coins -= 125;

						printf("\n                Your HP has been raised to %d and ARMOR to %d! ", hero.combat.hp, hero.combat.armor);
						printf("\n                        %d COINS left in your pocket. ", hero.coins);
						getchar();
					}

					else if (market == 'a' || market == 'A')
					{
						hero.combat.attack_min += 150;
						hero.combat.attack_max += 300;

						hero.coins -= 125;

						printf("\n          Your ATTACK_MIN has been raised to %d and ATTACK_MAX to %d! ", hero.combat.attack_min, hero.combat.attack_max);
						printf("\n                        %d COINS left in your pocket. ", hero.coins);
						getchar();
					}
				}
				else if (hero.coins < 125)
				{
					printf("\n _____________________________________________________________________________");
					printf("\n         You don't have enough COINS to purchase, control your pocket. ");
				}

			}
		}

		if (level = 4)
		{
			getchar();

			printf("\n\n + Okay, levels are rising. Aren't you done yet? Go for it! ");
			getchar();

			printf("\n + GET READY FOR THE FORTH LEVEL! ");
			getchar();

			goblin.combat.hp *= 2;
			goblin.combat.attack_min *= 2;
			goblin.combat.attack_max *= 2;
			goblin.combat.armor *= 2;

			combat(goblin, hero);

			if (hero.combat.hp > 0)//HERO UPDATES (1ST LEVEL)
			{
				int xp = rand() % (151 - 101) + 101;
				int coins = rand() % (301 - 201) + 301;
				printf("\n + Along this battle you gained %d XP and %d COINS. ", xp, coins);
				getchar();

				hero.xp += xp;
				hero.coins += coins;

				if (hero.coins >= 200)
				{
					printf("\n _____________________________________________________________________________");
					printf("\n           You now have %d COINS, do you want to trade them (- 200)? ", hero.coins);
					printf("\n  ([H] to increase HP and ARMOR / [A] to increase ATTACKS / [ENTER] to avoid) ");
					scanf("%c", &market);

					if (market == 'h' || market == 'H')
					{
						hero.combat.hp += 500;
						hero.combat.armor += 200;

						hero.coins -= 200;

						printf("\n                Your HP has been raised to %d and ARMOR to %d! ", hero.combat.hp, hero.combat.armor);
						printf("\n                        %d COINS left in your pocket. ", hero.coins);
						getchar();
					}

					else if (market == 'a' || market == 'A')
					{
						hero.combat.attack_min += 300;
						hero.combat.attack_max += 400;

						hero.coins -= 200;

						printf("\n          Your ATTACK_MIN has been raised to %d and ATTACK_MAX to %d! ", hero.combat.attack_min, hero.combat.attack_max);
						printf("\n                        %d COINS left in your pocket. ", hero.coins);
						getchar();
					}
				}
				else if (hero.coins < 200)
				{
					printf("\n _____________________________________________________________________________");
					printf("\n         You don't have enough COINS to purchase, control your pocket. ");
				}
			}
		}
		if (level = 5)
		{
			getchar();

			printf("\n\n + %s, you're unbelievable!. ", hero.name);
			getchar();

			printf("\n + Goblins can't stop you! ");
			getchar();

			printf("\n + GET READY FOR THE FIFTH LEVEL! ");
			getchar();

			goblin.combat.hp = hero.combat.hp + (rand() % (51 - 1) + 1);
			goblin.combat.attack_min = hero.combat.attack_min + (rand() % (26 - 1) + 1);
			goblin.combat.attack_max = hero.combat.attack_max;
			goblin.combat.armor = hero.combat.armor + (rand() % (26 - 1) + 1);
			

			int goblins_inaction = 1;

			printf("\n + You came across with GOBLOOM! Things got serious! ");
			getchar();

			if (hero.combat.attack_max < goblin.combat.armor && goblin.combat.attack_max < hero.combat.armor)//Avoid Infinite Loop Without Kills
			{
				printf("\n + You and GOBLOOM, none of you are going to give up... ");
				getchar();

				printf("\n + Space Time must explode! ");
				hero.combat.attack_max = goblin.combat.armor + (rand() % (2501 - 2001) + 2001);
				goblin.combat.attack_max = hero.combat.armor + (rand() % (2501 - 2001) + 2001);
				getchar();
			}

			while (hero.combat.hp > 0 && goblins_inaction > 0)
			{
				//CHARACTERS' AVERAGE ATTACKS
				int hero_average_maxmin_attack = rand() % (hero.combat.attack_max - hero.combat.attack_min) + hero.combat.attack_min;
				int goblin_average_maxmin_attack = rand() % (goblin.combat.attack_max - goblin.combat.attack_min) + goblin.combat.attack_min;

				int hero_damage = hero_average_maxmin_attack - goblin.combat.armor;
				if (goblin.combat.armor >= hero_average_maxmin_attack)//Negative Numbers Control
				{
					hero_damage = 0;
				}

				//HERO Start to Attack
				goblin.combat.hp = goblin.combat.hp - hero_damage;
				if (goblin.combat.hp < 0)//Negative Numbers Control
				{
					goblin.combat.hp = 0;
				}
				printf("\n > %s attacks him for %d, but its %d ARMOR makes you hit for %d.", hero.name, hero_average_maxmin_attack, goblin.combat.armor, hero_damage);
				printf("\n - GOBLOOM has %d HP left. ", goblin.combat.hp);

				if (goblin.combat.hp <= 0)//If GOB Dead -> XP & COINS
				{
					printf("\n > You've knocked down GOBLOOM!", goblins_inaction);
					
					goblin.combat.hp = rand() % (51 - 11) + 11;
					
					int xp = rand() % (301 - 101) + 101;
					int coins = rand() % (501 - 251) + 251;
					hero.xp += xp;
					hero.coins += coins;

					printf("\n\n + You completed the game with %d XP and %d COINS! ", hero.xp, hero.coins);
					--goblins_inaction;
				}
				getchar();

				//GOBLOOM Starts To Attack
				int goblins_attacks = goblins_inaction;//INACTION = Alive

				while (goblins_attacks > 0)//If exists GOBLOOM attacks -> Continue fight 
				{
					goblin_average_maxmin_attack = rand() % (goblin.combat.attack_max - goblin.combat.attack_min) + goblin.combat.attack_min;

					int goblin_damage = goblin_average_maxmin_attack - hero.combat.armor;
					if (hero.combat.armor >= goblin_average_maxmin_attack)//Negative Numbers Control
					{
						goblin_damage = 0;
					}

					hero.combat.hp = hero.combat.hp - goblin_damage;
					
					if (hero.combat.hp < 0)//Negative Numbers Control
					{
						hero.combat.hp = 0;
					}

					printf("\n   - GOBLOOM punches you for %d; your %d ARMOR makes you receive %d.", goblin_average_maxmin_attack, hero.combat.armor, goblin_damage);
					printf("\n   > Are alive or not? %d HP left. ", hero.combat.hp);
					--goblins_attacks;
					getchar();

					if (hero.combat.hp <= 0)//If HERO Dead -> END PROGRAM
					{
						printf("\n -----------------------------------------------------------------------------");
						printf("\n + This can't be possible! GOBLOOM knocked you down.");
						printf("\n + Better luck next time.");
						printf("\n ----------------------------------------------------------------------------- ");
						getchar();
						exit(0);
					}
				}

				if (goblins_inaction <= 0)//If GOBLINS Dead (INACTION = 0) -> COMBAT SUCCESS
				{
					printf("\n -----------------------------------------------------------------------------");
					printf("\n + Achievement Unlocked! Kill The Final Boss.");
					printf("\n ----------------------------------------------------------------------------- ");

					if (hero.xp > 500)
					{
						printf("\n -----------------------------------------------------------------------------");
						printf("\n + Achievement Unlocked! Complete the game with more than 500 XP.");
						printf("\n ----------------------------------------------------------------------------- ");
					}

					if (hero.coins > 850)
					{
						printf("\n -----------------------------------------------------------------------------");
						printf("\n + Achievement Unlocked! Complete the game with more than 850 COINS.");
						printf("\n ----------------------------------------------------------------------------- ");
					}
					getchar();
				}
			}
		}
	}
}

void combat(monster_data goblin, hero_data hero)
{
	int goblins_inaction = rand() % (7 - 1) + 1;
	
	printf("\n + You're going to fight against %d goblin(s)! ", goblins_inaction);
	getchar();

	if (goblins_inaction > 3)//Power-Up HERO If Necessary
	{
		if (hero.combat.hp <= 15)
		{
			printf("\n + Slow down a bit %s, these conditions won't take you anywhere!", hero.name);
			printf("\n + Take a Global-Power-Up potion! Won't last forever. ");
			hero.combat.hp *= 14;
			hero.combat.attack_min *= 2;
			hero.combat.attack_max *= 4;
			hero.combat.armor *= 2;
			getchar();
		}
		else if (hero.combat.hp <= 50)
		{
			printf("\n + Slow down a bit %s, you look too bad...", hero.name);
			printf("\n + Take this Revival-Stats-Power-Up potion! It's temporarily. ");
			hero.combat.hp *= 7;
			hero.combat.attack_min *= 1;
			hero.combat.attack_max *= 1;
			hero.combat.armor += rand() % (11 - 1) + 1;
			getchar();
		}
		else if (hero.combat.hp <= 100)
		{
			printf("\n + %s, check out your HP.", hero.name);
			printf("\n + Take this Hp-Power-Up potion. You'll need it. ");
			hero.combat.hp *= 5;
			hero.combat.attack_min *= 1;
			hero.combat.attack_max *= 2;
			hero.combat.armor *= 1;
			getchar();
		}
		else if (hero.combat.hp > 100)
		{
			hero.combat.hp *= 1;
			hero.combat.attack_min *= 1;
			hero.combat.attack_max *= 1;
			hero.combat.armor *= 1;
		}
	}
	
	if (hero.combat.armor >= goblin.combat.attack_max)//Too Powerful Hero
	{
		printf("\n - Wait a moment, you carry on too much ARMOR...");
		printf("\n - Goblin(s) don't like too covered visitors. ");
	    
		if (hero.combat.hp >= 10000)
		{
		goblin.combat.attack_max = hero.combat.armor + (rand() % (501 - 151) + 151);
		goblin.combat.attack_min = hero.combat.armor;
		}
		else if (hero.combat.hp < 10000)
		{
			goblin.combat.attack_max = hero.combat.armor + (rand() % (151 - 51) + 51);
			goblin.combat.attack_min = hero.combat.armor;
		}
		else if (hero.combat.hp < 5000)
		{
			goblin.combat.attack_max = hero.combat.armor + (rand() % (51 - 26) + 26);
			goblin.combat.attack_min = hero.combat.armor;
		}
		else if (hero.combat.hp < 1000)
		{
			goblin.combat.attack_max = hero.combat.armor + (rand() % (26 - 11) + 11);
			goblin.combat.attack_min = hero.combat.armor;
		}
		else if (hero.combat.hp < 200)
		{
			goblin.combat.attack_max = hero.combat.armor + (rand() % (11 - 6) + 6);
			goblin.combat.attack_min = hero.combat.armor;
		}
		else if (hero.combat.hp < 50)
		{
			goblin.combat.attack_max = hero.combat.armor + (rand() % (6 - 1) + 1);
			goblin.combat.attack_min = hero.combat.armor;
		}
		getchar();
	}

	if (hero.combat.attack_max < goblin.combat.armor)//To Prevent Ethernal Loop (Goblins Do Not Die)
	{
		printf("\n + %s, you're not in conditions, enemy's ARMOR is too resistant", hero.name);
		printf("\n > Take this Attack-Power-Up! ");
		hero.combat.attack_max = goblin.combat.armor + goblin.combat.attack_min;
		hero.combat.attack_min = goblin.combat.armor;
		getchar();
	}
	while (hero.combat.hp > 0 && goblins_inaction > 0)
	{
		//CHARACTERS' AVERAGE ATTACKS
		int hero_average_maxmin_attack = rand() % (hero.combat.attack_max - hero.combat.attack_min) + hero.combat.attack_min;
		int goblin_average_maxmin_attack = rand() % (goblin.combat.attack_max - goblin.combat.attack_min) + goblin.combat.attack_min;

		int hero_damage = hero_average_maxmin_attack - goblin.combat.armor;
		if (goblin.combat.armor >= hero_average_maxmin_attack)//Negative Numbers Control
		{
			hero_damage = 0;
		}

		//HERO Start to Attack
		goblin.combat.hp = goblin.combat.hp - hero_damage;
		if (goblin.combat.hp < 0)//Negative Numbers Control
		{
			goblin.combat.hp = 0;
		}
		printf("\n > %s hits goblin #%d for %d, but receives %d because of %d ARMOR.", hero.name, goblins_inaction, hero_average_maxmin_attack, hero_damage, goblin.combat.armor);
		printf("\n - Goblin has %d HP left. ", goblin.combat.hp);

		if (goblin.combat.hp <= 0)//If GOB Dead -> XP & COINS
		{
			printf("\n > You've destroyed it. ", goblins_inaction);
			
			goblin.combat.hp = rand() % (51 - 11) + 11;
			--goblins_inaction;
		}
		getchar();

		//GOBLINS Starts To Attack
		int goblins_attacks = goblins_inaction;//INACTION = Alive

		while (goblins_attacks > 0)//If exists GOBLIN attacks -> Continue fight 
		{
			goblin_average_maxmin_attack = rand() % (goblin.combat.attack_max - goblin.combat.attack_min) + goblin.combat.attack_min;
			int goblin_damage = goblin_average_maxmin_attack - hero.combat.armor;
			if (hero.combat.armor >= goblin_average_maxmin_attack)//Negative Numbers Control
			{
				goblin_damage = 0;
			}

			hero.combat.hp = hero.combat.hp - goblin_damage;
			if (hero.combat.hp < 0)//Negative Numbers Control
			{
				hero.combat.hp = 0;
			}

			printf("\n   - Goblin #%d attacks you for %d, but your %d ARMOR makes you receive %d.", goblins_attacks, goblin_average_maxmin_attack, hero.combat.armor, goblin_damage);
			printf("\n   > You have %d HP left. ", hero.combat.hp);
			--goblins_attacks;
			getchar();

			if (hero.combat.hp <= 0)//If HERO Dead -> END PROGRAM
			{
				printf("\n -----------------------------------------------------------------------------");
				printf("\n + You're dead! You need to train; this is too much for you.");
				printf("\n ----------------------------------------------------------------------------- ");
				getchar();
				exit(0);
			}
		}

		if (goblins_inaction <= 0)//If GOBLINS Dead (INACTION = 0) -> COMBAT SUCCESS
		{
			printf("\n -----------------------------------------------------------------------------");
			printf("\n + You won, great job!");
			printf("\n ----------------------------------------------------------------------------- ");
			getchar();
		}
	}
}