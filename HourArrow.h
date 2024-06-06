#pragma once

#include "Math.h"
#include "Arrow.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class HourArrow : Arrow
{
private:
	int hour;
	int min;

public:
	HourArrow(float startX, float startY, Pen^ pen, float radius, bool active)
		: Arrow(startX, startY, pen, radius * 0.5, active)
	{

	}

	void Tick() override;
};

void HourArrow::Tick()
{
	if (active)
	{
		hour = DateTime::Now.Hour % 12;
		min = DateTime::Now.Minute;
		double x = cos((Math::PI / 6 * hour) - Math::PI / 2 + (Math::PI / 360 * min));
		double y = sin((Math::PI / 6 * hour) - Math::PI / 2 + (Math::PI / 360 * min));
		end = Point(start.X + radius * x, start.Y + radius * y);
	}
}