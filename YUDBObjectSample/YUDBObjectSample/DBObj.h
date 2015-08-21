//
//  DBObj.h
//  YUDBObject
//
//  Created by BruceYu on 15/8/18.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//


#import <YUDBFramework/DBOBject.h>
#import "UserInfo.h"


@interface DBObj : DBOBject

@property (strong,nonatomic)NSString *name;

@property (strong,nonatomic)NSString *phone;

@property (strong,nonatomic)UserInfo *info;

@property (strong,nonatomic)NSArray *infoArry;

@end
