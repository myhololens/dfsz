#include "道具动画.h"
#include "道具.h"
namespace 东方山寨 {
//=============================================================================
// 道具动画
//=============================================================================
t向量3 C道具动画::f接口_g缩放() const {
	const float v = sqrt(m插值);
	return {v, v, 1};
}
void C道具动画::f接口_s父对象(void *p) {
	m道具 = static_cast<C道具*>(p);
}
void C道具动画::f接口_计算() {
	if (m插值 < 1) {
		m插值 = 数学::f线性渐变<float>(m插值, 1, f接口_g游戏速度()->fg秒() / C道具::c动画渐变时间);
	}
}
float C道具动画::f接口_g透明度() const {
	return m插值 * m道具->m道具属性->m最大透明度;
}
const C游戏速度 *C道具动画::f接口_g游戏速度() const {
	return m道具->m游戏速度;
}

}