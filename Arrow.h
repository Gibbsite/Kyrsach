#pragma once
#include "Math.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;


ref class Arrow
{
protected:
	Point start;
	Point end;
	Pen^ pen;
	float radius;
	bool active;

public:

	Arrow(float startX, float startY, Pen^ pen, float radius, bool active)
	{
		this->start = Point(startX, startY);
		this->pen = pen;
		this->radius = radius;
		this->active = active;
	}	
	void Draw(Graphics^ g);

	virtual void Tick() = 0;

	void setInactive();

	void setActive();
};

void Arrow::Draw(Graphics^ g)
{
	g->DrawLine(pen, start, end);
}

void Arrow::setInactive()
{
	active = 0;
}
void Arrow::setActive()
{
	active = 1;
}