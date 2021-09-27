//
//  XYBackgroundTaskHelper
//  XYToolKit
//
//  Created by robbin on 2019/3/26.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYBackgroundTaskHelper : NSObject

/// 开始后台任务
/// @param handler 任务执行block
+ (UIBackgroundTaskIdentifier)beginBackgroundTask:(void(^ __nullable)(void))handler;

/// 结束后台任务
/// @param backgroundTaskId 任务标识
+ (void)endBackgroundTask:(UIBackgroundTaskIdentifier)backgroundTaskId;

@end

NS_ASSUME_NONNULL_END
