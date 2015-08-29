/*图籍场景的实现*/

#ifndef __TujiLayer__H__
#define __TujiLayer__H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class TujiLayer : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TujiLayer);

	ListView* listView;

	void selectedItemEvent(Ref* pSender, ListViewEventType  type);     // ListView触摸事件 

private:
	size_t m_iBeforeSel;
	Sprite* m_pMZ_Pic;
	LabelTTF* m_pMZLabel;
	Sprite* m_pMZ_Txt;
	Sprite* m_pLion_Pic;
	LabelTTF* m_pLionLabel;
	Sprite* m_pStone_Pic ;
	LabelTTF* m_pStoneLabel;

};

#endif