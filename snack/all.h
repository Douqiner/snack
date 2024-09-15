#pragma once
#include <graphics.h>
#include <string>
#include <playsoundapi.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

#define MAP_L 30

extern int end_music;
/*------------------------------工具函数类------------------------------*/
class object;
class point {
public:
    int x;
    int y;
    point() {};
    point(int xx, int yy) {
        x = xx;
        y = yy;
    }
    void set(int xx, int yy) {
        x = xx;
        y = yy;
    }
    bool operator ==(const point& p) {
        if (x == p.x && y == p.y)
            return 1;
        else
            return 0;
    }
    void operator +=(const point& p) {
        x = (x + p.x) % MAP_L;
        y = (y + p.y) % MAP_L;
    }
};
class snack;
int getkeyboard(int& in_key);//获取键盘输入
void render(char map[30][30]);//渲染一幅画面
int key_id(int in_key, int id, int state);//判断输入
void outputflame(int character, int trip_map = 0);//输出单人游戏信息框架
void outputinfo(int score, const snack& kun, int time, int height_score);//输出信息
void show_mapinfo(int choice, int user_id);//展示地图
void show_characterinfo(int choice);//展示人物
void init_font();//初始化字体
int check_trip_finish(int map_trip, int score, object& ob_inmap);//检测坤坤之旅过关条件
void show_trip_map(int choice, int user_id);//展示地图结算
void outputinfo_m(int score1, int score2, const snack& kun, const snack& cai, int time);//多人游戏输出信息
void outputflame_m(int character1, int character2);//输出多人游戏信息框架
void check_multiple(snack& kun, snack& cai, object& ob_inmap, int& score1, int& score2);//看蛇是否冲突
void play_end_video();//播放结束mv

/*------------------------------游戏中对象函数类------------------------------*/
class wall {
public:
    char block[30][30] = { 0 };
    int bkcolor;
    wstring name;
    wstring disp1;
    wstring disp2;
};
extern wall wall_list[6];//所有初始地图
void init_wall();//初始化地图
#define BLOCK_ROCK 9
#define BLOCK_FENCE 8


struct body {
    point b_pos;
    int state;
    body* next;
};


class snack {
public:
    int id;//1-4
    int action;
    int life;
    int state;
    int next_action;//一级缓存
    int fast_time;
    int len;
    body* head = NULL;
    body* tail = NULL;
    snack();
    void set(int x, int y, int _id, int _life);
    int step(char lastmap[30][30], int& score, object& ob_inmap);//走一步，只检测吃到自然对象
    void load(char lastmap[30][30]);//加载到地图上
    void delete_tail(int n);//删除蛇尾n节点
    void die_load(int op, object& ob_inmap);//蛇死亡载入
    int relife(char map[30][30]);//重生
    void reset(int x, int y);//重设
    void clear();
    void sound(int sound_type);//发声,0为获得，1为减分
    ~snack();
};
#define ACTION_UP 0
#define ACTION_DN 1
#define ACTION_LF 2
#define ACTION_RT 3
extern const point op_list[4];//操作加

class snack_ai :public snack {
public:
    void direct(char map[30][30]);//根据地图决定移动方向
};

class object {
public:
    char nature[30][30] = { 0 };
    int apple_num = 0;
    int fast_wait = 10;//"激"等待时间
    int mud_num = 0;

    int check_generate(char map[30][30], int apple_en = 1, int mud_en = 1);
};
#define OBJECT_APPLE 1
#define OBJECT_FAST 2
#define OBJECT_MUD 3
#define OBJECT_BALL 4

/*------------------------------游戏、菜单函数类------------------------------*/
//----------选项标签类
class select_lable {
public:
    COLORREF write_color;
    COLORREF back_color;
    int height;
    int width;
};
extern select_lable lable_list[3];//所有标签
void init_select_lable();//初始化标签
#define LABLE_MAIN 2
#define LABLE_SUB 1
#define LABLE_NOUSE 0


//----------菜单类
class mune {
public:
    wstring text[5][4];//选项文字
    point pos[5][4];//选项左上角位置
    int row;//选项行数
    int col;//选项列数
    int select_lable;//选项类型

    void display();//初始打印
    int choice(int type, int user_id = 0);//菜单选择
    void flick(point choice);//选中闪动

};
extern mune mune_list[10];//所有菜单
void init_mune_list();//初始化菜单
#define MUNE_MAIN 0
#define MUNE_NEWGAME 1
#define MUNE_MAP 2
#define MUNE_CHARACTER 3
#define MUNE_USER 4
#define MUNE_PAUSE 5
#define MUNE_ADDSAVE 6
#define MUNE_LOADSAVE 7
#define MUNE_MULTIPLE 8

#define TYPE_GENERAL 0
#define TYPE_MAP 1
#define TYPE_CHARACTER 2

//----------游戏函数
void run_threshold(int map_choice, int character, int user_id, int is_load = 0, int save_id = 0);//入门版游戏
void run_advance(int map_choice, int character, int user_id, int is_load = 0, int save_id = 0);//进阶版游戏
void run_senior(int map_choice, int character, int user_id, int is_load = 0, int save_id = 0);//高级版游戏
void kunkun_trip(int user_id, int is_load = 0, int save_id = 0);//坤坤之旅
void run_multiple(int user_id);//多人游戏总控制
void run_double_player(int map_choice, int character1, int character2, int user_id);//双人游戏
void run_man_ai(int map_choice, int character1, int character2, int user_id);//人机对战
void run_web_game(int map_choice, int character_main, int user_id, int is_host);//网络对战

/*------------------------------用户存档函数类------------------------------*/
//----------排行结构体
struct gamerank {
    int highscore[5] = { 0 };
    int user_id[5] = { 0 };
};
extern gamerank game_rank;//各模式最高分


//----------存档结构体
struct save {
    int mode;//模式,-1表示没有，0，1，2，3对应选项
    int map_id;//地图
};


//----------用户类
class user {
public:
    int level = -1;//状态，为-1表示还没有这个用户
    //为0，1，2，3,打完第几关
    wchar_t name[20];
    save save_list[10];

    void append();//新建
    void reset(int user_id);//删除
    //添加覆盖存档
    void save_append(int user_id, int save_id, int map_id, int mode, const object& ob_inmap, const snack& kun, const int time, const int score);
    void save_load(int user_id, int save_id, int& map_id, object& ob_inmap, snack& kun, int& time, int& score);//读取存档
    void init_mune_addsave();//初始化添加存档菜单
    void init_mune_loadsave();//初始化载入存档菜单
};
extern user user_list[5];//所有用户

void download_user_list();//载入用户数据
void upload_user_list();//更新用户数据
void init_user_mune();//初始化用户菜单
void show_userinfo();//展示用户信息
int choice_to_user(int choice);//处理输入，返回用户

void download_rank();//载入最高得分数据
void upload_rank();//更新最高得分数据

void show_history();//展示历史记录数据
void upload_history(int gametype, int user_id, int score);//增加历史记录数据
