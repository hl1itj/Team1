/*
 * water.h
 *
 *  Created on: 2010. 12. 17.
 *      Author: ywyw
 */

#ifndef WATER_H_
#define WATER_H_

class water {
public:
	int num; // ����� �ѹ�
	int enable; // Ȱ��ȭ ����
	int x;
	int y;
public:
	water();
	virtual ~water();
	void move(int move_cnt);
	void water_setting(int pal_num, int obj_num);
};

#endif /* WATER_H_ */
