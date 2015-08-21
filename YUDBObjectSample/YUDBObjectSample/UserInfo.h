//
//  UserInfo.h
//  YUDBObject
//
//  Created by yuzhx on 15/8/12.
//  Copyright (c) 2015年 C6357. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <YUDBFramework/DBOBject.h>


@interface UserInfo : DBOBject 

@property (assign,nonatomic)int age;

@property (strong,nonatomic)NSString *name;

@property (strong,nonatomic)NSString *phone;

@property (assign,nonatomic)int sex;

@end
