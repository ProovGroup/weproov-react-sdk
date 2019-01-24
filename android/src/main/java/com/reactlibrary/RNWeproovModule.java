
package com.reactlibrary;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReadableMap;

import android.widget.Toast;
import report.Report;

import com.weproov.sdk.WPLoadingActivity;
import com.weproov.sdk.WPParameters;

public class RNWeproovModule extends ReactContextBaseJavaModule {
  
  private static final int REQ_CODE = 2106;

  private final ReactApplicationContext reactContext;

  public RNWeproovModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
  }

  @Override
  public String getName() {
    return "RNWeproov";
  }

  @ReactMethod
  public void setTheme(ReadableMap nothing, Callback failure){
    //We don't set theme like this on Android
  }

  @ReactMethod
  public void loadProovCode(String proovcode, Callback callback){
    WPParameters params = new WPParameters();
    //params.isImportSectionVisibleByDefault = true;
    getCurrentActivity().startActivityForResult(WPLoadingActivity.getIntent(getCurrentActivity(), proovcode, params), REQ_CODE);
  }

  @ReactMethod
  public void loadTemplate(int templateId, Callback callback){
    WPParameters params = new WPParameters();
    getCurrentActivity().startActivityForResult(WPLoadingActivity.getIntentForTemplate(getCurrentActivity(), templateId, params), REQ_CODE);
  }

  @ReactMethod
  public void haveReportInCache(Callback callback){
    if(Report.getCurrent() != null){
      callback.invoke(1);
    }
    else{
      callback.invoke(0);
    }
    
  }

}