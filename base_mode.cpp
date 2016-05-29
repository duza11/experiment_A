#include "base_mode.h"

BaseMode::BaseMode(IQuizFloor* iqf)
{
	iqf_ = iqf;
}

BaseMode::BaseMode(IQuizFloor* iqf, Quiz* q)
{
	iqf_ = iqf;
}

BaseMode::~BaseMode()
{
}

void BaseMode::Finitialize() {}

bool BaseMode::Update() { return true; }

void BaseMode::Print() {}