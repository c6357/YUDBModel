
Pod::Spec.new do |s|
  s.name         = "YUDBModel"
  s.version      = "1.0.1"
  s.summary      = "【绿色插件】-对象序列化、反序列化、对象一键增删改查"
  s.homepage     = "https://github.com/c6357/YUDBModel"
  s.license      = "MIT"
  s.author             = { "BruceYu" => "email@address.com" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/c6357/YUDBModel.git", :tag => "#{s.version}" }
  #s.source_files  = "Classes", "Classes/**/*.{h,m}"
  #s.exclude_files = "Classes/Exclude"
  # s.framework  = "SomeFramework"

  s.ios.vendored_frameworks = 'YUDBModel/YUDBModel.framework'
  s.requires_arc = true

end
