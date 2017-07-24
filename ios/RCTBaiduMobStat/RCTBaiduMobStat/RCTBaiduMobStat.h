//
//  RCTBaiduMobStat.h
//  RCTBaiduMobStat
//
//  Created by Rurui Ye on 18/07/2017.
//  Copyright © 2017 Rurui Ye. All rights reserved.
//

#import <Foundation/Foundation.h>
#if __has_include(<React/RCTBridgeModule.h>)
#import <React/RCTBridgeModule.h>
#elif __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#elif __has_include("React/RCTBridgeModule.h")
#import "React/RCTBridgeModule.h"
#endif

#import "BaiduMobStat.h"

@interface RCTBaiduMobStat : NSObject <RCTBridgeModule>

@end
