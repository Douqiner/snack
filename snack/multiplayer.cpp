#include "Client.h"
#include <iostream>
#include<string>
#include <conio.h>
#include"all.h"
using namespace NetworkHelper;
using namespace std;

void run_double_player(int map_choice, int character1, int character2, int user_id) {
	if (!end_music)
		PlaySoundA("resource\\music\\back_end.wav", NULL, SND_FILENAME | SND_ASYNC);
	int i, j;
	int score1 = 0, score2 = 0;
	object ob_inmap;
	char map[30][30];
	snack kun, cai;

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
	kun.set(20, 19, character1, 1);
	cai.set(27, 5, character2, 1);

	setbkcolor(wall_list[map_choice].bkcolor);
	clearrectangle(0, 0, 600, 600);

	IMAGE cavas_img;
	loadimage(&cavas_img, L"resource\\static\\canvas.png");
	putimage(600, 0, &cavas_img);

	//��ʼ����
	kun.load(map);
	cai.load(map);

	//��ʼ����ͼ
	render(map);
	outputflame_m(kun.id, cai.id);
	outputinfo_m(score1, score2, kun, cai, 0);
	_getche();

	//ʱ��
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type1, in_type2;
	int time_to_render = 0;

	BeginBatchDraw();//ֹͣ������滭
	while (kun.life || cai.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//��һ������
				in_type1 = key_id(in_key, 1, kun.state);
			else
				in_type1 = key_id(in_key, 1, kun.action);

			if (cai.action == cai.state)//��һ������
				in_type2 = key_id(in_key, 2, cai.state);
			else
				in_type2 = key_id(in_key, 2, cai.action);

			if (in_type1 == 5) {
				//�˳�ҳ��
				mune_list[MUNE_PAUSE].col = 2;
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
				else {//����
					break;
				}
			}
			else {
				if (in_type1 != -1) {
					if (kun.action == kun.state)//��һ������
						kun.action = in_type1;
					else
						kun.next_action = in_type1;
				}
				if (in_type2 != -1) {
					if (cai.action == cai.state)//��һ������
						cai.action = in_type2;
					else
						cai.next_action = in_type2;
				}
			}
		}

		end = clock();
		if (end - tmp >= 100) {
			tmp = end;
			if (time_to_render) {
				time_to_render = 0;

				if (kun.life && cai.life) {//�������
					if (!kun.step(map, score1, ob_inmap))
						if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10){//��������
							++kun.life;//��������
							score1 += 100;
						}
						else 
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (!cai.step(map, score2, ob_inmap))
						if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {//��������
							++cai.life;//��������
							score2 += 100;
						}
						else
							cai.die_load(BLOCK_ROCK, ob_inmap);
					check_multiple(kun, cai, ob_inmap, score1, score2);//��Ⲣ����
				}
				else {//�������
					if (kun.life)
						if (!kun.step(map, score1, ob_inmap))
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (cai.life)
						if (!cai.step(map, score2, ob_inmap))
							cai.die_load(BLOCK_ROCK, ob_inmap);
				}

				for (i = 0; i < 30; i++)
					for (j = 0; j < 30; j++)
						map[i][j] = ob_inmap.nature[i][j];
				if (kun.life)
					kun.load(map);
				if (cai.life)
					cai.load(map);
				ob_inmap.check_generate(map);

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo_m(score1, score2, kun, cai, end - start);
				FlushBatchDraw();//��ʼ���
				//next����
				if (kun.next_action != -1) {
					kun.action = kun.next_action;
					kun.next_action = -1;
				}
				if (cai.next_action != -1) {
					cai.action = cai.next_action;
					cai.next_action = -1;
				}
			}
			else {
				time_to_render = 1;
				if ((kun.life && kun.fast_time) || (cai.life && cai.fast_time)) {

					if (kun.life && cai.life) {//�������

						if (kun.fast_time) {
							--kun.fast_time;
							if (!kun.step(map, score1, ob_inmap)) {
								if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10) {
									++kun.life;//��������
									score1 += 100;
								}
								else
									kun.die_load(BLOCK_ROCK, ob_inmap);
							}
						}
						if (cai.fast_time) {
							--cai.fast_time;
							if (!cai.step(map, score2, ob_inmap)) {
								if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {
									++cai.life;//��������
									score2 += 100;
								}
								else
									cai.die_load(BLOCK_ROCK, ob_inmap);
							}
						}
						check_multiple(kun, cai, ob_inmap, score1, score2);//��Ⲣ����
					}
					else {//�������
						if (kun.life && kun.fast_time) {
							if (!kun.step(map, score1, ob_inmap))
								kun.die_load(BLOCK_ROCK, ob_inmap);
							--kun.fast_time;
						}
						if (cai.life && cai.fast_time) {
							if (!cai.step(map, score1, ob_inmap))
								cai.die_load(BLOCK_ROCK, ob_inmap);
							--cai.fast_time;
						}
					}

					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];

					if (kun.life)
						kun.load(map);
					if (cai.life)
						cai.load(map);
					ob_inmap.check_generate(map);

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo_m(score1, score2, kun, cai, end - start);
					FlushBatchDraw();//��ʼ���
					//next����
					if (kun.life && kun.fast_time && kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
					if (cai.life && cai.fast_time && cai.next_action != -1) {
						cai.action = cai.next_action;
						cai.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();

	//��ʷ��¼
	upload_history(4, user_id, max(score1, score2));

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"΢���ź�");
	settextcolor(0x0E0EF3);
	drawtext(L"��Ϸ�������س��˳�", &carry, DT_CENTER);
	getchar();
}


void run_man_ai(int map_choice, int character1, int character2, int user_id) {
	if (!end_music)
		PlaySoundA("resource\\music\\back_end.wav", NULL, SND_FILENAME | SND_ASYNC);
	int i, j;
	int score1 = 0, score2 = 0;
	object ob_inmap;
	char map[30][30];
	snack kun;
	snack_ai cai;

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
	kun.set(20, 19, character1, 1);
	cai.set(27, 5, character2, 1);

	setbkcolor(wall_list[map_choice].bkcolor);
	clearrectangle(0, 0, 600, 600);

	IMAGE cavas_img;
	loadimage(&cavas_img, L"resource\\static\\canvas.png");
	putimage(600, 0, &cavas_img);

	//��ʼ����
	kun.load(map);
	cai.load(map);

	//��ʼ����ͼ
	render(map);
	outputflame_m(kun.id, cai.id);
	outputinfo_m(score1, score2, kun, cai, 0);
	_getche();

	//ʱ��
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type;
	int time_to_render = 0;

	BeginBatchDraw();//ֹͣ������滭
	while (kun.life || cai.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//��һ������
				in_type = key_id(in_key, 1, kun.state);
			else
				in_type = key_id(in_key, 1, kun.action);

			if (in_type == 5) {
				//�˳�ҳ��
				mune_list[MUNE_PAUSE].col = 2;
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
				else {//����
					break;
				}
			}
			else {
				if (in_type != -1) {
					if (kun.action == kun.state)//��һ������
						kun.action = in_type;
					else
						kun.next_action = in_type;
				}
			}
		}

		end = clock();
		if (end - tmp >= 100) {
			tmp = end;
			if (time_to_render) {
				time_to_render = 0;

				if (kun.life && cai.life) {//�������
					cai.direct(map);//��·
					if (!kun.step(map, score1, ob_inmap))
						if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10) {//��������
							++kun.life;//��������
							score1 += 100;
						}
						else
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (!cai.step(map, score2, ob_inmap))
						if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {//��������
							++cai.life;//��������
							score2 += 100;
						}
						else
							cai.die_load(BLOCK_ROCK, ob_inmap);
					check_multiple(kun, cai, ob_inmap, score1, score2);//��Ⲣ����
				}
				else {//�������
					if (kun.life)
						if (!kun.step(map, score1, ob_inmap))
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (cai.life){
						cai.direct(map);//��·
						if (!cai.step(map, score2, ob_inmap))
							cai.die_load(BLOCK_ROCK, ob_inmap);
					}
				}

				for (i = 0; i < 30; i++)
					for (j = 0; j < 30; j++)
						map[i][j] = ob_inmap.nature[i][j];
				if (kun.life)
					kun.load(map);
				if (cai.life)
					cai.load(map);
				ob_inmap.check_generate(map);

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo_m(score1, score2, kun, cai, end - start);
				FlushBatchDraw();//��ʼ���
				//next����
				if (kun.next_action != -1) {
					kun.action = kun.next_action;
					kun.next_action = -1;
				}
			}
			else {
				time_to_render = 1;
				if ((kun.life && kun.fast_time) || (cai.life && cai.fast_time)) {

					if (kun.life && cai.life) {//�������
						
						if (kun.fast_time){
							--kun.fast_time;
							if (!kun.step(map, score1, ob_inmap)) {
								if(map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10){
									++kun.life;//��������
									score1 += 100;
								}
								else
									kun.die_load(BLOCK_ROCK, ob_inmap);
							}
						}
						if (cai.fast_time){
							cai.direct(map);//��·
							--cai.fast_time;
							if (!cai.step(map, score2, ob_inmap)) {
								if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {
									++cai.life;//��������
									score2 += 100;
								}
								else
									cai.die_load(BLOCK_ROCK, ob_inmap);
							}
							
						}
						check_multiple(kun, cai, ob_inmap, score1, score2);//��Ⲣ����
					}
					else {//�������
						if (kun.life && kun.fast_time) {
							if (!kun.step(map, score1, ob_inmap))
								kun.die_load(BLOCK_ROCK, ob_inmap);
							--kun.fast_time;
						}
						if (cai.life && cai.fast_time) {
							cai.direct(map);//��·
							if (!cai.step(map, score1, ob_inmap))
								cai.die_load(BLOCK_ROCK, ob_inmap);
							--cai.fast_time;
						}
					}

					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];

					if (kun.life)
						kun.load(map);
					if (cai.life)
						cai.load(map);
					ob_inmap.check_generate(map);

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo_m(score1, score2, kun, cai, end - start);
					FlushBatchDraw();//��ʼ���
					//next����
					if (kun.life && kun.fast_time && kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();

	//��ʷ��¼
	upload_history(5, user_id, score1);

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"΢���ź�");
	settextcolor(0x0E0EF3);
	drawtext(L"��Ϸ�������س��˳�", &carry, DT_CENTER);
	getchar();
}

int showRoom(ClientHelper& _client) {
	/*******************************
	չʾ�����б�
	getRoomList(room_list_t)����ֵΪbool������Ϊroom_list_t�����á�
	����ɹ���ȡ��������Ϣ����������true�����ҽ������б����ṹ��room_list_t��
	room_list_t�ṹ����
	struct room_list_t {
		uint32_t roomNum;   // ��ǰ���ڵķ�������
		room_t *rooms;    // ÿ���������Ϣ
	};
	room_t�ṹ����
	struct room_t {
		uint32_t roomId;     // ����id
		uint32_t existing;	 // ��������
		char roomName[40];	 // ������
		msg_t* everyOne;     // ���ڱ�������û�д���ó�Ա
	};
	������(showRoom)�ṩ�˶�ȡ������Ϣ��˼·�ο�
	********************************/
	room_list_t rlt;
	if (!_client.getRoomList(rlt)) {
		printf("��ȡ�б�ʧ��\n");
		return 0;
	}
	printf("��������:\t%u\n----�б�����----\n", rlt.roomNum);
	for (uint32_t i = 0; i < rlt.roomNum; ++i) {
		printf("����%u:\n", i + 1);
		printf("������:%s\t����id:%u\t��ǰ����:%u\n", rlt.rooms[i].roomName, rlt.rooms[i].roomId, rlt.rooms[i].existing);
	}
	return 1;
}

int connectRoom(ClientHelper& _client) {
	/*******************************
	������ĳ������
	ͨ�������id�������ӣ�����idΪΨһ��ʶ����
	connectToRoom(uint32_t)Ϊ������ָ������ķ�����������ӷ���ɹ�����������true��
	connectToRoom(room_t&)Ϊ���ط���������Դ���һ��room_t�ṹ�������ӷ��䡣
	�������ͨ����ȡ�����б�rtl��Ȼ��connectToRoom(rtl.rooms[i])���������ӷ��䡣
	********************************/
	showRoom(_client);

	uint32_t a;
	while(1){
		printf("������Ҫ����ķ���id\n");
		cin >> a;
		if (!_client.connectToRoom(a)) {
			printf("����ʧ��\n");
		}
		break;
	}
	return 1;
}

void run_web_game(int map_choice, int character_main, int user_id, int is_host) {

	ClientHelper client;
	msg_package_t m;
	room_t r;
	uint32_t roomId;
	closegraph();

	int character_sub;
	snack kun, cai;//����

	if(is_host){
		if (!client.connectToServer("127.0.0.1", 10001, "qin_snack_host")) {
			cout << "���ӷ�����ʧ��";
			initgraph(800, 600);  // ��ʼ������
			init_font();
			return;
		}
		if (!client.hostNewRoom("qin_game_room", roomId)) {
			cout << "��������ʧ��";
			initgraph(800, 600);  // ��ʼ������
			init_font();
			return;
		}

		cout << "�ȴ��������������idΪ" << roomId << ",����Ϊqin_game_room�ķ���" << endl;
		while (1) {//�ȴ����ܽ�ɫ��Ϣ
			if (client.recvMsg(m)) {
				memcpy(&character_sub, m.msgs[0]->msgContent, sizeof(character_sub));
				break;
			}
		}
		//���͵�ͼ��Ϣ
		if (!client.sendBinaryMsg((char*)&map_choice, sizeof(map_choice))) {
			cout << "����ʧ��";
			initgraph(800, 600);  // ��ʼ������
			init_font();
			return;
		}
		//���ͽ�ɫ��Ϣ
		if (!client.sendBinaryMsg((char*)&character_main, sizeof(character_main))) {
			cout << "����ʧ��";
			initgraph(800, 600);  // ��ʼ������
			init_font();
			return;
		}

		//��ʼ��
		kun.set(20, 19, character_main, 1);
		cai.set(27, 5, character_sub, 1);

	}
	else {
		if (!client.connectToServer("127.0.0.1", 10001, "qin_snack_guest")) {
			cout << "���ӷ�����ʧ��";
			initgraph(800, 600);  // ��ʼ������
			init_font();
			return;
		}
		connectRoom(client);//����
		//��һ�η��ͽ�ɫ��Ϣ
		if (!client.sendBinaryMsg((char*)&character_main, sizeof(character_main))) {
			cout << "����ʧ��";
			initgraph(800, 600);  // ��ʼ������
			init_font();
			return;
		}
		//���ܵ�ͼ��Ϣ
		while (1) {//�ȴ����ܵ�ͼ��Ϣ
			if (client.recvMsg(m)) {
				memcpy(&map_choice, m.msgs[0]->msgContent, sizeof(map_choice));
				break;
			}
		}
		//���ܽ�ɫ��Ϣ
		while (1) {//�ȴ����ܽ�ɫ��Ϣ
			if (client.recvMsg(m)) {
				memcpy(&character_sub, m.msgs[0]->msgContent, sizeof(character_sub));
				break;
			}
		}

		//��ʼ��
		kun.set(20, 19, character_sub, 1);
		cai.set(27, 5, character_main, 1);
	}
	initgraph(800, 600);  // ��ʼ������
	init_font();
	
	int i, j;
	int score1 = 0, score2 = 0;
	object ob_inmap;
	char map[30][30];

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


	setbkcolor(wall_list[map_choice].bkcolor);
	clearrectangle(0, 0, 600, 600);

	IMAGE cavas_img;
	loadimage(&cavas_img, L"resource\\static\\canvas.png");
	putimage(600, 0, &cavas_img);

	//��ʼ����
	kun.load(map);
	cai.load(map);

	//��ʼ����ͼ
	render(map);
	outputflame_m(kun.id, cai.id);
	outputinfo_m(score1, score2, kun, cai, 0);
	if (!end_music)
		PlaySoundA("resource\\music\\back_end.wav", NULL, SND_FILENAME | SND_ASYNC);

	//ʱ��
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type1 = -1, in_type2 = -1;
	int time_to_render = 0;

	BeginBatchDraw();//ֹͣ������滭
	while (kun.life || cai.life) {

		if (getkeyboard(in_key)) {

			if (is_host){
				if (kun.action == kun.state)//��һ������
					in_type1 = key_id(in_key, 1, kun.state);
				else
					in_type1 = key_id(in_key, 1, kun.action);
			}
			else {
				if (cai.action == cai.state)//��һ������
					in_type2 = key_id(in_key, 1, cai.state);
				else
					in_type2 = key_id(in_key, 1, cai.action);
			}

			if (in_type1 == 5 || in_type2 == 5) {
				//�˳�
				break;
			}
			else {
				if (is_host && in_type1 != -1) {
					if (kun.action == kun.state)//��һ������
						kun.action = in_type1;
					else
						kun.next_action = in_type1;
				}
				if (!is_host && in_type2 != -1) {
					if (cai.action == cai.state)//��һ������
						cai.action = in_type2;
					else
						cai.next_action = in_type2;
				}
			}
		}

		end = clock();
		if (end - tmp >= 100) {
			tmp = end;

			//���״̬�˳�
			if (!client.checkRoomStatus()) {
				break;
			}
			if (is_host){
				if (!client.getRoomInfo(roomId, r))
					break;
				if (r.existing != 2)
					break;
			}

			//��ȡ/������Ϣ
			if (is_host) {
				while (1) {//�ȴ�����ȷ����Ϣ
					if (client.recvMsg(m))
						break;
				}
				//�����˶���Ϣ
				client.sendBinaryMsg((char*)&kun.action, sizeof(kun.action));
				while (1) {//�ȴ����ܽ�ɫ�˶���Ϣ
					if (client.recvMsg(m)) {
						memcpy(&cai.action, m.msgs[0]->msgContent, sizeof(cai.action));
						break;
					}
				}
			}
			else {
				//����ȷ����Ϣ
				client.sendMsg("OK");
				
				while (1) {//�ȴ����ܽ�ɫ�˶���Ϣ
					if (client.recvMsg(m)) {
						memcpy(&kun.action, m.msgs[0]->msgContent, sizeof(kun.action));
						break;
					}
				}

				//�����˶���Ϣ
				client.sendBinaryMsg((char*)&cai.action, sizeof(cai.action));
			}

			if (time_to_render) {
				time_to_render = 0;

				if (kun.life && cai.life) {//�������

					if (!kun.step(map, score1, ob_inmap))
						if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10) {//��������
							++kun.life;//��������
							score1 += 100;
						}
						else
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (!cai.step(map, score2, ob_inmap))
						if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {//��������
							++cai.life;//��������
							score2 += 100;
						}
						else
							cai.die_load(BLOCK_ROCK, ob_inmap);
					check_multiple(kun, cai, ob_inmap, score1, score2);//��Ⲣ����
				}
				else {//�������
					if (kun.life)
						if (!kun.step(map, score1, ob_inmap))
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (cai.life)
						if (!cai.step(map, score2, ob_inmap))
							cai.die_load(BLOCK_ROCK, ob_inmap);
				}

				for (i = 0; i < 30; i++)
					for (j = 0; j < 30; j++)
						map[i][j] = ob_inmap.nature[i][j];
				if (kun.life)
					kun.load(map);
				if (cai.life)
					cai.load(map);

				if(is_host){
					while (1) {//�ȴ�����ȷ����Ϣ
						if (client.recvMsg(m))
							break;
					}
					//ͬ������
					ob_inmap.check_generate(map);
					client.sendBinaryMsg((char*)&ob_inmap, sizeof(ob_inmap));
				}
				else {
					//����ȷ����Ϣ
					client.sendMsg("OK");
					while (1) {//�ȴ�����������Ϣ
						if (client.recvMsg(m)) {
							memcpy(&ob_inmap, m.msgs[0]->msgContent, sizeof(ob_inmap));
							break;
						}
					}
				}

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo_m(score1, score2, kun, cai, end - start);
				FlushBatchDraw();//��ʼ���
				//next����
				if (is_host && kun.next_action != -1) {
					kun.action = kun.next_action;
					kun.next_action = -1;
				}
				if (!is_host && cai.next_action != -1) {
					cai.action = cai.next_action;
					cai.next_action = -1;
				}
			}
			else {
				time_to_render = 1;
				if ((kun.life && kun.fast_time) || (cai.life && cai.fast_time)) {

					if (kun.life && cai.life) {//�������

						if (kun.fast_time) {
							--kun.fast_time;
							if (!kun.step(map, score1, ob_inmap)) {
								if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10) {
									++kun.life;//��������
									score1 += 100;
								}
								else
									kun.die_load(BLOCK_ROCK, ob_inmap);
							}
						}
						if (cai.fast_time) {
							--cai.fast_time;
							if (!cai.step(map, score2, ob_inmap)) {
								if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {
									++cai.life;//��������
									score2 += 100;
								}
								else
									cai.die_load(BLOCK_ROCK, ob_inmap);
							}
						}
						check_multiple(kun, cai, ob_inmap, score1, score2);//��Ⲣ����
					}
					else {//�������
						if (kun.life && kun.fast_time) {
							if (!kun.step(map, score1, ob_inmap))
								kun.die_load(BLOCK_ROCK, ob_inmap);
							--kun.fast_time;
						}
						if (cai.life && cai.fast_time) {
							if (!cai.step(map, score1, ob_inmap))
								cai.die_load(BLOCK_ROCK, ob_inmap);
							--cai.fast_time;
						}
					}

					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];

					if (kun.life)
						kun.load(map);
					if (cai.life)
						cai.load(map);

					if (is_host) {
						//ͬ������
						ob_inmap.check_generate(map);
						client.sendBinaryMsg((char*)&ob_inmap, sizeof(ob_inmap));
						while (1) {//�ȴ�����ȷ����Ϣ
							if (client.recvMsg(m)) 
								break;
						}
					}
					else {
						while (1) {//�ȴ�����������Ϣ
							if (client.recvMsg(m)) {
								memcpy(&ob_inmap, m.msgs[0]->msgContent, sizeof(ob_inmap));
								break;
							}
						}
						//����ȷ����Ϣ
						client.sendMsg("OK");
					}

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo_m(score1, score2, kun, cai, end - start);
					FlushBatchDraw();//��ʼ���
					//next����
					if (is_host && kun.life && kun.fast_time && kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
					if (!is_host && cai.life && cai.fast_time && cai.next_action != -1) {
						cai.action = cai.next_action;
						cai.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();

	//��ʷ��¼
	upload_history(6, user_id, (is_host ? score1 : score2));

	//�˳�����
	if (!client.disconnectFromRoom()) {
		printf("�˳�����ʧ��\n");
		exit(-114514);
	}

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"΢���ź�");
	settextcolor(0x0E0EF3);
	drawtext(L"��Ϸ�������س��˳�", &carry, DT_CENTER);
	getchar();

}


void run_multiple(int user_id) {
	IMAGE img_main, img_end;
	loadimage(&img_end, _T("resource\\static\\end_back.jpg"));
	loadimage(&img_main, _T("resource\\static\\back_main.png"));
	IMAGE img;
	loadimage(&img, _T("resource\\static\\back.jpg"));

	if (end_music)
		putimage(-20, 0, &img_end);
	else
		putimage(-80, 0, &img_main);
	mune_list[MUNE_MULTIPLE].display();
	int choice = mune_list[MUNE_MULTIPLE].choice(TYPE_GENERAL);

	int character1, character2;

	switch (choice) {
	case 0://----------------˫����Ϸ

		putimage(-80, 0, &img);
		mune_list[MUNE_MAP].display();//չʾ�˵�
		choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//ѡ��˵�
		if (choice != -1) {
			putimage(-80, 0, &img);
			mune_list[MUNE_CHARACTER].display();
			character1 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//ѡ������
			if (character1 != -1){
				putimage(-80, 0, &img);
				mune_list[MUNE_CHARACTER].display();
				character2 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//ѡ������
				run_double_player(choice, character1 + 1, character2 + 1, user_id);
			}
		}

		break;
	case 1://----------------�˻���ս

		putimage(-80, 0, &img);
		mune_list[MUNE_MAP].display();//չʾ�˵�
		choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//ѡ��˵�
		if (choice != -1) {
			putimage(-80, 0, &img);
			mune_list[MUNE_CHARACTER].display();
			character1 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//ѡ������
			if (character1 != -1) {
				character2 = (character1 + 1) % 4;
				run_man_ai(choice, character1 + 1, character2 + 1, user_id);
			}
		}

		break;
	case 2://----------------�����ս/����

		putimage(-80, 0, &img);
		mune_list[MUNE_MAP].display();//չʾ�˵�
		choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//ѡ��˵�
		if (choice != -1) {
			putimage(-80, 0, &img);
			mune_list[MUNE_CHARACTER].display();
			character1 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//ѡ������
			if (character1 != -1) {
				run_web_game(choice, character1 + 1, user_id, 1);
			}
		}

		break;
	case 3://----------------�����ս/����

		putimage(-80, 0, &img);
		mune_list[MUNE_CHARACTER].display();
		character2 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//ѡ������
		if (character2 != -1) {
			run_web_game(choice, character2 + 1, user_id, 0);
		}

		break;
	}
}