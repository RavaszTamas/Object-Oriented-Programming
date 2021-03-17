#include "Domain.h"

bool Idea::operator==(const Idea & other) const
{
	return other.getCreator() == creator && other.getAct() == act && other.getDescription() == description && other.getStatus() == status;
}
