Pod::Spec.new do |s|

  s.name     = 'WSK_iOS_SDK'
  s.version  = '1.0.5'
  s.license  = { :"type" => "Copyright",
                 :"text" => " Copyright 2018 Visionet \n"}
  s.homepage = 'http://weisk.com/'
  s.author   = { 'sunyan' => 'sunyan@visionet.com.cn' }
  s.summary  = '微企微上客客服访客端 iOS SDK'
  
  s.platform = :ios
  s.ios.deployment_target  = '8.0'

  s.source   = { :git => 'https://github.com/visionetwsk/WSK_iOS_SDK.git', :tag => "1.0.5" }
  s.resource  = ['WSKSDK/WSKResource.bundle']
  s.vendored_frameworks = 'WSKSDK/*.{framework}'
  
  s.framework = 'UIKit','MobileCoreServices','SystemConfiguration','AVFoundation','CoreGraphics','ImageIO','CoreFoundation','UserNotifications'
  s.libraries = 'stdc++.6.0.9'

  s.requires_arc = true
  s.dependency 'Socket.IO-Client-Swift', '13.1.2'

  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  
end
