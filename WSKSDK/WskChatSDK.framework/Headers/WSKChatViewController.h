//
//  WSKChatViewController.h
//  WeiShangKeProj
//
//  Created by 焱 孙 on 5/18/15.
//  Copyright (c) 2015 visionet. All rights reserved.
//

#import <UIKit/UIKit.h>

//定义返回刷新Block类型
typedef void (^RefreshSessionBlock)(void);

@class WSKFaceToolBar;

/**
 *  客服会话ViewController,必须嵌入到UINavigationcontroller中
 */
@interface WSKChatViewController : UIViewController

/**
 *  会话窗口标题
 */
@property (nonatomic,strong) NSString *chatTitle;

@property (nonatomic,strong) WSKFaceToolBar *faceToolBar;
@property (nonatomic,strong) NSMutableArray *aryImageURL;                //聊天的图片列表
@property (nonatomic,strong) NSMutableArray *aryReceiverAudioIcon;       //用于播放时动态显示
@property (nonatomic,strong) NSMutableArray *arySenderAudioIcon;         //用于播放时动态显示

- (void)postPasteImageOperate;

@end
