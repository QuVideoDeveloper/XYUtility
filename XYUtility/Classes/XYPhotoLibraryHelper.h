//
//  XYPhotoLibraryHelper.h
//  XYToolKit
//
//  Created by robbin on 2019/3/21.
//  Copyright (c) 2021 Hangzhou Xiaoying Innovation Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 相册操作错误类型
typedef NS_ENUM(NSInteger, XYPhotoLibraryErrorCode) {
    XYPhotoLibraryErrorNone,
    XYPhotoLibraryErrorInvalidFileUrl,
    XYPhotoLibraryErrorCreateAssetFailed,
    XYPhotoLibraryErrorSaveAssetFailed,
    XYPhotoLibraryErrorGetAssetUrlFailed,
};

NS_ASSUME_NONNULL_BEGIN

/// 完成回调定义
typedef void (^XYPhotoLibrarySaveCompletionBlock)(NSURL * _Nullable assetURL, NSError * _Nullable error);
/// 完成回调定义(带有本地标识)
typedef void (^XYPhotoLibrarySaveCompletionBlockWithLocalIdetifier)(NSURL * _Nullable assetURL, NSError * _Nullable error, NSString * _Nullable localIdeitifier);

/// 相册操作工具类
@interface XYPhotoLibraryHelper : NSObject

/**
 保存视频到系统相册

 @param videoUrl 视频地址
 @param albumName 相册名称
 @param block 回调方法(带有本地标识)
 */
+ (void)xy_saveVideo:(NSURL *)videoUrl
       toCustomAlbum:(NSString *)albumName
     completionBlockWithLocalIdentifier:(XYPhotoLibrarySaveCompletionBlockWithLocalIdetifier)block ;

/**
 保存图片到系统相册

 @param imageUrl 图片地址
 @param albumName 相册名称
 @param block 回调方法(带有本地标识)
 */
+ (void)xy_saveImage:(NSURL *)imageUrl
       toCustomAlbum:(NSString *)albumName
     completionBlockWithLocalIdentifier:(XYPhotoLibrarySaveCompletionBlockWithLocalIdetifier)block;

/**
 保存视频到系统相册（已废弃）

 @param videoUrl 视频地址
 @param albumName 相册名称
 @param block 回调方法
 */
+ (void)xy_saveVideo:(NSURL *)videoUrl
       toCustomAlbum:(NSString *)albumName
     completionBlock:(XYPhotoLibrarySaveCompletionBlock)block __attribute__((deprecated("已废弃，建议使用 -xy_saveVideo:toCustomAlbum:completionBlockWithLocalIdentifier:")));

/**
 保存图片到系统相册（已废弃）

 @param imageUrl 图片地址
 @param albumName 相册名称
 @param block 回调方法
 */
+ (void)xy_saveImage:(NSURL *)imageUrl
       toCustomAlbum:(NSString *)albumName
     completionBlock:(XYPhotoLibrarySaveCompletionBlock)block __attribute__((deprecated("已废弃，建议使用 -xy_saveImage:toCustomAlbum:completionBlockWithLocalIdentifier:")));

@end

NS_ASSUME_NONNULL_END
