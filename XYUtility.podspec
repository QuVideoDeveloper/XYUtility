
Pod::Spec.new do |s|
  s.name             = 'XYUtility'
  s.version          = '0.1.0'
  s.summary          = 'A short description of XYUtility.'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/QuVideoDeveloper/XYUtility'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'irobbin1024' => 'longbin.lai@quvideo.com' }
  s.source           = { :git => 'https://github.com/QuVideoDeveloper/XYUtility.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  s.source_files = 'XYUtility/Classes/**/*'
end
