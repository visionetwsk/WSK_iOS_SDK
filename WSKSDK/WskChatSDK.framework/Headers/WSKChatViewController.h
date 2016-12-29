//
//  WSKChatViewController.h
//  WeiShangKeProj
//
//  Created by 焱 孙 on 5/18/15.
//  Copyright (c) 2015 visionet. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WSKCommodityVo.h"

/**
 *  提供了监控SDK内消息跳转行为的block;
 *  如果设置了block回调，则在链接点击之后执行该block
 *
 *  @return 是否执行SDK默认的跳转行为
 *  如果block返回为NO,则不执行SDK默认处理, 返回为YES则执行SDK默认跳转处理
 */
typedef BOOL (^WSKLinkClickBlock)(NSString *linkAddress);

@class WSKFaceToolBar;

/**
 *  客服会话ViewController,必须嵌入到UINavigationcontroller中
 */
@interface WSKChatViewController : UIViewController

/**
 *  会话窗口标题
 */
@property (nonatomic, strong) NSString *chatTitle;

/**
 *  商品信息展示
 */
@property (nonatomic, strong) WSKCommodityVo *commodityVo;

/**
 *  监控SDK内消息跳转行为的block
 *
 *  @return 是否执行SDK默认的跳转行为
 */
@property (nonatomic, copy) WSKLinkClickBlock linkClickBlock;

@property (nonatomic, strong) WSKFaceToolBar *faceToolBar;
@property (nonatomic, strong) NSMutableArray *aryImageURL;                //聊天的图片列表
@property (nonatomic, strong) NSMutableArray *aryReceiverAudioIcon;       //用于播放时动态显示
@property (nonatomic, strong) NSMutableArray *arySenderAudioIcon;         //用于播放时动态显示

- (void)postPasteImageOperate;
- (void)touchTableView;

@end
