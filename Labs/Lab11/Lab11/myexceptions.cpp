#include "myexceptions.h"

RepositoryException::RepositoryException(std::string error) : m_error(error)
{
}

const char * RepositoryException::what() const noexcept
{
	return m_error.c_str();
}

ServiceException::ServiceException(std::string error) : m_error(error)
{
}

const char * ServiceException::what() const noexcept
{
	return m_error.c_str();
}

ValidationException::ValidationException(std::string error) : m_error(error)
{
}

const char * ValidationException::what() const noexcept
{
	return m_error.c_str();
}
