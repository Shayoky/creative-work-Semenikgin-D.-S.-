#pragma once
#include <iostream>
#include <string>
#include <math.h>
int* arr = new int[2];
namespace Calculator {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	string* Box1 = new string[2];
string* Box2 = new string[2];
string* Box3 = new string[2];
string* Box4 = new string[2];
string* label = new string[2];
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 34);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(230, 35);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(12, 105);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(230, 35);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->ForeColor = System::Drawing::SystemColors::MenuText;
			this->textBox3->Location = System::Drawing::Point(12, 179);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(230, 35);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(75, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Сумма кредита";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(72, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Годовая ставка";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(72, 158);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(116, 18);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Срок выплаты";
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(248, 192);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 22);
			this->label4->TabIndex = 6;
			this->label4->Text = L"мес.";
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(248, 118);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 22);
			this->label5->TabIndex = 7;
			this->label5->Text = L"%";
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(248, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 25);
			this->label6->TabIndex = 8;
			this->label6->Text = L"руб.";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(141, 274);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(450, 36);
			this->textBox4->TabIndex = 9;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(12, 274);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(123, 41);
			this->label7->TabIndex = 10;
			this->label7->Text = L"label7";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(370, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(221, 34);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Вывод общей суммы выплат";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(370, 97);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(221, 35);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Вывод суммы переплат";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(370, 210);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(221, 35);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Сброс результата";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(370, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(221, 35);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Отмена последнего действия";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// button5
			// 
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(289, 35);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(39, 35);
			this->button5->TabIndex = 16;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->Location = System::Drawing::Point(289, 105);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(39, 35);
			this->button6->TabIndex = 17;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->Location = System::Drawing::Point(289, 179);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(39, 35);
			this->button7->TabIndex = 18;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(603, 324);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Form1";
			this->Text = L"Калькулятор кредитов";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: 	string SystemToStl(String^ s)
	{
		using namespace Runtime::InteropServices;
		const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		return string(ptr);
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		label7->Text = "";
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		arr[0] = 0;
		Box1[0] = "";
		Box2[0] = "";
		Box3[0] = "";
		Box4[0] = "";
		label[0] = "";
		arr[1] = 0;
		Box1[1] = "";
		Box2[1] = "";
		Box3[1] = "";
		Box4[1] = "";
		label[1] = "";

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			try
			{
				int s = System::Convert::ToInt32(textBox1->Text);
			}
			catch (FormatException ^ e)
			{
				textBox1->Clear();
				MessageBox::Show("Вы ввели символ! Пожалуйста,введите цифрy");
			}

	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label7->Text = "Общая сумма платежей";
		string sum, proc, mes;
		sum = SystemToStl(textBox1->Text);
		proc = SystemToStl(textBox2->Text);
		mes = SystemToStl(textBox3->Text);
		float sum1, proc1, mes1;
		sum1 = stof(sum);
		cout << "sum1 = " << sum1 << endl;
		proc1 = stof(proc);
		cout << "proc1 = " << proc1 << endl;
		mes1 = stof(mes);
		cout << "mes1 = " << mes1 << endl;
		proc1 = proc1 / (1200);
		cout << "proc1 = " << proc1 << endl;
		float platez;
		platez =mes1 * sum1 * ((proc1 * pow(proc1 + 1, mes1)) / (pow(1 + proc1, mes1) - 1));
		cout << "paltez = " << platez << endl;
		textBox4->Text = platez.ToString();
			arr[0] = arr[1];
			Box1[0] = Box1[1];
			Box2[0] = Box2[1];
			Box3[0] = Box3[1];
			Box4[0] = Box4[1];
			arr[1] = 1;
			Box1[1] = SystemToStl(textBox1->Text);
			Box2[1] = SystemToStl(textBox2->Text);
			Box3[1] = SystemToStl(textBox3->Text);
			Box4[1] = SystemToStl(textBox4->Text);
			label[1] = SystemToStl(label7->Text);
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			   label7->Text = "Общая сумма переплат";
			   string sum2, proc2, mes2;
			   sum2 = SystemToStl(textBox1->Text);
			   proc2 = SystemToStl(textBox2->Text);
			   mes2 = SystemToStl(textBox3->Text);
			   float sum3, proc3, mes3;
			   sum3 = stof(sum2);
			   proc3 = stof(proc2);
			   mes3 = stof(mes2);
			   proc3 = proc3 / (1200);
			   float platez1;
			   platez1 = (mes3 * sum3 * ((proc3 * pow(proc3 + 1, mes3)) / (pow(1 + proc3, mes3) - 1))) - sum3;
			   cout << "paltez = " << platez1 << endl;
			   textBox4->Text = platez1.ToString();
				   arr[0] = arr[1];
				   Box1[0] = Box1[1];
				   Box2[0] = Box2[1];
				   Box3[0] = Box3[1];
				   Box4[0] = Box4[1];
				   label[0] = label[1];
				   arr[1] = 1;
				   Box1[1] = SystemToStl(textBox1->Text);
				   Box2[1] = SystemToStl(textBox2->Text);
				   Box3[1] = SystemToStl(textBox3->Text);
				   Box4[1] = SystemToStl(textBox4->Text);
				   label[1]= SystemToStl(label7->Text);
    }
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		int h;
		string h1, h2, h3, h4, h5;
		h = arr[0];
		h1 = Box1[0];
		h2 = Box2[0];
		h3 = Box3[0];
		h4 = Box4[0];
		h5 = label[0];
		textBox1->Text = gcnew System::String(Box1[0].c_str());
		textBox2->Text = gcnew System::String(Box2[0].c_str());
		textBox3->Text = gcnew System::String(Box3[0].c_str());
		textBox4->Text = gcnew System::String(Box4[0].c_str());
		label7->Text= gcnew System::String(label[0].c_str());
		arr[0] = arr[1];
		Box1[0].swap(Box1[1]);
		Box2[0].swap(Box2[1]);
		Box3[0].swap(Box3[1]);
		Box4[0].swap(Box4[1]);
		label[0].swap(label[1]);
		arr[1] = h;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox4->Clear();
	label7->Text = "";
	arr[0] = arr[1];
	Box1[0] = Box1[1];
	Box2[0] = Box2[1];
	Box3[0] = Box3[1];
	Box4[0] = Box4[1];
	label[0] = label[1];
	arr[1] = 4;
	Box1[1] = SystemToStl(textBox1->Text);
	Box2[1] = SystemToStl(textBox2->Text);
	Box3[1] = SystemToStl(textBox3->Text);
	Box4[1] = SystemToStl(textBox4->Text);
	label[1] = SystemToStl(label7->Text);
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		int s = System::Convert::ToInt32(textBox2->Text);
	}
	catch (FormatException ^ e)
	{
		textBox2->Clear();
		MessageBox::Show("Вы ввели символ! Пожалуйста,введите цифрy");
	}
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		int s = System::Convert::ToInt32(textBox3->Text);
	}
	catch (FormatException ^ e)
	{
		textBox3->Clear();
		MessageBox::Show("Вы ввели символ! Пожалуйста,введите цифрy");
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	arr[0] = arr[1];
	Box1[0] = Box1[1];
	Box2[0] = Box2[1];
	Box3[0] = Box3[1];
	Box4[0] = Box4[1];
	label[0] = label[1];
	arr[1] = 5;
	Box1[1] = SystemToStl(textBox1->Text);
	Box2[1] = SystemToStl(textBox2->Text);
	Box3[1] = SystemToStl(textBox3->Text);
	Box4[1] = SystemToStl(textBox4->Text);
	label[1] = SystemToStl(label7->Text);
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	arr[0] = arr[1];
	Box1[0] = Box1[1];
	Box2[0] = Box2[1];
	Box3[0] = Box3[1];
	Box4[0] = Box4[1];
	label[0] = label[1];
	arr[1] = 6;
	Box1[1] = SystemToStl(textBox1->Text);
	Box2[1] = SystemToStl(textBox2->Text);
	Box3[1] = SystemToStl(textBox3->Text);
	Box4[1] = SystemToStl(textBox4->Text);
	label[1] = SystemToStl(label7->Text);
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	arr[0] = arr[1];
	Box1[0] = Box1[1];
	Box2[0] = Box2[1];
	Box3[0] = Box3[1];
	Box4[0] = Box4[1];
	label[0] = label[1];
	arr[1] = 7;
	Box1[1] = SystemToStl(textBox1->Text);
	Box2[1] = SystemToStl(textBox2->Text);
	Box3[1] = SystemToStl(textBox3->Text);
	Box4[1] = SystemToStl(textBox4->Text);
	label[1] = SystemToStl(label7->Text);
}
};
}
