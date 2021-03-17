#pragma once
#include <QTGui/qpixmap.h>
#include <string>

class Image
{
public:
	virtual QPixmap getData() = 0;
	virtual ~Image() {}
};

class ImageProxy : public Image
{
private:
	std::string location;
	QPixmap data;
	bool acquired;

public:
	ImageProxy(std::string loc) : location{ loc }, acquired{ false } {}

	QPixmap getData() override;
};
