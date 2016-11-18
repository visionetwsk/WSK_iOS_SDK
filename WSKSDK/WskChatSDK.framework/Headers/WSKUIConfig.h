//
//  WSKUIConfig.h
//  WSKChatSDK
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
 *  客户文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *customMessageTextColor;

/**
 *  客服文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *serviceMessageTextColor;

/**
 *  客户文本消息内嵌链接字体颜色
 */
@property (nonatomic, strong) UIColor *customMessageLinkTextColor;

/**
 *  客服文本消息内嵌链接字体颜色
 */
@property (nonatomic, strong) UIColor *serviceMessageLinkTextColor;

/**
 *  提示文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *tipMessageTextColor;

/**
 *  提示文本消息背景颜色
 */
@property (nonatomic, strong) UIColor *tipMessageBackgroundColor;

/**
 *  输入框文本消息字体颜色
 */
@property (nonatomic, strong) UIColor *inputTextColor;

/**
 *  消息时间颜色
 */
@property (nonatomic, strong) UIColor *messageTimeColor;

/**
 *  消息tableview的背景图片
 */
@property (nonatomic, strong) UIImageView *chatBackground;

/**
 *  客户头像
 */
@property (nonatomic, strong) UIImage *customerHeadImage;

/**
 *  客户消息气泡normal图片
 */
@property (nonatomic, strong) UIImage *customerMessageBubbleNormalImage;

/**
 *  客服消息气泡normal图片
 */
@property (nonatomic, strong) UIImage *serviceMessageBubbleNormalImage;

/**
 *  客户消息气泡pressed图片
 */
@property (nonatomic, strong) UIImage *customerMessageBubblePressedImage;

/**
 *  客服消息气泡pressed图片
 */
@property (nonatomic, strong) UIImage *serviceMessageBubblePressedImage;

/**
 *  默认是YES,默认进入聊天界面，是文本输入模式的话，会弹出键盘，设置为NO，可以修改为不弹出
 */
@property (nonatomic, assign) BOOL isShowKeyboard;

@end
