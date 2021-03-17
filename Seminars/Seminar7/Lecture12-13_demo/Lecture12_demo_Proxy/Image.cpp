#include "Image.h"

QPixmap ImageProxy::getData()
{
	if (!this->acquired)
	{
		QPixmap pixmap{ this->location.c_str() };
		this->data = pixmap;
		this->acquired = true;
	}

	return this->data;
}
