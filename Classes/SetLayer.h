﻿/*设置场景，用来设置音效，音乐，音量等*/


#ifndef __SetLayer__H__
#define __SetLayer__H__
#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
using namespace cocos2d::extension;

class SetLayer : public Layer {
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SetLayer);

	void changeMusicVol(Ref* pSender, Control::EventType type);
	void changeEffectVol(Ref* pSender, Control::EventType type);
	void saveSet(Ref* pSender);
	void closeBtn(Ref* pSender);
	void musicSet(Ref* pSender);
	void effectSet(Ref* pSender);

};

#endif