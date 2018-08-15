//
// Created by 13567 on 8/15/2018.
//

#ifndef CPP_NOTES_CMD_COLORS_WIN_H
#define CPP_NOTES_CMD_COLORS_WIN_H
// #include "stdafx.h"
#include <iostream>
#include <windows.h>

// using namespace std;

void SetColor(unsigned short forecolor = 4, unsigned short backgroudcolor = 0)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //获取缓冲区句柄
    SetConsoleTextAttribute(hCon, forecolor | backgroudcolor); //设置文本及背景色
}
// int _tmain(int argc, char *argv[])
// {
//     SetColor(40, 30);
//     std::cout << "Colored hello world for windows!\n";
//     SetColor(120, 20);
//     std::cout << "Colored hello world for windows!\n";
//     SetColor(10, 50);
//     std::cout << "Colored hello world for windows!\n";
//     return 0;
// }
#endif //CPP_NOTES_CMD_COLORS_WIN_H
