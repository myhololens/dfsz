#pragma once
#include "基础_数组.h"
#include "图形基础.h"
#include "图形引擎.h"
#include "动画接口.h"
namespace 东方山寨 {
struct S图形参数;
struct S图片动画属性;
//==============================================================================
// 实现
//==============================================================================
class C画图片动画 {
public:
	static void f显示图片(const t向量2 &坐标, const tp纹理 &纹理, const S顶点矩形 *顶点, const I动画 &动画);
	static void f显示图片2(const tp纹理 &纹理, const S顶点矩形 &顶点, const t向量2 &平移, float 旋转, const t向量2 &缩放, float 透明);
	static void f显示图片3(const tp纹理 &纹理, const S顶点矩形 &顶点, const t向量2 &平移, const t向量3 &旋转, const t向量3 &缩放, float 透明);
};
//==============================================================================
// 顶点动画,整合画图片的代码
//==============================================================================
class C内置图片动画 {
public:
	//属性
	virtual const S图片动画属性 &fg图片动画属性() const = 0;
	virtual const t向量2 &fg坐标() const = 0;
	bool fi纹理() const;
	const S顶点矩形 &fg顶点矩形() const;
	//动作
	virtual void f显示() const;
	void f显示图片() const;
public:
	std::unique_ptr<I动画> m动画 = nullptr;
};
//属性
struct S图片动画属性 {
	t属性指针<tp纹理> m纹理;
	t属性指针<S顶点矩形> m顶点;
	t扩展指针<I工厂<I动画>> m动画;
	std::unique_ptr<I动画> fc动画(void * = nullptr) const;
};
//==============================================================================
// 图片图形
//==============================================================================
class C二维图片图形 : public I粒子, public I事件, public I动画 {
public:
	C二维图片图形() = default;
	void f接口_计算() override;
	void f接口_显示() const override;
	void f接口_初始化(const S图形参数 &) override;
	t向量3 f接口_g旋转() const override;
	t向量3 f接口_g缩放() const override;
	float f接口_g透明度() const override;
	bool fi纹理() const;
	const S顶点矩形 &fg顶点矩形() const;
	void f显示图片() const;
protected:
	float m旋转 = 0;
	t向量2 m缩放 = t向量2::c一;
	const tp纹理 *m纹理 = nullptr;
	const S顶点矩形 *m顶点 = nullptr;
};
//三维
class C三维图片图形 : public I粒子, public I事件, public I动画 {
public:
	C三维图片图形() = default;
	void f接口_计算() override;
	void f接口_显示() const override;
	void f接口_初始化(const S图形参数 &) override;
	t向量3 f接口_g旋转() const override;
	t向量3 f接口_g缩放() const override;
	float f接口_g透明度() const override;
	bool fi纹理() const;
	const S顶点矩形 &fg顶点矩形() const;
	void f显示图片() const;
protected:
	t向量3 m旋转 = t向量3::c零;
	t向量3 m缩放 = t向量3::c一;
	const tp纹理 *m纹理 = nullptr;
	const S顶点矩形 *m顶点 = nullptr;
};

}	//namespace 东方山寨