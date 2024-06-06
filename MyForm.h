#pragma once

#include "Arrow.h"
#include "SecArrow.h"
#include "MinArrow.h"
#include "HourArrow.h"
#include "Clock.h"

namespace KYPCACH {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->Paint += gcnew PaintEventHandler(this, &MyForm::MyForm_Paint);
			myClock = gcnew Clock(150, 220, gcnew Pen(Brushes::PaleGreen, 20), 50);
			myClock->Add(gcnew SecArrow(150, 220, gcnew Pen(Brushes::Purple, 3), 50, 1));
			myClock->Add(gcnew MinArrow(150, 220, gcnew Pen(Brushes::Green, 3), 50, 1));
			myClock->Add(gcnew HourArrow(150, 220, gcnew Pen(Brushes::Red, 3), 50, 1));
			triggered = 0;

			timer->Start();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbSetTimer;
	private: System::Windows::Forms::TextBox^ tbSetTimer;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ currentTime;
	private: System::Windows::Forms::Label^ lbCurrentTime;

	private: Clock^ myClock;
	private: String^ alarm;
	private: bool triggered;






	protected:

	protected:



	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::Button^ bSetTimer;
			this->lbSetTimer = (gcnew System::Windows::Forms::Label());
			this->tbSetTimer = (gcnew System::Windows::Forms::TextBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->currentTime = (gcnew System::Windows::Forms::Label());
			this->lbCurrentTime = (gcnew System::Windows::Forms::Label());
			bSetTimer = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bSetTimer
			// 
			bSetTimer->Location = System::Drawing::Point(12, 109);
			bSetTimer->Name = L"bSetTimer";
			bSetTimer->Size = System::Drawing::Size(170, 34);
			bSetTimer->TabIndex = 5;
			bSetTimer->Text = L"Set Timer";
			bSetTimer->UseVisualStyleBackColor = true;
			bSetTimer->Click += gcnew System::EventHandler(this, &MyForm::bSetTimer_Click);
			// 
			// lbSetTimer
			// 
			this->lbSetTimer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbSetTimer->AutoSize = true;
			this->lbSetTimer->Font = (gcnew System::Drawing::Font(L"MP Manga Font Bold", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbSetTimer->Location = System::Drawing::Point(61, 10);
			this->lbSetTimer->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->lbSetTimer->Name = L"lbSetTimer";
			this->lbSetTimer->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->lbSetTimer->Size = System::Drawing::Size(278, 22);
			this->lbSetTimer->TabIndex = 0;
			this->lbSetTimer->Text = L"Оберiть час будильника";
			this->lbSetTimer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbSetTimer->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// tbSetTimer
			// 
			this->tbSetTimer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbSetTimer->Location = System::Drawing::Point(16, 37);
			this->tbSetTimer->Margin = System::Windows::Forms::Padding(7, 5, 7, 5);
			this->tbSetTimer->Name = L"tbSetTimer";
			this->tbSetTimer->Size = System::Drawing::Size(352, 28);
			this->tbSetTimer->TabIndex = 1;
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// currentTime
			// 
			this->currentTime->AutoSize = true;
			this->currentTime->Location = System::Drawing::Point(61, 86);
			this->currentTime->Name = L"currentTime";
			this->currentTime->Size = System::Drawing::Size(0, 20);
			this->currentTime->TabIndex = 2;
			// 
			// lbCurrentTime
			// 
			this->lbCurrentTime->AutoSize = true;
			this->lbCurrentTime->Location = System::Drawing::Point(12, 86);
			this->lbCurrentTime->Name = L"lbCurrentTime";
			this->lbCurrentTime->Size = System::Drawing::Size(67, 20);
			this->lbCurrentTime->TabIndex = 3;
			this->lbCurrentTime->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 361);
			this->Controls->Add(bSetTimer);
			this->Controls->Add(this->lbCurrentTime);
			this->Controls->Add(this->currentTime);
			this->Controls->Add(this->tbSetTimer);
			this->Controls->Add(this->lbSetTimer);
			this->Font = (gcnew System::Drawing::Font(L"MP Manga Font Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(7, 5, 7, 5);
			this->MinimumSize = System::Drawing::Size(400, 400);
			this->Name = L"MyForm";
			this->Text = L"Будильник";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Paint(Object^ sender, PaintEventArgs^ e)
	{
		Graphics^ g = e->Graphics;
		myClock->DrawCircle(g);
		myClock->DrawNumbers(g);
		myClock->Draw(g);
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (!triggered)
		{
			DateTime dateTime = DateTime::Now;
			if (dateTime.ToString() == alarm)
			{
				triggered = 1;
			}
			this->lbCurrentTime->Text = dateTime.ToString();
			myClock->Tick();
			Invalidate();
		}
	}
	private: System::Void bSetTimer_Click(System::Object^ sender, System::EventArgs^ e) {

		alarm = tbSetTimer->Text;
	}
};
}