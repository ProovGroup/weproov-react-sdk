package com.reactlibrary;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;

import com.google.android.gms.gcm.GcmNetworkManager;

import com.weproov.sdk.internal.UploadActivity;
import com.weproov.sdk.WPReportUploadService;

public class WPReportUploaderPlugin extends ReactContextBaseJavaModule {

    private final ReactApplicationContext reactContext;

    public WPReportUploaderPlugin(ReactApplicationContext reactContext) {
      super(reactContext);
      this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "WPReportUploaderPlugin";
    }

    @ReactMethod
    public void sync(){
        GcmNetworkManager.getInstance(this.getCurrentActivity()).schedule(WPReportUploadService.getTask());
    }

}