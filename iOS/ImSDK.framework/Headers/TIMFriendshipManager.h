//
//  TIMFriendshipManager.h
//  imsdk
//
//  Created by annidyfeng on 2019/3/7.
//  Copyright © 2019年 Tencent. All rights reserved.
//

#ifndef TIMFriendshipManager_h
#define TIMFriendshipManager_h

#import "TIMComm.h"
#import "TIMFriendshipDefine.h"

@interface TIMFriendshipManager : NSObject
/**
 *  获取好友管理器实例
 *
 *  @return 管理器实例
 */
+ (TIMFriendshipManager*)sharedInstance;

/**
 *  设置自己的资料
 *
 *  @param values    需要更新的属性，可一次更新多个字段. 参见 TIMFriendshipDefine.h 的 TIMProfileTypeKey_XXX
 *  @param succ 成功回调
 *  @param fail 失败回调
 *
 *  @return 0 发送请求成功
 */
- (int)modifySelfProfile:(NSDictionary<NSString *, id> *)values succ:(TIMSucc)succ fail:(TIMFail)fail;

/**
 *  获取自己的资料
 *
 *  @param succ  成功回调，返回 TIMUserProfile
 *  @param fail  失败回调
 *
 *  @return 0 发送请求成功
 */
- (int)getSelfProfile:(TIMGetProfileSucc)succ fail:(TIMFail)fail;

/**
 *  获取指定好友资料
 *
 *  @param users 用户id
 *  @prarm forceUpdate 强制从后台拉取
 *  @param succ 成功回调
 *  @param fail 失败回调
 *
 *  @return 0 发送请求成功
 */
- (int)getUsersProfile:(NSArray<NSString *> *)users forceUpdate:(BOOL)forceUpdate succ:(TIMGetProfileArraySucc)succ fail:(TIMFail)fail;


/**
 *  获取好友列表
 *
 *  @param succ 成功回调，返回好友列表
 *  @param fail 失败回调
 *
 *  @return 0 发送请求成功
 */
-(int)getFriendList:(TIMGetFriendSucc)succ fail:(TIMFail)fail;


/**
 *  添加好友
 *
 *  @param request 添加好友请求
 *  @param succ  成功回调
 *  @param fail  失败回调
 *
 *  @return 0 发送请求成功
 */
- (int)addFriend:(TIMFriendRequest *)request succ:(TIMSucc)succ fail:(TIMFail)fail;

/**
 *  响应对方好友邀请
 *
 *  @param response  响应请求
 *  @param succ      成功回调
 *  @param fail      失败回调
 *
 *  @return 0 发送请求成功
 */
- (int)doResponse:(TIMFriendResponse *)response succ:(TIMSucc)succ fail:(TIMFail)fail;

/**
 *  删除好友
 *
 *  @param user 要删除的好友的 identifier
 *  @param delType 删除类型（单向好友、双向好友）
 *  @param succ  成功回调
 *  @param fail  失败回调
 *
 *  @return 0 发送请求成功
 */
- (int)delFriend:(NSString *)user delType:(TIMDelFriendType)delType succ:(TIMSucc)succ fail:(TIMFail)fail;

/**
 *  设置好友的资料
 *
 *  @param identifier 好友的 identifier
 *  @param values  需要更新的属性，可一次更新多个字段. 参见 TIMFriendshipDefine.h 的 TIMUserTypeKey_XXX
 *  @param succ 成功回调
 *  @param fail 失败回调
 *
 *  @return 0 发送请求成功
 */
- (int)modifyUserProfile:(NSString *)identifier values:(NSDictionary<NSString *, id> *)values succ:(TIMSucc)succ fail:(TIMFail)fail;

@end

#endif /* TIMFriendshipManager_h */
