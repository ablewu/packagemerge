#ifndef SA_PACKAGE_MERGE_H
#define SA_PACKAGE_MERGE_H

#define N 95

class SaPackageMerge
{
public:
	SaPackageMerge(void);
	virtual SaPackageMerge(void);

	int InputPackageChannel1();
	int InputPackageChannel2();

private:
	std::array<stRTPPacket, N> m_arrBuf;
	
};

#endif	// SA_PACKAGE_MERGE_H
