﻿#include "GameMap.h"
#include "GlobalDefine.h"
#include "Hero.h"
#include "cocos2d.h"

USING_NS_CC;

GameMap::GameMap()
{
	m_map1 = NULL;
	m_map2 = NULL;
	m_map3 = NULL;
}
GameMap::~GameMap()
{
}

void GameMap::InitMap(const char *map_name1,const char *map_name2,const char *map_name3)
{
	this->m_map1 = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(map_name1));
	this->m_map2 = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(map_name2));
	this->m_map3 = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(map_name3));

	m_map1->setAnchorPoint(Point(0, 0));
	m_map1->setTag(11);
	m_map2->setAnchorPoint(Point(0, 0));
	m_map3->setAnchorPoint(Point(0, 0));

	parallax = ParallaxNode::create();
	parallax->addChild(m_map1, 1, Point(1.18, 0), Point(0,360));
	parallax->addChild(m_map2, 2, Point(1, 0), Point(0,0));
	parallax->addChild(m_map3, 3, Point(0.7, 0), Point(0, 0));

	this->setAnchorPoint(ccp(0, 0));
	this->addChild(parallax);
	log("%f%f", parallax->getPositionX(), parallax->getPositionY());
	log("%f%f", parallax->getContentSize().width, parallax->getContentSize().height);
	log("%f%f", m_map1->getContentSize().width, m_map1->getContentSize().height);
}

void GameMap::MoveMap(Hero *hero)//
{
	auto map = (Sprite*)parallax->getChildByTag(11);

	if (hero->JudgePosition(WINSIZE) && hero->HeroDirecton == false)//精灵运动到中间，地图才移动
	{
		if (this->getPositionX() >= -(m_map2->getContentSize().width - WINSIZE.width))//防止地图左边运动后超出边缘
			this->setPosition(this->getPositionX() - hero->m_iSpeed, this->getPositionY());
		log("map is %f", this->getPositionX());
	}
	if (hero->JudgePosition(WINSIZE) && hero->HeroDirecton == true)//精灵运动到中间，地图才移动
	{
		log("Hero Walk Left %f", hero->getPositionX());
		log("map is %f", this->getPositionX());
		if (this->getPositionX() <= -10)                      //防止地图左边运动后超出边缘
			this->setPosition(this->getPositionX() + hero->m_iSpeed, this->getPositionY());
	}
}
bool GameMap::JudgeMap(Hero *hero)
{
	if (this->getPositionX() >= -(m_map2->getContentSize().width - WINSIZE.width) && hero->HeroDirecton == false)//防止地图左边运动后超出边缘
		return false;
	else if (this->getPositionX() <= -10 && hero->HeroDirecton == true)  //防止地图左边运动后超出边缘
		return false;
	else //地图已经移动到达边缘
		return true;
}