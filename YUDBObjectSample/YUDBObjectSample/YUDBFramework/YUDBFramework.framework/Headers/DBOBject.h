//
//       \\     //    ========     \\    //
//        \\   //          ==       \\  //
//         \\ //         ==          \\//
//          ||          ==           //\\
//          ||        ==            //  \\
//          ||       ========      //    \\
//
//  DBObject.h
//  YUDBObject
//
//  Created by BruceYu on 15/8/12.
//  Copyright (c) 2015年 BruceYu. All rights reserved.
//

/* Database operations DBObject use:*/
/* .Inherited DBObject class*/


/*
 *  Support multiple data using FALASE OR TRUE
 
 *  Set TRUE customizable dbFolder () and dbName (), custom database location and file name
 
 *  Folder Path
 +(NSString*)dbFolder;
 *
 *  Database name
 +(NSString*)dbName;
 */


#import <Foundation/Foundation.h>
#import "YUDB/NSObject+DB.h"
#import "YUDB/DBBaseObject.h"


@interface DBObject : DBBaseObject

//Data creation time
@property (nonatomic,strong) NSString *createDate;

//Unique identifier ID, Warning: Do not modify and ignored
@property (nonatomic,strong) NSString *dId;

//Associated with the parent ID, used to query
@property (nonatomic,strong) NSString *parentId;


/*
 *  Folder Path 
 *  Default Sandbox project folder name
 */
+(NSString*)dbFolder;


/*
 *  Database name
 *  Default bundleName
 */
+(NSString*)dbName;


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
 *Deserialize DB data
 */
-(void)DeserializeFromDBResult:(FMResultSet*)reslut;

/*
 *Serialize Class -> json (depth Analytical Model)
 */
-(NSDictionary *)dictory;

/*
 *Serialize Class -> json (shallow Analytical Model)
 */
-(NSDictionary *)dictoryProperties;


/**
 *  save the model with keyName
 *
 *  @param obj      DBObject subClass
 *  @param keyName  select tableName where keyName = value,Search results, If present, the update, or the inserted
 *
 *  @return Save the result
 */
+(BOOL)save:(id)obj KeyName:(NSString*)keyName;


/**
 *  save the model with keyNames
 *
 *  @param obj      DBObject subClass
 *  @param keyNames keyName collection ,select tableName where keyName = value and keyName = value ...,Search results, If present, the update, or the inserted
 *
 *  @return Save the result
 */
+(BOOL)saveWtihConstraints:(id)obj KeyNames:(NSArray*)keyNames;


/**
 *  save the model
 *
 *  @param obj DBObject subClass
 *
 *  @return Save the result
 */
+(BOOL)save:(id)obj;


/**
 *  save the model
 *
 *  @param objs DBObject subClass collection
 *
 *  @return Save the result
 */
+(BOOL)saveObjs:(NSArray *)objs;


/**
 *  select * from   SELECT * FROM tableName WHERE keyName = value
 *
 *  @return select the result (DBObject model)
 */
+(id)get:(NSString*)keyName value:(NSString*)value;

/*
 * select * from   SELECT * FROM class WHERE keyName = value
 *
 *  @return select the result (DBObject model array)
 */
+(NSArray*)getList:(NSString*)keyName value:(NSString*)value;

/*
 * select * from   SELECT * FROM class WHERE keyName = value and keyName = value..
 *
 *@return select the result (DBObject model array)
 */
+(NSArray*)getWtihConstraints:(NSDictionary*)keyValues;


/*
 * select * from   SELECT * FROM class WHERE keyName = value and keyName = value..
 *
 *@return select the result (DBObject model array)
 */
+(NSArray *)selectWhere:(NSString *)where groupBy:(NSString *)groupBy orderBy:(NSString *)orderBy limit:(NSString *)limit;


/*
 * Get all the data into the table
 */
+(NSArray*)getAll;

/*
 *  Remove all
 */
+(void)deleteAll;

/*
 *Delete with keyName
 */
-(void)deleteWithKey:(NSString*)keyName;


/*
 *Delete with keyNames
 */
-(void)deleteWtihConstraints:(NSArray*)keyNames;


/*
 *Save with keyName
 */
-(BOOL)save:(NSString*)keyName;


/*
 *Save with keyNames
 */
-(BOOL)saveWtihConstraints:(NSArray*)keyNames;

@end

