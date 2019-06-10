public class EanConnectManager {
    private static final String TAG = EanConnectManager.class.getSimpleName();
    private static final String EAN_CONNECT_THREAD_NAME = "EanConnectThread";

    private boolean mIsListen = false;
    private EanConnectThread mEanConnectThread = null;
    
    private static int counter = 0;


    private static EanConnectManager mInstance = null;
    public static synchronized EanConnectManager getInstance() {
        if (mInstance == null) {
            mInstance = new EanConnectManager();
        }
        return mInstance;
    }

    public EanConnectManager() {
        try {
            LogUtil.i(TAG, "EanConnectManager created!");
            mEanConnectThread = new EanConnectThread();
            mEanConnectThread.start();
        } catch (Exception e) {
            e.printStackTrace();
            LogUtil.e(TAG, "EanConnectManager create fail!");
        }
    }

    public void startEanConnectManager() {
        mIsListen = true;
        LogUtil.i(TAG, "startEanConnectManager");
    }

    public void stopEanConnectManager() {
        mIsListen = false;
        LogUtil.i(TAG, "stopEanConnectManager");
    }

    private class EanConnectThread extends Thread {
        private boolean isRunning = true;

        public EanConnectThread() {
            this.setName(EAN_CONNECT_THREAD_NAME);
            LogUtil.i(TAG, "EanConnectThread created!");
        }

        public void cancel() {
            isRunning = false;
        }

        @Override
        public void run() {
            while (isRunning) {
                try {
                    if (isRunning == false) {
                        LogUtil.e(TAG, "EanConnectThread has been canceled!");
                        continue;
                    }

                    LogUtil.i(TAG, "EanConnectThread is running...");

                    if (mIsListen) {
                        counter++;
                        LogUtil.d(TAG, "EanConnecThread is listening -> counter = " + counter);
                    } else {
                        LogUtil.d(TAG, "EanConnectThread is not listening");
                    }
                    
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }


}