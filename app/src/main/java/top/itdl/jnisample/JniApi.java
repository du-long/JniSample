package top.itdl.jnisample;

public class JniApi {
    static {
        System.loadLibrary("jni-test");
    }

    public native static String getStringFormJni();
}
