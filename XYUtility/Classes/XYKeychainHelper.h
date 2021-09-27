//
//  XYKeychainHelper.h
//  XYToolKit
//
//  Created by robbin on 2021/8/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// keychain 存储工具类
@interface XYKeychainHelper : NSObject

/// 设置一个值
/// @param value 值，为空表示删除
/// @param key 键，不能为空
+ (BOOL)keychainSetValue:(nullable NSString *)value key:(NSString *)key;

/// 获取一个值
/// @param key 键，不能为空
+ (nullable NSString *)keychainGetValueWithKey:(NSString *)key;

/// 是否有对应的值
/// @param key 键，不能为空
+ (BOOL)hasValueWithKey:(NSString *)key;

/// 删除一个值
/// @param key 键，不能为空
+ (BOOL)removeValueWithKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
