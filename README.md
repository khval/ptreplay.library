# ptreplay.library
API reimplementation of ptreplay.library for AmigaOS4.1

    Short:        Library for playing ProTracker modules
    Author:       Fredrik Wikstrom
    Uploader:     Fredrik Wikstrom <fredrik@a500.org>
    Type:         util/libs
    Version:      7.2
    Architecture: ppc-amigaos

This is an API compatible reimplementation of Mattias Karlsson's and Andreas
Palsson's "ptreplay.library". Audio output is done as 16-bit, 44100 Hz, stereo
using "ahi.device". Module playback is done using an OS4 port of Ilkka
Lehtoranta's "ptplay.library".

The following functions of the library should be fully supported:
PTLoadModule, PTUnloadModule, PTPlay, PTStop, PTPause, PTResume, PTFade,
PTSetVolume, PTSongPos, PTSongLen, PTPatternPos, PTInstallBits, PTSetupMod,
PTFreeMod, PTStartFade, PTSetPos

Other functions are implemented simply as no-ops which do nothing except return
a constant value (usually null/zero) depending on the function definition.

Requirements:

    * AmigaOS 4.0 or newer
    * ptplay.library 2.6 (29.4.08)

Installation:

    Copy ptreplay.library LIBS:

Changes:

7.x (xx-xx-2022) changes by LiveForIt (Kjetil Hvalstrand)

    Implanted PTGetSample and PTPatternData
    (Experimental, naive implementation.
    Not uploaded yet to OS4Depot.net)

7.2 (19-Jul-2009)

    Opens a requester if ptplay.library fails to open

7.1 (23-Jun-2009)

    First released version
