#include "Level.h"

Level::Level() : m_currentLevel(1) {
    // 初始化关卡配置
    m_levels = {
        {1, 20, 2500, 100,   0,   0}, // 第一关：只有小飞机，生成频率 2500ms
        {2, 70, 1800, 70,   30,   0}, // 第二关：小飞机 70%，中飞机 30%
        {3, 120, 1200, 50,   30,  20}, // 第三关：小中大都有
        {4,9999, 800, 40,   35,  25}  // 第四关：加速
    };
}

const Level::LevelConfig& Level::getCurrentLevelConfig() const {
    return m_levels[m_currentLevel - 1];
}

void Level::updateLevel(int score) {
    // 如果分数达到阈值，自动进入下一关
    if (m_currentLevel < (int)m_levels.size() &&
        score >= m_levels[m_currentLevel - 1].scoreThreshold) {
        m_currentLevel++;
    }
}
