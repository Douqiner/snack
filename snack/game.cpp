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
	//主菜单
	mune_list[MUNE_MAIN].row = 5;
	mune_list[MUNE_MAIN].col = 1;
	mune_list[MUNE_MAIN].select_lable = LABLE_MAIN;
	mune_list[MUNE_MAIN].text[0][0] = L"新的开始";
	mune_list[MUNE_MAIN].text[1][0] = L"继续游戏";
	mune_list[MUNE_MAIN].text[2][0] = L"历史记录";
	mune_list[MUNE_MAIN].text[3][0] = L"退出游戏";
	mune_list[MUNE_MAIN].text[4][0] = L"更换音乐";
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

	//新的开始
	mune_list[MUNE_NEWGAME].row = 5;
	mune_list[MUNE_NEWGAME].col = 1;
	mune_list[MUNE_NEWGAME].select_lable = LABLE_MAIN;
	mune_list[MUNE_NEWGAME].text[0][0] = L"入门模式";
	mune_list[MUNE_NEWGAME].text[1][0] = L"进阶模式";
	mune_list[MUNE_NEWGAME].text[2][0] = L"高级模式";
	mune_list[MUNE_NEWGAME].text[3][0] = L"坤坤之旅";
	mune_list[MUNE_NEWGAME].text[4][0] = L"多人运动";
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

	//选择地图
	mune_list[MUNE_MAP].row = 1;
	mune_list[MUNE_MAP].col = 4;
	mune_list[MUNE_MAP].select_lable = LABLE_SUB;
	mune_list[MUNE_MAP].text[0][0] = L"经典空地";
	mune_list[MUNE_MAP].text[0][1] = L"冲破鸡窝";
	mune_list[MUNE_MAP].text[0][2] = L"中分之路";
	mune_list[MUNE_MAP].text[0][3] = L"斜阳之舞";
	carry.set(130 + 150 * 0, 500);
	mune_list[MUNE_MAP].pos[0][0] = carry;
	carry.set(130 + 150 * 1, 500);
	mune_list[MUNE_MAP].pos[0][1] = carry;
	carry.set(130 + 150 * 2, 500);
	mune_list[MUNE_MAP].pos[0][2] = carry;
	carry.set(130 + 150 * 3, 500);
	mune_list[MUNE_MAP].pos[0][3] = carry;
	
	//选择人物
	mune_list[MUNE_CHARACTER].row = 1;
	mune_list[MUNE_CHARACTER].col = 4;
	mune_list[MUNE_CHARACTER].select_lable = LABLE_SUB;
	mune_list[MUNE_CHARACTER].text[0][0] = L"靠谱鸡哥";
	mune_list[MUNE_CHARACTER].text[0][1] = L"种菜农民";
	mune_list[MUNE_CHARACTER].text[0][2] = L"茶会头子";
	mune_list[MUNE_CHARACTER].text[0][3] = L"查无此人";
	carry.set(130 + 150 * 0, 500);
	mune_list[MUNE_CHARACTER].pos[0][0] = carry;
	carry.set(130 + 150 * 1, 500);
	mune_list[MUNE_CHARACTER].pos[0][1] = carry;
	carry.set(130 + 150 * 2, 500);
	mune_list[MUNE_CHARACTER].pos[0][2] = carry;
	carry.set(130 + 150 * 3, 500);
	mune_list[MUNE_CHARACTER].pos[0][3] = carry;

	//暂停界面
	mune_list[MUNE_PAUSE].row = 1;
	mune_list[MUNE_PAUSE].col = 3;
	mune_list[MUNE_PAUSE].select_lable = LABLE_SUB;
	mune_list[MUNE_PAUSE].text[0][0] = L"继续游戏";
	mune_list[MUNE_PAUSE].text[0][1] = L"直接退出";
	mune_list[MUNE_PAUSE].text[0][2] = L"存档退出";
	carry.set(150 + 150 * 0, 300);
	mune_list[MUNE_PAUSE].pos[0][0] = carry;
	carry.set(150 + 150 * 1, 300);
	mune_list[MUNE_PAUSE].pos[0][1] = carry;
	carry.set(150 + 150 * 2, 300);
	mune_list[MUNE_PAUSE].pos[0][2] = carry;

	//多人运动
	mune_list[MUNE_MULTIPLE].row = 4;
	mune_list[MUNE_MULTIPLE].col = 1;
	mune_list[MUNE_MULTIPLE].select_lable = LABLE_MAIN;
	mune_list[MUNE_MULTIPLE].text[0][0] = L"双人游戏";
	mune_list[MUNE_MULTIPLE].text[1][0] = L"人机对战";
	mune_list[MUNE_MULTIPLE].text[2][0] = L"网络/房主";
	mune_list[MUNE_MULTIPLE].text[3][0] = L"网络/加入";
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
	//获取信息
	RECT carry;
	int width = lable_list[select_lable].width;//获取样式宽度
	int height = lable_list[select_lable].height;//获取样式高度
	COLORREF write_color = lable_list[select_lable].write_color;//获取样式前景色
	COLORREF back_color = lable_list[select_lable].back_color;//获取样式背景色

	//设置信息
	setbkcolor(back_color);
	setfillcolor(back_color);
	setlinecolor(write_color);
	settextcolor(write_color);
	settextstyle(20, 0, L"微软雅黑"); // 设置文字大小、字体

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//画矩形
			carry = { pos[i][j].x,pos[i][j].y + height / 2 - 10, pos[i][j].x + width,pos[i][j].y + height };
			fillrectangle(pos[i][j].x, pos[i][j].y, pos[i][j].x + width, pos[i][j].y + height);

			//画选择矩形
			clearrectangle(pos[i][j].x - 30, pos[i][j].y + height / 2 - 10, pos[i][j].x - 10, pos[i][j].y + height / 2 + 10);

			//写文字
			drawtext(text[i][j].c_str(), &carry, DT_CENTER);
		}
	}


}

int mune::choice(int type, int user_id) {
	point now_choice(0, 0);
	point last_choice(0, 0);
	IMAGE ball_img;
	loadimage(&ball_img, _T("resource\\static\\ball.jpg"));

	int width = lable_list[select_lable].width;//获取样式宽度
	int height = lable_list[select_lable].height;//获取样式高度
	COLORREF back_color = lable_list[select_lable].back_color;//获取样式背景色
	setbkcolor(back_color);

	int wait;
	int in_key;
	while (1) {
		wait = 1;
		in_key = 0;
		//覆盖更新
		clearrectangle(pos[last_choice.y][last_choice.x].x - 30, pos[last_choice.y][last_choice.x].y + height / 2 - 10,
			pos[last_choice.y][last_choice.x].x - 10, pos[last_choice.y][last_choice.x].y + height / 2 + 10);
		putimage(pos[now_choice.y][now_choice.x].x - 30, pos[now_choice.y][now_choice.x].y + height / 2 - 10, &ball_img);
		last_choice = now_choice;
		if (type == TYPE_MAP)//地图
			show_mapinfo(now_choice.x, user_id);
		if (type == TYPE_CHARACTER)
			show_characterinfo(now_choice.x);
		Sleep(100);
		//检测键盘
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
				case VK_RETURN://回车
					flick(now_choice);
					return (now_choice.y * col + now_choice.x);
				}
			}
		}
	}

	return -1;
}

void mune::flick(point choice) {
	//获取信息
	RECT carry;
	int width = lable_list[select_lable].width;//获取样式宽度
	int height = lable_list[select_lable].height;//获取样式高度
	COLORREF write_color = lable_list[select_lable].write_color;//获取样式前景色
	COLORREF back_color = lable_list[select_lable].back_color;//获取样式背景色

	carry = { pos[choice.y][choice.x].x,pos[choice.y][choice.x].y + height / 2 - 10, pos[choice.y][choice.x].x + width,pos[choice.y][choice.x].y + height };

	for (int i = 5; i >= 0; i--) {
		setbkcolor(write_color);
		setfillcolor(write_color);
		setlinecolor(back_color);
		settextcolor(back_color);
		//画矩形
		fillrectangle(pos[choice.y][choice.x].x, pos[choice.y][choice.x].y, pos[choice.y][choice.x].x + width, pos[choice.y][choice.x].y + height);
		//写文字
		drawtext(text[choice.y][choice.x].c_str(), &carry, DT_CENTER);
		Sleep(70);

		setbkcolor(back_color);
		setfillcolor(back_color);
		setlinecolor(write_color);
		settextcolor(write_color);
		//画矩形
		fillrectangle(pos[choice.y][choice.x].x, pos[choice.y][choice.x].y, pos[choice.y][choice.x].x + width, pos[choice.y][choice.x].y + height);
		//写文字
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

	//是否载入
	if (!is_load) {
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
		kun.set(20, 19, character, 1);
	}
	else {//载入存档
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

	//初始化蛇
	kun.load(map);

	//初始化地图
	render(map);
	outputflame(kun.id);
	outputinfo(score, kun, old_time, height_score);
	_getche();

	//时间
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type;
	int time_to_render = 0;

	BeginBatchDraw();//停止输出，绘画
	while (kun.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//第一次输入
				in_type = key_id(in_key, 1, kun.state);
			else
				in_type = key_id(in_key, 1, kun.action);

			if (in_type != -1) {
				if (in_type != 5)
					if (kun.action == kun.state)//第一次输入
						kun.action = in_type;
					else
						kun.next_action = in_type;
				else{
					//存档页面
					mune_list[MUNE_PAUSE].col = 3;
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
					else if (choice == 1) {//结算
						break;
					}
					else {//存档
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
				FlushBatchDraw();//开始输出
				//next置入
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
					FlushBatchDraw();//开始输出
					//next置入
					if (kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();
	//排行
	if (score >= height_score) {
		game_rank.highscore[0] = score;
		game_rank.user_id[0] = user_id;
		upload_rank();
	}
	//历史记录
	upload_history(0, user_id, score);

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"微软雅黑");
	settextcolor(0x0E0EF3);
	drawtext(L"游戏结束，回车退出", &carry, DT_CENTER);
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

	//是否载入
	if (!is_load) {
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
		kun.set(20, 19, character, 99999);
	}
	else {//载入存档
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

	//初始化蛇
	kun.load(map);

	//初始化地图
	render(map);
	outputflame(kun.id);
	outputinfo(score, kun, old_time, height_score);
	_getche();

	//时间
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type;
	int time_to_render = 0;

	BeginBatchDraw();//停止输出，绘画
	while (kun.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//第一次输入
				in_type = key_id(in_key, 1, kun.state);
			else
				in_type = key_id(in_key, 1, kun.action);

			if (in_type != -1) {
				if (in_type != 5)
					if (kun.action == kun.state)//第一次输入
						kun.action = in_type;
					else
						kun.next_action = in_type;
				else {
					//存档页面
					mune_list[MUNE_PAUSE].col = 3;
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
					else if (choice == 1) {//结算
						break;
					}
					else {//存档
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
					//重生处理
					kun.die_load(BLOCK_FENCE, ob_inmap);
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					if (kun.relife(map)) {
						kun.load(map);
						if (!ob_inmap.check_generate(map))//没有位置生成肽酶
							break;
						clearrectangle(0, 0, 600, 600);
						render(map);
						outputinfo(score, kun, end - start + old_time, height_score);
						FlushBatchDraw();//开始输出
						_getche();
						continue;
					}
					else//找不到位置
						break;
				}
				//一般处理
				for (i = 0; i < 30; i++)
					for (j = 0; j < 30; j++)
						map[i][j] = ob_inmap.nature[i][j];
				kun.load(map);
				if (!ob_inmap.check_generate(map))//没有位置生成肽酶
					break;

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo(score, kun, end - start + old_time, height_score);
				FlushBatchDraw();//开始输出
				//next置入
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
						//重生处理
						kun.die_load(BLOCK_FENCE, ob_inmap);
						for (i = 0; i < 30; i++)
							for (j = 0; j < 30; j++)
								map[i][j] = ob_inmap.nature[i][j];
						if (kun.relife(map)) {
							kun.load(map);
							if (!ob_inmap.check_generate(map))//没有位置生成肽酶
								break;
							clearrectangle(0, 0, 600, 600);
							render(map);
							outputinfo(score, kun, end - start + old_time, height_score);
							FlushBatchDraw();//开始输出
							_getche();
							continue;
						}
						else//找不到位置
							break;
					}
					//一般处理
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					kun.load(map);
					ob_inmap.check_generate(map);

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo(score, kun, end - start + old_time, height_score);
					FlushBatchDraw();//开始输出
					//next置入
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
	//历史记录
	upload_history(1, user_id, score);

	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"微软雅黑");
	settextcolor(0x0E0EF3);
	drawtext(L"游戏结束，回车退出", &carry, DT_CENTER);
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

	//是否载入
	if (!is_load) {
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
		kun.set(20, 19, character, 6);
	}
	else {//载入存档
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

	//初始化蛇
	kun.load(map);

	//初始化地图
	render(map);
	outputflame(kun.id);
	outputinfo(score, kun, old_time, height_score);
	_getche();

	//时间
	clock_t start, end, tmp;
	start = clock();
	tmp = clock();
	end = clock();

	int in_key, in_type;
	int time_to_render = 0;

	BeginBatchDraw();//停止输出，绘画
	while (kun.life) {
		if (getkeyboard(in_key)) {

			if (kun.action == kun.state)//第一次输入
				in_type = key_id(in_key, 1, kun.state);
			else
				in_type = key_id(in_key, 1, kun.action);

			if (in_type != -1) {
				if (in_type != 5)
					if (kun.action == kun.state)//第一次输入
						kun.action = in_type;
					else
						kun.next_action = in_type;
				else {
					//存档页面
					mune_list[MUNE_PAUSE].col = 3;
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
					else if (choice == 1) {//结算
						break;
					}
					else {//存档
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
					//重生处理
					kun.die_load(OBJECT_APPLE, ob_inmap);
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					if (kun.relife(map)) {
						kun.load(map);
						if (!ob_inmap.check_generate(map))//没有位置生成肽酶
							break;
						clearrectangle(0, 0, 600, 600);
						render(map);
						outputinfo(score, kun, end - start + old_time, height_score);
						FlushBatchDraw();//开始输出
						_getche();
						continue;
					}
					else//找不到位置
						break;
				}
				//一般处理
				for (i = 0; i < 30; i++)
					for (j = 0; j < 30; j++)
						map[i][j] = ob_inmap.nature[i][j];
				kun.load(map);
				if (!ob_inmap.check_generate(map))//没有位置生成肽酶
					break;

				clearrectangle(0, 0, 600, 600);
				render(map);
				outputinfo(score, kun, end - start + old_time, height_score);
				FlushBatchDraw();//开始输出
				//next置入
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
						//重生处理
						kun.die_load(OBJECT_APPLE, ob_inmap);
						for (i = 0; i < 30; i++)
							for (j = 0; j < 30; j++)
								map[i][j] = ob_inmap.nature[i][j];
						if (kun.relife(map)) {
							kun.load(map);
							if (!ob_inmap.check_generate(map))//没有位置生成肽酶
								break;
							clearrectangle(0, 0, 600, 600);
							render(map);
							outputinfo(score, kun, end - start + old_time, height_score);
							FlushBatchDraw();//开始输出
							_getche();
							continue;
						}
						else//找不到位置
							break;
					}
					//一般处理
					for (i = 0; i < 30; i++)
						for (j = 0; j < 30; j++)
							map[i][j] = ob_inmap.nature[i][j];
					kun.load(map);
					ob_inmap.check_generate(map);

					clearrectangle(0, 0, 600, 600);
					render(map);
					outputinfo(score, kun, end - start + old_time, height_score);
					FlushBatchDraw();//开始输出
					//next置入
					if (kun.next_action != -1) {
						kun.action = kun.next_action;
						kun.next_action = -1;
					}
				}
			}
		}
	}
	EndBatchDraw();
	//排行
	if (score >= height_score) {
		game_rank.highscore[2] = score;
		game_rank.user_id[2] = user_id;
		upload_rank();
	}
	//历史记录
	upload_history(2, user_id, score);
	
	RECT carry = { 200, 285, 400, 315 };
	settextstyle(25, 0, L"微软雅黑");
	settextcolor(0x0E0EF3);
	drawtext(L"游戏结束，回车退出", &carry, DT_CENTER);
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
	BeginBatchDraw();//停止输出，绘画

	for (; map_choice <= 3; map_choice++) { //三地图循环
		object ob_inmap;
		char map[30][30];
		snack kun;
		//是否载入
		if (!is_load) {
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
			kun.set(20, 19, 1, 1);
		}
		else {//载入存档
			user_list[user_id].save_load(user_id, save_id, map_choice, ob_inmap, kun, old_time, score);
			for (i = 0; i < 30; i++)
				for (j = 0; j < 30; j++)
					map[i][j] = ob_inmap.nature[i][j];
			--is_load;
		}
		
		setbkcolor(wall_list[map_choice].bkcolor);
		clearrectangle(0, 0, 600, 600);
		putimage(600, 0, &cavas_img);

		//初始化蛇
		kun.load(map);

		//初始化地图
		render(map);
		outputflame(kun.id, map_choice);
		outputinfo(score, kun, old_time, -1);
		FlushBatchDraw();//开始输出
		_getche();

		//时间
		clock_t start, end, tmp;
		start = clock();
		tmp = clock();
		end = clock();

		int in_key, in_type;
		int time_to_render = 0;

		while (kun.life) {
			if (getkeyboard(in_key)) {

				if (kun.action == kun.state)//第一次输入
					in_type = key_id(in_key, 1, kun.state);
				else
					in_type = key_id(in_key, 1, kun.action);

				if (in_type != -1) {
					if (in_type != 5)
						if (kun.action == kun.state)//第一次输入
							kun.action = in_type;
						else
							kun.next_action = in_type;
					else {
						//存档页面
						mune_list[MUNE_PAUSE].col = 3;
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
						else if (choice == 1) {//结算
							return;
						}
						else {//存档
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
					FlushBatchDraw();//开始输出
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
						FlushBatchDraw();//开始输出
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
			settextstyle(25, 0, L"微软雅黑");
			settextcolor(0x0E0EF3);
			drawtext(L"失败，回车重启旅行", &carry, DT_CENTER);
			FlushBatchDraw();//开始输出
			getchar();
			--map_choice;//这一关失败
		}
		else {
			//展示、解锁关卡信息
			show_trip_map(map_choice, user_id);
			FlushBatchDraw();//开始输出
			getchar();
		}

		old_time += end - start;
	}

	EndBatchDraw();

	//排行
	if (game_rank.highscore[3] == 0 || old_time <= game_rank.highscore[3]) {
		game_rank.highscore[3] = old_time;
		game_rank.user_id[3] = user_id;
		upload_rank();
	}
	//历史记录
	upload_history(3, user_id, old_time);

	if (map_choice == 4) {
		end_music = 1;
		mune_list[MUNE_MAIN].row = 5;
		//播放结束mv
		play_end_video();
	}
}