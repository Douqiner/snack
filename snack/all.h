#pragma once
#include <graphics.h>
#include <string>
#include <playsoundapi.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

#define MAP_L 30

extern int end_music;
/*------------------------------���ߺ�����------------------------------*/
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
int getkeyboard(int& in_key);//��ȡ��������
void render(char map[30][30]);//��Ⱦһ������
int key_id(int in_key, int id, int state);//�ж�����
void outputflame(int character, int trip_map = 0);//���������Ϸ��Ϣ���
void outputinfo(int score, const snack& kun, int time, int height_score);//�����Ϣ
void show_mapinfo(int choice, int user_id);//չʾ��ͼ
void show_characterinfo(int choice);//չʾ����
void init_font();//��ʼ������
int check_trip_finish(int map_trip, int score, object& ob_inmap);//�������֮�ù�������
void show_trip_map(int choice, int user_id);//չʾ��ͼ����
void outputinfo_m(int score1, int score2, const snack& kun, const snack& cai, int time);//������Ϸ�����Ϣ
void outputflame_m(int character1, int character2);//���������Ϸ��Ϣ���
void check_multiple(snack& kun, snack& cai, object& ob_inmap, int& score1, int& score2);//�����Ƿ��ͻ
void play_end_video();//���Ž���mv

/*------------------------------��Ϸ�ж�������------------------------------*/
class wall {
public:
    char block[30][30] = { 0 };
    int bkcolor;
    wstring name;
    wstring disp1;
    wstring disp2;
};
extern wall wall_list[6];//���г�ʼ��ͼ
void init_wall();//��ʼ����ͼ
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
    int next_action;//һ������
    int fast_time;
    int len;
    body* head = NULL;
    body* tail = NULL;
    snack();
    void set(int x, int y, int _id, int _life);
    int step(char lastmap[30][30], int& score, object& ob_inmap);//��һ����ֻ���Ե���Ȼ����
    void load(char lastmap[30][30]);//���ص���ͼ��
    void delete_tail(int n);//ɾ����βn�ڵ�
    void die_load(int op, object& ob_inmap);//����������
    int relife(char map[30][30]);//����
    void reset(int x, int y);//����
    void clear();
    void sound(int sound_type);//����,0Ϊ��ã�1Ϊ����
    ~snack();
};
#define ACTION_UP 0
#define ACTION_DN 1
#define ACTION_LF 2
#define ACTION_RT 3
extern const point op_list[4];//������

class snack_ai :public snack {
public:
    void direct(char map[30][30]);//���ݵ�ͼ�����ƶ�����
};

class object {
public:
    char nature[30][30] = { 0 };
    int apple_num = 0;
    int fast_wait = 10;//"��"�ȴ�ʱ��
    int mud_num = 0;

    int check_generate(char map[30][30], int apple_en = 1, int mud_en = 1);
};
#define OBJECT_APPLE 1
#define OBJECT_FAST 2
#define OBJECT_MUD 3
#define OBJECT_BALL 4

/*------------------------------��Ϸ���˵�������------------------------------*/
//----------ѡ���ǩ��
class select_lable {
public:
    COLORREF write_color;
    COLORREF back_color;
    int height;
    int width;
};
extern select_lable lable_list[3];//���б�ǩ
void init_select_lable();//��ʼ����ǩ
#define LABLE_MAIN 2
#define LABLE_SUB 1
#define LABLE_NOUSE 0


//----------�˵���
class mune {
public:
    wstring text[5][4];//ѡ������
    point pos[5][4];//ѡ�����Ͻ�λ��
    int row;//ѡ������
    int col;//ѡ������
    int select_lable;//ѡ������

    void display();//��ʼ��ӡ
    int choice(int type, int user_id = 0);//�˵�ѡ��
    void flick(point choice);//ѡ������

};
extern mune mune_list[10];//���в˵�
void init_mune_list();//��ʼ���˵�
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

//----------��Ϸ����
void run_threshold(int map_choice, int character, int user_id, int is_load = 0, int save_id = 0);//���Ű���Ϸ
void run_advance(int map_choice, int character, int user_id, int is_load = 0, int save_id = 0);//���װ���Ϸ
void run_senior(int map_choice, int character, int user_id, int is_load = 0, int save_id = 0);//�߼�����Ϸ
void kunkun_trip(int user_id, int is_load = 0, int save_id = 0);//����֮��
void run_multiple(int user_id);//������Ϸ�ܿ���
void run_double_player(int map_choice, int character1, int character2, int user_id);//˫����Ϸ
void run_man_ai(int map_choice, int character1, int character2, int user_id);//�˻���ս
void run_web_game(int map_choice, int character_main, int user_id, int is_host);//�����ս

/*------------------------------�û��浵������------------------------------*/
//----------���нṹ��
struct gamerank {
    int highscore[5] = { 0 };
    int user_id[5] = { 0 };
};
extern gamerank game_rank;//��ģʽ��߷�


//----------�浵�ṹ��
struct save {
    int mode;//ģʽ,-1��ʾû�У�0��1��2��3��Ӧѡ��
    int map_id;//��ͼ
};


//----------�û���
class user {
public:
    int level = -1;//״̬��Ϊ-1��ʾ��û������û�
    //Ϊ0��1��2��3,����ڼ���
    wchar_t name[20];
    save save_list[10];

    void append();//�½�
    void reset(int user_id);//ɾ��
    //��Ӹ��Ǵ浵
    void save_append(int user_id, int save_id, int map_id, int mode, const object& ob_inmap, const snack& kun, const int time, const int score);
    void save_load(int user_id, int save_id, int& map_id, object& ob_inmap, snack& kun, int& time, int& score);//��ȡ�浵
    void init_mune_addsave();//��ʼ����Ӵ浵�˵�
    void init_mune_loadsave();//��ʼ������浵�˵�
};
extern user user_list[5];//�����û�

void download_user_list();//�����û�����
void upload_user_list();//�����û�����
void init_user_mune();//��ʼ���û��˵�
void show_userinfo();//չʾ�û���Ϣ
int choice_to_user(int choice);//�������룬�����û�

void download_rank();//������ߵ÷�����
void upload_rank();//������ߵ÷�����

void show_history();//չʾ��ʷ��¼����
void upload_history(int gametype, int user_id, int score);//������ʷ��¼����
