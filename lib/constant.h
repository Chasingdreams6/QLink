#pragma once
#ifndef CONSTANT_H
#define CONSTANT_H


#define SCREEN_WIDTH 960 // 屏幕宽度至少960
#define SCREEN_HEIGHT 880 // 屏幕高度至少880
#define LINE 13 // 地图行数默认13, 行和列至少得有一个偶数使得有解，不同line/column的档不能互通
#define COLUMN 16 // 地图列数默认16， test是针对13*16写的，修改需要屏蔽test
#define SIZE 60 // 每一个方块的像素大小
#define X_SHIFT ((SCREEN_WIDTH - COLUMN * SIZE) / 2) // 左右偏移，使得页面在中央
#define Y_SHIFT (SCREEN_HEIGHT - LINE * SIZE) // 上下偏移
#define INIT_TIME 180   // 初始游戏时间180s
#define ADD_TIME 10 // +1s道具的增加时长
#define ADD_RATIO 0.05 // +1s道具每一秒的出现概率
#define SHUFFLE_RATIO 0.05
#define HINT_RATIO 0.05 // hint道具每秒的出现概率
#define SHUFFLE_CNT 50 //  交换次数
#define HINT_TIME 10 // 提示时间
#define RANDOM_LIM 10 // 一个随机次数的上限

#define BACKGROUND_PATH ":/images/blackground.bmp"
#define ITEM1_PATH ":/images/item1.jpeg"
#define ITEM2_PATH ":/images/item2.jpeg"
#define ITEM3_PATH ":/images/item3.jpeg"
#define ITEM4_PATH ":/images/item4.jpeg"
#define ITEM5_PATH ":/images/item5.jpeg"
#define ITEM6_PATH ":/images/item6.jpeg"
#define USER1_PATH ":/images/user1.jpeg"
#define USER2_PATH ":/images/user2.jpeg"
#define ADD1_PATH ":/images/add1.png"
#define SHUFFLE_PATH ":/images/shuffle.png"
#define HINT_PATH ":/images/hint.png"
#define ITEM1_SELECTED ":/images/item1_selected.jpeg"
#define ITEM2_SELECTED ":/images/item2_selected.jpeg"
#define ITEM3_SELECTED ":/images/item3_selected.jpeg"
#define ITEM4_SELECTED ":/images/item4_selected.jpeg"
#define ITEM5_SELECTED ":/images/item5_selected.jpeg"
#define ITEM6_SELECTED ":/images/item6_selected.jpeg"
#define ITEM1_HINTED ":/images/item1_hinted.jpeg"
#define ITEM2_HINTED ":/images/item2_hinted.jpeg"
#define ITEM3_HINTED ":/images/item3_hinted.jpeg"
#define ITEM4_HINTED ":/images/item4_hinted.jpeg"
#define ITEM5_HINTED ":/images/item5_hinted.jpeg"
#define ITEM6_HINTED ":/images/item6_hinted.jpeg"


#endif // CONSTANT_H
