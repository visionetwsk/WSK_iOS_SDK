//
//  WSKUserVo.h
//  Sloth
//
//  Created by Ann Yao on 12-9-11.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WSKUserVo : NSObject

@property(nonatomic,strong)NSString *userID;                //用户ID,客户openId
@property(nonatomic,strong)NSString *userName;              //用户真实姓名或别名
@property(nonatomic,strong)NSString *headerImageURL;            //用户头像
@property(nonatomic)NSInteger gender;                       //性别，1：男、2：女
@property(nonatomic,strong)NSString *phoneNumber;           //手机
@property(nonatomic,strong)NSString *telephone;             //固定电话
@property(nonatomic,strong)NSString *email;                 //邮箱

@property(nonatomic,strong)NSString *address;               //地址
@property(nonatomic,strong)NSString *position;              //职位
@property(nonatomic,strong)NSString *department;            //单位
@property(nonatomic,strong)NSString *birthday;              //生日(yyyy-MM-dd)
@property(nonatomic,strong)NSString *remark;                //备注

@end
