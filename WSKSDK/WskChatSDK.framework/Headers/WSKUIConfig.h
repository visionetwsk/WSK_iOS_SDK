//
//  WSKUIConfig.h
//  WskChatSDK
//
//  Created by 焱 孙 on 16/9/13.
//  Copyright © 2016年 焱 孙. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  提供了所有自定义UI的接口
 */
@interface WSKUIConfig : NSObject

+ (instancetype)sharedInstance;

- (void)resetUIConfig;

/**
 *  访客文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *customMessageTextColor;

/**
 *  客服文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *serviceMessageTextColor;

/**
 *  文本消息字体大小
 */
@property (nonatomic, assign) CGFloat messageTextFontSize;

/**
 *  提示文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *tipMessageTextColor;

/**
 *  提示文本消息字体大小
 */
@property (nonatomic, assign) CGFloat tipMessageTextFontSize;

/**
 *  提示文本消息背景颜色
 */
@property (nonatomic, strong) UIColor *tipMessageBackgroundColor;

/**
 *  输入框文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *inputTextColor;

/**
 *  输入框文本消息字体大小
 */
@property (nonatomic, assign) CGFloat inputTextFontSize;

/**
 *  消息tableview的背景图片
 */
@property (nonatomic, strong) UIImageView *sessionBackground;

/**
 *  访客头像
 */
@property (nonatomic, strong) UIImage *customerHeadImage;

/**
 *  客服头像
 */
@property (nonatomic, strong) UIImage *serviceHeadImage;

/**
 *  访客消息气泡normal图片
 */
@property (nonatomic, strong) UIImage *customerMessageBubbleNormalImage;

/**
 *  客服消息气泡normal图片
 */
@property (nonatomic, strong) UIImage *serviceMessageBubbleNormalImage;

/**
 *  访客消息气泡pressed图片
 */
@property (nonatomic, strong) UIImage *customerMessageBubblePressedImage;

/**
 *  客服消息气泡pressed图片
 */
@property (nonatomic, strong) UIImage *serviceMessageBubblePressedImage;

/**
 *  消息竖直方向间距
 */
@property (nonatomic, assign) CGFloat sessionMessageSpacing;

/**
 *  默认是YES,默认进入聊天界面，是文本输入模式的话，会弹出键盘，设置为NO，可以修改为不弹出
 */
@property (nonatomic, assign) BOOL isShowKeyboard;

@end
