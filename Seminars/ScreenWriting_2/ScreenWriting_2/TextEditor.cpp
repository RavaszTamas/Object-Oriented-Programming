#include "TextEditor.h"
#include <fstream>
#include <sstream>

using namespace std;

TextEditor::TextEditor(std::string _fileName,QWidget *parent)
	: QWidget(parent), fileName{ _fileName }
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->fileName));
	ifstream input{ fileName + ".txt" };
	if (input.good())
	{
		stringstream stream;
		stream << input.rdbuf();
		ui.textEdit->setText(QString::fromStdString(stream.str()));
	}
	input.close();
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &TextEditor::saveText);
}

TextEditor::~TextEditor()
{
}

void TextEditor::saveText()
{
	ofstream out(this->fileName + ".txt");
	out << ui.textEdit->toPlainText().toStdString();
	out.flush();
	out.close();
}
