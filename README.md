# XYUtility

[![CI Status](https://img.shields.io/travis/irobbin1024/XYUtility.svg?style=flat)](https://travis-ci.org/irobbin1024/XYUtility)
[![Version](https://img.shields.io/cocoapods/v/XYUtility.svg?style=flat)](https://cocoapods.org/pods/XYUtility)
[![License](https://img.shields.io/cocoapods/l/XYUtility.svg?style=flat)](https://cocoapods.org/pods/XYUtility)
[![Platform](https://img.shields.io/cocoapods/p/XYUtility.svg?style=flat)](https://cocoapods.org/pods/XYUtility)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.


## Usage

### 一. XYUtility的说明

XYUtility是一组常用工具类的集合，包括如下功能

- KVO监控
- 后台任务运行
- keychain存储
- 图片、视频写入相册
- 弱引用代理

### 二. 集成

```
pod 'XYUtility'
```

### 三. 使用

#### KVO监控

这个组件解决了KVO监控使用复杂，监控和取消监控不小心还容易闪退的问题

##### step1: 开始监控

```
[lis observe:person keyPath:@"age" block:^(id  _Nonnull newValue) {

    NSLog(@"newValue: %@", newValue);

}];
```

##### step3: 页面销毁，取消监控

```
[self.KVOListener unobserveAll];
```

#### 后台任务运行

##### step1: 进入后台

```
self.backgroundTaskId = [XYBackgroundTaskHelper beginBackgroundTask:^{

     

}];
```

##### step2: 退出后台

```
[XYBackgroundTaskHelper endBackgroundTask:self.backgroundTaskId];

self.backgroundTaskId = UIBackgroundTaskInvalid;
```

#### keychain存储

提供key-value形式存储

##### 0x01 设置一个值

```
[XYKeychainHelper keychainSetValue:value key:key];
```

##### 0x02 获取一个值

```
id value = [XYKeychainHelper keychainGetValueWithKey:key];
```

##### 0x03 是否有对应的值

```
BOOL hasValue = [XYKeychainHelper hasValueWithKey:key];
```

##### 0x04 删除一个值

```
BOOL deleteResult = [XYKeychainHelper removeValueWithKey:key];
```

#### 图片、视频写入相册

##### 0x01 保存视频到自定义相册

```
[XYPhotoLibraryHelper xy_saveVideo:[NSURL fileURLWithPath:_currentExportingFilePath] toCustomAlbum:albumName completionBlockWithLocalIdentifier:^(NSURL * _Nonnull assetURL, NSError * _Nonnull error, NSString * _Nonnull localIdeitifier) {

    

}];
```

##### 0x02 保存图片到自定义相册

```
[XYPhotoLibraryHelper xy_saveImage:[NSURL fileURLWithPath:_currentExportingFilePath] toCustomAlbum:albumName completionBlock:^(NSURL * _Nullable assetURL, NSError * _Nullable error, NSString * _Nullable localIdeitifier) {

    

}];
```

#### 弱引用代理

主要是给一些需要弱引用的场景使用，例如弱引用数组结构、解除NSTimer循环引用等

```
XYWeakProxy * weakProxy = [XYWeakProxy proxyWithTarget:self];



 [NSTimer scheduledTimerWithTimeInterval:0.1 target: weakProxy selector:@selector(targetMethod:) userInfo:nil repeats:YES];



- (void)dealloc {

    // 在dealoc中关闭timer非常方便，不用weakProxy的话，因为timer引用了self，导致self无法dealloc，需要在diddisappear和didappear中处理很多timer相关逻辑，非常麻烦

    [self.timer invalidate];

}
```

## Author

irobbin1024, longbin.lai@quvideo.com

## License

XYUtility is available under the MIT license. See the LICENSE file for more info.
