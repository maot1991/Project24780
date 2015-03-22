#include "CDSound.h"

CDSound::CDSound()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	HRESULT hRes;
	m_lpDirectSound=NULL;
	m_lpDSoundBuffer=NULL;
	m_bLoop=false;
	hRes = ::DirectSoundCreate(0, &m_lpDirectSound, 0);//����DirectSound����
	if( hRes != DS_OK )
		return;
}

CDSound::CDSound(HWND hWnd,char* filename,bool bPlay,bool bLoop)
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	HRESULT hRes;
	m_lpDirectSound=NULL;
	m_lpDSoundBuffer=NULL;
	m_bLoop=bLoop;
	hRes = ::DirectSoundCreate(0, &m_lpDirectSound, 0);//����DirectSound����
	if( hRes != DS_OK )
		return;
	m_bLoop=bLoop;
	SetCooperativeLevel(hWnd);
	//���������豸���ȼ���Ϊ"NORMAL"��
	OpenSoundFile(filename);
	if(bPlay)
		Play();
}

CDSound::~CDSound()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

void CDSound::OpenSoundFile(char* filename)
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	LPVOID lpPtr1;         //ָ��1;
	LPVOID lpPtr2;         //ָ��2;
	HRESULT hResult;
	DWORD dwLen1,dwLen2;
	LPVOID m_pMemory;      //ָ��WAVE�ļ���ָ��
	LPWAVEFORMATEX m_pFormat=NULL; //LPWAVEFORMATEX����ָ�룻
	LPVOID m_pData=NULL;   //ָ���������ݿ��ָ�룻
	DWORD m_dwSize=0;      //WAVE�ļ����������ݿ�ĳ��ȣ�
	FILE *filein;
	DWORD dwSize;//���WAV�ļ����ȣ�

	//��sound.wav�ļ���
	filein=fopen(filename, "rt");

	//fseek(): �� filein ��ָ�ļ���λ��ָ���ƶ����� 0 Ϊ��ַ��
	//         SEEK_END Ϊƫ������λ��
	fseek(filein,0,SEEK_END);  //�ƶ���WAVE�ļ��д���ļ����ȵĵط�
	dwSize = ftell(filein);    //��ȡWAVE�ļ�����

	fseek(filein,0,SEEK_SET);  //��λ���򿪵�WAVE�ļ��ļ�ͷ��
	int j = ftell(filein);     // j ??????

	//Ϊm_pMemory�����ڴ棬�������WAVE�ļ��е����ݣ�
	m_pMemory = GlobalAlloc (GMEM_FIXED, dwSize);
	fread(m_pMemory, 1, dwSize, filein);  //��ȡ�ļ��е����ݣ�
	fclose(filein);

	LPDWORD pdw,pdwEnd;
	DWORD dwRiff,dwType, dwLength;

	//�������ָ��ͱ����Ա�ʹ��
	if (m_pFormat)           //��ʽ��ָ��
		m_pFormat = NULL;
	if (m_pData)             //���ݿ�ָ��,����:LPBYTE
		m_pData = NULL;
	if (m_dwSize)            //���ݳ���,����:DWORD
		m_dwSize = 0;

	pdw = (DWORD *) m_pMemory;
	dwRiff = *pdw++;
	dwLength = *pdw++;
	dwType = *pdw++;
	if (dwRiff != MAKEFOURCC ('R', 'I', 'F', 'F'))
		return ;//�ж��ļ�ͷ�Ƿ�Ϊ"RIFF"�ַ���
	if (dwType != MAKEFOURCC ('W', 'A', 'V', 'E'))
		return ;//�ж��ļ���ʽ�Ƿ�Ϊ"WAVE"��
	//Ѱ�Ҹ�ʽ��,���ݿ�λ�ü����ݳ���
	pdwEnd = (DWORD *)((BYTE *) m_pMemory+dwLength -4);
	bool m_bend=false;
	while ((pdw < pdwEnd)&&(!m_bend))
	//pdw�ļ�û��ָ���ļ�ĩβ����û�л�ȡ����������ʱ����;
	{
		dwType = *pdw++;
		dwLength = *pdw++;
		switch (dwType)
		{
			case MAKEFOURCC('f', 'm', 't', ' ')://���Ϊ"fmt"��־��
				if (!m_pFormat)//��ȡLPWAVEFORMATEX�ṹ���ݣ�
				{
					if (dwLength < sizeof (WAVEFORMAT))
					return ;
					m_pFormat = (LPWAVEFORMATEX) pdw;
				}
			break;
			case MAKEFOURCC('d', 'a', 't', 'a')://���Ϊ"data"��־��
				if (!m_pData || !m_dwSize)
				{
					m_pData = (LPBYTE) pdw;//�õ�ָ���������ݿ��ָ�룻
					m_dwSize = dwLength;//��ȡ�������ݿ�ĳ��ȣ�
					if (m_pFormat)
						m_bend=TRUE;
				}
			break;
	}
	pdw = (DWORD *)((BYTE *) pdw + ((dwLength + 1)&~1));//�޸�pdwָ�룬����ѭ����
	
	}
	DSBUFFERDESC BufferDesc;//����DSUBUFFERDESC�ṹ����
	memset (&BufferDesc, 0, sizeof (BufferDesc));
	BufferDesc.lpwfxFormat = (LPWAVEFORMATEX)m_pFormat;
	BufferDesc.dwSize = sizeof (DSBUFFERDESC);
	BufferDesc.dwBufferBytes = m_dwSize;
	BufferDesc.dwFlags = 0;
	//�����������ݻ��壻
	if (m_lpDirectSound->CreateSoundBuffer (&BufferDesc, &m_lpDSoundBuffer, 0) == DS_OK)
	//�����������ݣ�����ʹ������ָ��lpPtr1,lpPtr2��ָ��DirectSoundBuffer�����������ݣ�����Ϊ�˴������WAVE�ļ�����Ƶġ�dwLen1,dwLen2�ֱ��Ӧ������ָ����ָ��Ļ������ĳ��ȡ�
		hResult=m_lpDSoundBuffer->Lock(0,m_dwSize,&lpPtr1,&dwLen1,&lpPtr2,&dwLen2,0);
	if (hResult == DS_OK)
	{
		memcpy (lpPtr1, m_pData, dwLen1);
		if(dwLen2>0) 
		{
			BYTE *m_pData1=(BYTE*)m_pData+dwLen1;
			m_pData=(void *)m_pData1;
			memcpy(lpPtr2,m_pData, dwLen2);
		}
		m_lpDSoundBuffer->Unlock (lpPtr1, dwLen1, lpPtr2, dwLen2);
	}
	GlobalFree(m_pMemory);
	m_pMemory=NULL;
}

void CDSound::SetCooperativeLevel(HWND hWnd)
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_hWnd=hWnd;
	m_lpDirectSound->SetCooperativeLevel(m_hWnd, DSSCL_NORMAL);
	//���������豸���ȼ���Ϊ"NORMAL"��
}

void CDSound::Play()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	DWORD dwFlags = 0; //DSBPLAY_LOOPING
	if (m_bLoop)
		dwFlags =DSBPLAY_LOOPING;
	m_lpDSoundBuffer->Play(0, 0, dwFlags); //����WAVE��������
}