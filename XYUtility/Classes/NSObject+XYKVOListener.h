//
//  NSObject+XYKVOListener.h
//  AWSCore
//
//  Created by Frenzy Feng on 2019/12/2.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYKVOListener.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (XYKVOListener)

/**
 @abstract Lazy-loaded XYKVOListener for use with any object
 @return FBKVOController associated with this object, creating one if necessary
 @discussion This makes it convenient to simply create and forget a FBKVOController, and when this object gets dealloc'd, so will the associated controller and the observation info.
 */
@property (nonatomic, strong) XYKVOListener *KVOListener;
@property (nonatomic, strong) XYKVOListener *KVOListenerNonRetaining;

/// 注册观察者对象
/// @param object 观察对象
/// @param keyPath 观察属性
/// @param block 变化回调block
- (void)observe:(id)object keyPath:(NSString *)keyPath block:(void(^)(id newValue))block;

@end

NS_ASSUME_NONNULL_END
