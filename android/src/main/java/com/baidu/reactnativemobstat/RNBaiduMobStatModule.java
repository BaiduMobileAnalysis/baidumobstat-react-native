package com.baidu.reactnativemobstat;

import android.text.TextUtils;

import com.baidu.mobstat.ExtraInfo;
import com.baidu.mobstat.StatService;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.ReadableMapKeySetIterator;

import java.util.HashMap;
import java.util.Map;

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

    /**
     * 设置用户id。设置后会在保存在本地，如果需要清除设置，传入null
     */
    @ReactMethod
    public void setUserId(String userId) {
        StatService.setUserId(this.reactContext, userId);
    }

    /**
     * 设置全局附加信息，设置的附加信息会组装在日志头部。只需设置一次，设置后，相关数据会保留，每次发送的日志都会携带此信息
     *
     * 最多设置10个key，key固定为V1-V10，value只能是String格式
     *
     * 传入null则清除历史设置的信息
     */
    @ReactMethod
    public void setGlobalExtraInfo(ReadableMap readableMap) {
        ExtraInfo extraInfo = new ExtraInfo();
        HashMap<String, String> infoMap = getConvertedMap(readableMap);
        for (Map.Entry<String, String> entry : infoMap.entrySet()) {
            String key = entry.getKey();
            String value = entry.getValue();
            if (TextUtils.isEmpty(key) || TextUtils.isEmpty(value)) {
                continue;
            }
            switch (key) {
                case "V1":
                    extraInfo.setV1(value);
                    break;
                case "V2":
                    extraInfo.setV2(value);
                    break;
                case "V3":
                    extraInfo.setV3(value);
                    break;
                case "V4":
                    extraInfo.setV4(value);
                    break;
                case "V5":
                    extraInfo.setV5(value);
                    break;
                case "V6":
                    extraInfo.setV6(value);
                    break;
                case "V7":
                    extraInfo.setV7(value);
                    break;
                case "V8":
                    extraInfo.setV8(value);
                    break;
                case "V9":
                    extraInfo.setV9(value);
                    break;
                case "V10":
                    extraInfo.setV10(value);
                    break;
                default:
                    break;
            }
        }
        StatService.setGlobalExtraInfo(this.reactContext, extraInfo);
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
