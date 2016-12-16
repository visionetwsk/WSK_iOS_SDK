//
//  WSKCommodityVo.h
//  WSKChatSDK
//
//  Created by 焱 孙 on 2016/12/15.
//  Copyright © 2016年 焱 孙. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  商品详情信息展示
 */
@interface WSKCommodityVo : NSObject

@property(nonatomic,strong)NSString *title;               //标题
@property(nonatomic,strong)NSString *desc;                //描述
@property(nonatomic,strong)NSString *imageUrlString;      //图片URL字符串
@property(nonatomic,strong)NSString *urlString;           //商品跳转URL

@end
