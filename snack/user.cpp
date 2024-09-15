#include <graphics.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "all.h"
#include <conio.h>


void download_user_list() {
	ifstream infile("resource\\user\\user_list.txt", ios::binary);
	if (!infile){
		cout << "游戏文件缺失";
		exit(-114514);
	}
	infile.read((char*)user_list, sizeof(user) * 5);
	infile.close();
}

void upload_user_list() {
	ofstream outfile("resource\\user\\user_list.txt", ios::binary);
	if (!outfile){
		cout << "游戏文件缺失";
		exit(-114514);
	}
	outfile.write((char*)user_list, sizeof(user) * 5);
	outfile.close();
}

void user::append() {
	int i;
	wstring input;

	closegraph();
	cout << "请输入英文名" << endl;
	wcin >> input;
	initgraph(800, 600);  // 初始化窗口
	init_font();

	if(input.length() >= 20){
		for (i = 0; i < 19; i++)
			name[i] = input[i];
		name[i] = char(0);
	}
	else{
		for (i = 0; i < input.length(); i++)
			name[i] = input[i];
		name[i] = char(0);
	}

	level = 0;
}

void user::reset(int user_id) {
	name[0] = char(0);
	level = -1;
	for (int i = 0; i < 10; i++)
		save_list[i].mode = -1;
	//检查排行榜
	for (int i = 0; i < 5; i++) {
		if (game_rank.user_id[i] == user_id)
			game_rank.highscore[i] = 0;
	}
}


void init_user_mune() {
	point carry(0, 0);
	//选择用户
	mune_list[MUNE_USER].row = 5;
	mune_list[MUNE_USER].col = 2;
	mune_list[MUNE_USER].select_lable = LABLE_SUB;
	for (int i = 0; i < 5; i++) {
		if(user_list[i].level == -1) {
			mune_list[MUNE_USER].text[i][0] = L"新建";
			mune_list[MUNE_USER].text[i][1] = L"删除";
			carry.set(450, 250 + 70 * i);
			mune_list[MUNE_USER].pos[i][0] = carry;
			carry.set(600, 250 + 70 * i);
			mune_list[MUNE_USER].pos[i][1] = carry;
		}
		else {
			mune_list[MUNE_USER].text[i][0] = L"载入";
			mune_list[MUNE_USER].text[i][1] = L"删除";
			carry.set(450, 250 + 70 * i);
			mune_list[MUNE_USER].pos[i][0] = carry;
			carry.set(600, 250 + 70 * i);
			mune_list[MUNE_USER].pos[i][1] = carry;
		}
	}

}

void show_userinfo() {

	RECT carry;
	settextcolor(0x0000000);
	setbkcolor(0xD49F00);
	settextstyle(30, 0, L"微软雅黑"); // 设置文字大小、字体

	for (int i = 0; i < 5; i++) {
		carry = { 100,250 + 70 * i, 400,250 + 70 * i + 40 };
		clearrectangle(100, 250 + 70 * i, 400, 250 + 70 * i + 40);
		if (user_list[i].level != -1) 
			drawtext(user_list[i].name, &carry, DT_CENTER);
	}
}

int choice_to_user(int choice) {
	if (choice % 2 == 1){
		user_list[choice / 2].reset(choice / 2);
		upload_user_list();
		return 5;
	}
	else {
		if (user_list[choice / 2].level == -1){
			user_list[choice / 2].append();
			upload_user_list();
			return 5;
		}
		return choice / 2;
	}
}


void download_rank() {
	ifstream infile("resource\\user\\rank.txt", ios::binary);
	if (!infile) {
		cout << "游戏文件缺失";
		exit(-114514);
	}
	infile.read((char*)(&game_rank), sizeof(game_rank));
	infile.close();
}

void upload_rank() {
	ofstream outfile("resource\\user\\rank.txt", ios::binary);
	if (!outfile) {
		cout << "游戏文件缺失";
		exit(-114514);
	}
	outfile.write((char*)(&game_rank), sizeof(game_rank));
	outfile.close();
}

void show_history() {
	int available[5] = { 1,1,1,1,0 };
	string mode[5] = {
		"版本：入门模式-最高分：",
		"版本：进阶模式-最高分：",
		"版本：高级模式-最高分：",
		"版本：坤坤之旅-最短时间：",
		"版本：多人运动-最高分：",
	};

	closegraph();

	//转char
	char username[20];
	size_t converted = 0;
	//最高分
	cout << "----------------最高得分----------------" << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	for (int i = 0; i < 5; i++) {
		if (available[i]) {
			wcstombs_s(&converted, username, 20, user_list[game_rank.user_id[i]].name, _TRUNCATE);
			if(i != 3){
				if (game_rank.highscore[i])
					cout << mode[i] << game_rank.highscore[i] << "分-记录保持者" << username << endl;
				else
					cout << mode[i] << "无记录" << endl;
			}
			else{
				if (game_rank.highscore[i])
					cout << mode[i] << (game_rank.highscore[i] * 1.0) / 1000 << "秒-记录保持者" << username << endl;
				else
					cout << mode[i] << "无记录" << endl;
			}
		}
	}
	cout << endl;
	cout << "----------------历史记录----------------" << endl;
	//历史记录
	string record;
	ifstream infile("resource\\user\\history.txt");
	if (!infile) {
		cout << "游戏文件缺失";
		exit(-114514);
	}
	while (infile >> record)
		cout << record << endl;

	while(1){
		cout << endl << "输入 q 确认" << endl;
		char c;
		c = _getche();
		if (c == 'q')
			break;
	}

	initgraph(800, 600);  // 初始化窗口
	init_font();
}

void upload_history(int gametype, int user_id, int score) {
	string mode[7] = {
		"版本：入门模式-用户名：",
		"版本：进阶模式-用户名：",
		"版本：高级模式-用户名：",
		"版本：坤坤之旅-用户名：",
		"版本：双人游戏-用户名：",
		"版本：人机对战-用户名：",
		"版本：网络对战-用户名："
	};

	time_t timep;
	struct tm p;

	time(&timep); //获取从1970至今过了多少秒，存入time_t类型的timep
	localtime_s(&p, &timep);

	//转char
	char username[20];
	size_t converted = 0;
	wcstombs_s(&converted, username, 20, user_list[user_id].name, _TRUNCATE);

	stringstream out;
	if (gametype == 3)
		out << mode[gametype] << username << "-耗时：" << score / 1000.0 << "秒";
	else
		out << mode[gametype] << username << "-得分：" << score;
	out  << "-时间：" <<1900 + p.tm_year << "年" << 1 + p.tm_mon << "月" << p.tm_mday << "日" <<
		p.tm_hour << "：" << p.tm_min << "：" << p.tm_sec;
	string record;
	out >> record;

	ofstream outfile("resource\\user\\history.txt", ios::app);
	if (!outfile) {
		cout << "游戏文件缺失";
		exit(-114514);
	}
	outfile << record << endl;
	outfile.close();
}

void user::save_append(int user_id, int save_id, int map_id, int mode, const object& ob_inmap, const snack& kun, const int time, const int score) {
	save_list[save_id].map_id = map_id;
	save_list[save_id].mode = mode;

	//写入文件
	string path = "resource\\save\\0\\0.txt";
	path[14] = char('0' + user_id);
	path[16] = char('0' + save_id);
	ofstream outfile(path, ios::binary);

	if (!outfile) {
		cout << "游戏文件缺失";
		exit(-114514);
	}
	outfile.write((char*)(&time), sizeof(time));
	outfile.write((char*)(&score), sizeof(score));
	outfile.write((char*)(&ob_inmap), sizeof(ob_inmap));
	outfile.write((char*)(&kun), sizeof(kun));
	//写链表，接下来是从尾部到头部的坐标数据
	body* p = kun.tail->next;
	while (p) {
		outfile.write((char*)&(p->b_pos), sizeof(p->b_pos));
		outfile.write((char*)&(p->state), sizeof(p->state));
		p = p->next;
	}
	outfile.close();
}

void user::save_load(int user_id, int save_id, int& map_id, object& ob_inmap, snack& kun, int& time, int& score){
	map_id = save_list[save_id].map_id;

	//读取文件
	string path = "resource\\save\\0\\0.txt";
	path[14] = char('0' + user_id);
	path[16] = char('0' + save_id);
	ifstream infile(path, ios::binary);

	infile.read((char*)(&time), sizeof(time));
	infile.read((char*)(&score), sizeof(score));
	infile.read((char*)(&ob_inmap), sizeof(ob_inmap));
	infile.read((char*)(&kun), sizeof(kun));

	//尾插法建表
	kun.tail = new(nothrow) body;
	if (!kun.tail)
		exit(-114514);
	body* p = kun.tail, * q;
	for (int i = 0; i < kun.len; i++) {
		//新建
		q = new(nothrow) body;
		if (!q)
			exit(-114514);

		//读取
		infile.read((char*)&(q->b_pos), sizeof(q->b_pos));
		infile.read((char*)&(q->state), sizeof(q->state));
		q->state = ACTION_UP;

		p->next = q;
		p = p->next;
		
	}
	p->next = NULL;
	kun.head = p;

	infile.close();
}

void user::init_mune_addsave() {
	point carry(0, 0);
	RECT _carry;

	wstring mode[4] = { L"入门模式" ,L"进阶模式" ,L"高级模式" ,L"坤坤之旅" };
	wstring map[4] = { L"经典空地" ,L"冲破鸡窝" ,L"中分之路" ,L"斜阳之舞" };
	wstringstream out;
	wstring text;

	setbkcolor(0xc47f00);
	setfillcolor(0xc47f00);
	settextcolor(0x000000);
	settextstyle(30, 0, L"微软雅黑"); // 设置文字大小、字体

	mune_list[MUNE_ADDSAVE].row = 5;
	mune_list[MUNE_ADDSAVE].col = 2;
	mune_list[MUNE_ADDSAVE].select_lable = LABLE_NOUSE;

	IMAGE back_img;
	loadimage(&back_img, _T("resource\\static\\back.jpg"));
	putimage(-80, 0, &back_img);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			_carry = { 50 + j * 400,50 + 100 * i, 370 + j * 400,90 + 100 * i };
			clearrectangle(50 + j * 400, 50 + 100 * i, 370 + j * 400, 90 + 100 * i);
			if (save_list[i * 2 + j].mode == -1) {
				mune_list[MUNE_ADDSAVE].text[i][j] = L"保存";
				drawtext(L"空存档", &_carry, DT_LEFT);
			}
			else {
				out.str(L"");
				mune_list[MUNE_ADDSAVE].text[i][j] = L"覆盖";
				out << mode[save_list[i * 2 + j].mode] << L"  " << map[save_list[i * 2 + j].map_id];
				text = out.str();
				drawtext(text.c_str(), &_carry, DT_LEFT);
			}
			carry.set(200 + j * 400, 100 + 100 * i);
			mune_list[MUNE_ADDSAVE].pos[i][j] = carry;
		}
	}
	
}

void user::init_mune_loadsave() {
	point carry(0, 0);
	RECT _carry;

	wstring mode[4] = { L"入门模式" ,L"进阶模式" ,L"高级模式" ,L"坤坤之旅" };
	wstring map[4] = { L"经典空地" ,L"冲破鸡窝" ,L"中分之路" ,L"斜阳之舞" };
	wstringstream out;
	wstring text;

	setbkcolor(0xc47f00);
	setfillcolor(0xc47f00);
	settextcolor(0x000000);
	settextstyle(30, 0, L"微软雅黑"); // 设置文字大小、字体

	mune_list[MUNE_LOADSAVE].row = 5;
	mune_list[MUNE_LOADSAVE].col = 4;
	mune_list[MUNE_LOADSAVE].select_lable = LABLE_NOUSE;

	IMAGE back_img;
	loadimage(&back_img, _T("resource\\static\\back.jpg"));
	putimage(-80, 0, &back_img);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			_carry = { 40 + j * 400,50 + 100 * i, 360 + j * 400,90 + 100 * i };
			clearrectangle(40 + j * 400, 50 + 100 * i, 360 + j * 400, 90 + 100 * i);
			if (save_list[i * 2 + j].mode == -1) {
				mune_list[MUNE_LOADSAVE].text[i][j * 2] = L"退出";
				mune_list[MUNE_LOADSAVE].text[i][j * 2 + 1] = L"删除";
				drawtext(L"空存档", &_carry, DT_LEFT);
			}
			else {
				out.str(L"");
				mune_list[MUNE_LOADSAVE].text[i][j * 2] = L"载入";
				mune_list[MUNE_LOADSAVE].text[i][j * 2 + 1] = L"删除";
				out << mode[save_list[i * 2 + j].mode] << L"  " << map[save_list[i * 2 + j].map_id];
				text = out.str();
				drawtext(text.c_str(), &_carry, DT_LEFT);
			}
			carry.set(200 + j * 400, 100 + 100 * i);
			mune_list[MUNE_LOADSAVE].pos[i][j * 2] = carry;
			carry.set(200 + j * 400 + 100, 100 + 100 * i);
			mune_list[MUNE_LOADSAVE].pos[i][j * 2 + 1] = carry;
		}
	}
}
