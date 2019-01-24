package com.reactlibrary;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;

import com.weproov.sdk.WPConfig;
import user.User;

public class WPUserPlugin extends ReactContextBaseJavaModule {
  
    private final ReactApplicationContext reactContext;

    public WPUserPlugin(ReactApplicationContext reactContext) {
      super(reactContext);
      this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "WPUserPlugin";
    }

    @ReactMethod
    public void connect(String token, String secret, final Callback success){
        WPConfig.connect(this.getCurrentActivity(), token, secret, new WPConfig.ConnectionListener() {
            @Override
            public void onError(Exception e) {
                success.invoke(e.getMessage());
            }

            @Override
            public void onConnected() {
                success.invoke(0);
            }
        });
    }

    @ReactMethod
    public void logout(){
        User.logout();
    }

    @ReactMethod
    public void isConnected(Callback callback){
        if (WPConfig.isConnected()) {
            callback.invoke(1);
        }
        else{
            callback.invoke(0);
        }
    }

    @ReactMethod
    public void setLang(String lang){
        WPConfig.init(lang);
    }


}