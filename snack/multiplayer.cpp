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

	//初始化地图
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

	//初始化蛇
	kun.load(map);
	cai.load(map);

	//初始化地图
	render(map);
	outputflame_m(kun.id, cai.id);
	outputinfo_m(score1, score2, kun, cai, 0);
	_getche();

	//时间
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type1, in_type2;
	int time_to_render = 0;

	BeginBatchDraw();//停止输出，绘画
	while (kun.life || cai.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//第一次输入
				in_type1 = key_id(in_key, 1, kun.state);
			else
				in_type1 = key_id(in_key, 1, kun.action);

			if (cai.action == cai.state)//第一次输入
				in_type2 = key_id(in_key, 2, cai.state);
			else
				in_type2 = key_id(in_key, 2, cai.action);

			if (in_type1 == 5) {
				//退出页面
				mune_list[MUNE_PAUSE].col = 2;
				EndBatchDraw();
				mune_list[MUNE_PAUSE].display();
				int choice = mune_list[MUNE_PAUSE].choice(TYPE_GENERAL);

				if (choice == 0 || choice == -1) {
					BeginBatchDraw();//停止输出，绘画
					setbkcolor(wall_list[map_choice].bkcolor);
					clearrectangle(0, 0, 600, 600);
					render(map);
					FlushBatchDraw();//开始输出

					_getche();
				}
				else {//结算
					break;
				}
			}
			else {
				if (in_type1 != -1) {
					if (kun.action == kun.state)//第一次输入
						kun.action = in_type1;
					else
						kun.next_action = in_type1;
				}
				if (in_type2 != -1) {
					if (cai.action == cai.state)//第一次输入
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

				if (kun.life && cai.life) {//多人情况
					if (!kun.step(map, score1, ob_inmap))
						if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10){//是其他蛇
							++kun.life;//搁置争议
							score1 += 100;
						}
						else 
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (!cai.step(map, score2, ob_inmap))
						if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {//是其他蛇
							++cai.life;//搁置争议
							score2 += 100;
						}
						else
							cai.die_load(BLOCK_ROCK, ob_inmap);
					check_multiple(kun, cai, ob_inmap, score1, score2);//检测并操作
				}
				else {//单人情况
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
				FlushBatchDraw();//开始输出
				//next置入
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

					if (kun.life && cai.life) {//多人情况

						if (kun.fast_time) {
							--kun.fast_time;
							if (!kun.step(map, score1, ob_inmap)) {
								if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10) {
									++kun.life;//搁置争议
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
									++cai.life;//搁置争议
									score2 += 100;
								}
								else
									cai.die_load(BLOCK_ROCK, ob_inmap);
							}
						}
						check_multiple(kun, cai, ob_inmap, score1, score2);//检测并操作
					}
					else {//单人情况
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
					FlushBatchDraw();//开始输出
					//next置入
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

	//历史记录
	upload_history(4, user_id, max(score1, score2));

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"微软雅黑");
	settextcolor(0x0E0EF3);
	drawtext(L"游戏结束，回车退出", &carry, DT_CENTER);
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

	//初始化地图
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

	//初始化蛇
	kun.load(map);
	cai.load(map);

	//初始化地图
	render(map);
	outputflame_m(kun.id, cai.id);
	outputinfo_m(score1, score2, kun, cai, 0);
	_getche();

	//时间
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type;
	int time_to_render = 0;

	BeginBatchDraw();//停止输出，绘画
	while (kun.life || cai.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//第一次输入
				in_type = key_id(in_key, 1, kun.state);
			else
				in_type = key_id(in_key, 1, kun.action);

			if (in_type == 5) {
				//退出页面
				mune_list[MUNE_PAUSE].col = 2;
				EndBatchDraw();
				mune_list[MUNE_PAUSE].display();
				int choice = mune_list[MUNE_PAUSE].choice(TYPE_GENERAL);

				if (choice == 0 || choice == -1) {
					BeginBatchDraw();//停止输出，绘画
					setbkcolor(wall_list[map_choice].bkcolor);
					clearrectangle(0, 0, 600, 600);
					render(map);
					FlushBatchDraw();//开始输出

					_getche();
				}
				else {//结算
					break;
				}
			}
			else {
				if (in_type != -1) {
					if (kun.action == kun.state)//第一次输入
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

				if (kun.life && cai.life) {//多人情况
					cai.direct(map);//走路
					if (!kun.step(map, score1, ob_inmap))
						if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10) {//是其他蛇
							++kun.life;//搁置争议
							score1 += 100;
						}
						else
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (!cai.step(map, score2, ob_inmap))
						if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {//是其他蛇
							++cai.life;//搁置争议
							score2 += 100;
						}
						else
							cai.die_load(BLOCK_ROCK, ob_inmap);
					check_multiple(kun, cai, ob_inmap, score1, score2);//检测并操作
				}
				else {//单人情况
					if (kun.life)
						if (!kun.step(map, score1, ob_inmap))
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (cai.life){
						cai.direct(map);//走路
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
				FlushBatchDraw();//开始输出
				//next置入
				if (kun.next_action != -1) {
					kun.action = kun.next_action;
					kun.next_action = -1;
				}
			}
			else {
				time_to_render = 1;
				if ((kun.life && kun.fast_time) || (cai.life && cai.fast_time)) {

					if (kun.life && cai.life) {//多人情况
						
						if (kun.fast_time){
							--kun.fast_time;
							if (!kun.step(map, score1, ob_inmap)) {
								if(map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10){
									++kun.life;//搁置争议
									score1 += 100;
								}
								else
									kun.die_load(BLOCK_ROCK, ob_inmap);
							}
						}
						if (cai.fast_time){
							cai.direct(map);//走路
							--cai.fast_time;
							if (!cai.step(map, score2, ob_inmap)) {
								if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {
									++cai.life;//搁置争议
									score2 += 100;
								}
								else
									cai.die_load(BLOCK_ROCK, ob_inmap);
							}
							
						}
						check_multiple(kun, cai, ob_inmap, score1, score2);//检测并操作
					}
					else {//单人情况
						if (kun.life && kun.fast_time) {
							if (!kun.step(map, score1, ob_inmap))
								kun.die_load(BLOCK_ROCK, ob_inmap);
							--kun.fast_time;
						}
						if (cai.life && cai.fast_time) {
							cai.direct(map);//走路
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
					FlushBatchDraw();//开始输出
					//next置入
					if (kun.life && kun.fast_time && kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();

	//历史记录
	upload_history(5, user_id, score1);

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"微软雅黑");
	settextcolor(0x0E0EF3);
	drawtext(L"游戏结束，回车退出", &carry, DT_CENTER);
	getchar();
}

int showRoom(ClientHelper& _client) {
	/*******************************
	展示房间列表
	getRoomList(room_list_t)返回值为bool，传参为room_list_t的引用。
	如果成功获取到房间信息，函数返回true，并且将房间列表存入结构体room_list_t。
	room_list_t结构如下
	struct room_list_t {
		uint32_t roomNum;   // 当前存在的房间数量
		room_t *rooms;    // 每个房间的信息
	};
	room_t结构如下
	struct room_t {
		uint32_t roomId;     // 房间id
		uint32_t existing;	 // 已有人数
		char roomName[40];	 // 房间名
		msg_t* everyOne;     // 对于本函数，没有存入该成员
	};
	本方法(showRoom)提供了读取房间信息的思路参考
	********************************/
	room_list_t rlt;
	if (!_client.getRoomList(rlt)) {
		printf("获取列表失败\n");
		return 0;
	}
	printf("房间数量:\t%u\n----列表如下----\n", rlt.roomNum);
	for (uint32_t i = 0; i < rlt.roomNum; ++i) {
		printf("房间%u:\n", i + 1);
		printf("房间名:%s\t房间id:%u\t当前人数:%u\n", rlt.rooms[i].roomName, rlt.rooms[i].roomId, rlt.rooms[i].existing);
	}
	return 1;
}

int connectRoom(ClientHelper& _client) {
	/*******************************
	连接至某个房间
	通过房间的id进行连接，房间id为唯一标识符。
	connectToRoom(uint32_t)为连接至指定房间的方法，如果连接房间成功，函数返回true。
	connectToRoom(room_t&)为重载方法，你可以传入一个room_t结构体来连接房间。
	即你可以通过获取房间列表rtl，然后connectToRoom(rtl.rooms[i])来快速连接房间。
	********************************/
	showRoom(_client);

	uint32_t a;
	while(1){
		printf("请输入要加入的房间id\n");
		cin >> a;
		if (!_client.connectToRoom(a)) {
			printf("连接失败\n");
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
	snack kun, cai;//主客

	if(is_host){
		if (!client.connectToServer("127.0.0.1", 10001, "qin_snack_host")) {
			cout << "连接服务器失败";
			initgraph(800, 600);  // 初始化窗口
			init_font();
			return;
		}
		if (!client.hostNewRoom("qin_game_room", roomId)) {
			cout << "建立房间失败";
			initgraph(800, 600);  // 初始化窗口
			init_font();
			return;
		}

		cout << "等待其它玩家连接至id为" << roomId << ",名称为qin_game_room的房间" << endl;
		while (1) {//等待接受角色信息
			if (client.recvMsg(m)) {
				memcpy(&character_sub, m.msgs[0]->msgContent, sizeof(character_sub));
				break;
			}
		}
		//发送地图信息
		if (!client.sendBinaryMsg((char*)&map_choice, sizeof(map_choice))) {
			cout << "连接失败";
			initgraph(800, 600);  // 初始化窗口
			init_font();
			return;
		}
		//发送角色信息
		if (!client.sendBinaryMsg((char*)&character_main, sizeof(character_main))) {
			cout << "连接失败";
			initgraph(800, 600);  // 初始化窗口
			init_font();
			return;
		}

		//初始化
		kun.set(20, 19, character_main, 1);
		cai.set(27, 5, character_sub, 1);

	}
	else {
		if (!client.connectToServer("127.0.0.1", 10001, "qin_snack_guest")) {
			cout << "连接服务器失败";
			initgraph(800, 600);  // 初始化窗口
			init_font();
			return;
		}
		connectRoom(client);//连接
		//第一次发送角色信息
		if (!client.sendBinaryMsg((char*)&character_main, sizeof(character_main))) {
			cout << "连接失败";
			initgraph(800, 600);  // 初始化窗口
			init_font();
			return;
		}
		//接受地图信息
		while (1) {//等待接受地图信息
			if (client.recvMsg(m)) {
				memcpy(&map_choice, m.msgs[0]->msgContent, sizeof(map_choice));
				break;
			}
		}
		//接受角色信息
		while (1) {//等待接受角色信息
			if (client.recvMsg(m)) {
				memcpy(&character_sub, m.msgs[0]->msgContent, sizeof(character_sub));
				break;
			}
		}

		//初始化
		kun.set(20, 19, character_sub, 1);
		cai.set(27, 5, character_main, 1);
	}
	initgraph(800, 600);  // 初始化窗口
	init_font();
	
	int i, j;
	int score1 = 0, score2 = 0;
	object ob_inmap;
	char map[30][30];

	//初始化地图
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

	//初始化蛇
	kun.load(map);
	cai.load(map);

	//初始化地图
	render(map);
	outputflame_m(kun.id, cai.id);
	outputinfo_m(score1, score2, kun, cai, 0);
	if (!end_music)
		PlaySoundA("resource\\music\\back_end.wav", NULL, SND_FILENAME | SND_ASYNC);

	//时间
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type1 = -1, in_type2 = -1;
	int time_to_render = 0;

	BeginBatchDraw();//停止输出，绘画
	while (kun.life || cai.life) {

		if (getkeyboard(in_key)) {

			if (is_host){
				if (kun.action == kun.state)//第一次输入
					in_type1 = key_id(in_key, 1, kun.state);
				else
					in_type1 = key_id(in_key, 1, kun.action);
			}
			else {
				if (cai.action == cai.state)//第一次输入
					in_type2 = key_id(in_key, 1, cai.state);
				else
					in_type2 = key_id(in_key, 1, cai.action);
			}

			if (in_type1 == 5 || in_type2 == 5) {
				//退出
				break;
			}
			else {
				if (is_host && in_type1 != -1) {
					if (kun.action == kun.state)//第一次输入
						kun.action = in_type1;
					else
						kun.next_action = in_type1;
				}
				if (!is_host && in_type2 != -1) {
					if (cai.action == cai.state)//第一次输入
						cai.action = in_type2;
					else
						cai.next_action = in_type2;
				}
			}
		}

		end = clock();
		if (end - tmp >= 100) {
			tmp = end;

			//检测状态退出
			if (!client.checkRoomStatus()) {
				break;
			}
			if (is_host){
				if (!client.getRoomInfo(roomId, r))
					break;
				if (r.existing != 2)
					break;
			}

			//获取/发送信息
			if (is_host) {
				while (1) {//等待接受确认信息
					if (client.recvMsg(m))
						break;
				}
				//发送运动信息
				client.sendBinaryMsg((char*)&kun.action, sizeof(kun.action));
				while (1) {//等待接受角色运动信息
					if (client.recvMsg(m)) {
						memcpy(&cai.action, m.msgs[0]->msgContent, sizeof(cai.action));
						break;
					}
				}
			}
			else {
				//发送确认信息
				client.sendMsg("OK");
				
				while (1) {//等待接受角色运动信息
					if (client.recvMsg(m)) {
						memcpy(&kun.action, m.msgs[0]->msgContent, sizeof(kun.action));
						break;
					}
				}

				//发送运动信息
				client.sendBinaryMsg((char*)&cai.action, sizeof(cai.action));
			}

			if (time_to_render) {
				time_to_render = 0;

				if (kun.life && cai.life) {//多人情况

					if (!kun.step(map, score1, ob_inmap))
						if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10) {//是其他蛇
							++kun.life;//搁置争议
							score1 += 100;
						}
						else
							kun.die_load(BLOCK_ROCK, ob_inmap);
					if (!cai.step(map, score2, ob_inmap))
						if (map[cai.head->b_pos.y][cai.head->b_pos.x] >= 10) {//是其他蛇
							++cai.life;//搁置争议
							score2 += 100;
						}
						else
							cai.die_load(BLOCK_ROCK, ob_inmap);
					check_multiple(kun, cai, ob_inmap, score1, score2);//检测并操作
				}
				else {//单人情况
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
					while (1) {//等待接受确认信息
						if (client.recvMsg(m))
							break;
					}
					//同步生成
					ob_inmap.check_generate(map);
					client.sendBinaryMsg((char*)&ob_inmap, sizeof(ob_inmap));
				}
				else {
					//发送确认信息
					client.sendMsg("OK");
					while (1) {//等待接受生成信息
						if (client.recvMsg(m)) {
							memcpy(&ob_inmap, m.msgs[0]->msgContent, sizeof(ob_inmap));
							break;
						}
					}
				}

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo_m(score1, score2, kun, cai, end - start);
				FlushBatchDraw();//开始输出
				//next置入
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

					if (kun.life && cai.life) {//多人情况

						if (kun.fast_time) {
							--kun.fast_time;
							if (!kun.step(map, score1, ob_inmap)) {
								if (map[kun.head->b_pos.y][kun.head->b_pos.x] >= 10) {
									++kun.life;//搁置争议
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
									++cai.life;//搁置争议
									score2 += 100;
								}
								else
									cai.die_load(BLOCK_ROCK, ob_inmap);
							}
						}
						check_multiple(kun, cai, ob_inmap, score1, score2);//检测并操作
					}
					else {//单人情况
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
						//同步生成
						ob_inmap.check_generate(map);
						client.sendBinaryMsg((char*)&ob_inmap, sizeof(ob_inmap));
						while (1) {//等待接受确认信息
							if (client.recvMsg(m)) 
								break;
						}
					}
					else {
						while (1) {//等待接受生成信息
							if (client.recvMsg(m)) {
								memcpy(&ob_inmap, m.msgs[0]->msgContent, sizeof(ob_inmap));
								break;
							}
						}
						//发送确认信息
						client.sendMsg("OK");
					}

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo_m(score1, score2, kun, cai, end - start);
					FlushBatchDraw();//开始输出
					//next置入
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

	//历史记录
	upload_history(6, user_id, (is_host ? score1 : score2));

	//退出房间
	if (!client.disconnectFromRoom()) {
		printf("退出房间失败\n");
		exit(-114514);
	}

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"微软雅黑");
	settextcolor(0x0E0EF3);
	drawtext(L"游戏结束，回车退出", &carry, DT_CENTER);
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
	case 0://----------------双人游戏

		putimage(-80, 0, &img);
		mune_list[MUNE_MAP].display();//展示菜单
		choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//选择菜单
		if (choice != -1) {
			putimage(-80, 0, &img);
			mune_list[MUNE_CHARACTER].display();
			character1 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//选择人物
			if (character1 != -1){
				putimage(-80, 0, &img);
				mune_list[MUNE_CHARACTER].display();
				character2 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//选择人物
				run_double_player(choice, character1 + 1, character2 + 1, user_id);
			}
		}

		break;
	case 1://----------------人机对战

		putimage(-80, 0, &img);
		mune_list[MUNE_MAP].display();//展示菜单
		choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//选择菜单
		if (choice != -1) {
			putimage(-80, 0, &img);
			mune_list[MUNE_CHARACTER].display();
			character1 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//选择人物
			if (character1 != -1) {
				character2 = (character1 + 1) % 4;
				run_man_ai(choice, character1 + 1, character2 + 1, user_id);
			}
		}

		break;
	case 2://----------------网络对战/房主

		putimage(-80, 0, &img);
		mune_list[MUNE_MAP].display();//展示菜单
		choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//选择菜单
		if (choice != -1) {
			putimage(-80, 0, &img);
			mune_list[MUNE_CHARACTER].display();
			character1 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//选择人物
			if (character1 != -1) {
				run_web_game(choice, character1 + 1, user_id, 1);
			}
		}

		break;
	case 3://----------------网络对战/加入

		putimage(-80, 0, &img);
		mune_list[MUNE_CHARACTER].display();
		character2 = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//选择人物
		if (character2 != -1) {
			run_web_game(choice, character2 + 1, user_id, 0);
		}

		break;
	}
}