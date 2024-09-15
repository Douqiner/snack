#include <iostream>
#include <queue>
#include <vector>
#include "all.h"

void init_wall() {
	int i, j;
	//空地图
	wall_list[0].bkcolor = 0xF1BB56;
	wall_list[0].name = L"经典空地";
	wall_list[0].disp1 = L"坤坤回到了寰宇未开的时代";
	wall_list[0].disp2 = L"上下四方曰宇，古往今来曰宙";
	//冲破鸡窝
	wall_list[1].bkcolor = 0x20BC15;
	wall_list[1].name = L"冲破鸡窝";
	wall_list[1].disp1 = L"坤坤曾经生活的鸡窝，那时没有鸡会思考未来";
	wall_list[1].disp2 = L"栅栏，青草，每日投放的食料。舞姿，篮球，缺失篮球的铁山靠。与其看别人舞蹈，不如自己冲破望不到头的日常";

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
	
	//中分之路
	wall_list[2].bkcolor = 0x88D614;
	wall_list[2].name = L"中分之路";
	wall_list[2].disp1 = L"鸡窝外的森林小路，那时篮球还没有滚很远";
	wall_list[2].disp2 = L"激励坤坤带领其他小鸡一同出逃的，是曾经望着篮球滚远，驻留栅栏旁不敢行动而追悔莫及的自己。寂静的森林中分出两条路，而坤坤选择了最人迹罕至的一条";

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
	//斜阳之舞
	wall_list[3].bkcolor = 0x1E8DF4;
	wall_list[3].name = L"斜阳之舞";
	wall_list[3].disp1 = L"篮球伫立的斜阳天空，那时我还有一舞谢幕";
	wall_list[3].disp2 = L"世之美景，多在于险远，泥潭中央，坤坤屹立于斜阳，篮球与诱惑，生活与理想，他只想以一跳回答，以一舞谢幕，这时他是世上唯一的，也是最后的只因";
	
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
	state = ACTION_UP;//上次移动方向
	next_action = -1;//表示没有
	fast_time = 0;
	len = 3;
	//头节点
	tail = new(nothrow) body;
	if (!tail)
		exit(-114514);
	//蛇头和蛇身
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
	//添加新蛇头
	body* p;
	p = new(nothrow) body;
	if (!p)
		exit(-1);
	point pos_carry(head->b_pos);
	pos_carry += op_list[action];
	p->b_pos = pos_carry;
	p->state = action;
	//尾插
	p->next = NULL;
	head->next = p;
	head = p;

	state = action;

	switch (lastmap[head->b_pos.y][head->b_pos.x]){
	case OBJECT_APPLE://肽酶苹果
		len += 1;
		ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
		ob_inmap.apple_num -= 1;
		score += 50;
		sound(0);
		return 1;
	case OBJECT_FAST://激
		fast_time = 30;
		delete_tail(1);
		ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
		score += 20;
		sound(0);
		return 1;
	case OBJECT_MUD://泥
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
	case OBJECT_BALL://篮球
		score += 1000;
		ob_inmap.nature[head->b_pos.y][head->b_pos.x] = 0;
		delete_tail(1);
		sound(0);
		return 1;
	case BLOCK_FENCE://栅栏
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
	case BLOCK_ROCK://岩石
		score -= 30;
		delete_tail(1);
		life -= 1;
		sound(1);
		return 0;
	case 0://啥也没碰到
		delete_tail(1);
		return 1;
	default://蛇身
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
	//删除并载入地图
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
	//寻找重生位置
	int x, y, i, j;
	//先随机尝试10次
	for (i = 0; i < 10; i++) {
		x = rand() % 30;
		y = rand() % 30;
		if (map[(y - 1 + 30) % 30][x] == 0 && map[y][x] == 0 && map[(y + 1) % 30][x] == 0 && map[(y + 2) % 30][x] == 0) {
			
			reset(x, y);
			return 1;
		}
	}
	//遍历查找
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
	state = ACTION_UP;//上次移动方向
	fast_time = 0;
	len = 3;
	//头节点
	tail = new(nothrow) body;
	if (!tail)
		exit(-1);
	//蛇头和蛇身
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
	//生成肽酶
	if (apple_num == 0 && apple_en) {
		int dst_num = rand() % 4 + 1;
		//先随机尝试50次
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
		//如果不够，遍历生成1个
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
		//如果为0
		if (apple_num == 0)
			return 0;

	}

	//生成泥干吗啊
	if (fast_wait == 0 && mud_en) {
		//随机尝试5次
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

	//生成激励黑子
	if (fast_wait == 0) {
		//随机尝试10次
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

	if (!is_find){//未找到
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
