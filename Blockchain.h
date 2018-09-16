#include<cstdint>
#include<vector>
#include "Block.h"
using namespace std;

class Blockchain
{
public:
	Blockchain();     //  »ý¼ºÀÚ

	void AddBlock(Block bNew);

private:
	uint32_t _nDifficulty;
	vector<Block> _vChain;

	Block _GetLastBlock() const;
};