# 微企微上客 iOS SDK 开发指南
## 简介

微企微上客 iOS SDK 是客服系统访客端的解决方案，既包含了客服聊天逻辑管理，也提供了聊天界面，开发者可方便的将客服功能集成到自己的 APP 中。iOS SDK 支持 iOS 8 以上版本，同时支持iPhone、iPad以及横竖屏UI。在iOS 9.2 以上版本中支持 IPv6，能正常通过苹果审核。

## SDK 目录讲解
 下载完 微上客 SDK，得到如下两部分：
 
 * WSKChatSDK.framework：静态库Framework,包含静态库文件和SDK的头文件
 * WSKResource.bundle：SDK的资源文件包
 
 >由于 SDK 是静态库，且为了方便开发者使用，我们将 i386、x86_64、armv7、arm64 平台的静态库合并成一个 Fat Library ，导致整个 SDK 比较大。但实际编译后大约只会增加 app 2-3M 大小

## 系统要求以及依赖第三方框架
* 系统要求  
该项目最低支持 iOS 8.0 和 Xcode 8.0。

* 依赖第三方框架  
微上客SDK 依赖 [Socket.IO-Client-Swift](https://github.com/socketio/socket.io-client-swift) 库，如果选择手动集成微上客SDK则需要用CocoaPods引入Socket.IO库，选择CocoaPods集成则不需要手动添加依赖处理。

## SDK 集成和配置

### 手动集成

* 下载 微上客 SDK，得到一个 WSKChatSDK.framework 文件、 WSKResource.bundle 文件夹，将他们导入工程
* 添加 微上客 SDK 依赖库

	* UIKit.framework
	* MobileCoreService.framework
	* SystemConfiguration.framework
	* AVFoundation.framwork
	* CoreGraphics.framework
	* ImageIO.framework
	* CoreFoundation.framework
	* UserNotifications.framework
	* libstdc++.6.0.9.tbd

* 添加第三方库：在Podfile中添加Socket.IO的依赖， pod 'Socket.IO-Client-Swift', '~> 8.0.2'

* 在 Build Settings -> Other Linker Flags 中添加 -ObjC 

### CocoaPods集成

在 Podfile 文件中加入 

```
	pod 'WSK_iOS_SDK', '~> 0.0.2'
```
> 推荐使用CocoaPods集成，因为只需在Podfile中加入上面一句即可

### 配置工程

*  允许App支持Http传输方法，由于SDK与服务器之间有部分请求使用的是http。在Info.plist中加入以下内容：

```
	<key>NSAppTransportSecurity</key>
	<dict>
		<key>NSAllowsArbitraryLoads</key>
		<true/>
	</dict>
```

* iOS10 权限设置,在Info.plist中加入以下内容：  

 ```
	<key>NSCameraUsageDescription</key>
	<string>App需要您的同意,才能访问相机</string>  
	<key>NSMicrophoneUsageDescription</key>  
	<string>App需要您的同意,才能访问麦克风</string>  
	<key>NSPhotoLibraryUsageDescription</key>  
	<string>App需要您的同意,才能访问相册</string>
```

* SDK 不支持 bitcode  
向 Build Settings → Linking → Enable Bitcode 中设置 NO。


## 使用详解

### 使用简介

* 在需要使用 SDK 的地方 #import \<WskChatSDK/WskChatSDK.h>。WSKSDK 类是整个SDK的唯一主入口，是一个单例。各个函数简介：
 
```objc
	初始化：
		- (void)registerAppKey:(NSString *)appKey appName:(NSString *)appName;
		
	集成客户聊天组件：
		- (WSKChatViewController *)chatViewController;
		
	自定义客户端聊天组件UI效果：
		- (WSKUIConfig *)customUIConfig;
		
	APNS推送：
		- (void)updateApnsToken:(NSData *)token;
		
	注销：
		- (void)logout:(WSKCompletionBlock)completion;

	设置用户信息
		- (void)setUserInfo:(WSKUserVo *)userVo;
		
```

### 初始化

```objc
	- (BOOL)application:(UIApplication *)application 
							didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 
	{
		......
		
		[[WSKSDK sharedSDK] registerAppKey:appKey appName:App名称];
	    
	    ......
	    
	    return YES;
	}
```
appKey可以在“管理后台” -> “设置” -> “App接入” -> “2. App Key” 找到, appName对应管理后台添加一个 app 时填写的 App 名称。

### 设置用户信息
设置个人信息，用户帐号登录成功之后，调用此函数。如果不设置用户信息，则使用匿名用户的方式进行客服咨询。应该在进入聊天咨询界面之前设置用户信息。

```objc
	WSKUserVo *userVo = [[WSKUserVo alloc]init];
	userVo.strUserID = @"45471429666";
	userVo.strUserName = @"iOS_SDK_用户1";
	[[WSKSDK sharedSDK] setUserInfo:userVo];
```

### 集成客户聊天组件

```objc
	[[WSKSDK sharedSDK] chatViewController];
```

应用层获取此 chatViewController 之后，必须嵌入到 UINavigationcontroller 中，就可以获得聊天窗口的UI以及所有功能。 chatViewController 只会使用到导航栏的 self.navigationItem.title。 self.navigationItem.title 放置标题栏； 必须注意，不能在 chatViewController 外层套其他 viewController 之后再嵌入到 UINavigationcontroller。

如果调用代码所在的viewController在UINavigationcontroller中，可以如下方式集成（第一种集成方式）：

```objc

    WSKChatViewController *chatViewController = [[WSKSDK sharedSDK] chatViewController];
    chatViewController.chatTitle = @"微上客SDK测试";
    chatViewController.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController: chatViewController animated:YES];
    
```

如果调用代码所在的viewController不在UINavigationcontroller中，可如下方式集成（第二种集成方式）：

```objc
    WSKChatViewController *chatViewController = [[WSKSDK sharedSDK] chatViewController];
    chatViewController.chatTitle = @"微上客SDK测试";
    chatViewController.hidesBottomBarWhenPushed = YES;
    
    UINavigationController *navController  = [[UINavigationController alloc] initWithRootViewController:chatViewController];
    [self presentViewController:navController animated:YES completion:nil];
```
一般来说，第二种方式会需要在左上角加一个返回按钮，在 “initWithRootViewController:chatViewController” 之前加上：

```objc
    chatViewController.navigationItem.leftBarButtonItem = 
    			[[UIBarButtonItem alloc] initWithTitle:@"返回" style:UIBarButtonItemStyleBordered 
    								target:self action:@selector(onBack:)];
```

“onBack” 的样例：

```objc
- (void)onBack:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}
```
    								
如果您的代码要求所有viewController继承某个公共基类，并且公共基类对UINavigationController统一做了某些处理；或者其他原因导致使用第一种方式集成会有问题；这些情况下，建议您使用第二种方式集成。

### 自定义访客端聊天组件UI效果

获取自定义UI类对象

```objc
	[[WSKSDK sharedSDK] customUIConfig];
```
WSKUIConfig是负责自定义UI的类；目前主要是定义聊天界面中的字体颜色、气泡图片、头像等。相关设置必须在集成客户聊天组件之前进行。
WSKUIConfig 只是负责替换部分皮肤相关内容，不包含所有的图片素材的替换,调整UI样例代码：

```objc
	/**
	 *  访客文本消息字体颜色
	 */
    [[WSKSDK sharedSDK] customUIConfig].customMessageTextColor = [UIColor blackColor];
    
    /**
	 *  客服文本消息字体颜色
	 */
    [[WSKSDK sharedSDK] customUIConfig].serviceMessageTextColor = [UIColor blackColor];
    
    /**
	 *  客户文本消息内嵌链接字体颜色
	 */
	[[WSKSDK sharedSDK] customUIConfig].customMessageLinkTextColor = [UIColor colorWithRed:128.0/255.0 green:233.0/255.0 blue:255.0/255.0 alpha:1.0];
	
	/**
	 *  客服文本消息内嵌链接字体颜色
	 */
	[[WSKSDK sharedSDK] customUIConfig].serviceMessageLinkTextColor = [UIColor colorWithRed:0.0/255.0 green:165.0/255.0 blue:224.0/255.0 alpha:1.0];
    
    /**
 	 *  提示文本消息字体颜色
 	 */
	[[WSKSDK sharedSDK] customUIConfig].tipMessageTextColor = [UIColor grayColor];

	/**
	 *  提示文本消息背景颜色
	 */
	[[WSKSDK sharedSDK] customUIConfig].tipMessageBackgroundColor = [UIColor whiteColor];
    
    /**
	 *  输入框文本消息字体颜色
	 */
	[[WSKSDK sharedSDK] customUIConfig].inputTextColor = [UIColor blackColor];

	/**
	 *  消息时间颜色
	 */
	[[WSKSDK sharedSDK] customUIConfig].messageTimeColor = [UIColor grayColor];

	/**
	 *  消息tableview的背景图片
	 */
    UIImageView *imageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"chat_bg"]];
    imageView.contentMode = UIViewContentModeScaleToFill;
    [[WSKSDK sharedSDK] customUIConfig].chatBackground = imageView;
    
	/**
	 *  客户头像
	 */
    [[WSKSDK sharedSDK] customUIConfig].customerHeadImage = [UIImage imageNamed:@"customer_avatar"];
    
    /**
	 *  客户消息气泡normal图片
	 */
    [[WSKSDK sharedSDK] customUIConfig].customerMessageBubbleNormalImage = 
										[[UIImage imageNamed:@"chat_send_text_bk"]
                                 resizableImageWithCapInsets:UIEdgeInsetsMake(26,26,26,26)
                                 resizingMode:UIImageResizingModeStretch];
                                 
    /**
	 *  客户消息气泡pressed图片
	 */
    [[WSKSDK sharedSDK] customUIConfig].customerMessageBubblePressedImage = 
    									[[UIImage imageNamed:@"chat_send_text_press_bk"]
                                  resizableImageWithCapInsets:UIEdgeInsetsMake(26,26,26,26)
                                  resizingMode:UIImageResizingModeStretch];
                                  
	/**
	 *  客服消息气泡normal图片
	 */
    [[WSKSDK sharedSDK] customUIConfig].serviceMessageBubbleNormalImage = 
    									[[UIImage imageNamed:@"chat_receive_text_bk"]
                                  resizableImageWithCapInsets:UIEdgeInsetsMake(26,26,26,26)
                                  resizingMode:UIImageResizingModeStretch];
                                  
    /**
	 *  客服消息气泡pressed图片
	 */
    [[WSKSDK sharedSDK] customUIConfig].serviceMessageBubblePressedImage = 
    									[[UIImage imageNamed:@"chat_receive_text_press_bk"]
                                  resizableImageWithCapInsets:UIEdgeInsetsMake(26,26,26,26)
                                  resizingMode:UIImageResizingModeStretch];
    
	/**
	 *  默认是YES,默认进入聊天界面，是文本输入模式的话，会弹出键盘，设置为NO，可以修改为不弹出
	 */
    [WSKUIConfig sharedInstance].isShowKeyboard = YES;
```

### APNS推送
* [制作推送证书并在管理后台配置](https://github.com/visionetwsk/WSK_iOS_SDK/wiki/iOS-证书-设置指南)
  
* Capabilities
如使用Xcode8及以上环境开发，请开启Application Target的Capabilities->Push Notifications选项，如图：  
![WSK_SDK_iOS](https://raw.githubusercontent.com/visionetwsk/Resource/master/image/capabilities_intro.png)


* 初始化

```objc
	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 
	{    
		......
		
		//传入正确的App名称
	   [[WSKSDK sharedSDK] registerAppKey:appKey appName:App名称];
	    
		//注册APNs推送
		if ([[UIDevice currentDevice].systemVersion floatValue] >= 10.0) {
		    [[UNUserNotificationCenter currentNotificationCenter] requestAuthorizationWithOptions:(UNAuthorizationOptionBadge | UNAuthorizationOptionSound | UNAuthorizationOptionAlert) completionHandler:^(BOOL granted, NSError * _Nullable error) {
		        if (!error) {
		            NSLog(@"request authorization succeeded!");
		        }
		    }];
		    [[UIApplication sharedApplication] registerForRemoteNotifications];
		} else {
		    //小于 iOS 10.0
		    UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound categories:nil];
		    [application registerUserNotificationSettings:settings];
		    [[UIApplication sharedApplication] registerForRemoteNotifications];
		}
		
		......
		
	    return YES;
	}
```

* 把 APNS Token 传给 SDK

```objc
	- (void)application:(UIApplication *)app 
					didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
	{
		......
		
	    [[WSKSDK sharedSDK] updateApnsToken:deviceToken];
	    
	    ......
	}
```

### 注销

```objc
	[[WSKSDK sharedSDK] logout:^{
        NSLog(@"注销成功！");
    }];
```

应用层退出自己的账号时需要调用 SDK 的注销操作，该操作会通知服务器进行 APNS 推送信息的解绑操作，避免用户已退出但推送依然发送到当前设备的情况发生。

## FAQ
如果集成过程中遇到任何问题，可查看 [FAQ](./iOS_FAQ.html "target=_blank")

## 补充说明

如果您看完此文档后，还有任何集成方面的疑问，可以参考下 iOS SDK Demo 源码:   <https://github.com/visionetwsk/WSK_iOS_SDK_Demo.git>。  
源码充分的展示了 iOS SDK 的能力，并且为集成 iOS SDK 提供了样例代码。



