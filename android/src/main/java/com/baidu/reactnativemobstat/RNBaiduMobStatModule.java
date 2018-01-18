package com.baidu.reactnativemobstat;

import com.baidu.mobstat.StatService;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.ReadableMapKeySetIterator;

import java.util.HashMap;

/**
 * Created by yangjie18 on 17/8/17.
 */

public class RNBaiduMobStatModule extends ReactContextBaseJavaModule {

    private ReactApplicationContext reactContext;

    public RNBaiduMobStatModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "BaiduMobStat";
    }

    @ReactMethod
    public void onPageStart(String name) {
        StatService.onPageStart(this.reactContext, name);
    }

    @ReactMethod
    public void onPageEnd(String name) {
        StatService.onPageEnd(this.reactContext, name);
    }

    @ReactMethod
    public void setDebugOn(Boolean isDebug) {
        StatService.setDebugOn(isDebug);
    }

    @ReactMethod
    public void onEvent(String eventId, String label) {
        StatService.onEvent(this.reactContext, eventId, label);
    }

    @ReactMethod
    public void onEventWithAttributes(String eventId, String label, ReadableMap readableMap) {
        StatService.onEvent(this.reactContext, eventId, label, 1, getConvertedMap(readableMap));
    }

    @ReactMethod
    public void onEventStart(String eventId, String label) {
        StatService.onEventStart(this.reactContext, eventId, label);
    }

    @ReactMethod
    public void onEventEnd(String eventId, String label) {
        StatService.onEventEnd(this.reactContext, eventId, label);
    }

    @ReactMethod
    public void onEventEndWithAttributes(String eventId, String label, ReadableMap readableMap) {
        StatService.onEventEnd(this.reactContext, eventId, label, getConvertedMap(readableMap));
    }

    @ReactMethod
    public void onEventDuration(String eventId, String label, Integer milliseconds) {
        StatService.onEventDuration(this.reactContext, eventId, label, milliseconds.longValue());
    }

    @ReactMethod
    public void onEventDurationWithAttributes(String eventId, String label, Integer milliseconds,
                                              ReadableMap readableMap) {
        StatService.onEventDuration(this.reactContext, eventId, label, milliseconds.longValue(),
                                    getConvertedMap(readableMap));
    }

    private HashMap<String, String> getConvertedMap(ReadableMap readableMap) {
        HashMap<String, String> hashMap = null;
        if (readableMap == null) {
            return hashMap;
        }

        ReadableMapKeySetIterator iterator = readableMap.keySetIterator();
        if ((iterator != null) && (iterator.hasNextKey())) {
            hashMap = new HashMap<String, String>();
        }

        while (iterator.hasNextKey()) {
            try {
                String key = iterator.nextKey();
                String value = readableMap.getString(key);
                hashMap.put(key, value);
            } catch (Exception e) {
                // no to print
            }
        }

        return hashMap;
    }

}
