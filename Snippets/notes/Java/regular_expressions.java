package Snippets.notes.Java;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class regular_expressions {

    private static final Pattern LOG = Pattern.compile("\\[(\\w+)\\]:\\s*(.*)");

    public static void main(String[] args) {
        String logLine = "[ERROR]: Disk full";   // must match the pattern to hit the if
        Matcher m = LOG.matcher(logLine);

        if (m.matches()) {
            String level = m.group(1).toLowerCase(); // "error"
            String message = m.group(2).trim();      // "Disk full"
            System.out.println(level + " / " + message);
        }
    }
}


//     public static Pattern P = Pattern.compile("\\[(\\w+)\\]:\\s+(.+?)\\s*");
// \\w = letter/digit/_
// \\d = digit
// \\s = space/tab/newline
// . = any character except linebreak
// *? = 0 or more lazily i.e. take as little as possible until regex to right of this matches to end

// e.g. "Timezone not set ". The trailing spaces are inside the group, which is the bug in your test.
// Lazy (.*?)\s*:
// .*? starts with nothing and asks, "can the rest match from here?"
// After T, \s* matches nothing and then the end of the string isn't reached, so the match fails. Take one more character and try again.
// This repeats until .*? has consumed exactly Timezone not set. Now \s* can eat \r\n and reach the end of the string, so the match succeeds.