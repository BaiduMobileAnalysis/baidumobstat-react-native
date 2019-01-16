//
//  RCTBaiduMobStat.m
//  RCTBaiduMobStat
//
//  Created by Rurui Ye on 18/07/2017.
//  Copyright © 2017 Rurui Ye. All rights reserved.
//

#import "RCTBaiduMobStat.h"
#import <React/RCTLog.h>

@implementation RCTBaiduMobStat

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(onEvent:(NSString *)eventId eventLabel:(NSString *)eventLabel) {
    [[BaiduMobStat defaultStat] logEvent:eventId eventLabel: eventLabel];
}

RCT_EXPORT_METHOD(onEventDuration:(NSString *)eventId eventLabel:(NSString *)eventLabel durationTime:(nonnull NSNumber *)duration) {
    [[BaiduMobStat defaultStat] logEventWithDurationTime:eventId eventLabel: eventLabel durationTime:[duration unsignedLongValue]];
}


RCT_EXPORT_METHOD(onEventStart:(NSString *)eventId eventLabel:(NSString *)eventLabel) {
    [[BaiduMobStat defaultStat] eventStart:eventId eventLabel: eventLabel];
}


RCT_EXPORT_METHOD(onEventEnd:(NSString *)eventId eventLabel:(NSString *)eventLabel) {
    [[BaiduMobStat defaultStat] eventEnd:eventId eventLabel: eventLabel];
}


RCT_EXPORT_METHOD(onEventWithAttributes:(NSString *)eventId eventLabel:(NSString *)eventLabel attributes:(NSDictionary *)attributes) {
    [[BaiduMobStat defaultStat] logEvent:eventId eventLabel: eventLabel attributes:attributes];
}


RCT_EXPORT_METHOD(onEventDurationWithAttributes:(NSString *)eventId eventLabel:(NSString *)eventLabel durationTime:(nonnull NSNumber *)duration attributes:(NSDictionary *)attributes) {
    [[BaiduMobStat defaultStat] logEventWithDurationTime:eventId eventLabel: eventLabel durationTime:[duration unsignedLongValue] attributes:attributes];
}


RCT_EXPORT_METHOD(onEventEndWithAttributes:(NSString *)eventId eventLabel:(NSString *)eventLabel attributes:(NSDictionary *)attributes) {
    [[BaiduMobStat defaultStat] logEvent:eventId eventLabel: eventLabel attributes:attributes];
}


RCT_EXPORT_METHOD(onPageStart:(NSString *)name) {
    [[BaiduMobStat defaultStat] pageviewStartWithName:name];
}


RCT_EXPORT_METHOD(onPageEnd:(NSString *)name) {
    [[BaiduMobStat defaultStat] pageviewEndWithName:name];
}
@end
