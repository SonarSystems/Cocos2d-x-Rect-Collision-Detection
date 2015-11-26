#include "HelloWorldScene.h"

USING_NS_CC;

using namespace std;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create( );
    listener->setSwallowTouches( true );
    
    listener->onTouchBegan = CC_CALLBACK_2( HelloWorld::onTouchBegan, this );
    listener->onTouchMoved = CC_CALLBACK_2( HelloWorld::onTouchMoved, this );
    listener->onTouchEnded = CC_CALLBACK_2( HelloWorld::onTouchEnded, this );
    
    Director::getInstance( )->getEventDispatcher( )->addEventListenerWithSceneGraphPriority( listener, this );
    
    sprite1 = Sprite::create( "HelloWorld.png" );
    sprite2 = Sprite::create( "HelloWorld.png" );
    
    
    sprite1->setPosition( Vec2( 100, 200 ) );
    sprite2->setPosition( Vec2( 400, 200 ) );
    
    sprite1->setScale( 0.1 );
    
    this->addChild( sprite1 );
    this->addChild( sprite2 );
    
    return true;
}



// called when the touch first begins
bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    sprite2->setPosition( Vec2( touch->getLocation( ).x, touch->getLocation( ).y ) );
    
    Rect rect1 = sprite1->getBoundingBox( );
    Point touchPoint = touch->getLocation( );
    
    if ( rect1.containsPoint( touchPoint ) )
    {
        log( "Touched" );
    }
    else
    {
        log( "Not touched" );
    }
    
    return true; // true if the function wants to swallow the touch
}

// called when the user moves their finger
void HelloWorld::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    sprite2->setPosition( Vec2( touch->getLocation( ).x, touch->getLocation( ).y ) );
    
    Rect rect1 = sprite1->getBoundingBox( );
    Rect rect2 = sprite2->getBoundingBox( );

    if ( rect1.intersectsRect( rect2 ) )
    {
        log( "Collided" );
    }
    else
    {
        log( "Not collided" );
    }
}

// called when the user lifts their finger
void HelloWorld::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    sprite2->setPosition( Vec2( touch->getLocation().x, touch->getLocation().y ) );
}