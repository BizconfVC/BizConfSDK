#
# Be sure to run `pod lib lint BizConfSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'BizConfSDK'
  s.version          = '1.0.0'
  s.summary          = '会畅通讯会议SDK'
  s.description      = <<-DESC
  会畅通讯会议SDK是一款云视频会议产品，满足企业全员对远程协同办公的高品质视频会议需要且具备音视频互动，屏幕共享，会议安全，企业直播，电话入会及同声传译等功能；支持全场景终端覆盖，包括Windows、Android、iOS、macOS及会议室终端
                       DESC

  s.homepage         = 'https://github.com/BizconfVC'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'liuhongfei' => 'hongfei_liu@bizconf.cn' }
  s.source           = { :git => 'https://github.com/BizconfVC/BizConfSDK.git', :tag => s.version.to_s }
  s.platform         = :ios
  s.ios.deployment_target = '12.0'
  s.xcconfig              = { "BUILD_LIBRARY_FOR_DISTRIBUTION" => "YES" }
  s.pod_target_xcconfig   = { "VALID_ARCHS" => "arm64 armv7 x86_64", "DEFINES_MODULE" => "YES" }
  s.user_target_xcconfig  = { "VALID_ARCHS" => "arm64 armv7 x86_64", "DEFINES_MODULE" => "YES" }
  s.vendored_frameworks   = 'BizConfSDK/Classes/BizConfSDK.xcframework'
  
  s.dependency 'HFUtils', '0.1.4'
  s.dependency 'HFLogBeaver', '1.0.0'
  s.dependency 'HFNetWorking', '0.1.1'
  s.dependency 'FcrUIScene', '3.4.2.1'
  
end
