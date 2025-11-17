#pragma once

namespace Lab10 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        Label^ labelTitle;
        Label^ labelAuthor;
        Label^ labelTask;
        TextBox^ textBoxResult;
        Button^ buttonCalc;
        Button^ buttonClear;
        Button^ buttonExit;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->labelTitle = (gcnew Label());
            this->labelAuthor = (gcnew Label());
            this->labelTask = (gcnew Label());
            this->textBoxResult = (gcnew TextBox());
            this->buttonCalc = (gcnew Button());
            this->buttonClear = (gcnew Button());
            this->buttonExit = (gcnew Button());
            this->SuspendLayout();

            // ----- Назва програми -----
            this->labelTitle->AutoSize = true;
            this->labelTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold));
            this->labelTitle->Location = System::Drawing::Point(30, 20);
            this->labelTitle->Text = L"Лабораторна робота №10: Використання циклів";

            // ----- Автор -----
            this->labelAuthor->AutoSize = true;
            this->labelAuthor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->labelAuthor->Location = System::Drawing::Point(30, 60);
            this->labelAuthor->Text = L"Автор програми: [Ваше ім’я]";

            // ----- Завдання -----
            this->labelTask->AutoSize = true;
            this->labelTask->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->labelTask->Location = System::Drawing::Point(30, 90);
            this->labelTask->Text = L"Знайти суму квадратів усіх натуральних чисел від 10 до 100.";

            // ----- Поле результату -----
            this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
            this->textBoxResult->Location = System::Drawing::Point(34, 130);
            this->textBoxResult->Size = System::Drawing::Size(350, 30);
            this->textBoxResult->ReadOnly = true;

            // ----- Кнопка Обчислити -----
            this->buttonCalc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->buttonCalc->Location = System::Drawing::Point(34, 180);
            this->buttonCalc->Size = System::Drawing::Size(100, 35);
            this->buttonCalc->Text = L"Обчислити";
            this->buttonCalc->Click += gcnew System::EventHandler(this, &MyForm::buttonCalc_Click);

            // ----- Кнопка Очистити -----
            this->buttonClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->buttonClear->Location = System::Drawing::Point(150, 180);
            this->buttonClear->Size = System::Drawing::Size(100, 35);
            this->buttonClear->Text = L"Очистити";
            this->buttonClear->Click += gcnew System::EventHandler(this, &MyForm::buttonClear_Click);

            // ----- Кнопка Вихід -----
            this->buttonExit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->buttonExit->Location = System::Drawing::Point(270, 180);
            this->buttonExit->Size = System::Drawing::Size(100, 35);
            this->buttonExit->Text = L"Вихід";
            this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm::buttonExit_Click);

            // ----- Властивості форми -----
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(420, 250);
            this->Controls->Add(this->labelTitle);
            this->Controls->Add(this->labelAuthor);
            this->Controls->Add(this->labelTask);
            this->Controls->Add(this->textBoxResult);
            this->Controls->Add(this->buttonCalc);
            this->Controls->Add(this->buttonClear);
            this->Controls->Add(this->buttonExit);
            this->Text = L"Лабораторна №10 - Використання циклів";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private:
        // Подія для кнопки "Обчислити"
        System::Void buttonCalc_Click(System::Object^ sender, System::EventArgs^ e)
        {
            int sum = 0;
            for (int i = 10; i <= 100; i++)
                sum += i * i;

            textBoxResult->Text = "Сума квадратів = " + sum.ToString();
        }

        // Подія для кнопки "Очистити"
        System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e)
        {
            textBoxResult->Clear();
        }

        // Подія для кнопки "Вихід"
        System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }
    };
}
