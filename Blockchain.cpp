#include"Blockchain.h"

Blockchain::Blockchain()
{
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 5;    // 난이도 5으로 초기화
}

void Blockchain::AddBlock(Block bNew)    // Block 삽입
{
	bNew.sPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock(_nDifficulty);
	_vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
	return _vChain.back();  //  returning the last block found in the _vChain vector using its back method
}