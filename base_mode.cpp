#include "base_mode.h"

BaseMode::BaseMode(IModeChanger* changer)
{
	m_mode_changer = changer;
}

BaseMode::~BaseMode()
{
}

void BaseMode::init() {}

void BaseMode::finit() {}

void BaseMode::update() {}

void BaseMode::print() {}