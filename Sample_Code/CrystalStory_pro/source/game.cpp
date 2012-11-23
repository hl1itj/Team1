/*
 * game.cpp
 *
 *  Created on: 2010. 12. 16.
 *      Author: ywyw
 */

#include "game.h"
#include "menu.h"
#include "cs_api.h"
#include "all_gfx.h"
#include "hero.h"
#include "princess.h"
#include "water.h"
#include "crystal.h"
#include "crystal_Ball.h"
#include "monster.h"

#define SCREEN_MAX_WATER	10

// �ʱ� ĳ���� ��ǥ
int x =160;
int y =160;
int move_cnt =0; // ����� �̵� ��
int water_cnt = 0; // hero �� ����� ����


// �������μ��� ��ü ����
static GameProcess gp;

Coordi* coordi;

// �̱� �÷��� �ʱ�ȭ
void init_singleplay() {
 PA_LoadBackground(DOWN_SCREEN, BG2, &bg_stage1_init);
 PA_WaitForVBL();
 //UnLoad_Screen();
 //PA_WaitForVBL();
 ret_next(); // next state
 dualback_print(&stage2); // ���ӹ��ȭ�� ��� (���)

 /* �ؽ�Ʈ ��� �κ� */
 PA_InitText(DOWN_SCREEN, BG0);
 PA_SetTextTileCol(DOWN_SCREEN, TEXT_WHITE); //
}

// �̱� �÷��� ��ŸƮ
void singleplay_start() {
	// ������ ��ü ����
	hero player;
	princess prin;
	monster mons1;
	water drop_water1;
	water drop_water2;
	water drop_water3;
	water drop_water4;
	crystal_Ball ball;

	// �������� x��ǥ����
	drop_water1.x = PA_Rand()%250;
	drop_water2.x = PA_Rand()%250;
	drop_water3.x = PA_Rand()%250;
	drop_water4.x = PA_Rand()%250;
	mons1.x = PA_Rand()%250;

	// ������ ��ü �̹��� ���
	// ����� �׸� ����� ��� (ù��° ���� - spriteNUM, �ι�°���� - objNUM)
	drop_water1.water_setting(SPRITE2_PAL, OBJ2_NUM);
	drop_water2.water_setting(SPRITE3_PAL, OBJ3_NUM);
	drop_water3.water_setting(SPRITE4_PAL, OBJ4_NUM);
	drop_water4.water_setting(SPRITE5_PAL, OBJ5_NUM);
	ball.ball_setting(SPRITE6_PAL, OBJ6_NUM);
	mons1.monster_setting(SPRITE7_PAL, OBJ7_NUM, mons1.x);

	while(1) // ���⿡�� ������ ����!!
	{
		/* �ؽ�Ʈ ��ºκ�- �������� (��������� ���)*/
		PA_OutputText(DOWN_SCREEN, 1, 21, "Stage%d", gp.stage_num);
		PA_OutputText(DOWN_SCREEN, 9, 21, "Score:%d", gp.score);
		PA_OutputText(DOWN_SCREEN, 18, 21, "Odd Monster:%d",gp.oddmonster);
		PA_OutputText(DOWN_SCREEN, 18, 22, "My Crystals:%d",gp.crystals);

		// ��ü �̵�
		player.move();
		prin.move(1);
		mons1.move(1);
		drop_water1.move(3);
		drop_water2.move(2);
		drop_water3.move(3);
		drop_water4.move(2);

		// ���Ϳ� ũ����Ż�� �浹���� ��,
		if (PA_Distance(mons1.x, mons1.y, ball.x, ball.y) < 32*32) {
			gp.score = gp.score+50;
			mons1.y = mons1.y-100; // ���Ͱ� �ڷ� �и��� ����
			mons1.hp = mons1.hp-15; // ������ �ǰ� 15�� ����
			ball.x = -100;
			ball.y = -100;
			if(mons1.hp<0)
			{
				gp.oddmonster--;
				gp.score = gp.score+100;
				mons1.~monster();
			}
		}
		// ������� ���ΰ��� �Ծ��� ��
		if (PA_Distance(drop_water1.x, drop_water1.y-240, player.x, player.y) < 16*8) {
			drop_water1.x = PA_Rand()%250;
			drop_water1.y = 0;
			gp.crystals++;
		}
		if(PA_Distance(drop_water2.x, drop_water2.y-240, player.x, player.y) < 16*8) {
			drop_water2.x = PA_Rand()%250;
			drop_water2.y = 0;
			gp.crystals++;
		}
		if(PA_Distance(drop_water3.x, drop_water3.y-240, player.x, player.y) < 16*8) {
			drop_water3.x = PA_Rand()%250;
			drop_water3.y = 0;
			gp.crystals++;
		}
		if(PA_Distance(drop_water4.x, drop_water4.y-240, player.x, player.y) < 16*8) {
			drop_water4.x = PA_Rand()%250;
			drop_water4.y = 0;
			gp.crystals++;
		}

		// ũ����Ż ī��Ʈ ( �������� ������� ���� ���� ��ŭ �� ���� )
		if(gp.crystals > 0 )
			gp.crystals = ball.move(player.x, gp.crystals); // �� ����

		/******************************** Motion Area ****************************************/

		move_sprite(SPRITE1, player.x, player.y); // hero ��ǥ ���� �� ���
		move_sprite(SPRITE9, prin.x, prin.y); // princess ��ǥ ���� �� ���

		dual_move(SPRITE2, drop_water1.x, drop_water1.y); // ����� ��ǥ ���� �� ���
		dual_move(SPRITE3, drop_water2.x, drop_water2.y); // ����� ��ǥ ���� �� ���
		dual_move(SPRITE4, drop_water3.x, drop_water3.y); // ����� ��ǥ ���� �� ���
		dual_move(SPRITE5, drop_water4.x, drop_water4.y); // ����� ��ǥ ���� �� ���

		if(mons1.y > 375)
			break;
		else
			dual_move(SPRITE7, mons1.x, mons1.y); // ���� ��ǥ ���� �� ���

		// ũ����Ż ��ǥ ���� �� ���
		if(gp.crystals > 0)
			dual_move(SPRITE6, ball.x, ball.y);

		PA_WaitForVBL();
	}

	UnLoad_Screen();
	PA_LoadBackground(UP_SCREEN, BG2, &gameover);
	PA_LoadBackground(DOWN_SCREEN, BG2, &gameover);
	wait(100);
}
