#pragma once
#include <math.h>
#include <vector>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

public ref class MyForm : public Form {
private:
    DataGridView^ table;
    Button^ runBtn;
    TextBox^ kInput;
public:
    MyForm() {
        this->Width = 600;
        this->Height = 400;

        kInput = gcnew TextBox();
        kInput->Location = Point(20, 20);
        kInput->Width = 50;
        this->Controls->Add(kInput);

        runBtn = gcnew Button();
        runBtn->Text = "Run";
        runBtn->Location = Point(100, 20);
        runBtn->Click += gcnew EventHandler(this, &MyForm::RunClick);
        this->Controls->Add(runBtn);

        table = gcnew DataGridView();
        table->Location = Point(20, 70);
        table->Width = 540;
        table->Height = 260;
        table->ColumnCount = 2;
        table->Columns[0]->Name = "x";
        table->Columns[1]->Name = "y";
        this->Controls->Add(table);
    }

    void RunClick(Object^ sender, EventArgs^ e) {
        table->Rows->Clear();
        double a = -2.1, b = 2.5;
        int k = Convert::ToInt32(kInput->Text);
        double h = (b - a) / k;

        for (int i = 0; i <= k; i++) {
            double x = a + i * h;
            double y = log(x * x + x + 2) / log(3);
            table->Rows->Add(x, y);
        }
    }
};
