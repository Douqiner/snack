#include <iostream>
#include <conio.h>
#include"all.h"
using namespace std;

void init_select_lable() {

	lable_list[LABLE_NOUSE].write_color = 0xffe493;
	lable_list[LABLE_NOUSE].back_color = 0xc47f00;
	lable_list[LABLE_NOUSE].height = 30;
	lable_list[LABLE_NOUSE].width = 50;

	lable_list[LABLE_SUB].write_color = 0xffe493;
	lable_list[LABLE_SUB].back_color = 0xc47f00;
	lable_list[LABLE_SUB].height = 40;
	lable_list[LABLE_SUB].width = 100;

	lable_list[LABLE_MAIN].write_color = 0xffe493;
	lable_list[LABLE_MAIN].back_color = 0xc47f00;
	lable_list[LABLE_MAIN].height = 40;
	lable_list[LABLE_MAIN].width = 200;
}


void init_mune_list() {
	point carry(0, 0);
	//���˵�
	mune_list[MUNE_MAIN].row = 5;
	mune_list[MUNE_MAIN].col = 1;
	mune_list[MUNE_MAIN].select_lable = LABLE_MAIN;
	mune_list[MUNE_MAIN].text[0][0] = L"�µĿ�ʼ";
	mune_list[MUNE_MAIN].text[1][0] = L"������Ϸ";
	mune_list[MUNE_MAIN].text[2][0] = L"��ʷ��¼";
	mune_list[MUNE_MAIN].text[3][0] = L"�˳���Ϸ";
	mune_list[MUNE_MAIN].text[4][0] = L"��������";
	carry.set(300, 260 + 50 * 0);
	mune_list[MUNE_MAIN].pos[0][0] = carry;
	carry.set(300, 260 + 50 * 1);
	mune_list[MUNE_MAIN].pos[1][0] = carry;
	carry.set(300, 260 + 50 * 2);
	mune_list[MUNE_MAIN].pos[2][0] = carry;
	carry.set(300, 260 + 50 * 3);
	mune_list[MUNE_MAIN].pos[3][0] = carry;
	carry.set(300, 260 + 50 * 4);
	mune_list[MUNE_MAIN].pos[4][0] = carry;

	//�µĿ�ʼ
	mune_list[MUNE_NEWGAME].row = 5;
	mune_list[MUNE_NEWGAME].col = 1;
	mune_list[MUNE_NEWGAME].select_lable = LABLE_MAIN;
	mune_list[MUNE_NEWGAME].text[0][0] = L"����ģʽ";
	mune_list[MUNE_NEWGAME].text[1][0] = L"����ģʽ";
	mune_list[MUNE_NEWGAME].text[2][0] = L"�߼�ģʽ";
	mune_list[MUNE_NEWGAME].text[3][0] = L"����֮��";
	mune_list[MUNE_NEWGAME].text[4][0] = L"�����˶�";
	carry.set(300, 260 + 50 * 0);
	mune_list[MUNE_NEWGAME].pos[0][0] = carry;
	carry.set(300, 260 + 50 * 1);
	mune_list[MUNE_NEWGAME].pos[1][0] = carry;
	carry.set(300, 260 + 50 * 2);
	mune_list[MUNE_NEWGAME].pos[2][0] = carry;
	carry.set(300, 260 + 50 * 3);
	mune_list[MUNE_NEWGAME].pos[3][0] = carry;
	carry.set(300, 260 + 50 * 4);
	mune_list[MUNE_NEWGAME].pos[4][0] = carry;

	//ѡ���ͼ
	mune_list[MUNE_MAP].row = 1;
	mune_list[MUNE_MAP].col = 4;
	mune_list[MUNE_MAP].select_lable = LABLE_SUB;
	mune_list[MUNE_MAP].text[0][0] = L"����յ�";
	mune_list[MUNE_MAP].text[0][1] = L"���Ƽ���";
	mune_list[MUNE_MAP].text[0][2] = L"�з�֮·";
	mune_list[MUNE_MAP].text[0][3] = L"б��֮��";
	carry.set(130 + 150 * 0, 500);
	mune_list[MUNE_MAP].pos[0][0] = carry;
	carry.set(130 + 150 * 1, 500);
	mune_list[MUNE_MAP].pos[0][1] = carry;
	carry.set(130 + 150 * 2, 500);
	mune_list[MUNE_MAP].pos[0][2] = carry;
	carry.set(130 + 150 * 3, 500);
	mune_list[MUNE_MAP].pos[0][3] = carry;
	
	//ѡ������
	mune_list[MUNE_CHARACTER].row = 1;
	mune_list[MUNE_CHARACTER].col = 4;
	mune_list[MUNE_CHARACTER].select_lable = LABLE_SUB;
	mune_list[MUNE_CHARACTER].text[0][0] = L"���׼���";
	mune_list[MUNE_CHARACTER].text[0][1] = L"�ֲ�ũ��";
	mune_list[MUNE_CHARACTER].text[0][2] = L"���ͷ��";
	mune_list[MUNE_CHARACTER].text[0][3] = L"���޴���";
	carry.set(130 + 150 * 0, 500);
	mune_list[MUNE_CHARACTER].pos[0][0] = carry;
	carry.set(130 + 150 * 1, 500);
	mune_list[MUNE_CHARACTER].pos[0][1] = carry;
	carry.set(130 + 150 * 2, 500);
	mune_list[MUNE_CHARACTER].pos[0][2] = carry;
	carry.set(130 + 150 * 3, 500);
	mune_list[MUNE_CHARACTER].pos[0][3] = carry;

	//��ͣ����
	mune_list[MUNE_PAUSE].row = 1;
	mune_list[MUNE_PAUSE].col = 3;
	mune_list[MUNE_PAUSE].select_lable = LABLE_SUB;
	mune_list[MUNE_PAUSE].text[0][0] = L"������Ϸ";
	mune_list[MUNE_PAUSE].text[0][1] = L"ֱ���˳�";
	mune_list[MUNE_PAUSE].text[0][2] = L"�浵�˳�";
	carry.set(150 + 150 * 0, 300);
	mune_list[MUNE_PAUSE].pos[0][0] = carry;
	carry.set(150 + 150 * 1, 300);
	mune_list[MUNE_PAUSE].pos[0][1] = carry;
	carry.set(150 + 150 * 2, 300);
	mune_list[MUNE_PAUSE].pos[0][2] = carry;

	//�����˶�
	mune_list[MUNE_MULTIPLE].row = 4;
	mune_list[MUNE_MULTIPLE].col = 1;
	mune_list[MUNE_MULTIPLE].select_lable = LABLE_MAIN;
	mune_list[MUNE_MULTIPLE].text[0][0] = L"˫����Ϸ";
	mune_list[MUNE_MULTIPLE].text[1][0] = L"�˻���ս";
	mune_list[MUNE_MULTIPLE].text[2][0] = L"����/����";
	mune_list[MUNE_MULTIPLE].text[3][0] = L"����/����";
	carry.set(300, 260 + 50 * 0);
	mune_list[MUNE_MULTIPLE].pos[0][0] = carry;
	carry.set(300, 260 + 50 * 1);
	mune_list[MUNE_MULTIPLE].pos[1][0] = carry;
	carry.set(300, 260 + 50 * 2);
	mune_list[MUNE_MULTIPLE].pos[2][0] = carry;
	carry.set(300, 260 + 50 * 3);
	mune_list[MUNE_MULTIPLE].pos[3][0] = carry;
}

void mune::display() {
	//��ȡ��Ϣ
	RECT carry;
	int width = lable_list[select_lable].width;//��ȡ��ʽ���
	int height = lable_list[select_lable].height;//��ȡ��ʽ�߶�
	COLORREF write_color = lable_list[select_lable].write_color;//��ȡ��ʽǰ��ɫ
	COLORREF back_color = lable_list[select_lable].back_color;//��ȡ��ʽ����ɫ

	//������Ϣ
	setbkcolor(back_color);
	setfillcolor(back_color);
	setlinecolor(write_color);
	settextcolor(write_color);
	settextstyle(20, 0, L"΢���ź�"); // �������ִ�С������

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//������
			carry = { pos[i][j].x,pos[i][j].y + height / 2 - 10, pos[i][j].x + width,pos[i][j].y + height };
			fillrectangle(pos[i][j].x, pos[i][j].y, pos[i][j].x + width, pos[i][j].y + height);

			//��ѡ�����
			clearrectangle(pos[i][j].x - 30, pos[i][j].y + height / 2 - 10, pos[i][j].x - 10, pos[i][j].y + height / 2 + 10);

			//д����
			drawtext(text[i][j].c_str(), &carry, DT_CENTER);
		}
	}


}

int mune::choice(int type, int user_id) {
	point now_choice(0, 0);
	point last_choice(0, 0);
	IMAGE ball_img;
	loadimage(&ball_img, _T("resource\\static\\ball.jpg"));

	int width = lable_list[select_lable].width;//��ȡ��ʽ���
	int height = lable_list[select_lable].height;//��ȡ��ʽ�߶�
	COLORREF back_color = lable_list[select_lable].back_color;//��ȡ��ʽ����ɫ
	setbkcolor(back_color);

	int wait;
	int in_key;
	while (1) {
		wait = 1;
		in_key = 0;
		//���Ǹ���
		clearrectangle(pos[last_choice.y][last_choice.x].x - 30, pos[last_choice.y][last_choice.x].y + height / 2 - 10,
			pos[last_choice.y][last_choice.x].x - 10, pos[last_choice.y][last_choice.x].y + height / 2 + 10);
		putimage(pos[now_choice.y][now_choice.x].x - 30, pos[now_choice.y][now_choice.x].y + height / 2 - 10, &ball_img);
		last_choice = now_choice;
		if (type == TYPE_MAP)//��ͼ
			show_mapinfo(now_choice.x, user_id);
		if (type == TYPE_CHARACTER)
			show_characterinfo(now_choice.x);
		Sleep(100);
		//������
		while (wait) {
			if (getkeyboard(in_key)) {
				switch (in_key) {
				case VK_UP:
				case 87://w
					now_choice.y = (now_choice.y - 1 + row) % row;
					wait = 0;
					break;
				case VK_DOWN:
				case 83://s
					now_choice.y = (now_choice.y + 1) % row;
					wait = 0;
					break;
				case VK_LEFT:
				case 65://a
					now_choice.x = (now_choice.x - 1 + col) % col;
					wait = 0;
					break;
				case VK_RIGHT:
				case 68://d
					now_choice.x = (now_choice.x + 1) % col;
					wait = 0;
					break;
				case VK_ESCAPE://esc
					return -1;
				case VK_RETURN://�س�
					flick(now_choice);
					return (now_choice.y * col + now_choice.x);
				}
			}
		}
	}

	return -1;
}

void mune::flick(point choice) {
	//��ȡ��Ϣ
	RECT carry;
	int width = lable_list[select_lable].width;//��ȡ��ʽ���
	int height = lable_list[select_lable].height;//��ȡ��ʽ�߶�
	COLORREF write_color = lable_list[select_lable].write_color;//��ȡ��ʽǰ��ɫ
	COLORREF back_color = lable_list[select_lable].back_color;//��ȡ��ʽ����ɫ

	carry = { pos[choice.y][choice.x].x,pos[choice.y][choice.x].y + height / 2 - 10, pos[choice.y][choice.x].x + width,pos[choice.y][choice.x].y + height };

	for (int i = 5; i >= 0; i--) {
		setbkcolor(write_color);
		setfillcolor(write_color);
		setlinecolor(back_color);
		settextcolor(back_color);
		//������
		fillrectangle(pos[choice.y][choice.x].x, pos[choice.y][choice.x].y, pos[choice.y][choice.x].x + width, pos[choice.y][choice.x].y + height);
		//д����
		drawtext(text[choice.y][choice.x].c_str(), &carry, DT_CENTER);
		Sleep(70);

		setbkcolor(back_color);
		setfillcolor(back_color);
		setlinecolor(write_color);
		settextcolor(write_color);
		//������
		fillrectangle(pos[choice.y][choice.x].x, pos[choice.y][choice.x].y, pos[choice.y][choice.x].x + width, pos[choice.y][choice.x].y + height);
		//д����
		drawtext(text[choice.y][choice.x].c_str(), &carry, DT_CENTER);
		Sleep(70);
	}
}

void run_threshold(int map_choice, int character, int user_id, int is_load, int save_id) {
	if (!end_music)
		PlaySoundA("resource\\music\\back_end.wav", NULL, SND_FILENAME | SND_ASYNC);
	int i, j, old_time = 0;
	int height_score = game_rank.highscore[0];
	int score = 0;
	object ob_inmap;
	char map[30][30];
	snack kun;

	//�Ƿ�����
	if (!is_load) {
		//��ʼ����ͼ
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++) {
				ob_inmap.nature[i][j] = wall_list[map_choice].block[i][j];
				map[i][j] = wall_list[map_choice].block[i][j];
				if (wall_list[map_choice].block[i][j] == OBJECT_APPLE)
					ob_inmap.apple_num++;
				if (wall_list[map_choice].block[i][j] == OBJECT_MUD)
					ob_inmap.mud_num++;
			}
		kun.set(20, 19, character, 1);
	}
	else {//����浵
		user_list[user_id].save_load(user_id, save_id, map_choice, ob_inmap, kun, old_time, score);
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++)
				map[i][j] = ob_inmap.nature[i][j];
	}

	setbkcolor(wall_list[map_choice].bkcolor);
	clearrectangle(0, 0, 600, 600);

	IMAGE cavas_img;
	loadimage(&cavas_img, L"resource\\static\\canvas.png");
	putimage(600, 0, &cavas_img);

	//��ʼ����
	kun.load(map);

	//��ʼ����ͼ
	render(map);
	outputflame(kun.id);
	outputinfo(score, kun, old_time, height_score);
	_getche();

	//ʱ��
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type;
	int time_to_render = 0;

	BeginBatchDraw();//ֹͣ������滭
	while (kun.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//��һ������
				in_type = key_id(in_key, 1, kun.state);
			else
				in_type = key_id(in_key, 1, kun.action);

			if (in_type != -1) {
				if (in_type != 5)
					if (kun.action == kun.state)//��һ������
						kun.action = in_type;
					else
						kun.next_action = in_type;
				else{
					//�浵ҳ��
					mune_list[MUNE_PAUSE].col = 3;
					EndBatchDraw();
					mune_list[MUNE_PAUSE].display();
					int choice = mune_list[MUNE_PAUSE].choice(TYPE_GENERAL);

					if (choice == 0 || choice == -1) {
						BeginBatchDraw();//ֹͣ������滭
						setbkcolor(wall_list[map_choice].bkcolor);
						clearrectangle(0, 0, 600, 600);
						render(map);
						FlushBatchDraw();//��ʼ���

						_getche();
					}
					else if (choice == 1) {//����
						break;
					}
					else {//�浵
						user_list[user_id].init_mune_addsave();
						mune_list[MUNE_ADDSAVE].display();
						int select = mune_list[MUNE_ADDSAVE].choice(TYPE_GENERAL);
						if (select != -1) {
							user_list[user_id].save_append(user_id, select, map_choice, 0, ob_inmap, kun, end - start + old_time, score);
							upload_user_list();
						}
						return;
					}
				}
			}
		}

		end = clock();
		if (end - tmp >= 100) {
			tmp = end;
			if (time_to_render) {
				time_to_render = 0;
				kun.step(map, score, ob_inmap);
				for (i = 0; i < 30; i++)
					for (j = 0; j < 30; j++)
						map[i][j] = ob_inmap.nature[i][j];
				kun.load(map);
				ob_inmap.check_generate(map);

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo(score, kun, end - start + old_time, height_score);
				FlushBatchDraw();//��ʼ���
				//next����
				if (kun.next_action != -1) {
					kun.action = kun.next_action;
					kun.next_action = -1;
				}
			}
			else{
				time_to_render = 1;
				if (kun.fast_time) {
					--kun.fast_time;

					kun.step(map, score, ob_inmap);
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					kun.load(map);
					ob_inmap.check_generate(map);

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo(score, kun, end - start + old_time, height_score);
					FlushBatchDraw();//��ʼ���
					//next����
					if (kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();
	//����
	if (score >= height_score) {
		game_rank.highscore[0] = score;
		game_rank.user_id[0] = user_id;
		upload_rank();
	}
	//��ʷ��¼
	upload_history(0, user_id, score);

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"΢���ź�");
	settextcolor(0x0E0EF3);
	drawtext(L"��Ϸ�������س��˳�", &carry, DT_CENTER);
	getchar();
}


void run_advance(int map_choice, int character, int user_id, int is_load, int save_id){
	if (!end_music)
		PlaySoundA("resource\\music\\back_end.wav", NULL, SND_FILENAME | SND_ASYNC);
	int i, j, old_time = 0;
	int height_score = game_rank.highscore[1];
	int score = 0;
	object ob_inmap;
	char map[30][30];
	snack kun;

	//�Ƿ�����
	if (!is_load) {
		//��ʼ����ͼ
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++) {
				ob_inmap.nature[i][j] = wall_list[map_choice].block[i][j];
				map[i][j] = wall_list[map_choice].block[i][j];
				if (wall_list[map_choice].block[i][j] == OBJECT_APPLE)
					ob_inmap.apple_num++;
				if (wall_list[map_choice].block[i][j] == OBJECT_MUD)
					ob_inmap.mud_num++;
			}
		kun.set(20, 19, character, 99999);
	}
	else {//����浵
		user_list[user_id].save_load(user_id, save_id, map_choice, ob_inmap, kun, old_time, score);
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++)
				map[i][j] = ob_inmap.nature[i][j];
	}

	setbkcolor(wall_list[map_choice].bkcolor);
	clearrectangle(0, 0, 600, 600);

	IMAGE cavas_img;
	loadimage(&cavas_img, L"resource\\static\\canvas.png");
	putimage(600, 0, &cavas_img);

	//��ʼ����
	kun.load(map);

	//��ʼ����ͼ
	render(map);
	outputflame(kun.id);
	outputinfo(score, kun, old_time, height_score);
	_getche();

	//ʱ��
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type;
	int time_to_render = 0;

	BeginBatchDraw();//ֹͣ������滭
	while (kun.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//��һ������
				in_type = key_id(in_key, 1, kun.state);
			else
				in_type = key_id(in_key, 1, kun.action);

			if (in_type != -1) {
				if (in_type != 5)
					if (kun.action == kun.state)//��һ������
						kun.action = in_type;
					else
						kun.next_action = in_type;
				else {
					//�浵ҳ��
					mune_list[MUNE_PAUSE].col = 3;
					EndBatchDraw();
					mune_list[MUNE_PAUSE].display();
					int choice = mune_list[MUNE_PAUSE].choice(TYPE_GENERAL);

					if (choice == 0 || choice == -1) {
						BeginBatchDraw();//ֹͣ������滭
						setbkcolor(wall_list[map_choice].bkcolor);
						clearrectangle(0, 0, 600, 600);
						render(map);
						FlushBatchDraw();//��ʼ���

						_getche();
					}
					else if (choice == 1) {//����
						break;
					}
					else {//�浵
						user_list[user_id].init_mune_addsave();
						mune_list[MUNE_ADDSAVE].display();
						int select = mune_list[MUNE_ADDSAVE].choice(TYPE_GENERAL);
						if (select != -1) {
							user_list[user_id].save_append(user_id, select, map_choice, 1, ob_inmap, kun, end - start + old_time, score);
							upload_user_list();
						}
						return;
					}
				}
			}
		}

		end = clock();
		if (end - tmp >= 100) {
			tmp = end;
			if (time_to_render) {
				time_to_render = 0;
				if (!kun.step(map, score, ob_inmap)) {
					//��������
					kun.die_load(BLOCK_FENCE, ob_inmap);
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					if (kun.relife(map)) {
						kun.load(map);
						if (!ob_inmap.check_generate(map))//û��λ��������ø
							break;
						clearrectangle(0, 0, 600, 600);
						render(map);
						outputinfo(score, kun, end - start + old_time, height_score);
						FlushBatchDraw();//��ʼ���
						_getche();
						continue;
					}
					else//�Ҳ���λ��
						break;
				}
				//һ�㴦��
				for (i = 0; i < 30; i++)
					for (j = 0; j < 30; j++)
						map[i][j] = ob_inmap.nature[i][j];
				kun.load(map);
				if (!ob_inmap.check_generate(map))//û��λ��������ø
					break;

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo(score, kun, end - start + old_time, height_score);
				FlushBatchDraw();//��ʼ���
				//next����
				if (kun.next_action != -1) {
					kun.action = kun.next_action;
					kun.next_action = -1;
				}
			}
			else {
				time_to_render = 1;
				if (kun.fast_time) {
					--kun.fast_time;

					if (!kun.step(map, score, ob_inmap)) {
						//��������
						kun.die_load(BLOCK_FENCE, ob_inmap);
						for (i = 0; i < 30; i++)
							for (j = 0; j < 30; j++)
								map[i][j] = ob_inmap.nature[i][j];
						if (kun.relife(map)) {
							kun.load(map);
							if (!ob_inmap.check_generate(map))//û��λ��������ø
								break;
							clearrectangle(0, 0, 600, 600);
							render(map);
							outputinfo(score, kun, end - start + old_time, height_score);
							FlushBatchDraw();//��ʼ���
							_getche();
							continue;
						}
						else//�Ҳ���λ��
							break;
					}
					//һ�㴦��
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					kun.load(map);
					ob_inmap.check_generate(map);

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo(score, kun, end - start + old_time, height_score);
					FlushBatchDraw();//��ʼ���
					//next����
					if (kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();

	if (score >= height_score) {
		game_rank.highscore[1] = score;
		game_rank.user_id[1] = user_id;
		upload_rank();
	}
	//��ʷ��¼
	upload_history(1, user_id, score);

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"΢���ź�");
	settextcolor(0x0E0EF3);
	drawtext(L"��Ϸ�������س��˳�", &carry, DT_CENTER);
	getchar();
}


void run_senior(int map_choice, int character, int user_id, int is_load, int save_id) {
	if(!end_music)
		PlaySoundA("resource\\music\\back_end.wav", NULL, SND_FILENAME | SND_ASYNC);
	int i, j, old_time = 0;
	int height_score = game_rank.highscore[2];
	int score = 0;
	object ob_inmap;
	char map[30][30];
	snack kun;

	//�Ƿ�����
	if (!is_load) {
		//��ʼ����ͼ
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++) {
				ob_inmap.nature[i][j] = wall_list[map_choice].block[i][j];
				map[i][j] = wall_list[map_choice].block[i][j];
				if (wall_list[map_choice].block[i][j] == OBJECT_APPLE)
					ob_inmap.apple_num++;
				if (wall_list[map_choice].block[i][j] == OBJECT_MUD)
					ob_inmap.mud_num++;
			}
		kun.set(20, 19, character, 6);
	}
	else {//����浵
		user_list[user_id].save_load(user_id, save_id, map_choice, ob_inmap, kun, old_time, score);
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++)
				map[i][j] = ob_inmap.nature[i][j];
	}

	setbkcolor(wall_list[map_choice].bkcolor);
	clearrectangle(0, 0, 600, 600);

	IMAGE cavas_img;
	loadimage(&cavas_img, L"resource\\static\\canvas.png");
	putimage(600, 0, &cavas_img);

	//��ʼ����
	kun.load(map);

	//��ʼ����ͼ
	render(map);
	outputflame(kun.id);
	outputinfo(score, kun, old_time, height_score);
	_getche();

	//ʱ��
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type;
	int time_to_render = 0;

	BeginBatchDraw();//ֹͣ������滭
	while (kun.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//��һ������
				in_type = key_id(in_key, 1, kun.state);
			else
				in_type = key_id(in_key, 1, kun.action);

			if (in_type != -1) {
				if (in_type != 5)
					if (kun.action == kun.state)//��һ������
						kun.action = in_type;
					else
						kun.next_action = in_type;
				else {
					//�浵ҳ��
					mune_list[MUNE_PAUSE].col = 3;
					EndBatchDraw();
					mune_list[MUNE_PAUSE].display();
					int choice = mune_list[MUNE_PAUSE].choice(TYPE_GENERAL);

					if (choice == 0 || choice == -1) {
						BeginBatchDraw();//ֹͣ������滭
						setbkcolor(wall_list[map_choice].bkcolor);
						clearrectangle(0, 0, 600, 600);
						render(map);
						FlushBatchDraw();//��ʼ���

						_getche();
					}
					else if (choice == 1) {//����
						break;
					}
					else {//�浵
						user_list[user_id].init_mune_addsave();
						mune_list[MUNE_ADDSAVE].display();
						int select = mune_list[MUNE_ADDSAVE].choice(TYPE_GENERAL);
						if (select != -1) {
							user_list[user_id].save_append(user_id, select, map_choice, 2, ob_inmap, kun, end - start + old_time, score);
							upload_user_list();
						}
						return;
					}
				}
			}
		}

		end = clock();
		if (end - tmp >= 100) {
			tmp = end;
			if (time_to_render) {
				time_to_render = 0;
				if (!kun.step(map, score, ob_inmap)) {
					if (!kun.life) {
						outputinfo(score, kun, end - start + old_time, height_score);
						break;
					}
					//��������
					kun.die_load(OBJECT_APPLE, ob_inmap);
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					if (kun.relife(map)) {
						kun.load(map);
						if (!ob_inmap.check_generate(map))//û��λ��������ø
							break;
						clearrectangle(0, 0, 600, 600);
						render(map);
						outputinfo(score, kun, end - start + old_time, height_score);
						FlushBatchDraw();//��ʼ���
						_getche();
						continue;
					}
					else//�Ҳ���λ��
						break;
				}
				//һ�㴦��
				for (i = 0; i < 30; i++)
					for (j = 0; j < 30; j++)
						map[i][j] = ob_inmap.nature[i][j];
				kun.load(map);
				if (!ob_inmap.check_generate(map))//û��λ��������ø
					break;

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo(score, kun, end - start + old_time, height_score);
				FlushBatchDraw();//��ʼ���
				//next����
				if (kun.next_action != -1) {
					kun.action = kun.next_action;
					kun.next_action = -1;
				}
			}
			else {
				time_to_render = 1;
				if (kun.fast_time) {
					--kun.fast_time;

					if (!kun.step(map, score, ob_inmap)) {
						if (!kun.life){
							outputinfo(score, kun, end - start + old_time, height_score);
							break;
						}
						//��������
						kun.die_load(OBJECT_APPLE, ob_inmap);
						for (i = 0; i < 30; i++)
							for (j = 0; j < 30; j++)
								map[i][j] = ob_inmap.nature[i][j];
						if (kun.relife(map)) {
							kun.load(map);
							if (!ob_inmap.check_generate(map))//û��λ��������ø
								break;
							clearrectangle(0, 0, 600, 600);
							render(map);
							outputinfo(score, kun, end - start + old_time, height_score);
							FlushBatchDraw();//��ʼ���
							_getche();
							continue;
						}
						else//�Ҳ���λ��
							break;
					}
					//һ�㴦��
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					kun.load(map);
					ob_inmap.check_generate(map);

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo(score, kun, end - start + old_time, height_score);
					FlushBatchDraw();//��ʼ���
					//next����
					if (kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();
	//����
	if (score >= height_score) {
		game_rank.highscore[2] = score;
		game_rank.user_id[2] = user_id;
		upload_rank();
	}
	//��ʷ��¼
	upload_history(2, user_id, score);
	
	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"΢���ź�");
	settextcolor(0x0E0EF3);
	drawtext(L"��Ϸ�������س��˳�", &carry, DT_CENTER);
	getchar();
}


void kunkun_trip(int user_id, int is_load, int save_id) {
	if (!end_music)
		PlaySoundA("resource\\music\\back_end.wav", NULL, SND_FILENAME | SND_ASYNC);
	int i, j, old_time = 0;
	int score = 0;
	int map_choice = 1;

	IMAGE cavas_img;
	loadimage(&cavas_img, L"resource\\static\\canvas.png");
	BeginBatchDraw();//ֹͣ������滭

	for (; map_choice <= 3; map_choice++) { //����ͼѭ��
		object ob_inmap;
		char map[30][30];
		snack kun;
		//�Ƿ�����
		if (!is_load) {
			//��ʼ����ͼ
			for (i = 0; i < 30; i++)
				for (j = 0; j < 30; j++) {
					ob_inmap.nature[i][j] = wall_list[map_choice].block[i][j];
					map[i][j] = wall_list[map_choice].block[i][j];
					if (wall_list[map_choice].block[i][j] == OBJECT_APPLE)
						ob_inmap.apple_num++;
					if (wall_list[map_choice].block[i][j] == OBJECT_MUD)
						ob_inmap.mud_num++;
				}
			kun.set(20, 19, 1, 1);
		}
		else {//����浵
			user_list[user_id].save_load(user_id, save_id, map_choice, ob_inmap, kun, old_time, score);
			for (i = 0; i < 30; i++)
				for (j = 0; j < 30; j++)
					map[i][j] = ob_inmap.nature[i][j];
			--is_load;
		}
		
		setbkcolor(wall_list[map_choice].bkcolor);
		clearrectangle(0, 0, 600, 600);
		putimage(600, 0, &cavas_img);

		//��ʼ����
		kun.load(map);

		//��ʼ����ͼ
		render(map);
		outputflame(kun.id, map_choice);
		outputinfo(score, kun, old_time, -1);
		FlushBatchDraw();//��ʼ���
		_getche();

		//ʱ��
		clock_t start, end, tmp;
		start = clock();
		tmp = clock();
		end = clock();

		int in_key, in_type;
		int time_to_render = 0;

		while (kun.life) {
			if (getkeyboard(in_key)) {

				if (kun.action == kun.state)//��һ������
					in_type = key_id(in_key, 1, kun.state);
				else
					in_type = key_id(in_key, 1, kun.action);

				if (in_type != -1) {
					if (in_type != 5)
						if (kun.action == kun.state)//��һ������
							kun.action = in_type;
						else
							kun.next_action = in_type;
					else {
						//�浵ҳ��
						mune_list[MUNE_PAUSE].col = 3;
						EndBatchDraw();
						mune_list[MUNE_PAUSE].display();
						int choice = mune_list[MUNE_PAUSE].choice(TYPE_GENERAL);

						if (choice == 0 || choice == -1) {
							BeginBatchDraw();//ֹͣ������滭
							setbkcolor(wall_list[map_choice].bkcolor);
							clearrectangle(0, 0, 600, 600);
							render(map);
							FlushBatchDraw();//��ʼ���

							_getche();
						}
						else if (choice == 1) {//����
							return;
						}
						else {//�浵
							user_list[user_id].init_mune_addsave();
							mune_list[MUNE_ADDSAVE].display();
							int select = mune_list[MUNE_ADDSAVE].choice(TYPE_GENERAL);
							if (select != -1) {
								user_list[user_id].save_append(user_id, select, map_choice, 3, ob_inmap, kun, end - start + old_time, score);
								upload_user_list();
							}
							return;
						}
					}
				}
			}

			end = clock();
			if (end - tmp >= 100) {
				tmp = end;
				if (time_to_render) {
					time_to_render = 0;
					kun.step(map, score, ob_inmap);
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					kun.load(map);
					if (map_choice == 1)
						ob_inmap.check_generate(map);
					else if (map_choice == 2)
						ob_inmap.check_generate(map, 1, 0);
					else
						ob_inmap.check_generate(map, 0, 0);

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo(score, kun, end - start + old_time, -1);
					FlushBatchDraw();//��ʼ���
					if (kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
				}
				else {
					time_to_render = 1;
					if (kun.fast_time) {
						--kun.fast_time;

						kun.step(map, score, ob_inmap);
						for (i = 0; i < 30; i++)
							for (j = 0; j < 30; j++)
								map[i][j] = ob_inmap.nature[i][j];
						kun.load(map);
						if (map_choice == 1)
							ob_inmap.check_generate(map);
						else if (map_choice == 2)
							ob_inmap.check_generate(map, 1, 0);
						else
							ob_inmap.check_generate(map, 0, 0);

						clearrectangle(0, 0, 600, 600);
						render(map);
						outputinfo(score, kun, end - start + old_time, -1);
						FlushBatchDraw();//��ʼ���
						if (kun.next_action != -1) {
							kun.action = kun.next_action;
							kun.next_action = -1;
						}
					}
				}
				if (check_trip_finish(map_choice, score, ob_inmap))
					break;
			}
		}
		if (kun.life == 0) {
			RECT carry = { 200, 285, 400, 315 };
			settextstyle(25, 0, L"΢���ź�");
			settextcolor(0x0E0EF3);
			drawtext(L"ʧ�ܣ��س���������", &carry, DT_CENTER);
			FlushBatchDraw();//��ʼ���
			getchar();
			--map_choice;//��һ��ʧ��
		}
		else {
			//չʾ�������ؿ���Ϣ
			show_trip_map(map_choice, user_id);
			FlushBatchDraw();//��ʼ���
			getchar();
		}

		old_time += end - start;
	}

	EndBatchDraw();

	//����
	if (game_rank.highscore[3] == 0 || old_time <= game_rank.highscore[3]) {
		game_rank.highscore[3] = old_time;
		game_rank.user_id[3] = user_id;
		upload_rank();
	}
	//��ʷ��¼
	upload_history(3, user_id, old_time);

	if (map_choice == 4) {
		end_music = 1;
		mune_list[MUNE_MAIN].row = 5;
		//���Ž���mv
		play_end_video();
	}
}