#pragma once

#include <QWidget>
#include "ui_TextEditor.h"

class TextEditor : public QWidget
{
	Q_OBJECT

public:
	TextEditor(std::string fileName,QWidget *parent = Q_NULLPTR);
	~TextEditor();

private:
	void saveText();
	std::string fileName;
	Ui::TextEditor ui;
};
