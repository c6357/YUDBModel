//
//       \\     //    ========     \\    //
//        \\   //          ==       \\  //
//         \\ //         ==          \\//
//          ||          ==           //\\
//          ||        ==            //  \\
//          ||       ========      //    \\
//
//  DBBaseObject.h
//  YUDBObject
//
//  Created by BruceYu on 15/8/19.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMDB.h"
#import "NSObject+Constant.h"

/*
 * DBObject base cass
 */
@interface DBBaseObject : NSObject



/*
 *  Model to save data, set the fields you want to ignore
 */
+(NSArray *)dbIgnoreFields;

/*
 */
//-(void)copyTo:(NSObject*)dest;


/*
 *Deserialize json -> Class
 */
-(void)Deserialize:(NSDictionary*)_dict;

-(void)Deserialize:(NSDictionary*)_dict arrayParserObj:(DB_Block_ParserForArray)_parser;

-(void)Deserialize:(NSDictionary*)_dict coustom:(DB_Block_Dealize_Parser)_custParser;

-(void)Deserialize:(NSDictionary *)_dict
    arrayObjParser:(DB_Block_ParserForArray)_parser
arrayObjCustParser:(DB_Block_Dealize_Parser)_custParser;

/*
 *Deserialize DB file
 */
-(void)DeserializeFromDBResult:(FMResultSet*)reslut;


/*
 *Delete with keyName
 */
-(void)deleteWithKey:(NSString*)keyName;

-(void)deleteWtihConstraints:(NSArray*)keyNames;


/*
 *Save with key
 */
-(BOOL)save:(NSString*)keyName;
-(BOOL)saveWtihConstraints:(NSArray*)keyNames;


/*
 *Serialize Class -> json
 */
-(NSDictionary *)dictory;

-(NSDictionary *)dictoryProperties;
@end
