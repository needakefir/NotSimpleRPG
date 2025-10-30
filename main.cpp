#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
int startGame(unsigned short code,std::string& name);
int main()
{
	short code_of_exiting_game;
	srand(static_cast<unsigned int>(time(0)));
	std::string player_name;
	char Difficulty;
	std::cout << "Created by needakefir!\n";
	std::cout << "Also the link on my github:https://github.com/needakefir\n";
	std::cout << "-----------------------------------------------------------\n";
	std::cout<< "Game NotSimpleRPG!\n";
	std::cout << "Enter your nickname:";
	std::cin >> player_name;
	if (player_name == "needakefir")
		std::cout << "You're a cool boy\n";
	std::cout << "Choose a difficulty!\n";
	std::cout << "S-Simple,M-Middle,H-Hard,I-Impossible,G-Guest,if you want discover a game:";
	std::cin >> Difficulty;
	if (Difficulty != 'G' && Difficulty != 'S' && Difficulty != 'M' && Difficulty != 'H' && Difficulty != 'I')
	{
		do
		{
			std::cout << "Choose a diffculty!\n";
			std::cout << "S-Simple,M-Middle,H-Hard,I-Impossible,G-Guest,if you want discover a game:";
		} while ((Difficulty != 'G' && Difficulty != 'S' && Difficulty != 'M' && Difficulty != 'H' && Difficulty != 'I') || std::cin.fail());
	}
	switch (Difficulty)
	{
	case 'G':
		std::cout << "You choosed Guest !:\n";
		std::cout << "-----------------------------------------------------------\n";
		code_of_exiting_game=startGame(0,player_name);
		break;
	case 'S':
		std::cout << "You choosed Simple!\n";
		std::cout << "-----------------------------------------------------------\n";
		code_of_exiting_game = startGame(1,player_name);
		break;
	case 'M':
		std::cout << "You choosed Middle!\n";
		std::cout << "-----------------------------------------------------------\n";
		code_of_exiting_game = startGame(2,player_name);
		break;
	case 'H':
		std::cout << "You choosed Hard!\n";
		std::cout << "-----------------------------------------------------------\n";
		code_of_exiting_game = startGame(3,player_name);
		break;
	case 'I':
		std::cout << "You choosed Impossible!\n";
		std::cout << "-----------------------------------------------------------\n";
		code_of_exiting_game = startGame(4, player_name);
		break;
	default:
		;
	}
	return code_of_exiting_game;
}
//End.......