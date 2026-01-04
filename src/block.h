#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "transaction.h"

typedef struct
{
	int index;
	int timestamp;
	std::vector<Transaction> transactions;
	std::string previousHash;
	int proof;
} Block;

#endif
