//
//       \\     //    ========     \\    //
//        \\   //          ==       \\  //
//         \\ //         ==          \\//
//          ||          ==           //\\
//          ||        ==            //  \\
//          ||       ========      //    \\
//
//  NSObject+YUModel.m
//  https://github.com/c6357/YUDBModel
//
//  Created by BruceYu on 15/8/18.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 反序列化json自定义操作（通常用于NSArray和特殊处理）
 
 @param key key值
 @param value value值
 @return 根据key和value返回相应的对象
 
 e.g.
 -(void)deserialize:(NSDictionary *)dictionary
 {
     [super deserialize:dictionary arrayParser:^id(NSString *key,id value) {
     
         if ([key isEqualToString:@"list"]) {
         
            return [UserInfo class];
         }
         
         else if ([key isEqualToString:@"array"]) {
         
            return @[@"1",@"2",@"3"];//自定义数组
         }
         
         else if ([key isEqualToString:@"name"]) {
 
            return @"自定义名字";
         }
         
         return nil;
     }];
 }
  详情见：https://github.com/c6357/YUDBModel
 */

typedef id (^arrayParserWithObj)(NSString *key,id value);


#pragma mark -
#pragma mark - 反序列化 支持NSCoding协议
/**
 对象和json的相互转换
 */
@interface NSObject (YUModel)<NSCoding>


/**
 反序列化 把json转换成NSObject对象

 @param dictionary dictionary
 */

-(void)deserialize:(NSDictionary*)dictionary;

-(void)deserialize:(NSDictionary*)dictionary
       arrayParser:(arrayParserWithObj)arrayParser;

/**
 序列化 把NSObject对象转换成json

 @return dictionary
 */
-(NSDictionary *)dictionary;



/**
 description

 @return return class description
 */
//-(NSString *)description;

@end
