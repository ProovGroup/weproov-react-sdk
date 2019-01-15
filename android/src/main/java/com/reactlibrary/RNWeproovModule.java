
package com.reactlibrary;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;

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
  public void setTheme(Callback success, Callback failure){
    success.invoke("Success");
  }

  @ReactMethod
  public void toast(String message){
    Toast.makeText(getReactApplicationContext(), message, Toast.LENGTH_SHORT).show();
  }

  @ReactMethod
  public void loadProovCode(String proovcode, Callback success, Callback failure){
    WPParameters params = new WPParameters();
    //params.isImportSectionVisibleByDefault = true;

    getCurrentActivity().startActivityForResult(WPLoadingActivity.getIntent(getCurrentActivity(), proovcode, params), REQ_CODE);
  }

  @ReactMethod
  public void loadTemplate(int templateId, Callback success, Callback failure){
    //TODO
  }

  @ReactMethod
  public void haveReportInCache(Callback success){
    if(Report.getCurrent() != null){
      success.invoke(1);
    }
    else{
      success.invoke(0);
    }
    
  }

}