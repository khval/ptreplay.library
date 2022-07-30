CC = gcc -mcrt=newlib
RM = delete
CP = copy

# Change these as required
CFLAGS = -O3 -g -Wall -Iinclude #-DDEBUG

# Flags passed to gcc during linking
LINK = 

# Name of the "thing" to build
TARGET = ptreplay.library

# Additional linker libraries
LIBS = 

# Version of the library to build
VERSION = 7

# Source code files used in this project
# Add any additional files to this line

SRCS = init.c ptreplay_68k.c ptreplay_private.c player_main.c

# -------------------------------------------------------------
# Nothing should need changing below this line

# "main" Interface Source Files
main_SRCS = main/PTLoadModule.c main/PTUnloadModule.c main/PTPlay.c \
	main/PTStop.c main/PTPause.c main/PTResume.c main/PTFade.c \
	main/PTSetVolume.c main/PTSongPos.c main/PTSongLen.c main/PTSongPattern.c \
	main/PTPatternPos.c main/PTPatternData.c main/PTInstallBits.c \
	main/PTSetupMod.c main/PTFreeMod.c main/PTStartFade.c main/PTOnChannel.c \
	main/PTOffChannel.c main/PTSetPos.c main/PTSetPri.c main/PTGetPri.c \
	main/PTGetChan.c main/PTGetSample.c 

OBJS = $(SRCS:.c=.o) $(main_SRCS:.c=.o)
# Rules for building
all: ../$(TARGET)

../$(TARGET): $(OBJS)
	$(CC) $(LINK) -nostartfiles -o $(TARGET).debug $^ $(LIBS)
	strip -R.comment -o $@ $(TARGET).debug

init.o: $(TARGET)_rev.h

install: ../$(TARGET)
	$(CP) /$(TARGET) LIBS:

clean:
	$(RM) $(OBJS) $(TARGET).debug

revision:
	bumprev $(VERSION) $(TARGET)
