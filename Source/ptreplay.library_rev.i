VERSION		EQU	7
REVISION	EQU	2

DATE	MACRO
		dc.b '19.7.2009'
		ENDM

VERS	MACRO
		dc.b 'ptreplay.library 7.2'
		ENDM

VSTRING	MACRO
		dc.b 'ptreplay.library 7.2 (19.7.2009)',13,10,0
		ENDM

VERSTAG	MACRO
		dc.b 0,'$VER: ptreplay.library 7.2 (19.7.2009)',0
		ENDM
