#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <string>
#include <vector>

#include "block.h"
#include "transaction.h"

class Blockchain
{
private:
	std::vector<Block> chain;
	std::vector<Transaction> pending;
	int difficulty;

	std::string normalize(Block block);
	std::string hash(Block block);

	int pow(int previousProof);
	bool valid_pow(int proof);

public:
	Blockchain();

	Block newBlock(int proof, std::string previousHash);
	int newTransaction(std::string sender, std::string receiver, int amount);

	std::string normalize(Transaction transaction);

	bool mine(std::string receiver);

	std::vector<Block> getBlocks();
	std::vector<Transaction> getPendingTransactions();
};

#endif
