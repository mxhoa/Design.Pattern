
public class ConnectManager {
    private static final String TAG = ConnectManager.class.getSimpleName();

    public static final int CONNECTED_BY_AOA  = 0;
    public static final int CONNECTED_BY_WIFI = 1;
    public static final int CONNECTED_BY_EAN  = 2;

    private static int mConnectType     = CONNECTED_BY_AOA;

    private static ConnectManager mInstance = null;
    public static synchronized ConnectManager getInstance() {
        if (mInstance == null) {
            mInstance = new ConnectManager();
        }
        return mInstance;
    }

    private ConnectManager() {
        LogUtil.d(TAG, "ConnectManager create!");
    }

    public int getConnectType() {
        return mConnectType;
    }   

    public void initConnectType(int type) {
        mConnectType = type;
    }

    public void startConnectThread(int connectType) {
        try {
            // int connectType = 1;
            LogUtil.i(TAG, "startConnectThread...");
            switch(connectType) {
                case CONNECTED_BY_WIFI:
                    WifiConnectManager.getInstance().startWifiConnectManager();
                    break;
                case CONNECTED_BY_AOA:
                    AOAConnectManager.getInstance().startAOAConnectManager();
                    break;
                case CONNECTED_BY_EAN:
                    EanConnectManager.getInstance().startEanConnectManager();
                    break;
                default:
                    break;
            }
        } catch (Exception e) {
            LogUtil.e(TAG, "Start ConnectThread Fail");
            e.printStackTrace();
        }
    }

    public void stopConnectThread() {
        try {
            int connectType = 0;
            LogUtil.i(TAG, "stopConnectThread...");
            switch(connectType) {
                case CONNECTED_BY_WIFI:
                    WifiConnectManager.getInstance().stopWifiConnectManager();
                    break;
                case CONNECTED_BY_AOA:
                    AOAConnectManager.getInstance().stopAOAConnectManager();
                    break;
                case CONNECTED_BY_EAN:
                    EanConnectManager.getInstance().stopEanConnectManager();
                    break;
                default:
                    break;
            }
        } catch (Exception e) {
            LogUtil.e(TAG, "Stop ConnectThread Fail");
            e.printStackTrace();
        }
    }
}