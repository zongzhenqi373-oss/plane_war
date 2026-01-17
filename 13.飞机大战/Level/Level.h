#pragma once
#include<iostream>
#include <string>
#include <vector>
using namespace std;


class Level {
public:
    struct LevelConfig {
        int level;             // 关卡编号
        int scoreThreshold;    // 进入下一关的分数
        int foeSpawnFreq;      // 敌机生成频率（ms）
        int smallFoeRate;      // 小飞机出现概率(0~100)
        int midFoeRate;        // 中飞机出现概率(0~100)
        int bigFoeRate;        // 大飞机出现概率(0~100)
    };

    Level();

    // 获取当前关卡配置，我不需要修改当前关卡配置，只需要读取获取就可以，因此使用常量成员函数
    const LevelConfig& getCurrentLevelConfig() const;

    // 根据分数更新关卡
    void updateLevel(int score);

    // 获取当前关卡
    int getCurrentLevel() const { return m_currentLevel; }   //不可修改

private:
    vector<LevelConfig> m_levels;   //用一个向量来存储关卡配置信息
    int m_currentLevel;     //当前的关卡
};
