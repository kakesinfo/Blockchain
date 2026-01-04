#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

typedef struct
{
	int timestamp;
	std::string sender;
	std::string receiver;
	int amount;
} Transaction;

#endif
