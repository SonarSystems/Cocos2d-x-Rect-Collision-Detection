#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    // called when the touch first begins
    bool onTouchBegan( Touch *touch, Event *event );
    // called when the user moves their finger
    void onTouchMoved( Touch *touch, Event *event );
    // called when the user lifts their finger
    void onTouchEnded( Touch *touch, Event *event );
    
    Sprite *sprite1;
    Sprite *sprite2;
    
};

#endif // __HELLOWORLD_SCENE_H__
