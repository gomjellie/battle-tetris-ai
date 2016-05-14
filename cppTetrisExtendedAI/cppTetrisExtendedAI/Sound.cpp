#include "Sound.h"
#define DIRECTORY "..\\cppTetrisExtendedAi\\res\\nyan.wav"

void Sound::playNyanNyanSong() {
	PlaySound(TEXT(DIRECTORY), NULL, SND_FILENAME |SND_ASYNC | SND_LOOP);
}