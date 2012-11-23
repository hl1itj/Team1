/*
 * game.h
 *
 *  Created on: 2010. 12. 16.
 *      Author: ywyw
 */

#ifndef CRYSTAL_H_
#define CRYSTAL_H_



/************************************* Class Area ****************************************/

/* ���� ���� ���� Ŭ���� - ���� �� �ٸ� ���׵鿡 ���� flag�� ������..*/
class GameProcess {
public:
	int score;      // ���� ����
	int oddmonster; // ���� ������ ��
	int stage_num;  // �ܰ� ī��Ʈ
	int crystals;

	GameProcess() {
		score = 0;
		oddmonster = 3;
		stage_num = 1;
		crystals = 0;
	}
};

/*********************************** Function Area **************************************/
/* ���� ���� ���� �Լ� */
void init_singleplay(); // �̱��÷��̾� ����  �ʱ�ȭ
void singleplay_start(); // �̱��÷��̾� ���� ��ŸƮ!

#endif /* CRYSTAL_H_ */
