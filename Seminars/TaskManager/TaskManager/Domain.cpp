#include "Domain.h"

bool Task::operator!=(Task other)
{
	if (other.description == description && other.id == id && other.status == status)
		return false;
	return true;
}
