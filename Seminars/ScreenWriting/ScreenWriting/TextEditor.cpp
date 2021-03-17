#include "TextEditor.h"
#include <fstream>
#include <string>
#include <sstream>
TextEditor::TextEditor(std::string _name,QWidget *parent)
	: QWidget(parent), name{ _name }
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &TextEditor::saveToFile);
	this->setWindowTitle(QString::fromStdString(this->name));

	std::ifstream input{ this->name + ".txt" };
	std::stringstream stuffs;
	stuffs << input.rdbuf();
	std::string stuff = stuffs.str();
	ui.textEdit->setText(QString::fromStdString(stuff));

}

TextEditor::~TextEditor()
{
}

void TextEditor::saveToFile()
{
	std::ofstream out{ this->name + ".txt" };
	out << ui.textEdit->toPlainText().toStdString();
	out.flush();
	out.close();
}
