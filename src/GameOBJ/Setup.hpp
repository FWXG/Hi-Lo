#pragma once
#include <iostream>
#include <cstdlib>

enum controlKeys
{
	FORWARD,
	LEFT,
	RIGHT,
	BACK
};

namespace game {

	class Setup {

		int m_movement;
		const char* upAndDownWall = "#########################";
		const char* leftAndRightWall = "#                       #";

	public:

		int controls(int move);
		void printWalls();

	};
}