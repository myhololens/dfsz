#include "判定处理_敌机与玩家子弹.h"
#include "敌机基础.h"
#include "玩家子弹基础.h"
namespace 东方山寨 {
//==============================================================================
// 子弹与玩家炸弹判定
//==============================================================================
void C敌机与玩家子弹判定::f绑定敌机(C敌机 &a敌机) {
	m敌机 = &a敌机;
}
void C敌机与玩家子弹判定::f绑定玩家子弹(C玩家子弹 &a子弹) {
	m子弹 = &a子弹;
}
bool C敌机与玩家子弹判定::f玩家子弹_提交判定(const tf判定 &af) {
	const t圆形 v敌机判定 = m敌机->fg判定点();
	const bool v结果 = af(t圆形{v敌机判定.m坐标, v敌机判定.m半径});
	if (v结果) {
		m敌机->f中弹(m子弹->f属性_g伤害());
	}
	return v结果;
}
bool C敌机与玩家子弹判定::f玩家子弹_提交判定(const t圆形 &a圆0) {
	return f玩家子弹_提交判定([&a圆0](const t圆形 &a圆1)->bool {
		return 数学::f圆形相交判定(a圆0, a圆1);
	});
}
bool C敌机与玩家子弹判定::f玩家子弹_提交判定(const t旋转矩形 &a矩形) {
	return f玩家子弹_提交判定([&a矩形](const t圆形 &a圆形)->bool {
		return 数学::f圆形旋转矩形相交判定(a圆形, a矩形);
	});
}
}