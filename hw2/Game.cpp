#include "io_utils.h"
#include "Game.h"

#define ESC 27

void Game::draw_all()
{
	size_t i;

	for (i = 0; i < num_of_items; i++)
	{
		items[i]->Draw();
	}

	for (i = 0; i < num_of_ships; i++)
	{
		ships[i]->draw(this->canvas);
	}

	for (i = 0; i < num_of_walls; i++)
	{
		walls[i]->draw(this->canvas);
	}
};

void Game::Run()
{
	// esc (Ascii 27) ends the loop
	while (!_kbhit() || _getch() != ESC)
	{
		this->draw_all();
		this->get_item(0)->advance_falling(this);
		Sleep(50);
		/*gotoxy(x, y);
		cout << "*" << endl;
		Sleep(50);
		gotoxy(x, y);
		cout << " " << endl;
		++x;
		if (x>79) { x = 1; }
		++y;
		if (y>20) { y = 1; }*/
	}
}