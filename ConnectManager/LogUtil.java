public class LogUtil {
    private static final String TAG = LogUtil.class.getSimpleName();

    private static final int VERBOSE = 0;
    private static final int DEBUG   = 1;
    private static final int INFO    = 2;
    private static final int WARN    = 3;
    private static final int ERROR   = 4;
    private static final int ASSERT  = 5;
    private static final int MAX     = 6;


    public static final String ANSI_RESET   = "\u001B[0m";
    public static final String ANSI_BLACK   = "\u001B[30m";
    public static final String ANSI_WHITE   = "\u001B[37m";     // Verbose
    public static final String ANSI_CYAN    = "\u001B[36m";     // Debug
    public static final String ANSI_YELLOW  = "\u001B[33m";     // Info 
    public static final String ANSI_GREEN   = "\u001B[32m";     // Warn
    public static final String ANSI_RED     = "\u001B[31m";     // Error
    public static final String ANSI_PURPLE  = "\u001B[35m";     // Assert 
    public static final String ANSI_BLUE    = "\u001B[34m";     // 


    public static final String ANSI_BLACK_BACKGROUND    = "\u001B[40m";
    public static final String ANSI_RED_BACKGROUND      = "\u001B[41m";
    public static final String ANSI_GREEN_BACKGROUND    = "\u001B[42m";
    public static final String ANSI_YELLOW_BACKGROUND   = "\u001B[43m";
    public static final String ANSI_BLUE_BACKGROUND     = "\u001B[44m";
    public static final String ANSI_PURPLE_BACKGROUND   = "\u001B[45m";
    public static final String ANSI_CYAN_BACKGROUND     = "\u001B[46m";
    public static final String ANSI_WHITE_BACKGROUND    = "\u001B[47m";


    private static final String[] PREFIX = {ANSI_WHITE  + "V/-", 
                                            ANSI_CYAN   + "D/-", 
                                            ANSI_YELLOW + "I/-", 
                                            ANSI_GREEN  + "W/-", 
                                            ANSI_RED    + "E/-", 
                                            ANSI_PURPLE + "A/-"};


    public static void v(String tag, String msg) {
        printMsg(VERBOSE, tag, msg);
    }

    public static void d(String tag, String msg) {
        printMsg(DEBUG, tag, msg);
    }

    public static void i(String tag, String msg) {
        printMsg(INFO, tag, msg);
    }

    public static void w(String tag, String msg) {
        printMsg(WARN, tag, msg);
    }

    public static void e(String tag, String msg) {
        printMsg(ERROR, tag, msg);
    }

    public static void a(String tag, String msg) {
        printMsg(ASSERT, tag, msg);
    }

    private static void printMsg(int level, String tag, String msg) {
        System.out.println(PREFIX[level] + tag + " || " + msg + ANSI_RESET);
    }

    public static void main(String[] args) {
        LogUtil.d("HELLO", "WORLD");
        LogUtil.i("HELLO", "WORLD");
        LogUtil.v("HELLO", "WORLD");
        LogUtil.e("HELLO", "WORLD");
        LogUtil.a("HELLO", "WORLD");

        // System.out.println(ANSI_GREEN_BACKGROUND + "This text has a green background but default text!" + ANSI_RESET);
        // System.out.println(ANSI_RED + "This text has red text but a default background!" + ANSI_RESET);
        // System.out.println(ANSI_GREEN_BACKGROUND + ANSI_RED + "This text has a green background and red text!" + ANSI_RESET);
    }
}