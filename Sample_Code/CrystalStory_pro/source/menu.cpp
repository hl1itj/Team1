/*
 * menu.cpp
 *
 *  Created on: 2010. 12. 16.
 *      Author: ��ǻ�Ͱ��а�
 */
#include "cs_api.h"
#include "menu.h"

void ret_next() // �ƹ����� Touch�� ���� ����ȭ������ ��ȯ
{
	while (1) {
		if ( Stylus.Newpress )
			return;
		PA_WaitForVBL();
	}
}

int sel_menu() // Touch�� ���� �޴��� ����. ���õ� �޴��� ��ȣ�� ����
{
	int select=0;
	while(1)
	{
		if(Stylus.Newpress) {
			if(Stylus.X > 28 && Stylus.Y < 226 && Stylus.X > 18 && Stylus.Y < 62) {
		        select = 1;
		        break;
			}
			else if(Stylus.X > 28 && Stylus.X < 226 && Stylus.X > 73 && Stylus.Y < 119) {
				select = 2;
				break;
			}
			else if(Stylus.X > 28 && Stylus.X < 226 && Stylus.X > 128 && Stylus.Y < 176) {
				select = 3;
				break;
			}
		}
		PA_WaitForVBL();
	}
	return select;
}
