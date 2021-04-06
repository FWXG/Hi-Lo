#include "Setup.hpp"

int game::Setup::controls(int move)
{
	if (move == 'w') {};
	if (move == 'd') {};
	return 0;
}

void game::Setup::printWalls()
{
	const int wallLen = 10;
	do
	{
		//system("cls");
		std::cout << upAndDownWall << std::endl;
		for (size_t i = 0; i < wallLen; i++)
			std::cout << leftAndRightWall << std::endl;
		std::cout << upAndDownWall << std::endl;

	} while (controls(m_movement) != 'e');


}
