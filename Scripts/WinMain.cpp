#include"Suken.h"
using namespace suken;

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	//�����ݒ�@��������//////////////////////////////////////////////
	
	DxLib::SetWindowStyleMode(0) ;/*�O�F���܂łǂ���̕��ʂ̃E�C���h�E �P�F�^�C�g���o�[�Ȃ��A������ �Q�F�^�C�g���o�[�������Ȃ�*/
	DxLib::SetMainWindowText("SukenLib");
	System.SetTargetFps(60.0);				//�ڕW�̃t���[�����[�g��ݒ�
	System.SetLoadingGraph("SukenLibAsset/LOGO/LOGO.png");	//���[�f�B���O��ʂɕ\������摜�̃A�h���X���w��
	System.SetUseThread_Awake(false);		//void Awake()�̎��s���o�b�N�O���E���h�ōs�����ǂ���
	System.SetLoadingMinimalTime(2000);		//Loading��ʂ̍Œ�\�����Ԃ��~���b�Őݒ�
	//�����ݒ�@�����܂�//////////////////////////////////////////////
	System.Awake();
	
	if(System.GetUseThread_Awake()){
		System.CreateNewThread(Awake);
	}else{
		Awake();
	}
	System.Wait_Loading();

	while(!ProcessMessage()&&!System.GetEscapeFlag()){
		ScreenFlip();
		ClearDrawScreen();
		System.Update();
		GameLoopEnter();
		Game.Loop();
		GameLoopExit();
		System.Wait();
	}
        
	System.End();
	return 0;
} 