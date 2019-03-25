public class Indentation {
    private StringBuffer sbIndent = new StringBuffer();

    public String getIndentation() {
        return sbIndent.toString();
    }

    public void increaseIndentation() {
        sbIndent.append("    ");
    }

    public void descreaseIndentation() {
        if (sbIndent.length() >= 4) {
            sbIndent.setLength(sbIndent.length() - 4);
        }
    }
}