var HelloWorldLayer = cc.Layer.extend({
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();
                                      
        var sprite1 = new cc.Sprite( res.CloseNormal_png );
        sprite1.setPosition( 100, 200 );
        this.addChild( sprite1 );

        var sprite2 = new cc.Sprite( res.CloseSelected_png );
        sprite2.setPosition( 120, 200 );
        this.addChild( sprite2 );

        sprite1.setScale( 0.4 );

        // checks if the device you are using is capable of touch
        if ( cc.sys.capabilities.hasOwnProperty( 'touches' ) )
        {
            cc.eventManager.addListener(
            {
                event: cc.EventListener.TOUCH_ONE_BY_ONE,
                
                // called when the touch first begins
                onTouchBegan:function( touch, event )
                {
                    var rect1 = sprite1.getBoundingBox();
                    var touchPoint = touch.getLocation( );
                    if ( cc.rectContainsPoint( rect1, touchPoint ) )
                    {
                        cc.log( "Touched" );
                    }
                    else
                    {
                        cc.log( "Not touched" );
                    }
                    
                    return true;
                },
                
                // called when the user moves their finger
                onTouchMoved:function( touch, event )
                {
                    sprite2.setPosition( touch.getLocationX( ), touch.getLocationY( ) );

                    var rect1 = sprite1.getBoundingBox();
                    var rect2 = sprite2.getBoundingBox();
                    if ( cc.rectIntersectsRect( rect1, rect2 ) )
                    {
                        cc.log( "Collided" );
                    }
                    else
                    {
                        cc.log( "Not collided" );
                    }
                },
                
                // called when the user lifts their finger
                onTouchEnded:function( touch, event )
                {
                    sprite2.setPosition( touch.getLocationX( ), touch.getLocationY( ) );
                }

            }, this );
        }
                                      
        return true;
    },
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});