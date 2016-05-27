#include "base_mode.h"

BaseMode::BaseMode(IQuizMakerChanger* changer)
{
	m_qm_changer = changer;
}

BaseMode::BaseMode(IQuizMakerChanger* changer, Quiz* q)
{

}

BaseMode::~BaseMode()
{
}

void BaseMode::init() {}

void BaseMode::finit() {}

bool BaseMode::update() { return true; }

void BaseMode::print() {}