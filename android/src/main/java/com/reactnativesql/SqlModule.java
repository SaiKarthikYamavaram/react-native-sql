package com.reactnativesql;


import androidx.annotation.NonNull;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;

public class SqlModule extends ReactContextBaseJavaModule {
  static {
    try {
      // Used to load the 'native-lib' library on application startup.
      System.loadLibrary("react-native-sql");
    } catch (Exception ignored) {
    }
  }

  private static native void initialize(long jsiPtr, String docDir);

  private static native void destruct();

  public static final String NAME = "QuickSQLite";

  public SqlModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }


  @NonNull
  @Override
  public void initialize() {
    super.initialize();

    SqlModule.initialize(
      this.getReactApplicationContext().getJavaScriptContextHolder().get(),
      this.getReactApplicationContext().getFilesDir().getAbsolutePath()
    );
  }

  @Override
  public void onCatalystInstanceDestroy() {
    SqlModule.destruct();
  }

}
