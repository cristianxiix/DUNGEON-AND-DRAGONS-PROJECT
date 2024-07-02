#pragma once
#include "Sounds.h"
#include <iostream>


 
Sound::Sound(const std::string filepath)
{
	if(SDL_LoadWAV(filepath.c_str(), &m_audioSpec, &m_wave_start, &m_waveLength) == nullptr)
	{
		std::cerr << "SOUND LOADING ERROR: " << SDL_GetError() << std::endl;
	}
}

Sound::~Sound()
{
	SDL_FreeWAV(m_wave_start);
	SDL_CloseAudioDevice(m_device);
	
}

void Sound::PlaySound()
{
	int status = SDL_QueueAudio(m_device, m_wave_start, m_waveLength);
	SDL_PauseAudioDevice(m_device, 0); /// -> if 0 not pausing, start playing
}

void Sound::StopSound()
{
	SDL_PauseAudioDevice(m_device, 1);
}

void Sound::SetupDevice()
{
	SDL_Init(SDL_INIT_AUDIO);

	m_device = SDL_OpenAudioDevice(nullptr, 0, &m_audioSpec, nullptr, SDL_AUDIO_ALLOW_ANY_CHANGE);
	if (0 == m_device)
	{
		std::cerr << "SOUND DEVICE ERROR: " << SDL_GetError() << std::endl;
	}
}


Sound* changeFilePath(const std::string newPath)
{
	Sound* p = new Sound(newPath);
	return p;
}

void StartPlaying(Sound* s)
{
	//settingUp the new device with the new filepath then calling PlaySound() methods, defined in Sounds.cpp
	s->SetupDevice();
	s->PlaySound();
}