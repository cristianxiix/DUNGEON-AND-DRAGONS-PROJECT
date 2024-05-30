#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <string>
#include "SDL_audio.h"



class ISound
{
public:
	virtual ~ISound() {};
	virtual void PlaySound() = 0;
	virtual void StopSound() = 0;
};

class Sound : public ISound
{
public:
	Sound(std::string filepath);
	~Sound();
	void PlaySound();
	void StopSound();

	void SetupDevice(); // -> specific to SDL_Audio API
	friend Sound* changeFilePath( std::string newPath);
	friend void StartPlaying();

private:
	SDL_AudioDeviceID m_device;
	SDL_AudioSpec m_audioSpec;
	Uint8* m_wave_start;
	Uint32 m_waveLength;
};
Sound* changeFilePath( std::string newPath);
void StartPlaying(Sound* s);
