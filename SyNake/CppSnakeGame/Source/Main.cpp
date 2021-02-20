/* Banner

   ::::::::  :::   ::: ::::    :::     :::     :::    ::: ::::::::::
  :+:    :+: :+:   :+: :+:+:   :+:   :+: :+:   :+:   :+:  :+:
  +:+         +:+ +:+  :+:+:+  +:+  +:+   +:+  +:+  +:+   +:+
  +#++:++#++   +#++:   +#+ +:+ +#+ +#++:++#++: +#++:++    +#++:++#
		 +#+    +#+    +#+  +#+#+# +#+     +#+ +#+  +#+   +#+
  #+#    #+#    #+#    #+#   #+#+# #+#     #+# #+#   #+#  #+#
   ########     ###    ###    #### ###     ### ###    ### ##########
*/

#include<iostream>
#include<Windows.h>
#include<conio.h>

bool stop;
bool hard;

const int width = 20;
const int height = 17;

int snakeX;
int snakeY;

int itemX;
int itemY;

int point;
int tailX[100], tailY[100];

int tail;

HWND Console = GetConsoleWindow();
RECT ConsoleRect;

enum Directon
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN,
}; Directon dir;

void Gotoxy(int x, int y)
{
	Sleep(30);
	COORD pos = { x*2 ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Start()
{
	SetConsoleTitleA(" SyNake");
	GetWindowRect(Console, &ConsoleRect);
	MoveWindow(Console, ConsoleRect.bottom, ConsoleRect.top, 600, 570, true);

	stop = false;
	dir = STOP;

	snakeX = width / 2;
	snakeY = height / 2;

	itemX = rand() % width;
	itemY = rand() % height; point = 0;
}

void System()
{
	Gotoxy(width, height);

	std::cout << std::endl;
	std::cout << "   ::::::::  :::   ::: ::::    :::     :::     :::    ::: :::::::::: " << std::endl;
	std::cout << "  :+:    :+: :+:   :+: :+:+:   :+:   :+: :+:   :+:   :+:  :+:        " << std::endl;
	std::cout << "  +:+         +:+ +:+  :+:+:+  +:+  +:+   +:+  +:+  +:+   +:+        " << std::endl;
	std::cout << "  +#++:++#++   +#++:   +#+ +:+ +#+ +#++:++#++: +#++:++    +#++:++#   " << std::endl;
	std::cout << "         +#+    +#+    +#+  +#+#+# +#+     +#+ +#+  +#+   +#+        " << std::endl;
	std::cout << "  #+#    #+#    #+#    #+#   #+#+# #+#     #+# #+#   #+#  #+#        " << std::endl;
	std::cout << "   ########     ###    ###    #### ###     ### ###    ### ########## " << std::endl;
	std::cout << std::endl << std::endl;
	
	std::cout << " Position: " << snakeX << ", " << snakeY << std::endl;
	std::cout << " Tail: " << itemX << ", " << itemY << std::endl;
	std::cout << " Point:" << point << std::endl;

	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "@";
	} std::cout << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				std::cout << "@";
			}

			if (j == snakeX && i == snakeY)
			{
				std::cout << "H";
			}

			else if (j == itemX && i == itemY)
			{
				std::cout << "o";
			}

			else
			{
				bool print = false;

				for (int k = 0; k < tail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						std::cout << "O";
						print = true;
					}
				}

				if (!print)
				{
					std::cout << " ";
				}
			}

			if (j == width - 1)
			{
				std::cout << "@";
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "@";
	}std::cout << std::endl;
}

void HardSystem()
{
	Gotoxy(width, height);

	std::cout << std::endl;
	std::cout << "   ::::::::  :::   ::: ::::    :::     :::     :::    ::: :::::::::: " << std::endl;
	std::cout << "  :+:    :+: :+:   :+: :+:+:   :+:   :+: :+:   :+:   :+:  :+:        " << std::endl;
	std::cout << "  +:+         +:+ +:+  :+:+:+  +:+  +:+   +:+  +:+  +:+   +:+        " << std::endl;
	std::cout << "  +#++:++#++   +#++:   +#+ +:+ +#+ +#++:++#++: +#++:++    +#++:++#   " << std::endl;
	std::cout << "         +#+    +#+    +#+  +#+#+# +#+     +#+ +#+  +#+   +#+        " << std::endl;
	std::cout << "  #+#    #+#    #+#    #+#   #+#+# #+#     #+# #+#   #+#  #+#        " << std::endl;
	std::cout << "   ########     ###    ###    #### ###     ### ###    ### ########## " << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << " Position: " << snakeX << ", " << snakeY << std::endl;
	std::cout << " Tail: " << itemX << ", " << itemY << std::endl;
	std::cout << " Point:" << point << std::endl;

	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "@";
	} std::cout << std::endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				std::cout << "@";
			}

			if (j == snakeX && i == snakeY)
			{
				std::cout << "H";
			}

			else if (j == itemX && i == itemY)
			{
				std::cout << " ";
			}

			else
			{
				bool print = false;

				for (int k = 0; k < tail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						std::cout << "O";
						print = true;
					}
				}

				if (!print)
				{
					std::cout << " ";
				}
			}

			if (j == width - 1)
			{
				std::cout << "@";
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		std::cout << "@";
	}std::cout << std::endl;
}

void Keys()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if (dir == DOWN)
			{
				break;
			}
			dir = UP;
			break;

		case 'a':
			if (dir == RIGHT)
			{
				break;
			}
			dir = LEFT;
			break;

		case 's':
			if (dir == UP)
			{
				break;
			}
			dir = DOWN;
			break;

		case 'd':
			if (dir == LEFT)
			{
				break;
			}
			dir = RIGHT;
			break;

		case 'W':
			if (dir == DOWN)
			{
				break;
			}
			dir = UP;
			break;

		case 'A':
			if (dir == RIGHT)
			{
				break;
			}
			dir = LEFT;
			break;

		case 'S':
			if (dir == UP)
			{
				break;
			}
			dir = DOWN;
			break;

		case 'D':
			if (dir == LEFT)
			{
				break;
			}
			dir = RIGHT;
			break;
		}
	}
}

void Movement()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;

	tailX[0] = snakeX;
	tailY[0] = snakeY;

	for (int i = 1; i < tail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];

		tailX[i] = prevX;
		tailY[i] = prevY;

		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case LEFT:
		snakeX--;
		break;

	case RIGHT:
		snakeX++;
		break;

	case UP:
		snakeY--;
		break;

	case DOWN:
		snakeY++;
		break;

	default:
		break;
	}

	if (snakeY >= width)
	{
		snakeX = 0;
	}

	else if (snakeX < 0)
	{
		snakeX = width - 1;
	}

	if (snakeY >= height)
	{
		snakeY = 0;
	}

	else if (snakeY < 0)
	{
		snakeY = height - 1;
	}

	for (int i = 0; i < tail; i++)
	{
		if (tailX[i] == snakeX && tailY[i] == snakeY)
			stop = true;
	}

	if (snakeX == itemX && snakeY == itemY)
	{
		point += 10;

		itemX = rand() % width;
		itemY = rand() % height;

		tail++;
	}
}

int main()
{
	std::cout << "Easy/Hard" << std::endl;
	std::cout << " 1: easy" << std::endl;
	std::cout << " 2: hard" << std::endl;

	int a = 1;
	std::cin >> a;

	switch (a)
	{
	case 1:
		hard = false;
		break;

	case 2:
		hard = true;
		break;
	}

	Start();
	while (hard)
	{
		while (!stop)
		{
			HardSystem();
			Keys();
			Movement();
		}
	}

	while (!hard)
	{
		while (!stop)
		{
			System();
			Keys();
			Movement();
		}
	}

	std::cin.get();
	return 0;
}