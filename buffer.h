#ifndef SA_BUFFER_H
#define SA_BUFFER_H

#include <array>

#define N 95

class SaBuffer
{
public:
	SaBuffer(void);
	virtual SaBuffer(void);

	int WriteOneBuffer(int nIdx, const char* pchData, int nLen);
	int ReadOneBuffer(void);
	int Reset(void);	
	
private:
	std::array<tagRTPHeader, int> m_pArray;
	std::array<tagRTPHeader, int>::iterator m_pReadIter;
};

#endif	// SA_BUFFER_H
