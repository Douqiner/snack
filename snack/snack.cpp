#include <iostream>
#include <queue>
#include <vector>
#include "all.h"

void init_wall() {
	int i, j;
	//�յ�ͼ
	wall_list[0].bkcolor = 0xF1BB56;
	wall_list[0].name = L"����յ�";
	wall_list[0].disp1 = L"�����ص������δ����ʱ��";
	wall_list[0].disp2 = L"�����ķ�Ի���������Ի��";
	//���Ƽ���
	wall_list[1].bkcolor = 0x20BC15;
	wall_list[1].name = L"���Ƽ���";
	wall_list[1].disp1 = L"������������ļ��ѣ���ʱû�м���˼��δ��";
	wall_list[1].disp2 = L"դ������ݣ�ÿ��Ͷ�ŵ�ʳ�ϡ����ˣ�����ȱʧ�������ɽ�������俴�����赸�������Լ�����������ͷ���ճ�";

	wall_list[1].block[2][12] = OBJECT_MUD;
	wall_list[1].block[2][13] = OBJECT_MUD;
	wall_list[1].block[1][13] = OBJECT_MUD;
	wall_list[1].block[1][14] = OBJECT_MUD;

	wall_list[1].block[2][17] = OBJECT_MUD;
	wall_list[1].block[2][16] = OBJECT_MUD;
	wall_list[1].block[1][16] = OBJECT_MUD;
	wall_list[1].block[2][18] = OBJECT_MUD;
	for(i = 0; i < 7; i++){
		wall_list[1].block[3][12 + i] = BLOCK_FENCE;
		wall_list[1].block[9][12 + i] = BLOCK_FENCE;
		
	}
	for (i = 0; i < 7; i++) {
		wall_list[1].block[3 + i][12] = BLOCK_FENCE;
		wall_list[1].block[3 + i][18] = BLOCK_FENCE;
	}
	for (i = 0; i < 13; i++) {
		wall_list[1].block[10][10 + i] = BLOCK_FENCE;
		wall_list[1].block[10 + i][10] = BLOCK_FENCE;
		wall_list[1].block[10 + i][22] = BLOCK_FENCE;
		wall_list[1].block[10 + i][14] = BLOCK_ROCK;
	}
	for (i = 0; i < 21; i++) {
		wall_list[1].block[23][6 + i] = BLOCK_FENCE;
	}
	for (i = 0; i < 5; i++) {
		wall_list[1].block[24 + i][5] = BLOCK_FENCE;
		wall_list[1].block[24 + i][27] = BLOCK_FENCE;
	}
	for (i = 0; i < 9; i++) {
		wall_list[1].block[14][14 + i] = BLOCK_ROCK;
	}
	
	//�з�֮·
	wall_list[2].bkcolor = 0x88D614;
	wall_list[2].name = L"�з�֮·";
	wall_list[2].disp1 = L"�������ɭ��С·����ʱ����û�й���Զ";
	wall_list[2].disp2 = L"����������������С��һͬ���ӵģ����������������Զ��פ��դ���Բ����ж���׷��Ī�����Լ����ž���ɭ���зֳ�����·��������ѡ�������˼�������һ��";

	for (i = 0; i < 30; i++) {
		wall_list[2].block[i][0] = BLOCK_FENCE;
		wall_list[2].block[i][29] = BLOCK_FENCE;
		wall_list[2].block[0][i] = BLOCK_FENCE;
		wall_list[2].block[29][i] = BLOCK_FENCE;
	}
	for (i = 0; i < 7; i++) {
		wall_list[2].block[5 + i][17 + i] = BLOCK_ROCK;
		wall_list[2].block[6 + i][17 + i] = BLOCK_ROCK;
		wall_list[2].block[7 + i][17 + i] = BLOCK_ROCK;
		wall_list[2].block[8 + i][17 + i] = BLOCK_ROCK;
		wall_list[2].block[5 + i][11 - i] = BLOCK_ROCK;
		wall_list[2].block[6 + i][11 - i] = BLOCK_ROCK;
		wall_list[2].block[7 + i][11 - i] = BLOCK_ROCK;
		wall_list[2].block[8 + i][11 - i] = BLOCK_ROCK;

		wall_list[2].block[15 + i][17 + i] = BLOCK_ROCK;
		wall_list[2].block[16 + i][17 + i] = BLOCK_ROCK;
		wall_list[2].block[17 + i][17 + i] = BLOCK_ROCK;
		wall_list[2].block[18 + i][17 + i] = BLOCK_ROCK;
		wall_list[2].block[15 + i][11 - i] = BLOCK_ROCK;
		wall_list[2].block[16 + i][11 - i] = BLOCK_ROCK;
		wall_list[2].block[17 + i][11 - i] = BLOCK_ROCK;
		wall_list[2].block[18 + i][11 - i] = BLOCK_ROCK;
	}
	wall_list[2].block[18][20] = 0;
	wall_list[2].block[19][20] = 0;
	wall_list[2].block[20][20] = 0;
	wall_list[2].block[21][20] = 0;
	for (i = 0; i < 7; i++) {
		wall_list[2].block[6][11 + i] = OBJECT_MUD;
		wall_list[2].block[7][11 + i] = OBJECT_MUD;
		wall_list[2].block[16][11 + i] = OBJECT_MUD;
		wall_list[2].block[17][11 + i] = OBJECT_MUD;
	}
	wall_list[2].block[11][11] = OBJECT_APPLE;
	wall_list[2].block[11][17] = OBJECT_APPLE;
	wall_list[2].block[29][11] = OBJECT_FAST;
	wall_list[2].block[29][17] = OBJECT_FAST;
	//б��֮��
	wall_list[3].bkcolor = 0x1E8DF4;
	wall_list[3].name = L"б��֮��";
	wall_list[3].disp1 = L"����������б����գ���ʱ�һ���һ��лĻ";
	wall_list[3].disp2 = L"��֮��������������Զ����̶���룬����������б�����������ջ����������룬��ֻ����һ���ش���һ��лĻ����ʱ��������Ψһ�ģ�Ҳ������ֻ��";
	
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			wall_list[3].block[i][j] = OBJECT_MUD;
		}
	}
	wall_list[3].block[7][7] = OBJECT_BALL;
	for (i = 0; i < 15; i++) {
		wall_list[3].block[0][i] = BLOCK_FENCE;
		wall_list[3].block[14][i] = BLOCK_FENCE;
		wall_list[3].block[i][0] = BLOCK_FENCE;
		wall_list[3].block[i][14] = BLOCK_FENCE;

	}
	for (i = 0; i < 7; i++) {
		wall_list[3].block[15][i] = BLOCK_FENCE;
		wall_list[3].block[21][i] = BLOCK_FENCE;
		wall_list[3].block[15 + i][0] = BLOCK_FENCE;
		wall_list[3].block[15 + i][6] = BLOCK_FENCE;
	}
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			wall_list[3].block[16 + i][1 + j] = OBJECT_APPLE;
		}
	}
}

snack::snack(){
}

void snack::set(int x, int y, int _id, int _life){
	clear();
	id = _id;
	life = _life;
	action = ACTION_UP;
	state = ACTION_UP;//�ϴ��ƶ�����
	next_action = -1;//��ʾû��
	fast_time = 0;
	len = 3;
	//ͷ�ڵ�
	tail = new(nothrow) body;
	if (!tail)
		exit(-114514);
	//��ͷ������
	body* p = tail, * q;
	for (int i = 0; i < 3; i++) {
		q = new(nothrow) body;
		if (!q)
			exit(-1);
		p->next = q;
		p = p->next;
		p->b_pos.x = x % 30;
		p->b_pos.y = (y + 2 - i) % 30;
		p->state = ACTION_UP;
	}
	p->next = NULL;
	head = p;
}

int snack::step(char lastmap[30][30], int& score, object& ob_inmap){
	//�������ͷ
	body* p;
	p = new(nothrow) body;
	if (!p)
		exit(-1);
	point pos_carry(head->b_pos);
	pos_carry += op_list[action];
	p->b_pos = pos_carry;
	p->state = action;
	//β��
	p->next = NULL;
	head->next = p;
	head = p;

	state = action;

	switch (lastmap[head->b_pos.y][head->b_pos.x]){
	case OBJECT_APPLE://��øƻ��
		len += 1;
		ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
		ob_inmap.apple_num -= 1;
		score += 50;
		sound(0);
		return 1;
	case OBJECT_FAST://��
		fast_time = 30;
		delete_tail(1);
		ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
		score += 20;
		sound(0);
		return 1;
	case OBJECT_MUD://��
		ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
		ob_inmap.mud_num -= 1;
		score -= 30;
		sound(1);
		if(len >= 3){
			delete_tail(3);
			len -= 2;
			return 1;
		}
		else{
			life -= 1;
			return 0;
		}
	case OBJECT_BALL://����
		score += 1000;
		ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
		delete_tail(1);
		sound(0);
		return 1;
	case BLOCK_FENCE://դ��
		score -= len / 2 * 10;
		sound(1);
		if(len >= 2){
			delete_tail(1 + len / 2);
			len -= len / 2;
			ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
			return 1;
		}
		else {
			life -= 1;
			ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
			return 0;
		}
	case BLOCK_ROCK://��ʯ
		score -= 30;
		delete_tail(1);
		life -= 1;
		sound(1);
		return 0;
	case 0://ɶҲû����
		delete_tail(1);
		return 1;
	default://����
		state = 0;
		if (head->b_pos == tail->next->b_pos){
			delete_tail(1);
			return 1;
		}
		else{
			score -= 100;
			delete_tail(1);
			life -= 1;
			return 0;
		}
	}

	return 0;
}

void snack::load(char lastmap[30][30]) {
	body* p = tail->next;

	while (p) {
		if(p == head){
			lastmap[p->b_pos.y][p->b_pos.x] = char(id * 10 + 0);
			break;
		}
		else {
			lastmap[p->b_pos.y][p->b_pos.x] = char(id * 10 + 1);
			p = p->next;
		}
	}

}

void snack::delete_tail(int n){
	body* q, * p;
	p = tail->next;

	for (int i = 0; i < n; i++) {
		q = p;
		p = p->next;
		delete q;
	}
	tail->next = p;
}

void snack::die_load(int op, object& ob_inmap){
	//ɾ���������ͼ
	body* p, * q = tail->next;
	delete tail;
	int num = 0;
	while (q) {
		p = q;
		q = q->next;

		if (ob_inmap.nature[p->b_pos.y][p->b_pos.x] == 0 && p != head){
			ob_inmap.nature[p->b_pos.y][p->b_pos.x] = op;
			num++;
		}

		delete p;
	}
	if (op == OBJECT_APPLE)
		ob_inmap.apple_num += num;
	tail = NULL;
	head = NULL;
}

int snack::relife(char map[30][30]) {
	//Ѱ������λ��
	int x, y, i, j;
	//���������10��
	for (i = 0; i < 10; i++) {
		x = rand() % 30;
		y = rand() % 30;
		if (map[(y - 1 + 30) % 30][x] == 0 && map[y][x] == 0 && map[(y + 1) % 30][x] == 0 && map[(y + 2) % 30][x] == 0) {
			
			reset(x, y);
			return 1;
		}
	}
	//��������
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			if (map[(i - 1 + 30) % 30][j] == 0 && map[i][j] == 0 && map[(i + 1) % 30][j] == 0 && map[(i + 2) % 30][j] == 0) {
				
				reset(j, i);
				return 1;
			}
		}
	}

	return 0;
}

void snack::reset(int x, int y){

	action = ACTION_UP;
	state = ACTION_UP;//�ϴ��ƶ�����
	fast_time = 0;
	len = 3;
	//ͷ�ڵ�
	tail = new(nothrow) body;
	if (!tail)
		exit(-1);
	//��ͷ������
	body* p = tail, * q;
	for (int i = 0; i < 3; i++) {
		q = new(nothrow) body;
		if (!q)
			exit(-1);
		p->next = q;
		p = p->next;
		p->b_pos.x = x % 30;
		p->b_pos.y = (y + 2 - i) % 30;
		p->state = ACTION_UP;
	}
	p->next = NULL;
	head = p;
}

void snack::clear(){
	body* p, * q = tail;
	while (q) {
		p = q;
		q = q->next;
		delete p;
	}
	tail = NULL;
	head = NULL;
}

void snack::sound(int sound_type){
	if (!end_music){
		if (id == 1) {
			if (sound_type == 0){
				if (rand() % 3 == 2)
					PlaySoundA("resource\\music\\ctrl.wav", NULL, SND_FILENAME | SND_ASYNC);
			}
			else if (sound_type == 1)
				PlaySoundA("resource\\music\\kun_dead.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		else if (id == 2) {
			if (sound_type == 0)
				if (rand() % 3 == 1)
					PlaySoundA("resource\\music\\cai_gain.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
	}
}

snack::~snack(){
	body* p, * q = tail;
	while (q) {
		p = q;
		q = q->next;
		delete p;
	}

}

int object::check_generate(char map[30][30], int apple_en, int mud_en) {

	int x, y, i, j;
	//������ø
	if (apple_num == 0 && apple_en) {
		int dst_num = rand() % 4 + 1;
		//���������50��
		for (i = 0; i < 50; i++) {
			x = rand() % 30;
			y = rand() % 30;
			if (map[y][x] == 0) {
				nature[y][x] = OBJECT_APPLE;
				map[y][x] = OBJECT_APPLE;
				apple_num++;
				if (apple_num == dst_num)
					break;
			}
		}
		//�����������������1��
		if (apple_num == 0) {
			for (i = 0; i < 30; i++) {
				for (j = 0; j < 30; j++) {
					if (map[i][j] == 0) {
						nature[i][j] = OBJECT_APPLE;
						map[y][x] = OBJECT_APPLE;
						apple_num++;
						break;
					}
				}
				if (apple_num)
					break;
			}
		}
		//���Ϊ0
		if (apple_num == 0)
			return 0;

	}

	//���������
	if (fast_wait == 0 && mud_en) {
		//�������5��
		for (i = 0; i < 5; i++) {
			x = rand() % 30;
			y = rand() % 30;
			if (map[y][x] == 0) {
				nature[y][x] = OBJECT_MUD;
				map[y][x] = OBJECT_MUD;
				mud_num++;
			}
		}
	}

	//���ɼ�������
	if (fast_wait == 0) {
		//�������10��
		for (i = 0; i < 10; i++) {
			x = rand() % 30;
			y = rand() % 30;
			if (map[y][x] == 0) {
				nature[y][x] = OBJECT_FAST;
				map[y][x] = OBJECT_FAST;
				break;
			}
		}
		fast_wait = 100;
	}
	else
		fast_wait -= 1;

	return 1;
}


struct node {
	point pos;
	int from;
	int now_len;
};

void snack_ai::direct(char map[30][30]) {
	point dir[4] = { {0,MAP_L - 1},{0,MAP_L + 1},{MAP_L - 1,0},{MAP_L + 1,0} };
	int vis[30][30] = { 0 }, i;
	node carry, burden;
	queue<node> q;
	vector<node> path;
	int path_num = 0;
	int last_from = 0;
	int is_find = 0;
	int find_time = 0;

	carry.from = -1;
	carry.pos = head->b_pos;
	carry.now_len = len;

	q.push(carry);
	vis[head->b_pos.y][head->b_pos.x] = 1;

	while (!q.empty() && !is_find) {
		burden = q.front();
		q.pop();
		path.push_back(burden);
		++path_num;

		for (i = 0; i < 4; i++) {
			carry = burden;
			carry.from = path_num - 1;
			carry.pos += dir[i];

			if (!vis[carry.pos.y][carry.pos.x]) {
				vis[carry.pos.y][carry.pos.x] = 1;
				switch (map[carry.pos.y][carry.pos.x]) {
				case 0:
					q.push(carry);
					break;
				case OBJECT_APPLE:
				case OBJECT_FAST:
				case OBJECT_BALL:
					is_find = 1;
					last_from = carry.from;
					if(!last_from){
						action = i;
						return;
					}
					
					break;
				case OBJECT_MUD:
					carry.now_len -= 10;
					if(carry.now_len >= 1)
						q.push(carry);
					break;
				case BLOCK_FENCE:
					carry.now_len -= carry.now_len / 2 + 10;
					if (carry.now_len >= 1)
						q.push(carry);
					break;
				}
			}
			
		}
		++find_time;
		if (find_time > 400)
			break;
	}

	if (!is_find){//δ�ҵ�
		if (path_num == 1)
			return;
		last_from = rand() % path_num;
	}

	while (path[last_from].from > 0)
		last_from = path[last_from].from;
	for (i = 0; i < 4; i++) {
		carry.pos = head->b_pos;
		carry.pos += dir[i];
		if (carry.pos == path[last_from].pos) {
			action = i;
			return;
		}
	}

}
