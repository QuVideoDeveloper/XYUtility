//
//  XYKeychainHelper.m
//  XYToolKit
//
//  Created by robbin on 2021/8/2.
//

#import "XYKeychainHelper.h"
#import <Security/Security.h>

@implementation XYKeychainHelper

NSMutableDictionary* keychainGetSearchDictionary(NSString *key)
{
    NSMutableDictionary *dictionary = [NSMutableDictionary dictionary];
    dictionary[(__bridge id)kSecClass] = (__bridge id)kSecClassGenericPassword;
    
    NSData *encodedIdentifier = [key dataUsingEncoding:NSUTF8StringEncoding];
    
    dictionary[(__bridge id)kSecAttrGeneric] = encodedIdentifier;
    dictionary[(__bridge id)kSecAttrAccount] = encodedIdentifier;
    
    NSString *serviceName = [NSBundle mainBundle].bundleIdentifier;
    dictionary[(__bridge id)kSecAttrService] = serviceName;
    
    return dictionary;
}

+ (BOOL)keychainSetValue:(NSString *)value key:(NSString *)key {
    NSMutableDictionary *searchDictionary = keychainGetSearchDictionary(key);
    NSData * data = [value dataUsingEncoding:NSUTF8StringEncoding];
    OSStatus status = errSecSuccess;
    CFTypeRef ignore;
    if (SecItemCopyMatching((__bridge CFDictionaryRef)searchDictionary, &ignore) == errSecSuccess)
    { // Update
        if (!data)
        {
            status = SecItemDelete((__bridge CFDictionaryRef)searchDictionary);
        } else {
            NSMutableDictionary *updateDictionary = [NSMutableDictionary dictionary];
            updateDictionary[(__bridge id)kSecValueData] = data;
            status = SecItemUpdate((__bridge CFDictionaryRef)searchDictionary, (__bridge CFDictionaryRef)updateDictionary);
        }
    }
    else if (data)
    { // Add
        searchDictionary[(__bridge id)kSecValueData] = data;
        status = SecItemAdd((__bridge CFDictionaryRef)searchDictionary, NULL);
    }
    if (status != errSecSuccess)
    {
        return NO;
        NSLog(@"XYStoreKeychainPersistence: failed to set key %@ with error %ld.", key, (long)status);
    }
    return YES;
}

+ (NSString *)keychainGetValueWithKey:(NSString *)key {
    NSMutableDictionary *searchDictionary = keychainGetSearchDictionary(key);
    searchDictionary[(__bridge id)kSecMatchLimit] = (__bridge id)kSecMatchLimitOne;
    searchDictionary[(__bridge id)kSecReturnData] = (id)kCFBooleanTrue;
    
    CFDataRef value = nil;
    OSStatus status = SecItemCopyMatching((__bridge CFDictionaryRef)searchDictionary, (CFTypeRef *)&value);
    if (status != errSecSuccess && status != errSecItemNotFound)
    {
        NSLog(@"XYStoreKeychainPersistence: failed to get key %@ with error %ld.", key, (long)status);
    }
    NSData * data = (__bridge NSData*)value;
    if (data) {
        return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    } else {
        return nil;
    }
}

+ (BOOL)hasValueWithKey:(NSString *)key {
    NSString * value = [self keychainGetValueWithKey:key];
    return value && [value isKindOfClass:NSString.class] && value.length > 0;
}

+ (BOOL)removeValueWithKey:(NSString *)key {
    return [self keychainSetValue:nil key:key];
}

@end
