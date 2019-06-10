public class AOAConnectManager {
    private static final String TAG = AOAConnectManager.class.getSimpleName();
    private static final String AOA_CONNECT_THREAD_NAME = "AOAConnectThread";

    private boolean mIsListen = true;
    private AOAConnectThread mAOAConnectThread = null;
    
    private static int counter = 0;

    private static AOAConnectManager mInstance = null;
    public static synchronized AOAConnectManager getInstance() {
        if (mInstance == null) {
            mInstance = new AOAConnectManager();
        }
        return mInstance;
    }

    public AOAConnectManager() {
        try {
            mAOAConnectThread = new AOAConnectThread();
            mAOAConnectThread.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void startAOAConnectManager() {
        LogUtil.i(TAG, "startAOAConnectManager");
        mIsListen = true;
    }

    public void stopAOAConnectManager() {
        LogUtil.i(TAG, "stopAOAConnectManager");
        mIsListen = false;
    }

    private class AOAConnectThread extends Thread {
        private boolean isRunning = true;

        public AOAConnectThread() {
            LogUtil.i(TAG, "AOAConnectThread created!");
            this.setName(AOA_CONNECT_THREAD_NAME);
        }

        public void cancel() {
            isRunning = false;
        }


        @Override
        public void run() {
            try {
                while (isRunning) {
                    if (isRunning == false) {
                        LogUtil.e(TAG, "AOAConnectThread has been canceled!");
                        continue;
                    }
    
                    LogUtil.i(TAG, "AOAConnectThread is running...");
    
                    if (mIsListen) {
                        counter++;
                        LogUtil.d(TAG, "AOAConnectThread is listening -> counter = " + counter);
                    } else {
                        LogUtil.d(TAG, "AOAConnectThread is not listening");
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}