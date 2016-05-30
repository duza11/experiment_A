#include "menu.h"

Menu::Menu(IQuizFloor *iqf)
{
	iqf_ = iqf;
}

Menu::Menu(IQuizFloor *iqf, Quiz *quiz)
{
	iqf_ = iqf;
}

Menu::~Menu()
{
}

void Menu::Finitialize() {}

bool Menu::Update() { return true; }

void Menu::Print() {}
