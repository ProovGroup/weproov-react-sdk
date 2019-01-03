require 'json'

package = JSON.parse(File.read(File.join(__dir__, 'package.json')))

Pod::Spec.new do |s|
  s.name         = "RNWeproov"
  s.version      = package['version']
  s.summary      = "RNWeproov"
  s.description  = <<-DESC
                  RNWeproov
                   DESC
  s.homepage     = "https://weproov.com"
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author             = { "author" => "author@domain.cn" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/ProovGroup/RNWeproov.git", :tag => "master" }
  s.source_files  = "ios/*.{h,m}"
  s.requires_arc = true

  s.dependency "React"
  s.dependency "WeProovSDK"

end

  