//
//  UserInfo.m
//  YUDBObject
//
//  Created by yuzhx on 15/8/12.
//  Copyright (c) 2015年 C6357. All rights reserved.
//

#import "UserInfo.h"


@implementation UserInfo

+(NSString *)dbName{
    return @"User.db";
}

+(NSString *)dbFolder{
    return [NSObject createFileDirectories:@"user"];
}

+(NSArray *)dbIgnoreFields{
    return @[];
}
@end
