
#ifndef _H_DIRECTSOUND_INCLUDE
#define _H_DIRECTSOUND_INCLUDE

#include <stdio.h>			// Header File For Standard Input/Output
#include <dsound.h>         // Header File For The Dsound Libaray
                            // OpenGL's graphics technology work together 
							// with the DX's sound technology, hahaha~~~~...^O^
							// 注：Dsound 是 DXSDK 的一部分.

#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
		((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
		((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))

class CDSound
{
public:
	CDSound();
	CDSound(HWND hWnd,char* filename,bool bPlay, bool bLoop=false); 
	~CDSound();
	void SetCooperativeLevel(HWND hWnd);
	void OpenSoundFile(char* filename);
	void Play();
private:
	LPDIRECTSOUND m_lpDirectSound;           
	LPDIRECTSOUNDBUFFER m_lpDSoundBuffer;
	HWND m_hWnd;
	bool m_bLoop;
};

#endif