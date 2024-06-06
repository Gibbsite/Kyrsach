#pragma once

#include "Math.h"
#include "Arrow.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class MinArrow : Arrow
{
private:
	int min;

public:
	MinArrow(float startX, float startY, Pen^ pen, float radius, bool active)
		: Arrow(startX, startY, pen, radius * 0.7, active)
	{

	}

	void Tick() override;
};

void MinArrow::Tick()
{
	if (active)
	{
		min = DateTime::Now.Minute;
		double x = cos((Math::PI / 30 * min) - Math::PI / 2);
		double y = sin((Math::PI / 30 * min) - Math::PI / 2);
		end = Point(start.X + radius * x, start.Y + radius * y);
	}
}