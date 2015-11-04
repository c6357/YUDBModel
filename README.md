Welcome to the YUDBFramework!

一、DBOBject 介绍

感谢FMDB  
DBOBject 使用runtime + fmdb 封装


1.自动建表

2.自动检查增删表字段

3.自定义数据库名，文件路径

4.支持一对一对象数据库存储

5.支持多路径，多数据库关联查询

6.一键保存、修改、删除、查找、多级关联查询解析、反序列化

7.支持数据解析序列化、反序列化、json -> model  and  model ->json 

8.使用FMDatabaseQueue队列操作

9.只依赖唯一第三方库FMDB

二、如何使用


/*
*  Support multiple data using FALASE OR TRUE
*  Set TRUE customizable dbFolder () and dbName (), custom database location and file name
*
*  Folder Path
+(NSString*)dbFolder;
*
*  Database name
+(NSString*)dbName;
*/

#define SupportMultipleDB TRUE

/*
* Open DBObject framework console log
* TRUE Open, FALASE closed
*/
#define DBLogOpen 1


#import <YUDBFramework/DBOBject.h>

![.对象继承DBOBject 创建模型](http://static.oschina.net/uploads/space/2015/0821/223509_f4Vw_868062.png)

![2.自定义名字和路径，序列化属性](http://static.oschina.net/uploads/space/2015/0821/223746_K5lO_868062.png)
![2.自定义名字和路径，序列化属性](http://static.oschina.net/uploads/space/2015/0821/223747_rRnF_868062.png)

![.生成目录](http://static.oschina.net/uploads/space/2015/0821/224011_3fPy_868062.png)
![.生成目录](http://static.oschina.net/uploads/space/2015/0821/224013_1aEx_868062.png)
![3.具体实现](http://static.oschina.net/uploads/space/2015/0821/223849_UUZe_868062.png)
![](http://static.oschina.net/uploads/space/2015/0821/224744_ldNG_868062.png)


2015-08-21 22:41:14.498 YUDBObjectSample[3004:119272] 
 ||========================================================================||
 ||        \\    //    ========      \\    //                              ||
 ||         \\  //          ==        \\  //                               ||
 ||          \\//         ==           \\//                                ||   
 ||           ||         ==            //\\  Debug DBBaseObject:2015-08-21 ||
 ||           ||        ==            //  \\                               ||
 ||           ||       ========      //    \\                              ||
 ||========================================================================||
2015-08-21 22:41:14.499 YUDBObjectSample[3004:119272] 数据库位置：/Application/02781A8F-61C5-4669-8F63-BD038E7DBD00/Documents/user/User.db
2015-08-21 22:41:14.508 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5b930> time cost: 0.005
2015-08-21 22:41:14.512 YUDBObjectSample[3004:119272] 数据库位置：Application/02781A8F-61C5-4669-8F63-BD038E7DBD00/Documents/base/DB.db
2015-08-21 22:41:14.517 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5b930> time cost: 0.002
2015-08-21 22:41:14.517 YUDBObjectSample[3004:119272] 解析 DBObj 关联模型: UserInfo
2015-08-21 22:41:14.517 YUDBObjectSample[3004:119272] 解析 DBObj 关联NSArray: (
    "<UserInfo: 0x7fddf9f12790>",
    "<UserInfo: 0x7fddf9e57c10>",
    "<UserInfo: 0x7fddf9e5a820>",
    "<UserInfo: 0x7fddf9e5ba90>",
    "<UserInfo: 0x7fddf9e5d2b0>",
    "<UserInfo: 0x7fddf9e61200>",
    "<UserInfo: 0x7fddf9e613c0>",
    "<UserInfo: 0x7fddf9e5fd90>",
    "<UserInfo: 0x7fddf9e60430>",
    "<UserInfo: 0x7fddf9e5ea80>",
    "<UserInfo: 0x7fddf9e5df10>",
    "<UserInfo: 0x7fddf9e5f260>",
    "<UserInfo: 0x7fddf9e63630>",
    "<UserInfo: 0x7fddf9e5e090>",
    "<UserInfo: 0x7fddf9e60ef0>"
)
2015-08-21 22:41:14.538 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9f12790> time cost: 0.003
2015-08-21 22:41:14.541 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e57c10> time cost: 0.003
2015-08-21 22:41:14.544 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5a820> time cost: 0.003
2015-08-21 22:41:14.547 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5ba90> time cost: 0.003
2015-08-21 22:41:14.550 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5d2b0> time cost: 0.003
2015-08-21 22:41:14.553 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e61200> time cost: 0.003
2015-08-21 22:41:14.557 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e613c0> time cost: 0.003
2015-08-21 22:41:14.561 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5fd90> time cost: 0.004
2015-08-21 22:41:14.564 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e60430> time cost: 0.003
2015-08-21 22:41:14.567 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5ea80> time cost: 0.003
2015-08-21 22:41:14.570 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5df10> time cost: 0.003
2015-08-21 22:41:14.572 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5f260> time cost: 0.002
2015-08-21 22:41:14.575 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e63630> time cost: 0.002
2015-08-21 22:41:14.577 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e5e090> time cost: 0.002
2015-08-21 22:41:14.579 YUDBObjectSample[3004:119272] save <UserInfo: 0x7fddf9e60ef0> time cost: 0.002
2015-08-21 22:41:14.582 YUDBObjectSample[3004:119272] save <DBObj: 0x7fddf9e67400> time cost: 0.068
2015-08-21 22:41:14.604 YUDBObjectSample[3004:119272] info  {
    createDate = "2015-08-21 21:04:33.747";
    dId = "06F01456-9DFC-48BC-B590-66C0B2D727CD";
    info = "";
    infoArry = "";
    name = test1;
    parentId = " ";
    phone = 123456789;
}
2015-08-21 22:41:14.694 YUDBObjectSample[3004:119272] info  {
    createDate = "2015-08-21 21:05:01.765";
    dId = "9721F3AD-369F-451E-ADA2-C0D74C741979";
    info = "";
    infoArry = "";
    name = test1;
    parentId = " ";
    phone = 123456789;
}
2015-08-21 22:41:14.694 YUDBObjectSample[3004:119272] info  {
    createDate = "2015-08-21 21:20:39.917";
    dId = "56F2BAF9-5F09-4455-BE8C-CA9296BF9326";
    info = "";
    infoArry = "";
    name = test1;
    parentId = " ";
    phone = 123456789;
}
2015-08-21 22:41:14.695 YUDBObjectSample[3004:119272] info  {
    createDate = "2015-08-21 22:41:14.514";
    dId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    info =     {
        age = 0;
        createDate = "2015-08-21 22:41:14.503";
        dId = "96393192-4212-4626-AD79-D3F0629CBAD7";
        name = test;
        parentId = "";
        phone = 18521911111;
        sex = 0;
    };
    infoArry =     (
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.509";
            dId = "17EAFCB2-2A21-464B-BE7D-F583D185B47E";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_0";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.509";
            dId = "7DC0F438-CCA1-4A71-A2E0-65E38CA24D0A";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_1";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.509";
            dId = "D6DD121D-7B5C-4D3A-A0CF-2EA6B0B9242A";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_2";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.510";
            dId = "34572BA0-869D-4074-83BD-3C0990828A4F";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_3";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.510";
            dId = "504DE8CD-2AD8-4D74-9BAC-CDEC8B94E3C7";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_4";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.510";
            dId = "F7DA5E3A-CF34-404F-B030-A035EDB1BF98";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_5";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.510";
            dId = "A91A2F8D-746E-4768-BC39-9484EFFDA96C";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_6";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.511";
            dId = "6080C71A-6201-467E-B4DF-E7DF6C594E40";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_7";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.511";
            dId = "0EBBE1AE-BB07-4C82-82A9-CD7B4CD4FAD1";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_8";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.511";
            dId = "C0BD913E-BF68-4D74-8FCB-FCD3614C26DE";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_9";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.511";
            dId = "4CD83B9B-EB79-4A59-913D-4C6386291D3E";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_10";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.511";
            dId = "9530FBF0-DCE0-48BA-960B-4B9F7D64E1A0";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_11";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.512";
            dId = "75EE2B43-5273-485B-831D-A830C2C31E58";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_12";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.512";
            dId = "3E80CDF2-9691-47DF-BAA6-A21C94709ECC";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_13";
            sex = 0;
        },
                {
            age = 1;
            createDate = "2015-08-21 22:41:14.512";
            dId = "77958EB4-FA9F-4C60-B211-0F10856CEC3E";
            name = test;
            parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
            phone = "185219_14";
            sex = 0;
        }
    );
    name = test1;
    parentId = " ";
    phone = 123456789;
}
2015-08-21 22:41:14.756 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.509";
    dId = "17EAFCB2-2A21-464B-BE7D-F583D185B47E";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_0";
    sex = 0;
}
2015-08-21 22:41:14.781 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.509";
    dId = "7DC0F438-CCA1-4A71-A2E0-65E38CA24D0A";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_1";
    sex = 0;
}
2015-08-21 22:41:14.781 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.509";
    dId = "D6DD121D-7B5C-4D3A-A0CF-2EA6B0B9242A";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_2";
    sex = 0;
}
2015-08-21 22:41:14.782 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.510";
    dId = "34572BA0-869D-4074-83BD-3C0990828A4F";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_3";
    sex = 0;
}
2015-08-21 22:41:14.782 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.510";
    dId = "504DE8CD-2AD8-4D74-9BAC-CDEC8B94E3C7";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_4";
    sex = 0;
}
2015-08-21 22:41:14.782 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.510";
    dId = "F7DA5E3A-CF34-404F-B030-A035EDB1BF98";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_5";
    sex = 0;
}
2015-08-21 22:41:14.783 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.510";
    dId = "A91A2F8D-746E-4768-BC39-9484EFFDA96C";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_6";
    sex = 0;
}
2015-08-21 22:41:14.783 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.511";
    dId = "6080C71A-6201-467E-B4DF-E7DF6C594E40";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_7";
    sex = 0;
}
2015-08-21 22:41:14.783 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.511";
    dId = "0EBBE1AE-BB07-4C82-82A9-CD7B4CD4FAD1";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_8";
    sex = 0;
}
2015-08-21 22:41:14.783 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.511";
    dId = "C0BD913E-BF68-4D74-8FCB-FCD3614C26DE";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_9";
    sex = 0;
}
2015-08-21 22:41:14.784 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.511";
    dId = "4CD83B9B-EB79-4A59-913D-4C6386291D3E";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_10";
    sex = 0;
}
2015-08-21 22:41:14.784 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.511";
    dId = "9530FBF0-DCE0-48BA-960B-4B9F7D64E1A0";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_11";
    sex = 0;
}
2015-08-21 22:41:14.784 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.512";
    dId = "75EE2B43-5273-485B-831D-A830C2C31E58";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_12";
    sex = 0;
}
2015-08-21 22:41:14.785 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.512";
    dId = "3E80CDF2-9691-47DF-BAA6-A21C94709ECC";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_13";
    sex = 0;
}
2015-08-21 22:41:14.785 YUDBObjectSample[3004:119272] obj  {
    age = 1;
    createDate = "2015-08-21 22:41:14.512";
    dId = "77958EB4-FA9F-4C60-B211-0F10856CEC3E";
    name = test;
    parentId = "F0F964A8-D873-4E67-BA3B-6684481AF697";
    phone = "185219_14";
    sex = 0;
}
