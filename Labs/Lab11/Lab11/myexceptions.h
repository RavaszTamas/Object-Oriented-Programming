#pragma once
#include <exception>
#include <cstring>
#include <string>

class RepositoryException : public std::exception {
private:
	std::string m_error;
public:
	RepositoryException(std::string error);

	const char* what() const noexcept override;

};

class ServiceException : public std::exception {
private:
	std::string m_error;
public:
	ServiceException(std::string error);

	const char* what() const noexcept override;

};

class ValidationException : public std::exception {
private:
	std::string m_error;
public:
	ValidationException(std::string error);

	const char* what() const noexcept override;

};
