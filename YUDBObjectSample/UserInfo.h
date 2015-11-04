//
//  UserInfo.h
//  YUDBObject
//
//  Created by BruceYu on 15/8/12.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YUDBFramework/DBOBject.h>


@interface UserInfo : DBObject 

@property (strong,nonatomic)NSString *name;

@property (strong,nonatomic)NSString *phone;

@property (assign,nonatomic)int age;

@property (assign,nonatomic)int sex;

@end
