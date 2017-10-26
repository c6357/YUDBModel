
Pod::Spec.new do |s|
  s.name         = "YUDBModel"
  s.version      = "2.0.4"
  s.summary      = "【绿色插件】-对象序列化、反序列化、对象一键增删改查"
  s.homepage     = "https://github.com/c6357/YUDBModel"
  s.license      = "MIT"
  s.author       = { "BruceYu" => "c6357@outlook.com" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/c6357/YUDBModel.git", :tag => s.version}
  s.ios.vendored_frameworks = 'YUDBModel.framework'
  s.library = 'sqlite3'
  s.frameworks = 'Foundation'
  s.requires_arc = true
end
