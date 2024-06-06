#pragma once

#include "Math.h"
#include "Arrow.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class SecArrow : Arrow
{
private:
	int sec;

public:
	SecArrow(float startX, float startY, Pen^ pen, float radius, bool active)
		: Arrow(startX, startY, pen, radius * 0.9, active)
	{

	}

	void Tick() override;
};

void SecArrow::Tick()
{
	if (active)
	{
		sec = DateTime::Now.Second;
		double deltaX = cos((Math::PI / 30 * sec) - Math::PI / 2);
		double deltaY = sin((Math::PI / 30 * sec) - Math::PI / 2);
		end = Point(start.X + radius * deltaX, start.Y + radius * deltaY);
	}
}