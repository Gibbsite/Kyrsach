#pragma once
#include "Math.h"
#include "Arrow.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref struct Element
{
	Arrow^ data;
	Element^ next;

	Element()
	{
		data = nullptr;
		next = nullptr;
	}

	Element(Arrow^ arrow)
	{
		data = arrow;
		next = nullptr;
	}
};

ref class Clock
{
private:
	Element^ first;
	int x;
	int y;
	int radius;
	Pen^ pen;
	Font^ font;

public:
	Clock(int x, int y, Pen^ pen, int radius)
	{
		this->x = x;
		this->y = y;
		this->radius = radius;
		font = gcnew Font("Arial", 10);
		this->pen = pen;
	}
	void DrawCircle(Graphics^ g);

	void DrawNumbers(Graphics^ g);

	void Add(Arrow^ arrow);

	void Tick();

	void Draw(Graphics^ g);

	void setActive();

	void setInactive();
};

void Clock::DrawCircle(Graphics^ g)
{
	g->DrawEllipse(pen, x - radius, y - radius, 2 * radius, 2 * radius);
}

void Clock::DrawNumbers(Graphics^ g)
{
	for (int i = 12; i > 0; i--)
	{
		double x = this->x + radius * cos((Math::PI / 6 * i) - Math::PI / 2);
		double y = this->y + radius * sin((Math::PI / 6 * i) - Math::PI / 2);
		g->DrawString((i).ToString(), font, Brushes::Black, x - 4, y - 7);
	}
}

void Clock::Add(Arrow^ arrow)
{
	if (first == nullptr)
	{
		first = gcnew Element(arrow);
	}
	else
	{
		Element^ temp = first;
		first = gcnew Element(arrow);
		first->next = temp;
	}
}

void Clock::Tick()
{
	Element^ cur = gcnew Element();
	cur = first;
	while (cur != nullptr)
	{
		cur->data->Tick();
		cur = cur->next;
	}
}

void Clock::Draw(Graphics^ g)
{
	Element^ cur = gcnew Element();
	cur = first;
	while (cur != nullptr)
	{
		cur->data->Draw(g);
		cur = cur->next;
	}
}

void Clock::setActive()
{
	Element^ cur = gcnew Element();
	cur = first;
	while (cur != nullptr)
	{
		cur->data->setActive();
		cur = cur->next;
	}
}

void Clock::setInactive()
{
	Element^ cur = gcnew Element();
	cur = first;
	while (cur != nullptr)
	{
		cur->data->setInactive();
		cur = cur->next;
	}
}
