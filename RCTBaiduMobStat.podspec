require 'json'

package = JSON.parse(File.read(File.join(__dir__, 'package.json')))

Pod::Spec.new do |s|
  s.name         = "RCTBaiduMobStat"
  s.version      = package['version']
  s.summary      = package['description']
  s.license      = package['license']

  s.authors      = package['author']
  s.homepage     = package['homepage']
  s.platforms    = { :ios => "9.0", :tvos => "9.2", :osx => "10.14" }

  s.source       = { :git => "https://github.com/BaiduMobileAnalysis/baidumobstat-react-native.git" }
  s.source_files  = "ios/RCTBaiduMobStat/**/*.{h,m}"

  s.dependency 'React'
end
