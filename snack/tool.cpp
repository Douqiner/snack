#include<iostream>
#include<sstream>
#include "all.h"

int getkeyboard(int& in_key) {
    INPUT_RECORD inRec = { 0 };                    // 输入信息结构体，记录输入信息
    DWORD res;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);       // 获取控制台标准输入句柄
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);     // 获取控制台标准输出句柄

    // 开启控制台窗口鼠标输入
    //SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

    // 获取当前输入信息，采用WaitForSingleObject来防止函数阻塞（异步监听）
    if (WaitForSingleObject(hInput, 0) == WAIT_OBJECT_0) {
        ReadConsoleInputA(hInput, &inRec, 1, &res);
        // 监听事件状态
        switch (inRec.EventType) {
        case KEY_EVENT:
            // 键盘事件
            // dwControlKeyState 会记录键盘控制键状态，例如大小写是否开启等
            // wVirtualKeyCode wVirtualScanCode 是最终键盘按键的可以使用的组合变量
            //cout << "KeyEvent.bKeyDown" << inRec.Event.KeyEvent.bKeyDown << black << endl;
            //cout << "KeyEvent.dwControlKeyState" << inRec.Event.KeyEvent.dwControlKeyState << black << endl;
            //cout << "KeyEvent.uChar.AsciiChar" << inRec.Event.KeyEvent.uChar.AsciiChar << black << endl;
            //cout << "KeyEvent.uChar.UnicodeChar" << inRec.Event.KeyEvent.uChar.UnicodeChar << black << endl;
            //cout << "KeyEvent.wRepeatCount" << inRec.Event.KeyEvent.wRepeatCount << black << endl;
            //cout << "KeyEvent.wVirtualScanCode" << inRec.Event.KeyEvent.wVirtualScanCode << black << endl;
            if(inRec.Event.KeyEvent.bKeyDown){
                in_key = inRec.Event.KeyEvent.wVirtualKeyCode;
                return 1;
            }
        default:
            return 0;
        }
    }
    return 0;

}


void render(char map[30][30]) {
    int i, j;

    IMAGE object1, object2, object3, object4, object8, object9;
    IMAGE head1, head2, head3, head4;
    IMAGE body1, body2, body3, body4;
    loadimage(&object1, L"resource\\static\\object1.png", 20, 20);
    loadimage(&object2, L"resource\\static\\object2.png", 20, 20);
    loadimage(&object3, L"resource\\static\\object3.png", 20, 20);
    loadimage(&object4, L"resource\\static\\ball.jpg", 20, 20);
    loadimage(&object8, L"resource\\static\\object8.png", 20, 20);
    loadimage(&object9, L"resource\\static\\object9.png", 20, 20);
    loadimage(&head1, L"resource\\static\\head1.png", 20, 20);
    loadimage(&head2, L"resource\\static\\head2.png", 20, 20);
    loadimage(&head3, L"resource\\static\\head3.png", 20, 20);
    loadimage(&head4, L"resource\\static\\head4.png", 20, 20);
    loadimage(&body1, L"resource\\static\\body1.png", 20, 20);
    loadimage(&body2, L"resource\\static\\body2.png", 20, 20);
    loadimage(&body3, L"resource\\static\\body3.png", 20, 20);
    loadimage(&body4, L"resource\\static\\body4.png", 20, 20);

    for(i = 0;i < 30; i++){
        for (j = 0; j < 30; j++) {
            switch(map[i][j]){
            case 0:
                break;
            case OBJECT_APPLE:
                putimage(j * 20, i * 20, &object1);
                break;
            case OBJECT_FAST:
                putimage(j * 20, i * 20, &object2);
                break;
            case OBJECT_MUD:
                putimage(j * 20, i * 20, &object3);
                break;
            case OBJECT_BALL:
                putimage(j * 20, i * 20, &object4);
                break;
            case BLOCK_FENCE:
                putimage(j * 20, i * 20, &object8);
                break;
            case BLOCK_ROCK:
                putimage(j * 20, i * 20, &object9);
                break;
            case 1 * 10 + 1:
                putimage(j * 20, i * 20, &body1);
                break;
            case 1 * 10 + 0:
                putimage(j * 20, i * 20, &head1);
                break;
            case 2 * 10 + 1:
                putimage(j * 20, i * 20, &body2);
                break;
            case 2 * 10 + 0:
                putimage(j * 20, i * 20, &head2);
                break;
            case 3 * 10 + 1:
                putimage(j * 20, i * 20, &body3);
                break;
            case 3 * 10 + 0:
                putimage(j * 20, i * 20, &head3);
                break;
            case 4 * 10 + 1:
                putimage(j * 20, i * 20, &body4);
                break;
            case 4 * 10 + 0:
                putimage(j * 20, i * 20, &head4);
                break;

            }
        }
    }
}


int key_id(int in_key, int id, int state) {
    switch (in_key) {
    case VK_UP:
    case 73://i
        if (id == 2 && state != ACTION_DN)
            return ACTION_UP;
        break;
    case 87://w
        if (id == 1 && state != ACTION_DN)
            return ACTION_UP;
        break;
    case VK_DOWN:
    case 75://k
        if (id == 2 && state != ACTION_UP)
            return ACTION_DN;
        break;
    case 83://s
        if (id == 1 && state != ACTION_UP)
            return ACTION_DN;
        break;
    case VK_LEFT:
    case 74://j
        if (id == 2 && state != ACTION_RT)
            return ACTION_LF;
        break;
    case 65://a
        if (id == 1 && state != ACTION_RT)
            return ACTION_LF;
        break;
    case VK_RIGHT:
    case 76://l
        if (id == 2 && state != ACTION_LF)
            return ACTION_RT;
        break;
    case 68://d
        if (id == 1 && state != ACTION_LF)
            return ACTION_RT;
        break;
    case VK_ESCAPE://esc
        return 5;
    }
    return -1;
}

void outputflame(int character, int trip_map) {
    IMAGE head;
    wstring path = L"resource\\static\\head1.png";
    path[20] = char(character + '0');
    loadimage(&head, path.c_str());
    putimage(620, 20, &head);

    RECT carry;

    settextstyle(20, 0, L"微软雅黑");
    settextcolor(0x0E0EF3);
    carry = { 670, 15, 800, 35 };
    drawtext(L"当前生命", &carry, DT_LEFT);
    carry = { 670, 40, 800, 60 };
    drawtext(L"当前长度", &carry, DT_LEFT);

    settextstyle(25, 0, L"微软雅黑");
    settextcolor(0xE11B8B);
    carry = { 620, 65, 800, 90 };
    drawtext(L"当前得分", &carry, DT_LEFT);
    carry = { 620, 115, 800, 140 };
    if (!trip_map)
        drawtext(L"历史最高得分", &carry, DT_LEFT);
    else if (trip_map == 1)
        drawtext(L"任务:获取2000分", &carry, DT_LEFT);
    else if (trip_map == 2)
        drawtext(L"任务:清理所有泥干嘛", &carry, DT_LEFT);
    else
        drawtext(L"任务:拿回篮球", &carry, DT_LEFT);
    carry = { 620, 165, 800, 190 };
    drawtext(L"时间", &carry, DT_LEFT);
}

void outputinfo(int score, const snack& kun, int time, int height_score) {
    RECT carry;
    wstring op;
    wstringstream out;
    //生命
    settextstyle(20, 0, L"微软雅黑");
    settextcolor(0x0E0EF3);
    carry = { 750, 15, 800, 35 };
    clearrectangle(750, 15, 800, 35);
    out << kun.life;
    op = out.str();
    drawtext(op.c_str(), &carry, DT_LEFT);
    //长度
    out.str(L"");
    out << kun.len;
    op = out.str();
    carry = { 750, 40, 800, 60 };
    clearrectangle(750, 40, 800, 60);
    drawtext(op.c_str(), &carry, DT_LEFT);
    //得分
    out.str(L"");
    out << score;
    op = out.str();
    settextstyle(25, 0, L"微软雅黑");
    carry = { 620, 90, 800, 115 };
    clearrectangle(620, 90, 800, 115);
    drawtext(op.c_str(), &carry, DT_LEFT);
    //历史得分
    if (height_score != -1){
        out.str(L"");
        out << (score > height_score ? score : height_score);
        op = out.str();
        carry = { 620, 140, 800, 165 };
        clearrectangle(620, 140, 800, 165);
        drawtext(op.c_str(), &carry, DT_LEFT);
    }
    //时间
    out.str(L"");
    out.setf(ios::fixed);
    out.precision(1);
    out << (time * 1.0 / 1000);
    op = out.str();
    op += L's';
    carry = { 620, 190, 800, 215 };
    clearrectangle(620, 190, 800, 215);
    drawtext(op.c_str(), &carry, DT_LEFT);
}

void show_mapinfo(int choice, int user_id) {
    IMAGE img;
    RECT carry1, carry2;
    carry1 = { 470, 60, 750, 150 };
    carry2 = { 470, 160, 750, 460 };
    settextcolor(0x0000000);
    setbkcolor(0xD49F00);
    settextstyle(25, 0, L"微软雅黑"); // 设置文字大小、字体

    wstring path = _T("resource\\static\\map0.png");
    path[19] = char(choice + '0');

    loadimage(&img, path.c_str());
    putimage(60, 60, &img);
    clearrectangle(470, 60, 750, 150);
    clearrectangle(470, 160, 750, 460);
    drawtext(wall_list[choice].disp1.c_str(), &carry1, DT_LEFT | DT_WORDBREAK);
    if (user_list[user_id].level >= choice)
        drawtext(wall_list[choice].disp2.c_str(), &carry2, DT_LEFT | DT_WORDBREAK);
    else
        drawtext(L"继续完成坤坤的旅行以解锁文本", &carry2, DT_LEFT | DT_WORDBREAK);
}

void show_characterinfo(int choice) {
    wstring path1 = _T("resource\\static\\body1.png");
    wstring path2 = _T("resource\\static\\head1.png");
    path1[20] = char(choice + 1 + '0');
    path2[20] = char(choice + 1 + '0');

    IMAGE img1, img2;
    loadimage(&img1, path1.c_str());
    loadimage(&img2, path2.c_str());
    putimage(320, 300, &img1);
    putimage(360, 300, &img1);
    putimage(400, 300, &img1);
    putimage(440, 300, &img2);

}

void init_font() {
    LOGFONT f;//字体变量
    f.lfEscapement = 0;//角度
    f.lfOrientation = 0;//角度
    f.lfStrikeOut = 0;
    f.lfUnderline = 0;
    f.lfItalic = 0;
    f.lfQuality = ANTIALIASED_QUALITY;//抗锯齿
    f.lfWeight = FW_SEMIBOLD;
    settextstyle(&f);
    setbkmode(TRANSPARENT);
}

int check_trip_finish(int map_trip, int score, object& ob_inmap) {
    switch (map_trip) {
    case 1:
        if (score >= 2000)
            return 1;
        else
            return 0;
    case 2:
        if (ob_inmap.mud_num == 0)
            return 1;
        else
            return 0;
    case 3:
        if (ob_inmap.nature[7][7] == 0)
            return 1;
        else
            return 0;
    }
    return 0;
}

void show_trip_map(int choice, int user_id) {
    IMAGE back_img;
    loadimage(&back_img, _T("resource\\static\\back.jpg"));
    putimage(-80, 0, &back_img);

    IMAGE img;
    RECT carry1, carry2, carry3, carry4;
    carry1 = { 470, 60, 750, 150 };
    carry2 = { 470, 160, 750, 460 };
    carry3 = { 470, 360, 750, 460 };
    carry4 = { 670, 360, 750, 460 };
    settextcolor(0x0000000);
    setbkcolor(0xD49F00);
    settextstyle(25, 0, L"微软雅黑"); // 设置文字大小、字体

    wstring path = _T("resource\\static\\map0.png");
    path[19] = char(choice + '0');

    loadimage(&img, path.c_str());
    putimage(60, 60, &img);
    clearrectangle(470, 60, 750, 150);
    clearrectangle(470, 160, 750, 460);
    drawtext(wall_list[choice].disp1.c_str(), &carry1, DT_LEFT | DT_WORDBREAK);

    drawtext(wall_list[choice].disp2.c_str(), &carry2, DT_LEFT | DT_WORDBREAK);
    settextcolor(0x0E0EF3);
    if (user_list[user_id].level < choice){
        ++user_list[user_id].level;
        upload_user_list();
        drawtext(L"新文本解锁!", &carry3, DT_LEFT);
    }
    drawtext(L"回车确定", &carry4, DT_LEFT);
    
}

void outputinfo_m(int score1, int score2, const snack& kun, const snack& cai, int time){
    RECT carry;
    wstring op;
    wstringstream out;
    //----角色1
    //生命
    settextstyle(20, 0, L"微软雅黑");
    settextcolor(0x0E0EF3);
    carry = { 750, 15, 800, 35 };
    clearrectangle(750, 15, 800, 35);
    out << kun.life;
    op = out.str();
    drawtext(op.c_str(), &carry, DT_LEFT);
    //长度
    out.str(L"");
    out << kun.len;
    op = out.str();
    carry = { 750, 40, 800, 60 };
    clearrectangle(750, 40, 800, 60);
    drawtext(op.c_str(), &carry, DT_LEFT);
    //得分
    out.str(L"");
    out << score1;
    op = out.str();
    settextstyle(25, 0, L"微软雅黑");
    carry = { 620, 90, 800, 115 };
    clearrectangle(620, 90, 800, 115);
    drawtext(op.c_str(), &carry, DT_LEFT);
    //----角色2
    //生命
    out.str(L"");
    settextstyle(20, 0, L"微软雅黑");
    settextcolor(0x0E0EF3);
    carry = { 750, 165, 800, 185 };
    clearrectangle(750, 165, 800, 185);
    out << cai.life;
    op = out.str();
    drawtext(op.c_str(), &carry, DT_LEFT);
    //长度
    out.str(L"");
    out << cai.len;
    op = out.str();
    carry = { 750, 190, 800, 210 };
    clearrectangle(750, 190, 800, 210);
    drawtext(op.c_str(), &carry, DT_LEFT);
    //得分
    out.str(L"");
    out << score2;
    op = out.str();
    settextstyle(25, 0, L"微软雅黑");
    carry = { 620, 240, 800, 265 };
    clearrectangle(620, 240, 800, 265);
    drawtext(op.c_str(), &carry, DT_LEFT);

    //时间
    out.str(L"");
    out.setf(ios::fixed);
    out.precision(1);
    out << (time * 1.0 / 1000);
    op = out.str();
    op += L's';
    carry = { 620, 325, 800, 350 };
    clearrectangle(620, 325, 800, 350);
    drawtext(op.c_str(), &carry, DT_LEFT);
}

void outputflame_m(int character1, int character2){
    IMAGE head;
    wstring path = L"resource\\static\\head1.png";
    RECT carry;

    //角色1
    path[20] = char(character1 + '0');
    loadimage(&head, path.c_str());
    putimage(620, 20, &head);

    settextstyle(20, 0, L"微软雅黑");
    settextcolor(0x0E0EF3);
    carry = { 670, 15, 800, 35 };
    drawtext(L"当前生命", &carry, DT_LEFT);
    carry = { 670, 40, 800, 60 };
    drawtext(L"当前长度", &carry, DT_LEFT);

    settextstyle(25, 0, L"微软雅黑");
    settextcolor(0xE11B8B);
    carry = { 620, 65, 800, 90 };
    drawtext(L"当前得分", &carry, DT_LEFT);

    //角色2
    path[20] = char(character2 + '0');
    loadimage(&head, path.c_str());
    putimage(620, 170, &head);

    settextstyle(20, 0, L"微软雅黑");
    settextcolor(0x0E0EF3);
    carry = { 670, 165, 800, 185 };
    drawtext(L"当前生命", &carry, DT_LEFT);
    carry = { 670, 190, 800, 210 };
    drawtext(L"当前长度", &carry, DT_LEFT);

    settextstyle(25, 0, L"微软雅黑");
    settextcolor(0xE11B8B);
    carry = { 620, 215, 800, 240 };
    drawtext(L"当前得分", &carry, DT_LEFT);
    
    carry = { 620, 300, 800, 325 };
    drawtext(L"时间", &carry, DT_LEFT);
}

void check_multiple(snack& kun, snack& cai, object& ob_inmap, int& score1, int& score2){
    if (!kun.tail || !cai.tail)
        return;
    body* p = cai.tail->next;
    //检测kun头
    while (p) {
        if (kun.head->b_pos == p->b_pos) {
            if (p == cai.head) {//头撞头了
                --kun.life;
                score1 -= 100;
                --cai.life;
                score2 -= 100;
                kun.die_load(BLOCK_ROCK, ob_inmap);
                cai.die_load(BLOCK_ROCK, ob_inmap);
                return;
            }
            else {
                --kun.life;
                score1 -= 100;
                kun.die_load(BLOCK_ROCK, ob_inmap);
                return;
            }
            break;
        }
        p = p->next;
    }
    p = kun.tail->next;
    while (p) {
        if (kun.head->b_pos == p->b_pos) {
            if (p == kun.head) {
                break;
            }
            else {
                --kun.life;
                score1 -= 100;
                kun.die_load(BLOCK_ROCK, ob_inmap);
                return;
            }
            break;
        }
        p = p->next;
    }
    //检测cai头
    p = kun.tail->next;
    while (p) {
        if (cai.head->b_pos == p->b_pos) {
            --cai.life;
            score2 -= 100;
            cai.die_load(BLOCK_ROCK, ob_inmap);
            break;
        }
        p = p->next;
    }
    p = cai.tail->next;
    while (p) {
        if (cai.head->b_pos == p->b_pos) {
            if (p == cai.head) {
                break;
            }
            else {
                --cai.life;
                score2 -= 100;
                cai.die_load(BLOCK_ROCK, ob_inmap);
                return;
            }
            break;
        }
        p = p->next;
    }
}

/*终于要写完了--12.31--13.33*/
void play_end_video() {

    initgraph(640, 360);  // 初始化窗口
    clock_t start, end;
    IMAGE img;
    int num = 1;
    double time = 1000.0 / 30;
    wchar_t filename[] = { L"resource\\music\\video\\video_000001.jpg" };
    PlaySoundA("resource\\music\\end_song.wav", NULL, SND_LOOP | SND_ASYNC);
    start = clock();
    end = clock();

    while (1) {
        if (end - start >= int(time)) {
            filename[30] = char(num / 100 + '0');
            filename[31] = char((num - (num / 100) * 100) / 10 + '0');
            filename[32] = char(num % 10 + '0');
            //读取展示图片
            loadimage(&img, filename);
            putimage(0, 0, &img);
            num++;
            if (num == 706)
                break;
            time = 1000.0 * num / 30;
        }
        end = clock();
    }
    initgraph(800, 600);  // 初始化窗口
    init_font();
}
