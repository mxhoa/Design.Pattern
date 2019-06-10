
public class WifiConnectManager {
    private static final String TAG = WifiConnectManager.class.getSimpleName();
    private static final String WIFI_CONNECT_THREAD_NAME = "WifiConnectThread";

    private boolean mIsListen = true;
    private WifiConnectThread mWifiConnectThread = null;
    
    private static int counter = 0;

    private static WifiConnectManager mInstance = null;
    public static synchronized WifiConnectManager getInstance() {
        if (mInstance == null) {
            mInstance = new WifiConnectManager();
        }
        return mInstance;
    }


    public WifiConnectManager() {
        try {
            LogUtil.i(TAG, "WifiConnectManager created!!!");
            mWifiConnectThread = new WifiConnectThread();
            mWifiConnectThread.start();
        } catch (Exception e) {
            LogUtil.e(TAG, "WifiConnectManager create fail!!!");
            e.printStackTrace();
        }
    }

    public void startWifiConnectManager() {
        LogUtil.i(TAG, "startWifiConnectManager");
        mIsListen = true;
    }

    public void stopWifiConnectManager() {
        LogUtil.i(TAG, "stopWifiConnectManager");
        mIsListen = false;
    }

    private class WifiConnectThread extends Thread {
        private boolean isRunning = true;

        public WifiConnectThread() {
            LogUtil.i(TAG, "WifiConnectThread Created");
            this.setName(WIFI_CONNECT_THREAD_NAME);
        }

        public void cancel() {
            isRunning = false;
        }

        @Override
        public void run() {
            while (isRunning) {
                try {
                    if (isRunning == false) {
                        LogUtil.e(TAG, "WifiConnectThread has been canceled");
                        continue;
                    }
                    LogUtil.e(TAG, "WifiConnectThread is Running....");
                    
                    if (mIsListen) {
                        counter++;
                        if (counter == 1000)
                        {
                            mIsListen = false;
                        }
                        LogUtil.d(TAG, "WifiConnectThread is Listening.... Counter = " + counter);
                    } else {
                        LogUtil.d(TAG, "WifiConnectThread is not Listening...");
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}