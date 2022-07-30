VERSION = 7
REVISION = 2

.macro DATE
.ascii "19.7.2009"
.endm

.macro VERS
.ascii "ptreplay.library 7.2"
.endm

.macro VSTRING
.ascii "ptreplay.library 7.2 (19.7.2009)"
.byte 13,10,0
.endm

.macro VERSTAG
.byte 0
.ascii "$VER: ptreplay.library 7.2 (19.7.2009)"
.byte 0
.endm
