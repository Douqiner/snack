#include <iostream>
#include "all.h"
using namespace std;

select_lable lable_list[3];//���б�ǩ
mune mune_list[10];//���в˵�
wall wall_list[6];//���г�ʼ��ͼ
user user_list[5];//�����û�
gamerank game_rank;//��ģʽ��߷�
const point op_list[4] = { {0,MAP_L - 1},{0,1}, {MAP_L - 1,0}, {1,0} };//������
int end_music;//�Ƿ�һֱΪend����

int main() {

    // ��ʼ���������    
    srand((unsigned)time(NULL));

    initgraph(800, 600);  // ��ʼ������
    init_font();

    IMAGE img_main, img_end;

    loadimage(&img_end, _T("resource\\static\\end_back.jpg"));
    loadimage(&img_main, _T("resource\\static\\back_main.png"));
    IMAGE img;
    loadimage(&img, _T("resource\\static\\back.jpg"));
    init_select_lable();
    init_mune_list();
    init_wall();

    download_rank();//��ȡ����
    download_user_list();//��ȡ�û�

    //����Ϸ����
    int game = 1, user_choice, user_id;
    while(game){

        putimage(-80, 0, &img);
        //��ʼ�û��˵�
        
        init_user_mune();
        show_userinfo();
        mune_list[MUNE_USER].display();
        user_choice = mune_list[MUNE_USER].choice(TYPE_GENERAL);
        if (user_choice == -1)
            break;
        else {
            user_id = choice_to_user(user_choice);
            if (user_id == 5)
                continue;
        }

        RECT carry = { 300, 50, 500, 100 };
        settextstyle(40, 0, L"΢���ź�");
        settextcolor(0x0E0EF3);
        drawtext(L"������......", &carry, DT_CENTER);

        int wait_game = 1;
        int choice, character;

        if (user_list[user_id].level == 3)
            mune_list[MUNE_MAIN].row = 5;
        else{
            end_music = 0;
            mune_list[MUNE_MAIN].row = 4;
        }

        if(end_music)
            PlaySoundA("resource\\music\\end_song.wav", NULL, SND_LOOP | SND_ASYNC);
        else
            PlaySoundA("resource\\music\\back_begin.wav", NULL, SND_FILENAME | SND_SYNC);
        while (wait_game) {//--------------------------------------------------------��¼��Ϸ
            if(!end_music)
                PlaySoundA("resource\\music\\back_repeat.wav", NULL, SND_LOOP | SND_ASYNC);
            if(end_music)
                putimage(-20, 0, &img_end);
            else
                putimage(-80, 0, &img_main);
            mune_list[MUNE_MAIN].display();//չʾ�˵�
            choice = mune_list[MUNE_MAIN].choice(TYPE_GENERAL);//ѡ��˵�

            switch (choice) {
            case -1://----------------------------------------�����ϼ�

                wait_game = 0;
                break;

            case 0://----------------------------------------�µĿ�ʼ

                mune_list[MUNE_NEWGAME].display();//չʾ�˵�
                choice = mune_list[MUNE_NEWGAME].choice(TYPE_GENERAL);//ѡ��˵�

                switch (choice) {
                case -1://------------------------�����ϼ�

                    break;

                case 0://------------------------����ģʽ

                    putimage(-80, 0, &img);
                    mune_list[MUNE_MAP].display();//չʾ�˵�
                    choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//ѡ��˵�
                    if (choice != -1) {
                        putimage(-80, 0, &img);
                        mune_list[MUNE_CHARACTER].display();
                        character = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//ѡ������
                        if (character != -1)
                            run_threshold(choice, character + 1, user_id);
                    }

                    break;
                case 1://------------------------����ģʽ

                    putimage(-80, 0, &img);
                    mune_list[MUNE_MAP].display();//չʾ�˵�
                    choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//ѡ��˵�
                    if (choice != -1) {
                        putimage(-80, 0, &img);
                        mune_list[MUNE_CHARACTER].display();
                        character = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//ѡ������
                        if (character != -1)
                            run_advance(choice, character + 1, user_id);
                    }

                    break;
                case 2://------------------------�߼�ģʽ

                    putimage(-80, 0, &img);
                    mune_list[MUNE_MAP].display();//չʾ�˵�
                    choice = mune_list[MUNE_MAP].choice(TYPE_MAP, user_id);//ѡ��˵�
                    if (choice != -1) {
                        putimage(-80, 0, &img);
                        mune_list[MUNE_CHARACTER].display();
                        character = mune_list[MUNE_CHARACTER].choice(TYPE_CHARACTER);//ѡ������
                        if (character != -1)
                            run_senior(choice, character + 1, user_id);
                    }

                    break;
                case 3://------------------------����֮��

                    kunkun_trip(user_id);

                    break;

                case 4://------------------------�����˶�

                    run_multiple(user_id);

                    break;
                }

                break;
            case 1://----------------------------------------������Ϸ

            while (1){
                download_user_list();
                user_list[user_id].init_mune_loadsave();
                mune_list[MUNE_LOADSAVE].display();
                choice = mune_list[MUNE_LOADSAVE].choice(TYPE_GENERAL);
                if (choice == -1)
                    break;
                else {
                    if (choice % 2 == 1) {//ɾ��
                        user_list[user_id].save_list[choice / 2].mode = -1;
                        upload_user_list();
                    }
                    else {//�˳�������
                        character = 0;
                        if (user_list[user_id].save_list[choice / 2].mode != -1){
                            switch (user_list[user_id].save_list[choice / 2].mode) {
                            case 0:
                                run_threshold(choice, character + 1, user_id, 1, choice / 2);
                                break;
                            case 1:
                                run_advance(choice, character + 1, user_id, 1, choice / 2);
                                break;
                            case 2:
                                run_senior(choice, character + 1, user_id, 1, choice / 2);
                                break;
                            case 3:
                                kunkun_trip(user_id, 1, choice / 2);
                                break;
                            }
                        }
                        break;
                    }
                }
            }

                break;
            case 2://----------------------------------------��ʷ��¼

                show_history();

                break;
            case 3://----------------------------------------�˳���Ϸ

                wait_game = 0;
                game = 0;
                break;

            case 4://----------------------------------------��������

                if(end_music){
                    end_music = 0;
                }
                else{
                    PlaySoundA("resource\\music\\end_song.wav", NULL, SND_LOOP | SND_ASYNC);
                    end_music = 1;
                }
                break;
            }
        }
        
    }

    closegraph();
    return 0;
}