#include "��Ƶ����.h"
namespace ����ɽկ {
//==============================================================================
// ��Ƶ����
//==============================================================================
void C��Ƶ����::f��ʼ��() {
	m��Ƶ = std::make_unique<��Ƶ::C��Ƶ>();
	m��Ƶ->f��ʼ��();
	m���ſ��� = std::make_unique<C���ſ���>();
	m���ſ���->f��ʼ��_�ӿ�(*m��Ƶ);
}
void C��Ƶ����::f����() {
	m���ſ���->f����();
}
void C��Ƶ����::f����() {
	m���ſ���->f����();
	m��Ƶ->f����();
	m��Ƶ.reset();
}
C��������<tp����> &C��Ƶ����::fg����() {
	return ma����;
}
C�������� &C��Ƶ����::fg��������() {
	if (m�������� == nullptr) {
		m�������� = std::make_unique<C��������>();
		m��������->f��ʼ��_�ӿ�(*m��Ƶ);
		m��������->f��ʼ��_����(ma����);
	}
	return *m��������;
}

C���ſ��� &C��Ƶ����::fg���ſ���() {
	return *m���ſ���;
}
//==============================================================================
// ���ſ���
//==============================================================================
void C���ſ���::f��ʼ��_�ӿ�(��Ƶ::C��Ƶ &a��Ƶ) {
	m���� = std::make_unique<��Ƶ::C���ſ���>(a��Ƶ);
	m����->fs�ظ����ż��(c���ż��);
	for (auto &v��� : ma���) {
		a��Ƶ.f�������(v���);
	}
}
void C���ſ���::f����() {
	m����->fˢ��();
}
void C���ſ���::f����() {
	m����->fֹͣȫ��();
	for (auto &v��� : ma���) {
		v���->f����();
	}
}
void C���ſ���::f������Чs(const ��Ƶ::C���� &a����) {
	m����->f����(a����, *ma���[e��Чs]);
}
void C���ſ���::f������Чm(const ��Ƶ::C���� &a����) {
	m����->f����(a����, *ma���[e��Чm]);
}
void C���ſ���::f������Чl(const ��Ƶ::C���� &a����) {
	m����->f����(a����, *ma���[e��Чl]);
}
void C���ſ���::f��������(const ��Ƶ::C���� &a����) {
	if (m����) {
		m����->fֹͣ(m����);
	}
	m���� = m����->f����(a����, *ma���[e����]);
}
void C���ſ���::fs��Ч����(float a) {
	ma���[e��Чs]->fs����(a * c��Чs);
	ma���[e��Чm]->fs����(a * c��Чm);
	ma���[e��Чl]->fs����(a * c��Чl);
}
void C���ſ���::fs��������(float a) {
	ma���[e����]->fs����(a);
}
float C���ſ���::fg��Ч����() const {
	return ma���[e��Чl]->fg����();
}
float C���ſ���::fg��������() const {
	return ma���[e����]->fg����();
}
//==============================================================================
// ��������
//==============================================================================
void C��������::f��ʼ��_�ӿ�(��Ƶ::C��Ƶ &a) {
	m��Ƶ = &a;
}
void C��������::f��ʼ��_����(C��������<tp����> &a) {
	ma���� = &a;
}
tp���� C��������::f��������(int a��ʶ, const std::wstring &a�ļ���) {
	if (ma����->fi������(a��ʶ)) {
		tp���� v����;
		HRESULT hr = m��Ƶ->f��������(v����, a�ļ���.c_str());
		if (FAILED(hr)) {
			return nullptr;
		}
		ma����->f����(a��ʶ, v����);
		return v����;
	} else {
		return ma����->fg����(a��ʶ);
	}
}
}