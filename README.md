##

The demo show how to intercept apps' OpenGLES API `glClear` in android.

Tested on Android 9.0!

### build step

down the latest NDK from Android official web site.

```
$ cd jni
$ {the-part-of-ndk}/ndk-build
```

### run the demo

1. first prepare a rooted android phone. 
2. install the gles demo apk
3. run

```
$ adb root
$ adb push libdldemo.so /data/data/gles.demo/
$ adb shell setprop wrap.gles.demo LD_PRELOAD=/data/data/gles.demo/libdldemo.so

```

launch the app, and logcat

```
adb logcat -s GAPID
```

you can see

```
05-26 13:37:11.635 10445 10501 I GAPID   : [/home/wetest/workspace/dldemo/jni/../test.cpp:19] ######: glClear enter #######: arg: 16384
05-26 13:37:11.650 10445 10501 I GAPID   : [/home/wetest/workspace/dldemo/jni/../test.cpp:21] ######: glClear leave
05-26 13:37:11.651 10445 10501 I GAPID   : [/home/wetest/workspace/dldemo/jni/../test.cpp:19] ######: glClear enter #######: arg: 16384
05-26 13:37:11.666 10445 10501 I GAPID   : [/home/wetest/workspace/dldemo/jni/../test.cpp:21] ######: glClear leave
05-26 13:37:11.667 10445 10501 I GAPID   : [/home/wetest/workspace/dldemo/jni/../test.cpp:19] ######: glClear enter #######: arg: 16384
```

## reference

1. https://github.com/googlesamples/android-ndk/tree/master-ndkbuild
2. https://developer.android.google.cn/ndk/guides/cpp-support
3. https://developer.android.google.cn/ndk/guides/android_mk
4. https://www.zcfy.cc/article/dynamic-linker-tricks-using-ld-preload-to-cheat-inject-features-and-investigate-programs
