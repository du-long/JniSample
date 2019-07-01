# JNI 学习笔记

## Android 使用C/C++代码


### 1、创建JNI目录
在java同级目录中创建jni文件夹：\JniSample\app\src\main\jni <br>
或者model（app）右键->New->Folder->Jni Folder->Finish

### 2、创建C/C++文件
jni目录右键->New->C/C++ Source File 

### 3、声明Jni方法
Jni方法名必须指令调用的类的全称及方法<br> 
如：
``` 
#include <jni.h>
jstring Java_top_itdl_jni_NDKTools_getStringFormNDK(JNIEnv *env, jclass type) {
    return (*env)->NewStringUTF(env, "I am Str from jni libs!");
}
```

### 4、编写 Android.mk 文件
LOCAL_PATH := $(call my-dir)<br>
include $(CLEAR_VARS)<br>
LOCAL_MODULE := jni-test<br>
LOCAL_SRC_FILES := JniTest.c<br>
include $(BUILD_SHARED_LIBRARY)<br>

``` 
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := jni-test
LOCAL_SRC_FILES := JniTest.c
include $(BUILD_SHARED_LIBRARY)
```

### 5、 build.gradle 添加配置

``` 
android {
   ....
    externalNativeBuild {
        ndkBuild {
            path 'src/main/jni/Android.mk'
        }
    }
    sourceSets {
        main {
            jniLibs.srcDirs = ['libs']
        }
    }
}

```

### 6、声明本地方法 
通过 native 关键字生命的方法为jni方法
```
package top.itdl.jnisample;

public class JniApi {
    static {
        System.loadLibrary("jni-test");
    }

    public native static String getStringFormJni();
}

```

### 7、Android 调用 Jni 方法
```
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String stringFormJni = JniApi.getStringFormJni();
        ((TextView) findViewById(R.id.tv_text)).setText(stringFormJni);
    }
}
```