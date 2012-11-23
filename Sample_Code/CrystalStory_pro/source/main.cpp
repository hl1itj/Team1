/*
 * main.cpp
 *
 *  Created on: 2010. 12. 16.
 *      Author: ��ǻ�Ͱ��а�
 *description : CrystalStory main
 */

#include "cs_api.h"
// Converted using PAGfx
#include "all_gfx.h"
#include "game.h"
#include "menu.h"

int main()
{
	// PAlib �ʱ�ȭ
	PA_Init();
	// PAlib VBL Reference �ʱ�ȭ
	PA_InitVBL();

	while(true)
	{
		// ���� ���ȭ�� ���
		PA_LoadBackground(UP_SCREEN, BG2, &bg_main_up);
		PA_LoadBackground(DOWN_SCREEN, BG2, &bg_main_down);

		int selnum=0;
		ret_next(); // ��ġ�� �ƹ����� ������ ���� ���·��� ����
		PA_WaitForVBL();
		PA_LoadBackground(DOWN_SCREEN, BG2, &bg_menu); // �޴�ȭ�� ���

		selnum = sel_menu();

		if(selnum == 1){
			// �޴�1 - ���ӼҰ� (�̱���)
		}
		else if(selnum == 2){
			// �޴�2 - Single Player
			init_singleplay(); // 1player �ʱ�ȭ
			singleplay_start(); // 1player ���ӽ���
		}
		else if(selnum == 3){
			// �޴�3 - Multi Player
		}
		else
			;
		PA_WaitForVBL();
	}
}
