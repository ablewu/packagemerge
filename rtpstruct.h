#ifndef SA_RTP_STRUCT_H
#define SA_RTP_STRUCT_H

#include <stdint.h>
#include <sys/types.h>
/*
  RTP packet header bit offset 	0-1 	2 	3 	4-7 	8 	9-15 	16-31
  0 	Version 	P 	X 	CC 	M 	PT 	Sequence Number
  32 	Timestamp
  64 	SSRC identifier
  96 	CSRC identifiers
  ...
  96+32×CC 	Profile-specific extension header ID 	Extension header length
  128+32×CC 	Extension header
  ...
  
 */
//#define RTP_BIG_ENDIAN
typedef struct _tagRTPHeader
{
#ifdef RTP_BIG_ENDIAN
	uint8_t version:2;
	uint8_t padding:1;
	uint8_t extension:1;
	uint8_t csrccount:4;
	
	uint8_t marker:1;
	uint8_t payloadtype:7;
#else // little endian
	uint8_t csrccount:4;
	uint8_t extension:1;
	uint8_t padding:1;
	uint8_t version:2;
	
	uint8_t payloadtype:7;
	uint8_t marker:1;
#endif // RTP_BIG_ENDIAN

	uint16_t sequencenumber;
	uint32_t timestamp;
	uint32_t ssrc;	
}tagRTPHeader;

#endif	// SA_RTP_STRUCT_H
