#pragma once

#include <QWidget>
#include "ui_TextEditor.h"

class TextEditor : public QWidget
{
	Q_OBJECT

public:
	TextEditor(std::string name,QWidget *parent = Q_NULLPTR);
	~TextEditor();

private:
	Ui::TextEditor ui;
	std::string name;
	void saveToFile();
};
