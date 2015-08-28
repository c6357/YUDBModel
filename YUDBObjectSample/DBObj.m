//
//  DBObj.m
//  YUDBObject
//
//  Created by BruceYu on 15/8/18.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//

#import "DBObj.h"

@implementation DBObj

+(NSString *)dbName{
    return @"base.db";
}

+(NSString *)dbFolder{
    return [NSObject createFileDirectories:@"base"];
}

+(NSArray *)dbIgnoreFields{
    return @[];
}

//Deserialize json -> Class
-(void)Deserialize:(NSDictionary *)_dict
{
    [super Deserialize:_dict arrayParserObj:^Class(NSString *field) {
        if ([field isEqualToString:@"infoArry"]) {
            return [UserInfo class];
        }
        return nil;
    }];
}

@end
